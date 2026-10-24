# UDP (C#)

## نظرة عامة
(Server & Client) لتبادل الرسائل النصية باستخدام بروتوكول **UDP (User Datagram Protocol)**.

على عكس بروتوكول TCP، يُعد بروتوكول UDP:
* **Connectionless:** لا يحتاج إلى إنشاء اتصال مسبق (Handshake) بين الطرفين.
* **Datagram-Oriented:** تُرسل البيانات على هيئة حزم منفصلة ومستقلة دون ضمان للترتيب أو الوصول، مما يجعله أسرع وأخف في استهلاك الموارد.

---

## 1. كود الخادم (UDP Server)

يعمل الخادم بنمط الاستماع الدائم داخل حلقة مستمرة (`while (true)`) لتجنب إغلاق شاشة الكونسول فور استلام أول رسالة، وليتمكن من خدمة أكثر من مرسل.

```csharp
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class UdpServer
{
    static void Main()
    {
        // 1. إنشاء السوكت: نوع Dgram وبروتوكول Udp
        Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

        // 2. ربط السوكت بعنوان الجهاز المحلي والمنفذ 5020
        server.Bind(new IPEndPoint(IPAddress.Any, 5020));

        Console.Title = "UDP Server - Listening on Port 5020";
        Console.WriteLine("=======================================");
        Console.WriteLine(" UDP Server Started & Waiting for data ");
        Console.WriteLine("=======================================\n");

        byte[] buffer = new byte[1024];

        // 3. حلقة مستمرة لاستقبال البيانات وإبقاء نافذة الكونسول مفتوحة
        while (true)
        {
            // كائن EndPoint لتخزين عنوان ومنفذ العميل المُرسل تلقائياً
            EndPoint senderRemote = new IPEndPoint(IPAddress.Any, 0);

            // استقبال البيانات (دالة Blocking تنتظر حتى تصل حزمة)
            int count = server.ReceiveFrom(buffer, ref senderRemote);

            // تحويل البايتات المستلمة إلى نص
            string msg = Encoding.ASCII.GetString(buffer, 0, count);

            // طباعة وقت الاستلام وعنوان العميل والرسالة
            Console.WriteLine($"[{DateTime.Now:HH:mm:ss}] From {senderRemote}: {msg}");
        }

        // server.Close(); // لن يصل إليها البرنامج إلا عند الإيقاف اليدوي
    }
}

```

---

## 2. كود العميل (UDP Client)

يقوم العميل بتحويل النص إلى مصفوفة بايتات وإرسالها مباشرة إلى السيرفر دفعة واحدة باستخدام `SendTo`، مع إيقاف الشاشة في النهاية لضمان عدم إغلاقها تلقائياً.

```csharp
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class UdpClient
{
    static void Main()
    {
        // 1. إنشاء سوكت UDP
        Socket client = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

        // 2. تحديد عنوان السيرفر والمنفذ المستهدف
        // ملاحظة: للتجربة على جهازين بالمعمل، استبدل Loopback بالـ IP الفعلي للسيرفر
        EndPoint serverEp = new IPEndPoint(IPAddress.Loopback, 5020);

        Console.Title = "UDP Client";
        Console.Write("Enter message to send: ");
        string msg = Console.ReadLine();

        // 3. تحويل النص إلى مصفوفة بايتات
        byte[] data = Encoding.ASCII.GetBytes(msg);

        // 4. إرسال الحزمة مباشرة دون حاجة لعمل Connect
        client.SendTo(data, serverEp);
        Console.WriteLine("--> Message sent successfully!");

        // 5. إغلاق السوكت وتحرير الموارد
        client.Close();

        // منع إغلاق نافذة الكونسول تلقائياً
        Console.WriteLine("\nPress any key to exit...");
        Console.ReadKey();
    }
}

```

---

## مقارنة برمجية سريعة: TCP مقابل UDP

| الوظيفة البرمجية | في بروتوكول TCP | في بروتوكول UDP |
| --- | --- | --- |
| **تعريف السوكت** | `SocketType.Stream, ProtocolType.Tcp` | `SocketType.Dgram, ProtocolType.Udp` |
| **استماع السيرفر** | يتطلب `Listen()` ثم `Accept()` | لا يتطلب جلسة استماع؛ يستخدم `Bind()` فقط |
| **طريقة الإرسال** | `client.Send(data)` (بعد `Connect`) | `client.SendTo(data, remoteEndPoint)` |
| **طريقة الاستقبال** | `client.Receive(buffer)` | `server.ReceiveFrom(buffer, ref remoteEndPoint)` |

---

## خطوات التشغيل والتجربة في المعمل

1. **تشغيل الخادم (Server):** يتم تشغيل ملف السيرفر أولاً؛ ستظهر رسالة الانتظار وتظل النافذة ثابتة.
2. **تشغيل العميل (Client):** يتم تشغيل العميل في نافذة طرفية منفصلة وإدخال الرسالة، ثم الضغط على Enter.

