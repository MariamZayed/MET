# 🧩 Arrays in C++ (Part 2)

## 🔹 Deletion (الحذف)
---

### 💻 Example – Deleting an element at a specific index in a sorted array:


```cpp
#include <iostream>
using namespace std;

int main() {
    int LA[] = {1, 3, 5, 7, 8};
    int k = 3, n = 5; // k هو رقم العنصر اللي هنحذفه (بداية من 1)
    int i, j;

    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++)
        cout << "LA[" << i << "] = " << LA[i] << "\n";

    // حذف العنصر في المكان k-1
    j = k - 1;
    while (j < n - 1) {
        LA[j] = LA[j + 1];
        j++;
    }
    n = n - 1; // تقليل حجم المصفوفة بعد الحذف

    cout << "\nThe array elements after deletion:\n";
    for (i = 0; i < n; i++)
        cout << "LA[" << i << "] = " << LA[i] << "\n";

    return 0;
}
```

📘 **الشرح بسرعة:**

* `k = 3` يعني هنحذف العنصر الثالث (اللي هو 5).
* الحلقة `while` بتنقل كل العناصر اللي بعده خطوة لليسار.
* بعد كده بنقلل حجم المصفوفة `n` بواحد.

📘 **الناتج النهائي:**

```
LA[0] = 1
LA[1] = 3
LA[2] = 7
LA[3] = 8
```

---
### هنشرح بعدين ازاي نحذف في مصفوفه غير مرتبة
---

## 🔹 Searching (البحث)

**Learning Objective:** Learn how to find an element in an array using linear search.

---

### 💻 Example – Linear Search:

```cpp
#include <iostream>
using namespace std;

int main() {
    int LA[] = {1, 3, 5, 7, 8};
    int item = 5, n = 5;
    int i = 0, j = 0;

    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "] = " << LA[i] << "\n";
    }

    // البحث عن العنصر
    while (j < n) {
        if (LA[j] == item) {
            break;
        }
        j = j + 1;
    }

    if (j < n)
        cout << "\nFound element " << item << " at position " << j + 1 << ".\n";
    else
        cout << "\nElement " << item << " not found in the array.\n";

    return 0;
}
```
📘 **النتيجة المتوقعة:**

```
The original array elements are:
LA[0] = 1
LA[1] = 3
LA[2] = 5
LA[3] = 7
LA[4] = 8

Found element 5 at position 3.
```

---
### هنشرح بعدين ازاي نبحث في مصفوفه غير مرتبة
---


## 🔹 Update (التحديث)

**Learning Objective:** Be able to modify an element's value using its index directly.

---

### 💻 Example – Update an element:
```cpp
#include <iostream>
using namespace std;

int main() {
    int LA[] = {1, 3, 5, 7, 8};
    int k = 3, n = 5, item = 10;
    int i;

    cout << "The original array elements are:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "] = " << LA[i] << "\n";
    }

    // تحديث العنصر في الموضع k-1
    LA[k - 1] = item;

    cout << "\nThe array elements after update:\n";
    for (i = 0; i < n; i++) {
        cout << "LA[" << i << "] = " << LA[i] << "\n";
    }

    return 0;
}
```

📘 **النتيجة المتوقعة:**

```
The original array elements are:
LA[0] = 1
LA[1] = 3
LA[2] = 5
LA[3] = 7
LA[4] = 8

The array elements after update:
LA[0] = 1
LA[1] = 3
LA[2] = 10
LA[3] = 7
LA[4] = 8
```

---
### هنشرح بعدين ازاي هنعدل في مصفوفه غير مرتبة
---


## Tasks

### Task 1 – Deletion

Write a C++ program to delete the **first occurrence** of a specific value (not index) entered by the user.

**You will learn:** How to combine searching and deletion logic.


### Task 2 – Search

Write a program to search for multiple values (entered by the user) in an array and print whether each exists or not.

**You will learn:** How to repeat a search operation and manage user input.


### Task 3 – Update

Write a C++ program that asks the user to enter an index and a new value, then updates the array and prints it.

**You will learn:** How to access and modify elements using user input.


