# 🧩 Session 5 — Stack in C++

## 🧠 Applications of Stack

### Expression Evaluation

Stack بتُستخدم بشكل واسع في **تقييم الـ arithmetic expressions**، خصوصًا عند التحويل من **infix** إلى **postfix** أو **prefix** notation.

#### Notations Overview

| Type    | Example | Description                         |
| ------- | ------- | ----------------------------------- |
| Infix   | a + b   | الـ operator بيكون بين الـ operands |
| Prefix  | + a b   | الـ operator بيكون قبل الـ operands |
| Postfix | a b +   | الـ operator بيكون بعد الـ operands |

ميزة الـ Prefix والـ Postfix إنهم بيشيلوا الحاجة لوجود أقواس أو قواعد أسبقية في التنفيذ، فبيكون التقييم مباشر وواضح.

#### Postfix Evaluation Algorithm

```
1. نعمل stack فاضي.
2. نبدأ نقرأ التعبير من الشمال لليمين.
3. لو العنصر اللي بنقراه operand → نعمله push في الـ stack.
4. لو العنصر operator → نعمل pop لآخر قيمتين من الـ stack.
   نطبّق الـ operator عليهم.
   بعدين نعمل push للنتيجة تاني في الـ stack.
5. نكرر لحد نهاية التعبير.
6. آخر قيمة في الـ stack هي النتيجة النهائية.
```

⏱️ الـ Time Complexity = O(n)

#### Example

Expression: `2 3 4 + * 5 -`

```
(3 + 4) = 7
(2 * 7) = 14
(14 - 5) = 9
Result = 9
```

---

### Backtracking

الـ Stack بتُستخدم في الـ algorithms اللي فيها خطوات متعددة لازم نرجع فيها خطوة أو أكتر لما نوصل لطريق غلط أو حل جزئي.

📍 أمثلة:

* حل الـ maze.
* تنفيذ خوارزمية DFS في الـ graphs.
* خاصية Undo / Redo في البرامج.

الـ Stack هنا بيخزّن كل خطوة (decision point)، ولما نوصل لنقطة فشل، بنعمل pop ونرجع نجرب طريق تاني.

---

### Memory Management

في لغات البرمجة زي C++ و Java، الـ runtime system بيستخدم **call stack** لإدارة الـ function calls.

كل function بتتندَه بيكون ليها **Activation Record** فيه:

* الـ parameters
* الـ local variables
* الـ return address

ولما الـ function تخلص، الـ record بتاعها بيتشال (pop) من الـ stack وبيرجع التنفيذ للدالة اللي نادتها.

---

## Stack — Definition

الـ Stack هو **Abstract Data Type (ADT)** بيسمح بتنفيذ العمليات على **طرف واحد فقط** (الـ top)، وبيشتغل بنظام **LIFO (Last In, First Out)**.

🧱 أمثلة واقعية:

* مجموعة أطباق فوق بعض.
* كومة كتب.

في أي وقت، العنصر الوحيد اللي نقدر نوصل له هو الـ top element.

---

## Basic Stack Operations

| Operation   | Description                                               |
| ----------- | --------------------------------------------------------- |
| `push()`    | إدخال عنصر جديد في الـ stack                              |
| `pop()`     | إزالة العنصر الموجود في الـ top                           |
| `peek()`    | عرض العنصر في الـ top من غير حذفه                         |
| `isEmpty()` | التحقق إذا كان الـ stack فاضي                             |
| `isFull()`  | التحقق إذا كان الـ stack مليان (في الـ fixed-size stacks) |

---

## Implementation (Using Array)

### Algorithm — push()

```
begin procedure push(data)
  if stack is full:
     print "Overflow"
  else:
     top = top + 1
     stack[top] = data
end procedure
```

### Algorithm — pop()

```
begin procedure pop()
  if stack is empty:
     print "Underflow"
  else:
     value = stack[top]
     top = top - 1
     return value
end procedure
```

### Algorithm — peek()

```
begin procedure peek()
  return stack[top]
end procedure
```

### Algorithm — isEmpty() / isFull()

```
bool isEmpty():
  return (top == -1)

bool isFull():
  return (top == MAXSIZE - 1)
```

---

## C++ Implementation

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
    if (isFull()) {
        cout << "Error: Stack Overflow" << endl;
    } else {
        top++;
        stack[top] = data;
        cout << data << " pushed into stack." << endl;
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Error: Stack Underflow" << endl;
        return -1;
    } else {
        int value = stack[top--];
        cout << value << " popped from stack." << endl;
        return value;
    }
}

int peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        cout << "Stack is empty." << endl;
        return -1;
    }
}

void traverse() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Current Stack Elements: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();
    pop();
    traverse();
    return 0;
}
```

---

## Summary

* Stack بيشتغل بنظام LIFO.
* العمليات الأساسية: push, pop, peek.
* ممكن يتنفذ باستخدام Array أو Linked List.
* أهم التطبيقات: Expression Evaluation, Backtracking, Memory Management.
---
<br>

## 🧠 **Tasks — Stack Applications & Implementation**

### **Task 1 — Postfix Evaluation**
Write a C++ program to **evaluate a postfix expression** using a stack.  
- Define a function `evaluatePostfix(string expression)` that returns the result.  
- Use an **array-based stack** (like in the session).  
- Test it with this expression:  
  ```
  2 3 4 + * 5 -
  ```
  The output should be:  
  ```
  Result = 9
  ```

---

### **Task 2 — Backtracking Concept**
Simulate a **simple backtracking process** using a stack.  
Example: Suppose you’re exploring rooms labeled A → B → C → D,  
and you need to go back to the previous room when you find a dead end.  
- Use `push()` when you move forward.  
- Use `pop()` when you backtrack.  
- Print each action (e.g., `"Moved to B"`, `"Backtracked to A"`).

---

### **Task 3 — Stack Overflow & Underflow**
Modify the array-based Stack program from the session to test:  
- **Overflow** (try pushing 6 elements when `MAX = 5`)  
- **Underflow** (try popping from an empty stack)  
Then print clear messages for both conditions.

---

### **Task 4 — Clean Implementation Practice**
Re-implement the stack using **functions only (no global variables)**.  
- Create `push()`, `pop()`, `peek()`, `isEmpty()`, and `isFull()` that take `stack[]` and `top` as parameters.  
- Make sure every student uses the same variable names:
  ```cpp
  int stack[MAX];
  int top;
  ```
  and initialize `top = -1;
