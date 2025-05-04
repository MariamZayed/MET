# 💡 سكشن شرح: استخدام phpMyAdmin والتعامل مع قواعد البيانات

---

## 🧭 Headlines

* Access phpMyAdmin
* Create a database and tables
* Check if data is inserted correctly
* Perform Add, Edit, Delete, and Display operations
* Connect frontend form with database

---

## 🎯 الهدف من السكشن:

* يفهم الطالب دور phpMyAdmin في التعامل مع قواعد البيانات.
* يعرف يدخل على phpMyAdmin ويبدأ ينشئ قاعدة بيانات وجداول.
* يقدر يعاين البيانات اللي تم إدخالها من الفورم.

---

## 🧩 أولاً: ما هو phpMyAdmin؟

* واجهة رسومية GUI لإدارة قواعد بيانات MySQL/MariaDB.
* بتيجي مع XAMPP/WAMP.
* بتسهل إنشاء قواعد البيانات والجداول، وتنفيذ الاستعلامات، ومراجعة البيانات.

---

## 🚪 ثانياً: الدخول إلى phpMyAdmin

1. شغّل XAMPP (Apache + MySQL).
2. افتح المتصفح وادخل على:

   ```
   http://localhost/phpmyadmin
   ```
3. هتظهر لك لوحة التحكم الخاصة بـ phpMyAdmin.

---

## 🏗️ ثالثاً: إنشاء قاعدة بيانات

1. من القائمة الجانبية، اضغط على **New**.
2. اكتب اسم القاعدة مثلاً: `test_db`.
3. اضغط على **Create**.

:ملحوظة: هتلاقي إن فيه قواعد بيانات افتراضية موجودة بالفعل, دول بيبقوا خاصين بالنظام نفسه، ومش لازم نعدل فيهم. زي

- information_schema
- performance_schema
- mysql
- phpmyadmin

---

## 📋 رابعاً: إنشاء جدول داخل القاعدة

1. بعد إنشاء القاعدة، phpMyAdmin هيطلب منك اسم الجدول وعدد الأعمدة.
2. اكتب:

   * Table Name: `students`
   * عدد الأعمدة: 5
3. اضغط **Go**.

---

## 🧱 خامساً: تحديد أعمدة الجدول

| الاسم | النوع   | الطول | خصائص إضافية                 |
| ----- | ------- | ----- | ---------------------------- |
| id    | INT     | 11    | AUTO\_INCREMENT, PRIMARY KEY |
| name  | VARCHAR | 100   |                              |
| email | VARCHAR | 100   |                              |
| age   | INT     | 3     |                              |
| photo | VARCHAR | 255   |                              |

ثم اضغط **Save**.

---

## 📥 سادساً: التأكد من أن البيانات بتدخل فعلاً

1. بعد ما الطالب يرسل الفورم من `form-handler.php`، يدخل على phpMyAdmin.
2. يفتح قاعدة البيانات `test_db`.
3. يختار الجدول `students`.
4. يروح على تبويب **Browse**.
5. هيشوف كل الصفوف اللي اتحفظت.

---

## 🛠️ سابعاً: تعديلات وتحسينات ممكنة

* ممكن تضيف عمود timestamp للتاريخ.
* ممكن تعمل validation في الفورم على client/server.
* ممكن تستخدم phpMyAdmin لكتابة استعلامات يدويًا من تبويب SQL.

---

## 📦 ثامناً: مثال كامل على العمليات CRUD (إضافة - تعديل - حذف)

### ✅ إضافة صف جديد:

```php
<?php
$name = 'Ahmed';
$email = 'ahmed@example.com';
$age = 22;
$photo = 'default.jpg';

$stmt = $conn->prepare("INSERT INTO students (name, email, age, photo) VALUES (?, ?, ?, ?)");
$stmt->bind_param("ssis", $name, $email, $age, $photo);
$stmt->execute();
echo "✅ تمت الإضافة بنجاح";
?>
```

### 📝 تعديل بيانات طالب:

```php
<?php
$newEmail = 'newemail@example.com';
$targetId = 1; // رقم الطالب المراد تعديله

$stmt = $conn->prepare("UPDATE students SET email = ? WHERE id = ?");
$stmt->bind_param("si", $newEmail, $targetId);
$stmt->execute();
echo "✏️ تم التعديل بنجاح";
?>
```

### ❌ حذف طالب:

```php
<?php
$targetId = 1;

$stmt = $conn->prepare("DELETE FROM students WHERE id = ?");
$stmt->bind_param("i", $targetId);
$stmt->execute();
echo "🗑️ تم الحذف بنجاح";
?>
```

### 📤 عرض كل الطلاب:

```php
<?php
$result = $conn->query("SELECT * FROM students");

while ($row = $result->fetch_assoc()) {
    echo "Name: " . $row['name'] . "<br>";
    echo "Email: " . $row['email'] . "<br>";
    echo "Age: " . $row['age'] . "<br>";
    echo "Photo: <img src='uploads/{$row['photo']}' width='100'><br><br>";
}
?>
```

---

## 🧠 ملاحظات ختامية

* phpMyAdmin أداة للتعليم والتجارب، لكن في المشاريع الحقيقية بنعتمد أكتر على الكود.
* لازم تتأكد إن `uploads/` عندك لها صلاحية كتابة.
* ترتيب السكريبتات:

  ```
  require 'db.php';
  require 'file-handler.php';
  ```

  علشان الكود يشتغل بترتيب منطقي.

---
