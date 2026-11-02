تم عكس الأدوار؛ جهازك الأول (10.77.2.1) هو السيرفر الذي يبث شاشته، والجهاز الثاني (10.77.2.3) هو الكلاينت الذي سيشاهد الشاشة.
أولاً: كود جهازك الأول (10.77.2.1 - Server / الجهاز الذي سنعرض شاشته)
 * افتحي مشروع Windows Forms App (.NET Framework) على جهازك 10.77.2.1.
 * بدون إضافة أي أدوات على الفورم، افتحي صفحة الكود (View Code) واستبدلي الكود بالتالي، ثم شغليه (Run):
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
            this.Text = "Server (10.77.2.1) - Waiting for 10.77.2.3...";
            
            Thread serverThread = new Thread(StartServer);
            serverThread.IsBackground = true;
            serverThread.Start();
        }

        private void StartServer()
        {
            try
            {
                // يستمع على جهازك الأول (10.77.2.1) على بورت 5000
                TcpListener server = new TcpListener(IPAddress.Any, 5000);
                server.Start();

                TcpClient client = server.AcceptTcpClient();
                this.Invoke((MethodInvoker)(() => this.Text = "Connected to 10.77.2.3! Streaming my screen..."));

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

(تأكدي من الضغط على Allow Access لو ظهرت نافذة الـ Firewall على جهازك).
ثانياً: كود الجهاز الثاني (10.77.2.3 - Client / الجهاز الذي سيشاهد شاشة جهازك)
 * افتحي مشروع Windows Forms App (.NET Framework) على الجهاز الثاني 10.77.2.3.
 * ضعي PictureBox (pictureBox1 واجعلي SizeMode يساوي StretchImage)، وضعي زرار Button (button1).
 * اضغطي دبل كليك على الزرار لربط الحدث، وضعي الكود التالي (يتصل بالـ IP الخاص بجهازك 10.77.2.1):
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
        public Form1()
        {
            InitializeComponent();
            this.Text = "Client Viewer (10.77.2.3)";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Enabled = false;
            // الاتصال بجهازك الأول 10.77.2.1
            StartReceiving("10.77.2.1");
        }

        private void StartReceiving(string serverIp)
        {
            Thread clientThread = new Thread(() =>
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

                        pictureBox1.Invoke((MethodInvoker)(() =>
                        {
                            pictureBox1.Image?.Dispose();
                            pictureBox1.Image = img;
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

شغلي جهازك الأول (10.77.2.1) أولاً، ثم شغلي الجهاز الثاني (10.77.2.3) واضغطي على الزرار لتظهر شاشة جهازك عليه.
