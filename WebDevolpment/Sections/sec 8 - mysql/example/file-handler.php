<?php

function handleUploadedFile($file)
{
    // تحقق من وجود خطأ
    switch ($file['error']) {
        case UPLOAD_ERR_OK:
            break;
        case UPLOAD_ERR_NO_FILE:
            exit("⚠️ No file uploaded.");
        case UPLOAD_ERR_INI_SIZE:
        case UPLOAD_ERR_FORM_SIZE:
            exit("⚠️ File is too large.");
        case UPLOAD_ERR_PARTIAL:
            exit("⚠️ File was only partially uploaded.");
        case UPLOAD_ERR_NO_TMP_DIR:
            exit("🚨 Missing a temporary folder.");
        case UPLOAD_ERR_CANT_WRITE:
            exit("🚨 Failed to write file to disk.");
        case UPLOAD_ERR_EXTENSION:
            exit("🚨 Upload stopped by a PHP extension.");
        default:
            exit("⚡ Unknown error occurred during upload.");
    }

    // تحقق من الحجم
    if ($file['size'] > 100 * 1024) {
        exit("⚠️ File size must be less than 100KB.");
    }

    // تحقق من النوع
    $allowedTypes = ['image/jpeg', 'image/png', 'image/gif', 'image/webp'];
    if (!in_array($file['type'], $allowedTypes)) {
        exit("⚠️ Only image files (JPEG, PNG, GIF, WebP) are allowed.");
    }

    // مجلد الرفع
    $uploadDir = 'uploads/';
    if (!is_dir($uploadDir)) {
        mkdir($uploadDir, 0755, true);
    }

    // تأمين اسم الملف
    $safeFileName = uniqid() . '-' . basename($file['name']);
    $destination = $uploadDir . $safeFileName;

    if (move_uploaded_file($file['tmp_name'], $destination)) {
        return $safeFileName; // رجع اسم الفايل لو اتحرك بنجاح
    } else {
        exit("🚨 Failed to move uploaded file.");
    }
}
?>
