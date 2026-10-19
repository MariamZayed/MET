### ما هو الـ Socket برمجياً؟

الـ **Socket** هو كائن برمجي (Software Object) يعمل كنقطة نهاية (End Point) لإنشاء قناة اتصال ثنائية الاتجاه (Bidirectional Link) بين برنامجين لنقل وتبادل البيانات عبر الشبكة، سواء كانا على جهازين مختلفين أو على نفس الجهاز.

حتى يصل أي برنامج لبرنامج آخر في الشبكة بدقة، يعتمد السوكت على عنصرين أساسيين:


$$\text{Socket} = \text{IP Address} + \text{Port Number}$$

* **IP Address:** يحدد الجهاز المستهدف في الشبكة.


* **Port Number:** يحدد البرنامج أو الخدمة المحددة داخل ذلك الجهاز التي تستقبل البيانات.



---

### كود البرنامج كاملاً (Server & Client)

#### 1. كود الخادم (Server)

```csharp
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Server
{
    static void Main()
    {
        // 1. إنشاء السوكت وتحديد العنوان والمنفذ
        Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        listener.Bind(new IPEndPoint(IPAddress.Any, 5020));
        listener.Listen(1);
        Console.WriteLine("Server: Waiting for client...");

        // 2. انتظار وقبول اتصال العميل
        Socket client = listener.Accept();

        // 3. استقبال البيانات وقراءتها
        byte[] buffer = new byte[1024];
        int count = client.Receive(buffer);
        string msg = Encoding.ASCII.GetString(buffer, 0, count);
        Console.WriteLine("Received: " + msg);

        // 4. إغلاق الاتصال
        client.Close();
        listener.Close();
    }
}

```

---

#### 2. كود العميل (Client)

```csharp
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Client
{
    static void Main()
    {
        // 1. إنشاء السوكت والاتصال بالسيرفر
        Socket client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        client.Connect(new IPEndPoint(IPAddress.Loopback, 5020));

        // 2. إدخال الأمر وتحويله إلى بايتس
        Console.Write("Enter command: ");
        string msg = Console.ReadLine();
        byte[] data = Encoding.ASCII.GetBytes(msg);

        // 3. إرسال البيانات إلى السيرفر
        client.Send(data);

        // 4. إغلاق الاتصال
        client.Close();
    }
}

```

---

### الشرح التفصيلي للأسطر البرمجية

#### أولاً: جهة الخادم (Server)

1. **`using System.Net;` و `using System.Net.Sockets;` و `using System.Text;**`
* استدعاء المكتبات المسؤولة عن عناوين الشبكة (`IPAddress`, `IPEndPoint`)، وفئات إدارة السوكت والبروتوكولات (`Socket`, `SocketType`, `ProtocolType`)، ومكتبة تحويل النصوص إلى بايتات والعكس (`Encoding.ASCII`).




2. **`Socket listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);`**
* **`AddressFamily.InterNetwork`:** يحدد استخدام نظام عناوين IPv4.


* **`SocketType.Stream`:** يحدد نمط نقل البيانات كتدفق مستمر ومنتظم، وهو النمط الخاص باتصالات TCP الموثوقة.


* **`ProtocolType.Tcp`:** يحدد بروتوكول التحكم في الإرسال (TCP) كبروتوكول لطبقة النقل.




3. **`listener.Bind(new IPEndPoint(IPAddress.Any, 5020));`**
* **`Bind`:** ربط كائن السوكت بعنوان شبكة ومنفذ محدد داخل نظام التشغيل.


* **`IPAddress.Any`:** السماح للسيرفر بقبول الاتصالات الواردة من أي واجهة شبكة متاحة بالجهاز.


* **`5020`:** رقم المنفذ (Port) المخصص للخدمة، وهو يقع ضمن نطاق المنافذ المسجلة (Registered Ports من 1024 إلى 49151).




4. **`listener.Listen(1);`**
* تحويل السوكت إلى وضع الاستماع للطلبات الواردة.


* الرقم `1` (Backlog) يحدد الحد الأقصى لعدد طلبات الاتصال التي يمكن أن تنتظر في طابور النظام حتى يتم استدعاء دالة القبول.




5. **`Socket client = listener.Accept();`**
* دالة توقف وتنتظر (Blocking Primitive) حتى يحاول عميل الاتصال.


* عند حدوث الاتصال، تُنشئ الدالة سوكت جديداً بالكامل (`client`) مخصصاً للمحادثة ونقل البيانات مع هذا العميل بعينه، بينما يستمر السوكت الأصلي `listener` في مهامه.




6. **`byte[] buffer = new byte[1024];`**
* حجز مصفوفة بايتات في الذاكرة بسعة 1024 بايت، لتعمل كوعاء تخزين مؤقت للبيانات الواردة عبر الشبكة.




7. **`int count = client.Receive(buffer);`**
* دالة تستقبل البيانات من العميل وتخزنها في مصفوفة `buffer`.


* تُرجع الدالة عدداً صحيحاً يمثل العدد الفعلي للبايتات المستلمة لتجنب قراءة المساحات غير المستخدمة في الذاكرة.




8. **`string msg = Encoding.ASCII.GetString(buffer, 0, count);`**
* تحويل البايتات المستلمة فعلياً من الإندكس `0` وحتى الطول `count` إلى نص يمكن قراءته وطباعته.




9. **`client.Close();` و `listener.Close();**`
* إنهاء الاتصال وتحرير الموارد والمنافذ المحجوزة في نظام التشغيل.





---

#### ثانياً: جهة العميل (Client)

1. **`Socket client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);`**
* إنشاء سوكت العميل بنفس إعدادات البروتوكول (IPv4 و TCP Stream) ليتوافق مع السيرفر.




2. **`client.Connect(new IPEndPoint(IPAddress.Loopback, 5020));`**
* دالة المبادرة بالاتصال (Active Connection) مع السيرفر عبر عنوانه ومنفذه.


* **`IPAddress.Loopback`:** يمثل العنوان الداخلي للجهاز المحلي `127.0.0.1`.


* **`5020`:** المنفذ المطابق تماماً للمنفذ الذي يستمع عليه السيرفر.




3. **`string msg = Console.ReadLine();`**
* قراءة الأمر أو الرسالة المطلوب إرسالها من مدخلات المستخدم.




4. **`byte[] data = Encoding.ASCII.GetBytes(msg);`**
* تحويل السلسلة النصية إلى مصفوفة بايتات؛ حيث تعتمد طبقة النقل في الشبكة على تداول البايتات الخام فقط.




5. **`client.Send(data);`**
* إرسال مصفوفة البايتات عبر قناة الاتصال لتصل إلى مصفوفة الاستقبال في السيرفر.




6. **`client.Close();`**
* إغلاق السوكت الخاص بالعميل بعد إتمام إرسال الأمر.