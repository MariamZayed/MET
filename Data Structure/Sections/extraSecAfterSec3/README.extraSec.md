# 🧩 C++ Data Structure Session

## 🔹 Introduction

في السيشن دي، هنشرح 3 خوارزميات أساسية في الـ **Data Structure**:
- هنكمل شرح تاني توع من السيرش
- ونبدا في اول نوعين من السورت الجورزيم
- متنساش اننا في داتا ستراكشر اسمها array وبنذاكر الجوزيم السيرش والسورت بتاعهاا

1. **Binary Search**
2. **Bubble Sort**
3. **Selection Sort**

وهنضيف كمان تاسكات للتدريب العملي بعد كل جزء.

---

## 🔸 1. Binary Search

### 📘 الفكرة

الباينري سيرش بتشتغل على **array تكون مرتبة (sorted)**، وبتقسمها نصين كل مرة علشان تدور على القيمة المطلوبة بسرعة.

بدل ما نلف على كل عنصر زي الـ Linear Search، بنشوف العنصر اللي في النص:

* لو هو أصغر من القيمة اللي بندور عليها → نكمّل في النصف التاني.
* لو أكبر منها → نكمّل في النصف الأول.
* لو بيساويها → لقيناها.

### 🧮 خطوات التنفيذ

1. نبدأ بـ `first = 0` و `last = n - 1`.
2. نحسب `middle = (first + last) / 2`.
3. نقارن `array[middle]` مع القيمة اللي بندور عليها.
4. نكرّر لحد ما نلاقي العنصر أو تنتهي العناصر.

### 🧩 Code Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int array[100], n, search, first, last, middle;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];

    cout << "Enter value to find: ";
    cin >> search;

    first = 0;
    last = n - 1;

   return 0;
}
```
```
    while (first <= last) {
        middle = (first + last) / 2;

        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search) {
            cout << search << " found at location " << middle + 1 << endl;
            return 0;
        } else
            last = middle - 1;
    }

    cout << "Not found! " << search << " isn't present in the list.\n";
 
```

---

## 🔸 2. Bubble Sort

### 📘 الفكرة

الـ **Bubble Sort** بيمر على الـ array كذا مرة، وكل مرة بيقارن عنصرين جنب بعض ويبدّلهم لو الترتيب غلط.

كأننا بنخلي العناصر الكبيرة "تطفو" على السطح في نهاية الـ array.

### 🧮 خطوات التنفيذ

1. نقارن كل عنصر باللي بعده.
2. نبدّلهم لو كانوا مش بترتيب تصاعدي.
3. نكرّر الخطوات دي `n-1` مرة.

### 🧩 Code Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int array[100], n, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < num; i++)
        cin >> array[i];

// after sortion do the following code block
    cout << "Sorted array: ";
    for (i = 0; i < num; i++)
        cout << array[i] << " ";

    return 0;
}
```
```
    // Bubble Sort
    int i = 0;
    while (i < num - 1) {
        int j = 0;
        while (j < num - i - 1) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
```

---

## 🔸 3. Selection Sort

### 📘 الفكرة

الـ **Selection Sort** بيدور على **أصغر عنصر** في الجزء الغير مرتب من الـ array، ويحطه في مكانه الصحيح.

### 🧮 خطوات التنفيذ

1. نبدأ من أول عنصر.
2. ندور على أصغر عنصر في باقي الـ array.
3. نبدّل مكانه بالعنصر الحالي.
4. نكرّر العملية لباقي العناصر.

### 🧩 Code Example

```cpp
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int array[100], size;

    cout << "Enter number of elements: ";
    cin >> size;

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];

// after sortion do the following code block
    cout << "Sorted array: ";
    for (i = 0; i < size; i++)
        cout << array[i] << " ";

    return 0;
}
```
```
    int i = 0;
    while (i < size - 1) {
        int minIndex = i;
        int j = i + 1;
        while (j < size) {
            if (array[j] < array[minIndex])
                minIndex = j;
            j++;
        }
        swap(&array[i], &array[minIndex]);
        i++;
    }

```
---

## 🎯 الملخص

| Algorithm      | Type   | Best Case | Worst Case | Requires Sorted Input? |
| -------------- | ------ | --------- | ---------- | ---------------------- |
| Binary Search  | Search | O(1)      | O(log n)   | ✅ Yes                  |
| Bubble Sort    | Sort   | O(n)      | O(n²)      | ❌ No                   |
| Selection Sort | Sort   | O(n²)     | O(n²)      | ❌ No                   |

---

> 💡 **Tip:** دايمًا قبل تطبيق أي خوارزمية، فكّر هي مناسبة لنوع البيانات وعدد العناصر ولا لأ.


---

## 🧠 Task

* ✳️ Rewrite the **Binary Search** algorithm using a `for loop` instead of `while`.
* ✳️ Make sure to handle the case when the element is **not found** clearly.
* ✳️ Rewrite the **Bubble Sort** using a `for loop` instead of `while`.
* ✳️ Try to optimize it by **stopping early** if no swaps happen during a pass.
* ✳️ Rewrite the **Selection Sort** using a `for loop`.
* ✳️ Add a counter to show **how many swaps** happened during the sort.
---
