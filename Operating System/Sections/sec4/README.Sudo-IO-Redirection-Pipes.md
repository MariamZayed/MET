
# 🧩 Session 4 — Using `sudo` Command, I/O Redirection, and Pipes

---

## 🔹 Using `sudo` Command

* الـ `sudo` بيُستخدم لتشغيل أوامر بصلاحيات الـ **root** بدون ما نكون logged in كـ root user.
* بيعتبر أكثر أمانًا من تسجيل الدخول كـ root مباشرة، لأنه بيطلب كلمة المرور الخاصة بالمستخدم وبيسجل كل العمليات اللي تمت.
* التحكم في صلاحيات الـ `sudo` بيتم من خلال الملف `/etc/sudoers`.

---

### ✳️ Editing `/etc/sudoers`

* ما ينفعش نعدّل على `/etc/sudoers` مباشرة، لكن لازم نستخدم أمر اسمه `visudo`.
* `visudo` هو **editor** بيضمن إن الملف ما يتخزنش إلا لو مفيهوش أخطاء في الصيغة (syntax errors).

---

### ✳️ Example of `sudoers` Configuration

```bash
User_Alias LIMITEDTRUST = st1, st2
Cmnd_Alias MINUMUM = /etc/init.d/httpd
Cmnd_Alias SHELLS = /bin/sh, /bin/bash
LIMITEDTRUST ALL = MINUMUM
user5 ALL = ALL, !SHELLS
%development station1 = ALL, !SHELL
```

📌 **الشرح:**

* `User_Alias` بيستخدم لتعريف مجموعة مستخدمين.
* `Cmnd_Alias` لتعريف مجموعة أوامر.
* السطر `LIMITEDTRUST ALL = MINUMUM` معناه إن المستخدمين st1 و st2 يقدروا يشغلوا بس الأمر `/etc/init.d/httpd`.
* السطر `user5 ALL = ALL, !SHELLS` معناه إن user5 يقدر يشغل أي أمر إلا الـ shells (زي bash أو sh).
* `%development station1 = ALL, !SHELL` معناها إن كل أعضاء مجموعة development يقدروا يشغلوا أوامر من station1، باستثناء الـ shell.

---

### ✳️ Editing Files Using `nano`

* أمر `nano` بيعرض محتوى الملف وبيسمح بتعديله من الترمینال.
* الصيغة العامة:

  ```bash
  nano file_name
  ```
* للتحفظ: `Ctrl + O`
* للخروج: `Ctrl + X`

---

## 🔹 Inode Table

* كل ملف أو directory في Linux له **رقم inode** فريد بيميزه عن غيره.
* الـ **inode** هو معرف خاص في الـ filesystem بيحتوي معلومات عن الملف زي الحجم، الصلاحيات، وتاريخ التعديل.
* لعرض أرقام الـ inode نستخدم:

  ```bash
  ls -i
  ```
* الخيار `-i` بيعرض جدول الـ inode الخاص بالنظام الحالي.

---

## 🔹 Standard Input / Output / Error

* **Standard Input (stdin):** هو مصدر البيانات اللي بيتم إدخالها للأوامر (زي لوحة المفاتيح أو ملف).
* **Standard Output (stdout):** هو المكان اللي بيظهر فيه ناتج الأمر (عادةً على الشاشة).
* **Standard Error (stderr):** هو المكان اللي بتظهر فيه رسائل الخطأ الناتجة عن الأمر.

---

## 🔹 Redirecting Input and Output

### ✅ Redirecting Input

* بنستخدم `<` لإرسال محتوى ملف كمدخل لأمر:

  ```bash
  command < file_name
  ```
* مثال:

  ```bash
  tr 'a' 'b' < file1
  ```

  الأمر `tr` هنا بيستبدل كل حرف `a` بـ `b` داخل محتوى الملف `file1`.

---

### ✅ Redirecting Output

* بنستخدم `>` لتخزين ناتج الأمر في ملف (بيستبدل المحتوى السابق):

  ```bash
  command > file_name
  ```
* بنستخدم `>>` للإضافة إلى الملف بدل الاستبدال:

  ```bash
  command >> file_name
  ```
* مثال:

  ```bash
  ls -l /etc >> findresult
  ```

---

### ✅ Redirecting Standard Error

* بنستخدم `2>` لتوجيه الأخطاء إلى ملف معين:

  ```bash
  command 2> file_name
  ```
* مثال:

  ```bash
  find / -name passwd 2> errs
  ```

---

## 🔹 Pipes (`|`)

* الـ **pipe** بيربط أمرين بحيث يكون ناتج الأول هو مدخل التاني.
* الصيغة العامة:

  ```bash
  command1 | command2
  ```
* مثال:

  ```bash
  head -n 4 /etc/passwd | tail -n 3
  ```

  هنا بيعرض أول 4 أسطر من `/etc/passwd`، وبعدين آخر 3 أسطر من الناتج ده.

---

## 🔹 Useful Commands

### 🟩 `grep`

* بيبحث عن pattern داخل ملف ويعرض الأسطر اللي فيها تطابق:

  ```bash
  grep pattern filename
  ```

---

### 🟩 `sort`

* بيرتب البيانات نصيًا:

  ```bash
  sort filename
  ```

---

### 🟩 `wc`

* بيحسب عدد الأحرف أو الكلمات أو السطور:

  ```bash
  wc option filename
  ```
* **Options:**

  * `-c` : عدد الأحرف
  * `-l` : عدد الأسطر
  * `-w` : عدد الكلمات

---

### 🟩 `tr`

* بيستبدل أي سلسلة بحروف أو سلاسل أخرى:

  ```bash
  tr 'a' 'b' < file
  ```

---

### 🟩 `tee`

* بيقرأ من الـ standard input ويكتب الناتج في ملف **وفي نفس الوقت** يعرضه على الشاشة:

  ```bash
  command | tee file_name
  ```

---

## 🧠 Tasks 

1. **Create a new file** called `students.txt` and write inside it five student names using `nano`.
2. **Use `ls -i`** to display the inode numbers of all files in your current directory.
3. **Redirect the output** of the command `ls /etc` to a file called `etc_list.txt`.
4. **Append** the output of `date` command to the same file without overwriting it.
5. **Search** inside `etc_list.txt` for the word `ssh` using `grep`.
6. **Count** the number of lines in `etc_list.txt` using `wc`.
7. **Sort** the contents of `students.txt` alphabetically using `sort`.
8. **Replace** all occurrences of the letter `a` with `@` in `students.txt` using `tr`.
9. **Redirect errors** from this command to a file called `errors.txt`:

   ```bash
   cat /root/hiddenfile 2> errors.txt
   ```
10. **Use a pipe** to display only the first 3 lines of `/etc/passwd` and then the last 2 lines from that result.

    ```bash
    head -n 3 /etc/passwd | tail -n 2
    ```
11. **Use `tee`** to list files in `/home` and save the result in a file `homelist.txt` while also displaying it on screen.
