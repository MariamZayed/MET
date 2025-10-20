# 🧩 Session 1 — Introduction to Linux

🎯 **Goal:**
تعريف الطلاب بأساسيات نظام Linux بطريقة بسيطة وعملية تساعدهم يكتسبوا ثقة في استخدام الـ command line.

---

## 🧠 1. Topics Covered

### 🔹 What is an Operating System and why Linux?

نظام التشغيل (Operating System) هو اللي بيوصل بين المستخدم والهاردوير، وبيتحكم في إدارة الموارد زي الذاكرة والمعالج والملفات.
الفرق بين Linux وWindows إن Linux مفتوح المصدر (Open Source)، مجاني، وأكثر أمانًا واستقرارًا، وبيُستخدم بشكل واسع في السيرفرات.

---

### 🔹 Linux Distributions

فيه نسخ مختلفة من Linux اسمها “Distributions” أو “Distros”، وكل واحدة ليها أدوات وواجهة مختلفة شوية، زي:

* **Ubuntu** (سهلة الاستخدام ومناسبة للمبتدئين)
* **Debian** (مستقرة جدًا وتعتبر الأساس لكتير من التوزيعات التانية)
* **Fedora** (حديثة وتضم أحدث التقنيات)

---

### 🔹 Difference between File and Folder

* **File**: عبارة عن وحدة تخزين فيها بيانات أو محتوى (نص، صورة، كود...).
* **Folder (Directory)**: بيحتوي على ملفات أو مجلدات تانية.

---

### 🔹 Filesystem Hierarchy Overview

هيكل الملفات في Linux منظم بشكل هرمي يبدأ من الجذر `/`، وكل حاجة جواه مجلد فرعي.

| المسار  | الوصف                        |
| ------- | ---------------------------- |
| `/`     | الجذر الأساسي للنظام.        |
| `/home` | يحتوي على مجلدات المستخدمين. |
| `/etc`  | ملفات إعداد النظام.          |
| `/bin`  | الأوامر الأساسية للمستخدم.   |
| `/var`  | ملفات متغيرة زي الـ logs.    |

---

### 🔹 Creating Files and Folders using commands

بعض الأوامر الأساسية:

* `pwd` : يعرض المسار الحالي.
* `ls` : يعرض محتويات المجلد.
* `cd` : لتغيير المجلد الحالي.
* `mkdir` : لإنشاء مجلد جديد.
* `rmdir` : لحذف مجلد فاضي.
* `touch` : لإنشاء ملف جديد فارغ.
* `echo` : لطباعة نص أو كتابته داخل ملف.
* `cat` : لعرض محتوى ملف.

---

### 🔹 Viewing File Content

* `cat` : يعرض الملف بالكامل.
* `head` : يعرض أول 10 (أو عدد محدد من) الأسطر.
* `tail` : يعرض آخر 10 (أو عدد محدد من) الأسطر.
* `less` : لتصفح ملف كبير والتنقل داخله.

---

### 🔹 File Permissions

كل ملف أو مجلد في Linux ليه صلاحيات وصول (Permissions): قراءة (read)، كتابة (write)، تنفيذ (execute).
الأمر `ls -l` بيعرض الصلاحيات.
والأمر `chmod` بيستخدم لتغييرها.

---

### 🔹 Command Syntax

كل أمر بيتكتب بالشكل ده:

```
command [options] [arguments]
```

* **Options**: تغيّر سلوك الأمر.
* **Arguments**: الملفات أو المعلومات اللي بيتعامل معاها الأمر.
  ممكن تكتبي أكتر من أمر في سطر واحد باستخدام `;` للفصل بينهم.

---

## 📘 3. Getting Help

| Command          | Description                                                 |
| ---------------- | ----------------------------------------------------------- |
| `man -k keyword` | يعرض كل الأوامر اللي صفحات المساعدة بتاعتها فيها الكلمة دي. |
| `man -s keyword` | يعرض المساعدة الخاصة بـ section معينة.                      |
| `whatis command` | وصف سطر واحد عن الأمر.                                      |
| `command --help` | طريقة تانية لعرض المساعدة من داخل الأمر نفسه (لو مدعوم).    |

---

## 📂 4. Listing Directory Contents

| Command       | Description                                                             | Example Output                                         |
| ------------- | ----------------------------------------------------------------------- | ------------------------------------------------------ |
| `ls -a dir1`  | يعرض كل الملفات بما فيها المخفية (. و ..).                              | `. .. .f1 f1 .f2 f2`                                   |
| `ls -l dir1`  | عرض تفصيلي بالمعلومات (المالك، التاريخ، الحجم...).                      | <pre>-rw-r--r-- 1 islam islam 20 May 21 16:11 f1</pre> |
| `ls -F`       | يضيف رموز توضح نوع العنصر (`/` للمجلد، `*` للملف التنفيذي، `@` للرابط). | `dir1/ file1 file2* file3@`                            |
| `ls -ld dir1` | يعرض تفاصيل المجلد نفسه بدل محتواه.                                     | `drwxr-xr-x 2 islam islam 512 May 21 16:06 dir1`       |
| `ls -R`       | يعرض كل الملفات في المجلدات الفرعية أيضًا.                              | <pre>.: dir1 dir2 file1 ./dir1: f1 f2</pre>            |

---

## 📖 5. Viewing File Contents

| Command      | Description              |
| ------------ | ------------------------ |
| `cat fname`  | يعرض محتوى الملف مباشرة. |
| `more fname` | يعرض الملف صفحة صفحة.    |

⌨️ **Scrolling Keys (for more):**

| Key        | Function           |
| ---------- | ------------------ |
| `Spacebar` | التقدم صفحة للأمام |
| `Enter`    | التمرير سطر واحد   |
| `b`        | الرجوع صفحة للخلف  |
| `/string`  | البحث عن كلمة      |
| `n`        | تكرار البحث        |
| `q`        | الخروج             |

🔹 **Other Useful Commands:**

* `head -n fname` → أول n سطر من الملف.
* `tail [-n +n] fname` → آخر أو بداية الملف بعد عدد معين من الأسطر.

---

## 💻 6. In-class Command Practice

```bash
# عرض المسار الحالي
pwd

# إنشاء مجلد جديد والدخول إليه
mkdir linux_lab && cd linux_lab

# إنشاء ملفات نصية بطرق مختلفة
touch file1.txt
echo "Hello Linux" > file2.txt
cat > file3.txt    # اكتب نص ثم Ctrl + D

# عرض الملفات مع الصلاحيات
ls -l

# تغيير صلاحيات ملف إلى قراءة فقط
chmod 444 file2.txt
ls -l file2.txt

# عرض أول أو آخر 20 سطر من الملف
head -20 file3.txt
tail -20 file3.txt
```

---
### **Tasks

1. Inside the `linux_lab` directory, create a new folder named after your first name.
2. Move into that folder using `cd`.
3. Inside it, create **three text files** using different methods (`touch`, `echo`, and `cat`).
4. Verify that the files were created using `ls -l`.

1. Open one of your text files and add **at least 25 lines** of content (you can copy and paste repeated lines).
2. Use the command `head -10 filename.txt` to show the first 10 lines.
3. Then use `tail -10 filename.txt` to show the last 10 lines.
4. Finally, use `less filename.txt` to navigate up and down inside the file.

1. Pick one of your created files.
2. Change its permissions using `chmod 755 filename.txt`.
3. Run `ls -l` to check the new permissions.
4. Explain to your partner (or write in notes) what the numbers mean (rwxr-xr-x).

## 🧠 Extra Practice

1. استخدم `man` وابحث عن أمر زي `ls` أو `cat`.
2. قارن بين مخرجات `ls`, `ls -l`, و`ls -a`.
3. استخدم `ls -F` وفهم معنى الرموز `/`, `*`, و`@`.
4. جرّب البحث داخل ملف باستخدام `more` و`/string`.
5. اكتب 3 أوامر مختلفة في سطر واحد باستخدام `;`.
6. اعرض أول 5 أسطر من ملف باستخدام `head -5 filename`.
7. اعرض آخر 3 أسطر باستخدام `tail -3 filename`.
8. لاحظ الفرق بين `ls -ld` و `ls -l` في المخرجات.
