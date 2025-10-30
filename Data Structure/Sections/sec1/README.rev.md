# C++ Revision Section

## 1. Introduction

في C++ أي برنامج بيبدأ من الدالة الأساسية `main()`. الكود بيتكتب جواها، وهي اللي بتتنفذ أول حاجة.

---

## 2. Input / Output

* علشان نستخدم الدوال الجاهزة زي `cout` و `cin` لازم نكتب `#include <iostream>`.
* عادةً لازم نكتب `std::cout` و `std::cin`، بس لو كتبنا `using namespace std;` فوق (بعد المكتبات) هنقدر نستخدم `cout` و `cin` على طول من غير `std::`.

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

`variables` هي أماكن نخزن فيها بيانات. C++ strongly typed، يعني لازم نحدد نوع الـ variable (int, long, float, double, char, bool...).

### Initialization Methods

1. **Copy Initialization**

```cpp
int x = 5;
```

2. **Direct Initialization**

```cpp
int y(10);
```

3. **Uniform Initialization (Brace Initialization)**

```cpp
int z{15};
```

4. **Type Deduction with auto**

```cpp
auto pi = 3.14; // pi هيبقى double
```

### Constants

* `const` values ما ينفعش تتغير.
* `constexpr` values بتتحدد وقت الـ compile.

```cpp
const int DAYS = 7;
constexpr double gravity = 9.81;
```

---

## 4. Flow Control

### if / else

```cpp
int x = 10;
if (x > 5) {
    cout << "x is greater than 5" << endl;
} else {
    cout << "x is less or equal to 5" << endl;
}
```

### switch

```cpp
int day = 2;
switch(day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    default: cout << "Other day";
}
```

### Loops

#### for loop

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

#### while loop

```cpp
int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;
}
```

#### do-while loop

```cpp
int i = 0;
do {
    cout << i << endl;
    i++;
} while (i < 5);
```

---

## 5. Functions

`functions` بتخلينا نقسم الكود لأجزاء قابلة لإعادة الاستخدام. ممكن نستخدم **reference** كـ parameter علشان نعدل على القيمة الأصلية.

```cpp
int add(int a, int b) {
    return a + b;
}

void increment(int &x) {
    x++;
}

int main() {
    cout << add(3, 4) << endl; // 7
    int num = 5;
    increment(num);
    cout << num << endl; // 6
}
```

---

## 6. Arrays

`array` بتخزن أكتر من قيمة من نفس النوع.

### Declaration and Initialization

```cpp
int arr1[3] = {1, 2, 3};
int arr2[] = {4, 5, 6};
int arr3[5] = {0}; // باقي العناصر هتبقى 0
```

### Access Elements

```cpp
cout << arr1[0]; // 1
```

### Loop through array

```cpp
for (int i = 0; i < 3; i++) {
    cout << arr1[i] << " ";
}
```

---

## 7. Pointers

`pointers` بتخزن عنوان متغير.

```cpp
int x = 10;
int* ptr = &x;
cout << *ptr; // 10
```

---

## 8. Object Oriented Programming (OOP)

الـ OOP في C++ مبنية على 4 مبادئ أساسية:

1. **Encapsulation**: نجمع البيانات والدوال اللي بتشتغل عليها في class.
2. **Inheritance**: class يرث من class تاني.
3. **Polymorphism**: نفس الـ function ممكن يبقى ليها سلوك مختلف.
4. **Abstraction**: نخفي التفاصيل ونظهر الوظائف الأساسية.

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
    d.eat();  // inherited from Animal
    d.bark(); // specific to Dog
}
```

---

## Tasks for Students

### Task 1: Input / Output & Variables

* اعمل برنامج يطلب من المستخدم **string name** و **int age**.
* اطبع رسالة ترحيب فيها الاسم والسن.

### Task 2: Flow Control & Functions

* اكتب function تستقبل **int number**.
* تتحقق إذا الرقم **even or odd**.
* اطبع النتيجة.

### Task 3: OOP

* اعمل class اسمه `Student` فيه:

  * variable `string name`
  * variable `int grade`
* عرف كائنين (objects) من الـ class.
* اطبع بياناتهم باستخدام function جوه الـ class.

