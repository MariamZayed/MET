# 🧩 Session 5 — Stack in C++ (Data Structure)

## 🎯 Goal

تعريف الطلاب بمفهوم **Stack** كمثال على الـ **Abstract Data Type (ADT)**، وشرح تطبيقاته الأساسية في البرمجة، وطريقة تطبيقه عمليًا بلغة **C++** باستخدام المصفوفة (Array).

---

## 🔹 Stack Applications (تطبيقات الـ Stack)

### 🧠 1. Expression Evaluation (تقييم التعابير الرياضية)

عند كتابة معادلة مثل:

```cpp
a + b * c
```

الكمبيوتر يحتاج يعرف ترتيب العمليات (الضرب قبل الجمع). يتم ذلك بتحويل المعادلة إلى **Postfix notation**:

```
a b c * +
```

ويتم استخدام **Stack** لتنفيذ التحويل وكذلك لتقييم الناتج، بحيث يتم تخزين القيم مؤقتًا، وكلما وُجد عامل (operator)، يتم تنفيذ العملية على آخر عنصرين في الـ Stack.

> **Time Complexity:** O(n)

---

### 🎯 2. Backtracking (التراجع الذكي)

يُستخدم في الخوارزميات التي تحتاج إلى تجرِبة مسارات مختلفة مثل:

* حل المتاهة (Maze Solving)
* البحث عن طريق في الرسم البياني (Graph Traversal)
* الألعاب (Chess, Sudoku...)

الـ Stack يحتفظ بالقرارات السابقة، وعندما تصل إلى طريق مسدود (Dead-end)، يقوم البرنامج بعمل **Pop** للقرار الأخير ويجرب خيارًا آخر.

---

### 💾 3. Memory Management (إدارة الذاكرة)

كل برنامج أثناء التشغيل بيستخدم ما يُعرف بـ **Call Stack**، حيث يتم حفظ كل استدعاء دالة (Function Call) في الستاك.

مثال:

```cpp
void B() {}
void A() { B(); }
int main() { A(); }
```

تتسلسل العمليات كالتالي:

1. `main()` يدخل إلى الستاك.
2. `A()` يُضاف فوقه.
3. `B()` فوق الكل.
4. عند انتهاء `B()`، يتم **Pop** منها ونعود إلى `A()`.

وهذا هو الأساس في عمل أنظمة التشغيل والـ **runtime systems**.

---

## 🔹 Stack Overview

الـ **Stack** هو هيكل بيانات يتبع مبدأ **LIFO (Last In, First Out)**.
أي أن آخر عنصر يتم إدخاله هو أول من يتم إخراجه.

### 🧩 العمليات الأساسية

* `push()` → إضافة عنصر جديد
* `pop()` → حذف آخر عنصر
* `peek()` → عرض العنصر الأخير بدون حذفه
* `isEmpty()` → التحقق من أن الستاك فارغ
* `isFull()` → التحقق من امتلاء الستاك

---

## 🔹 Stack Implementation using Array

```cpp
#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull())
        cout << "Stack Overflow!\n";
    else {
        top++;
        stack[top] = data;
        cout << data << " pushed to stack.\n";
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
        return -1;
    } else {
        int val = stack[top];
        top--;
        return val;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty())
        cout << "Stack is empty.\n";
    else {
        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << "\n";
    }
}

int main() {
    int choice, val;
    while (true) {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            push(val);
            break;
        case 2:
            cout << "Popped: " << pop() << endl;
            break;
        case 3:
            cout << "Top element: " << peek() << endl;
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
```

---

## 🔹 Tasks for Students

1. Rewrite the above program using a **while loop** instead of `for` where applicable.
2. Add a function `size()` that returns the number of elements currently in the stack.
3. Try to implement the same stack using a **Linked List** instead of an array (Bonus Task).
