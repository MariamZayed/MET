## سكشن PHP: ما بعد الانترو

### أنواع الـ Arrays في PHP:

1. **Indexed Arrays:**
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

3. **Multidimensional Arrays:**
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

