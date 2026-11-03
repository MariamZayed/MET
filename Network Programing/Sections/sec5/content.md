
# Mini Remote Desktop (C# TCP Socket Programming)

A lightweight LAN screen-streaming application built using C# Windows Forms and TCP Sockets.

---

## 1. How It Works
* **Server (`10.77.2.1`):** Captures the primary screen, compresses it into a `JPEG` byte array (`byte[]`), sends the **4-byte image size header**, followed by the **image payload** over Port `5000`.
* **Client (`10.77.2.3`):** Connects to the Server IP, reads the first 4 bytes to determine the incoming frame size, reads the full image byte array from the `NetworkStream`, and renders it inside a `PictureBox`.

---

## 2. Network Setup
1. Open `CMD` on both machines and run `ipconfig` to verify the **IPv4 Address**:
   * **Server IP:** `10.77.2.1`
   * **Client IP:** `10.77.2.3`
2. Verify connectivity from the Client machine by running:
   ```cmd
   ping 10.77.2.1

3. Execution Steps & Source Code
Step A: Server Machine (10.77.2.1)
 * Open Visual Studio and create a new Windows Forms Application named RemoteServerApp.
 * Press F7 to open Form1.cs, replace all existing code with the following, and press F5 to run (Click Allow Access if prompted by Windows Firewall):

```
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Windows.Forms;

namespace RemoteServerApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Text = "Server (10.77.2.1) - Waiting...";
            this.Size = new Size(400, 150);

            Thread serverThread = new Thread(StartServer);
            serverThread.IsBackground = true;
            serverThread.Start();
        }

        private void StartServer()
        {
            try
            {
                TcpListener server = new TcpListener(IPAddress.Any, 5000);
                server.Start();

                TcpClient client = server.AcceptTcpClient();
                this.Invoke((MethodInvoker)(delegate { this.Text = "Connected! Streaming..."; }));

                NetworkStream stream = client.GetStream();

                while (client.Connected)
                {
                    Rectangle bounds = Screen.PrimaryScreen.Bounds;
                    using (Bitmap bitmap = new Bitmap(bounds.Width, bounds.Height))
                    {
                        using (Graphics g = Graphics.FromImage(bitmap))
                        {
                            g.CopyFromScreen(Point.Empty, Point.Empty, bounds.Size);
                        }

                        using (MemoryStream ms = new MemoryStream())
                        {
                            bitmap.Save(ms, ImageFormat.Jpeg);
                            byte[] imageBytes = ms.ToArray();

                            byte[] sizeInfo = BitConverter.GetBytes(imageBytes.Length);
                            stream.Write(sizeInfo, 0, sizeInfo.Length);
                            stream.Write(imageBytes, 0, imageBytes.Length);
                        }
                    }
                    Thread.Sleep(100);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Server Error: " + ex.Message);
            }
        }
    }
}
```

Step B: Client Machine (10.77.2.3)
 * Open Visual Studio and create a new Windows Forms Application named RemoteClientApp.
 * Press F7 to open Form1.cs (no need to drag any controls from the Toolbox), replace all existing code with the following, and press F5 to run:
 * Click the "Connect to 10.77.2.1" button to start viewing the Server screen.

```
using System;
using System.Drawing;
using System.IO;
using System.Net.Sockets;
using System.Threading;
using System.Windows.Forms;

namespace RemoteClientApp
{
    public partial class Form1 : Form
    {
        private PictureBox screenBox;
        private Button btnConnect;

        public Form1()
        {
            InitializeComponent();
            this.Text = "Client Viewer (10.77.2.3)";
            this.Size = new Size(800, 600);

            btnConnect = new Button();
            btnConnect.Text = "Connect to 10.77.2.1";
            btnConnect.Dock = DockStyle.Top;
            btnConnect.Height = 40;
            btnConnect.Click += BtnConnect_Click;

            screenBox = new PictureBox();
            screenBox.Dock = DockStyle.Fill;
            screenBox.SizeMode = PictureBoxSizeMode.StretchImage;

            this.Controls.Add(screenBox);
            this.Controls.Add(btnConnect);
        }

        private void BtnConnect_Click(object sender, EventArgs e)
        {
            btnConnect.Enabled = false;
            btnConnect.Text = "Connected - Viewing 10.77.2.1";
            StartReceiving("10.77.2.1");
        }

        private void StartReceiving(string serverIp)
        {
            Thread clientThread = new Thread(delegate ()
            {
                try
                {
                    TcpClient client = new TcpClient(serverIp, 5000);
                    NetworkStream stream = client.GetStream();

                    while (client.Connected)
                    {
                        byte[] sizeBuffer = new byte[4];
                        int read = 0;
                        while (read < 4)
                        {
                            int r = stream.Read(sizeBuffer, read, 4 - read);
                            if (r == 0) return;
                            read += r;
                        }
                        int imageSize = BitConverter.ToInt32(sizeBuffer, 0);

                        byte[] imageBytes = new byte[imageSize];
                        int totalRead = 0;
                        while (totalRead < imageSize)
                        {
                            int r = stream.Read(imageBytes, totalRead, imageSize - totalRead);
                            if (r == 0) return;
                            totalRead += r;
                        }

                        MemoryStream ms = new MemoryStream(imageBytes);
                        Image img = Image.FromStream(ms);

                        screenBox.Invoke((MethodInvoker)(delegate
                        {
                            if (screenBox.Image != null) screenBox.Image.Dispose();
                            screenBox.Image = img;
                        }));
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Client Error: " + ex.Message);
                }
            });
            clientThread.IsBackground = true;
            clientThread.Start();
        }
    }
}
```

4. Key Classes Used
 * TcpListener / TcpClient: Establishes the TCP connection over Port 5000.
 * NetworkStream: Sends and receives raw byte[] streams across the network.
 * Graphics.CopyFromScreen: Captures the desktop screen into a Bitmap.
 * MemoryStream: Converts the Bitmap image to a compressed JPEG byte array and vice versa.
 * BitConverter: Converts the image length (int) into a 4-byte header (Length-Prefixed Framing).

