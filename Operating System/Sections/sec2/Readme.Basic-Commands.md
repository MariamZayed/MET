
## Session 2 — Introduction to Linux Basic Commands


# 1. Topics Covered
- What is an Operating System and why Linux?
- Difference between File and Folder
- Filesystem Hierarchy Overview
- Listing Directory Contents
- Basic Commands
- - 1.Command Syntax
- - 2.Getting Help
- - 3.Listing Directory Contents
- - 4.Viewing and Creating Files using cat
- - 5.Viewing File Contents (more, head, tail, less)
- - 6.File and Directory Management
- - 7.In-class Command Practice

---
# What is an Operating System and why Linux?

- نظام التشغيل (Operating System) هو اللي بيوصل بين المستخدم والهاردوير، وبيتحكم في إدارة الموارد زي الذاكرة والمعالج والملفات.
- الفرق بين Linux وWindows إن Linux مفتوح المصدر (Open Source)، مجاني، وأكثر أمانًا واستقرارًا، وبيُستخدم بشكل واسع في السيرفرات.


---

## Linux Distributions
 فيه نسخ مختلفة من Linux اسمها “Distributions” أو “Distros”، وكل واحدة ليها أدوات وواجهة مختلفة شوية، زي:
- نظام Ubuntu (سهلة الاستخدام ومناسبة للمبتدئين)
- نظام Debian (مستقرة جدًا وتعتبر الأساس لكتير من التوزيعات التانية)
- نظام Fedora (حديثة وتضم أحدث التقنيات)



---

# Difference between File and Folder

- File: عبارة عن وحدة تخزين فيها بيانات أو محتوى (نص، صورة، كود...).
- Folder (Directory): بيحتوي على ملفات أو مجلدات تانية.

---

# Filesystem Hierarchy Overview

هيكل الملفات في Linux منظم بشكل هرمي يبدأ من الجذر /، وكل حاجة جواه مجلد فرعي.
- / root او الجذر الأساسي للنظام.
- /home	يحتوي على مجلدات المستخدمين.
- /etc	ملفات إعداد النظام.
- /bin	الأوامر الأساسية للمستخدم.
- /var	ملفات متغيرة زي الـ logs.
---
# Basic Commands

## 1- Command Syntax

كل أمر في Linux بيتكتب بالشكل ده:
```
command [options] [arguments]
```
- كل جزء بيتفصل بمسافة.
- الـ Options: تغيّر في سلوك الأمر.
- الـ Arguments: ملفات أو معلومات إضافية محتاجها الأمر.
- ممكن تكتب أكتر من أمر في سطر واحد باستخدام ; للفصل بينهم.
---

## 2. Getting Help

Command	Description

- man -k keyword	يعرض كل الأوامر اللي صفحات المساعدة بتاعتها فيها الكلمة دي.
- man -s keyword	يعرض المساعدة الخاصة بـ section معينة.
- whatis command	وصف سطر واحد عن الأمر.
- command --help	طريقة تانية لعرض المساعدة من داخل الأمر نفسه (لو مدعوم).

---

## 3. Listing Directory Contents

Command	Description	Example Output
- ls -a dir1	يعرض كل الملفات بما فيها المخفية (. و ..).	. .. .f1 f1 .f2 f2
- ls -l dir1	عرض تفصيلي بالمعلومات (المالك، التاريخ، الحجم...).	<pre>-rw-r--r-- 1 islam islam 20 May 21 16:11 f1</pre>
- ls -F	يضيف رموز توضح نوع العنصر (/ للمجلد، * للملف التنفيذي، @ للرابط).	dir1/ file1 file2* file3@
- ls -ld dir1	يعرض تفاصيل المجلد نفسه بدل محتواه.	drwxr-xr-x 2 islam islam 512 May 21 16:06 dir1
- ls -R	يعرض كل الملفات في المجلدات الفرعية أيضًا.	<pre>.: dir1 dir2 file1 ./dir1: f1 f2</pre>

---

## 4. Viewing and Creating Files using cat

أمر cat (اختصار لـ concatenate) بيُستخدم لعرض محتوى الملفات أو دمجها، وكمان ممكن ينشئ ملفات جديدة.

Command	Description:
- cat filename.txt	يعرض محتوى الملف بالكامل.
- cat > filename.txt	ينشئ ملف جديد (أو يستبدل ملف قديم) ويدخلك في input mode لكتابة محتوى جديد. بعد الانتهاء اضغطي Ctrl + D للحفظ والخروج.
- cat >> filename.txt	يضيف (append) نص جديد في نهاية الملف بدون حذف المحتوى القديم.
- cat file1.txt file2.txt	يدمج محتوى ملفين ويعرضهم مع بعض على الشاشة.
- cat file1.txt file2.txt > combined.txt	يدمج ملفين ويحفظ الناتج في ملف جديد.
- cat -n filename.txt	يعرض محتوى الملف مع ترقيم الأسطر.
---

## 5. Viewing File Contents (more, head, tail, less)

Command	Description
- more fname	لعرض الملف صفحة صفحة.
- head -n fname	يعرض أول n سطر من الملف.
- tail [-n +n] fname	يعرض آخر أو بداية الملف بعد عدد معين من الأسطر.
- less fname	يسمحلك تتنقل داخل الملفات الكبيرة بسهولة.


⌨️ Scrolling Keys (for more): Key	Function
- Spacebar	التقدم صفحة للأمام
- Enter	التمرير سطر واحد
- b	الرجوع صفحة للخلف
- /string	البحث عن كلمة
- n	تكرار البحث
- q	الخروج

---

## 6. File and Directory Management

Command	Description
- mkdir foldername	إنشاء مجلد جديد.
- mkdir -p parent/child	إنشاء مجلد متداخل في مسار غير موجود.
- rmdir foldername	حذف مجلد فاضي فقط.
- rm filename.txt	حذف ملف.
- rm -r foldername	حذف مجلد وكل الملفات اللي جواه.
- rm -rf foldername	حذف مجلد بكل محتواه بدون تأكيد.
- mv source target	نقل أو إعادة تسمية ملف أو مجلد.
- cp source target	نسخ ملف أو مجلد (باستخدام -r لنسخ مجلد كامل).
- touch filename.txt	إنشاء ملف جديد فارغ.
- echo "text" > filename.txt	إنشاء ملف وكتابة نص جواه.

---

## 7. In-class Command Practice

### عرض المسار الحالي
pwd

### إنشاء مجلد جديد والدخول إليه
mkdir linux_lab && cd linux_lab

### إنشاء ملفات نصية بطرق مختلفة
touch file1.txt
echo "Hello Linux" > file2.txt
cat > file3.txt    # اكتب نص ثم Ctrl + D

### عرض الملفات مع الصلاحيات
ls -l

### تغيير صلاحيات ملف إلى قراءة فقط
chmod 444 file2.txt
ls -l file2.txt

### عرض أول أو آخر 20 سطر من الملف
head -20 file3.txt
tail -20 file3.txt

### دمج ملفين في ملف جديد
cat file1.txt file2.txt > merged.txt


---

# Tasks

Task 1:
1. داخل مجلد linux_lab، أنشئ مجلد باسمك.
2. ادخل باستخدام cd.
3. جوه المجلد، أنشئ 3 ملفات نصية بطرق مختلفة (touch, echo, cat).
4. اعرض الملفات باستخدام ls -l.


Task 2:
1. افتح أحد الملفات واكتب فيه 25 سطر.
2. استخدم head -10 filename.txt و tail -10 filename.txt لعرض أول وآخر الأسطر.
3. استخدم less filename.txt للتنقل داخل الملف.

Task 3:
1. اختار ملف واحد.
2. غيّر صلاحياته إلى chmod 755 filename.txt.
3. اعمل ls -l وشوفي الفرق في الصلاحيات.
4. فسّر معنى الأرقام (rwxr-xr-x).

task4:
1. استخدم man للبحث عن أمر زي ls أو cat.
2. قارن بين ls, ls -l, و ls -a.
3. استخدم ls -F وافهمي معنى الرموز /, *, و@.
4. جرّب البحث داخل ملف باستخدام more و/string.
5. اكتب 3 أوامر مختلفة في سطر واحد باستخدام ;.
6. اعرض أول 5 أسطر من ملف باستخدام head -5 filename.
7. اعرض آخر 3 أسطر باستخدام tail -3 filename.
