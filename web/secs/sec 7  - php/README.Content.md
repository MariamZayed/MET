## سكشن PHP: ما بعد الانترو

### أنواع الـ Arrays في PHP:

1. **Indexed Arrays (مصفوفات مفهرسة):**
   - تحتوي على عناصر بترتيب رقمي.
   ```php
   $colors = array("red", "green", "blue");
   echo $colors[0]; // red
   ```

2. **Associative Arrays (مصفوفات ترابطية):**
   - كل عنصر فيها مرتبط بمفتاح نصي.
   ```php
   $person = array("name" => "Ali", "age" => 25);
   echo $person["name"]; // Ali
   ```

3. **Multidimensional Arrays (مصفوفات متعددة الأبعاد):**
   - تحتوي على أكثر من array داخلية.
   ```php
   $people = array(
       array("name" => "Ali", "age" => 25),
       array("name" => "Sara", "age" => 22)
   );
   echo $people[1]["name"]; // Sara
   ```

### الفرق بين [] و array():

من أول إصدار PHP 5.4، بقى ممكن تكتبي الأراي باستخدام الأقواس المربعة `[]` بدل `array()`.

```php
// الطريقة القديمة:
$x = array(1, 2, 3);

// الطريقة الجديدة:
$x = [1, 2, 3];
```

الاتنين بيعملوا نفس الحاجة، بس `[]` شكلها أبسط وأشيك. استخدمي الطريقة اللي تناسب نسخة الـ PHP عندك.

### التعامل مع Arrays:

- **الطباعة:**
  - `print_r()` لعرض البيانات داخل array.
  - `var_dump()` تعرض النوع والقيمة وتفيد جدًا في الـ debugging.
  ```php
  print_r($colors);
  var_dump($person);
  ```

### Loops (الحلقات):

1. **for loop:**
   ```php
   for ($i = 0; $i < count($colors); $i++) {
       echo $colors[$i] . "<br>";
   }
   ```

2. **while loop:**
   ```php
   $i = 0;
   while ($i < count($colors)) {
       echo $colors[$i] . "<br>";
       $i++;
   }
   ```

3. **foreach loop:**
   - الأفضل مع الـ arrays.
   ```php
   foreach ($person as $key => $value) {
       echo "$key : $value <br>";
   }
   ```

### If Statement وغيره:

- **if / else / elseif:**
  ```php
  if ($age < 18) {
      echo "أنت قاصر";
  } elseif ($age >= 18 && $age <= 60) {
      echo "أنت بالغ";
  } else {
      echo "أنت كبير في السن";
  }
  ```

- **switch:**
  ```php
  $day = "Saturday";
  switch ($day) {
      case "Saturday":
          echo "أول الأسبوع";
          break;
      case "Sunday":
          echo "ثاني يوم";
          break;
      default:
          echo "يوم عادي";
  }
  ```

### Functions (الدوال):

- **تعريف دالة:**
  ```php
  function greet($name) {
      return "أهلا، $name!";
  }
  echo greet("مريم");
  ```

- **دالة بدون بارامترات:**
  ```php
  function sayHi() {
      echo "Hi!";
  }
  ```

- **دالة ببارامترات وقيمة راجعة:**
  ```php
  function sum($a, $b) {
      return $a + $b;
  }
  echo sum(5, 3); // 8
  ```

---

### Task (تاسك السكشن):

1. اعمل array ترابطية فيها بيانات طالب: الاسم - العمر - الكلية.
2. اطبع البيانات باستخدام `foreach`.
3. اعمل شرط `if` لو الطالب عمره أقل من 20 اطبع "طالب صغير"، لو بين 20 و30 اطبع "شاب جامعي".
4. اكتب دالة اسمها `printStudentInfo` تاخد array لطالب وتطبع بياناته بتنسيق منسق.
5. نادِ على الدالة ومرر لها بيانات الطالب.

---

ممكن الطلاب يعملوا الكود في ملف واحد اسمه `student.php`.