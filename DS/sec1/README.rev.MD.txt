# C++ Revision Section

## 1. Introduction

في السي بلص بلص عندنا برامج بتبدأ من الدالة الأساسية `main()`. الكود بيتكتب جواها، وهي اللي بتتنفذ أول حاجة.

---

## 2. Input / Output

* علشان نستخدم الدوال الجاهزة زي `cout` و `cin` بنحتاج نكتب `#include <iostream>`.
* عادةً لازم نكتب `std::cout` و `std::cin`، بس لو كتبنا `using namespace std;` فوق (بعد المكتبات) هنقدر نستخدم `cout` و `cin` على طول من غير `std::`. ده بيوفر كتابة طويلة كل مرة.

#### Example without `using namespace std;`

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

#### Example with `using namespace std;`

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Enter a number: ";  
    int x;  
    cin >> x;  
    cout << "You entered: " << x << endl;  
    return 0;  
}
```

---

## 3. Variables and Data Types

المتغيرات هي مكان نخزن فيه البيانات. السي بلص بلص strongly typed، يعني لازم نحدد نوع المتغير (int, float, double, char...).

#### Example:

```cpp
int age = 25;
float pi = 3.14;
char grade = 'A';
```

---

## 4. Control Structures

بتخلينا نتحكم في تدفق البرنامج:

* if/else
* loops (for, while, do-while)

#### Example:

```cpp
int x = 10;
if (x > 5) {
    cout << "x is greater than 5" << endl;
}
```

---

## 5. Functions

وظائف/دوال بتخلينا نقسم الكود لأجزاء صغيرة قابلة لإعادة الاستخدام.

### مكان تعريف الفانكشنز

* ينفع نعرف الفانكشن **قبل الماين**.
* أو نعرفها **بعد الماين**، وفي الحالة دي لازم نكتب **Prototype** فوق عشان الكومبايلر يعرف إنها موجودة.

#### Example: تعريف قبل `main()`

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    cout << add(3, 4);
}
```

#### Example: تعريف بعد `main()` مع Prototype

```cpp
#include <iostream>
using namespace std;

int add(int a, int b); // Prototype

int main() {
    cout << add(3, 4);
}

int add(int a, int b) {
    return a + b;
}
```

#### Example: void Function

```cpp
#include <iostream>
using namespace std;

void greet(string name) {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greet("Mariam");
}
```

---

## 6. Arrays

بتخزن أكتر من قيمة من نفس النوع.

```cpp
int arr[3] = {1, 2, 3};
cout << arr[0]; // يطبع 1
```

---

## 7. Pointers

مؤشرات بتخزن عنوان متغير.

```cpp
int x = 10;
int* ptr = &x;
cout << *ptr; // يطبع 10
```

---

## 8. Object Oriented Programming (OOP)

الـ OOP في C++ مبنية على 4 مبادئ أساسية:

1. **Encapsulation**: نجمع البيانات والدوال اللي بتشتغل عليها في كلاس واحد.
2. **Inheritance**: كلاس يرث خصائص ودوال من كلاس تاني.
3. **Polymorphism**: نفس الدالة يكون ليها سلوك مختلف حسب السياق.
4. **Abstraction**: إخفاء التفاصيل وإظهار الوظائف الأساسية.

#### Example:

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!" << endl; }
};

int main() {
    Dog d;
    d.eat();  // موروثة من Animal
    d.bark(); // خاصة بـ Dog
}
```

---

## Tasks for Students

### Task 1: Input / Output & Variables

* اعمل برنامج يطلب من المستخدم **اسمه (string name)** و **سنه (int age)**.
* اطبع رسالة ترحيب فيها الاسم والسن.

### Task 2: Control Structures & Functions

* اكتب دالة تستقبل **int number**.
* تتحقق إذا الرقم **زوجي أو فردي**.
* اطبع النتيجة للمستخدم.

### Task 3: OOP

* اعمل كلاس اسمه `Student` فيه:

  * متغير `string name`
  * متغير `int grade`
* عرف كائنين (objects) من الكلاس.
* اطبع بياناتهم باستخدام دالة داخل الكلاس.
