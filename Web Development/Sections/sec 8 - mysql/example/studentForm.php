<?php
require 'connection.php'; // الاتصال بقاعدة البيانات
require 'file-handler.php'; // استدعاء ملف الفايل هاندلر


if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = $_POST['name'] ?? '';
    $email = $_POST['email'] ?? '';
    $age = $_POST['age'] ?? '';
    $uploadedFileName = '';

    // لو في فايل جاي
    if (isset($_FILES['uploadedFile'])) {
        $uploadedFileName = handleUploadedFile($_FILES['uploadedFile']);
    }

    // حفظ البيانات في الداتا بيز
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
