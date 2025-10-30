# التعامل مع الفورمات والملفات في PHP

---

## أولاً: الاتصال بقاعدة البيانات

من أساسيات العمل في PHP هو إنشاء اتصال مع قاعدة بيانات MySQL.

**مثال:**

```php
<?php
$host = 'localhost';
$user = 'root';
$password = '';
$database = 'test_db';

$conn = new mysqli($host, $user, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
```

---

## ثانياً: معالجة الفورمات (Form Handling)

لمعالجة نتائج فورم استعمل طريقة `POST` أو `GET`.

**مثال:**

```php
<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = $_POST['name'] ?? '';
    $email = $_POST['email'] ?? '';
    // ...
}
?>
```

---

## ثالثاً: Include & Require

- `include` و `require` يسمحوا بإدراج ملفات PHP أخرى.
- `require` يوقف البرنامج إذا فشلت عملية الضم.

**مثال:**

```php
<?php
require 'db.php';
include 'header.php';
?>
```

---

## رابعاً: استقبال ملف من الفورم

لقبول ملفات من المستخدم يجب استخدام `enctype="multipart/form-data"` في فورم HTML.

**HTML Form:**

```html
<form action="form-handler.php" method="post" enctype="multipart/form-data">
    Name: <input type="text" name="name"><br>
    Email: <input type="email" name="email"><br>
    Age: <input type="number" name="age"><br>
    Upload Photo: <input type="file" name="uploadedFile"><br>
    <button type="submit">Submit</button>
</form>
```

---

## خامساً: تعامل مع ملف مرفوع

لمعالجة ملف مرفوع نستخدم دالة منظمة:

**file-handler.php:**

```php
<?php
function handleUploadedFile($file) {
    if ($file['error'] !== UPLOAD_ERR_OK) {
        exit("Error during file upload.");
    }

    if ($file['size'] > 100 * 1024) {
        exit("File must be less than 100KB.");
    }

    $allowedTypes = ['image/jpeg', 'image/png', 'image/gif', 'image/webp'];
    if (!in_array($file['type'], $allowedTypes)) {
        exit("Only image files allowed.");
    }

    $uploadDir = 'uploads/';
    if (!is_dir($uploadDir)) {
        mkdir($uploadDir, 0755, true);
    }

    $safeFileName = uniqid() . '-' . basename($file['name']);
    $destination = $uploadDir . $safeFileName;

    if (move_uploaded_file($file['tmp_name'], $destination)) {
        return $safeFileName;
    } else {
        exit("Failed to move uploaded file.");
    }
}
?>
```

**form-handler.php:**

```php
<?php
require 'file-handler.php';
require 'db.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = $_POST['name'] ?? '';
    $email = $_POST['email'] ?? '';
    $age = $_POST['age'] ?? '';
    $uploadedFileName = '';

    if (isset($_FILES['uploadedFile'])) {
        $uploadedFileName = handleUploadedFile($_FILES['uploadedFile']);
    }

    $stmt = $conn->prepare("INSERT INTO students (name, email, age, photo) VALUES (?, ?, ?, ?)");
    $stmt->bind_param("ssis", $name, $email, $age, $uploadedFileName);

    if ($stmt->execute()) {
        echo "✅ Data saved successfully.";
    } else {
        echo "🚨 Error: " . $stmt->error;
    }

    $stmt->close();
    $conn->close();
}
?>
```

---

# ملاحظات
- التأكد من أن `uploads/` موجودة وأنها قابلة للكتابة.
- الاستخدام الصحيح لـ `require` و `include` ينظم الكود ويسهّل الصيانة.

