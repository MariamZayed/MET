# Session 3: Users, Groups, and Permissions in Linux

---

🧩 **أولًا: يعني إيه “user” في Linux؟**

في Linux، كل شخص بيتعامل مع النظام لازم يكون ليه حساب مستخدم خاص بيه (User Account).
ده بيدي أمان وتنظيم، لأن:

* كل مستخدم ليه ملفاته الخاصة.
* وله صلاحياته المحددة.
* وما يقدرش يغيّر حاجة في ملفات مستخدم تاني إلا بإذن.

---

🧰 **ثانيًا: إزاي نعمل يوزر جديد**

عشان تضيفي مستخدم جديد، لازم تكوني بصلاحيات الـ **root** (يعني الأدمن).

**الطريقة:**

```bash
sudo adduser username
```

مثلاً لو عايزة تعملي يوزر اسمه “mariam”:

```bash
sudo adduser mariam
```

هيطلب منك شوية بيانات:

* الباسورد للمستخدم الجديد
* اسمه الحقيقي (اختياري)
* باقي التفاصيل لو عايزة

بعد كده هيكون عندك يوزر جديد ليه فولدر خاص في:

```
/home/mariam
```

---

👤 **ثالثًا: طيب أقدر أشوف كل المستخدمين إزاي؟**

اكتبي:

```bash
cat /etc/passwd
```

هتلاقي فيه قائمة بكل المستخدمين على الجهاز، بالشكل ده مثلًا:

```
root:x:0:0:root:/root:/bin/bash
mariam:x:1001:1001::/home/mariam:/bin/bash
```

---

👥 **رابعًا: والجروبس بقى؟**

كل مستخدم بينتمي على الأقل لمجموعة واحدة (**group**).
الجروب دي بتجمع أكتر من مستخدم مع بعض، عشان يقدروا يشاركوا صلاحيات معينة.

مثلاً:

* جروب اسمها **students** ممكن تضم كل طلبة القسم.
* جروب اسمها **teachers** تضم المعيدين والدكاترة.

ولما تضيفي يوزر لجروب:

```bash
sudo usermod -aG groupname username
```

مثلاً:

```bash
sudo usermod -aG teachers mariam
```

---

## Permissions and Access Control

كل ملف أو فولدر في Linux ليه 3 أنواع من الصلاحيات (permissions):

* **read (r)** – قراءة الملف.
* **write (w)** – تعديل أو حذف الملف.
* **execute (x)** – تشغيل الملف (لو برنامج أو سكربت).

ودي بتتوزع على 3 مجموعات:

* **User (u)** → صاحب الملف.
* **Group (g)** → الجروب اللي بينتمي ليها.
* **Others (o)** → باقي المستخدمين.

لما نكتب:

```bash
ls -l
```

هيظهر بالشكل ده:

```
-rwxr-xr-- 1 mariam teachers 4096 Oct 7 09:30 script.sh
```

نفسرها كده:

* `rwx` → اليوزر يقدر يقرأ ويكتب وينفذ.
* `r-x` → الجروب تقرأ وتنفذ فقط.
* `r--` → الآخرين يقدروا يقرؤوا فقط.

---

## Useful Commands Recap

| الأمر                                 | الوصف                         |
| ------------------------------------- | ----------------------------- |
| `sudo adduser username`               | إنشاء مستخدم جديد             |
| `cat /etc/passwd`                     | عرض كل المستخدمين             |
| `sudo usermod -aG groupname username` | إضافة مستخدم لجروب            |
| `ls -l`                               | عرض تفاصيل الملفات والصلاحيات |

---

## 🧠 Tasks

1. **Create two users** called `student1` and `student2` using `adduser`.
2. **Create a group** called `classroom`, and add both users to it.
3. **List all users** and verify that both are created successfully.
4. **Check permissions** of files in `/home/student1` using `ls -l`.
5. **Experiment**: change one file’s permission to read-only and observe the difference.

---
