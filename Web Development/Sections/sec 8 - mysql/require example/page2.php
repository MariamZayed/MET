<?php
    // استدعاء الهيدر
    require 'includes/header.html';
?>


<form method="POST" action="studentForm.php" enctype="multipart/form-data">
    Name: <input type="text" name="name" required><br><br>
    Age: <input type="number" name="age" required><br><br>
    Department: <input type="text" name="department" required><br><br>
    Upload Photo: <input type="file" name="studentPhoto" required><br><br>
    <input type="submit" value="Submit">
</form>

<?php
    // استدعاء الفوتر
    require 'includes/footer.html';
?>
