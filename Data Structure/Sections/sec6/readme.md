## 🎯 **Session 6 – Queue Data Structure**

### 🔹 1. مقدمة

الـ **Queue (الطابور)** هي **هيكل بيانات (Data Structure)** بيتبع مبدأ

> **FIFO – First In, First Out**
> يعني أول عنصر يدخل هو أول عنصر يخرج.

🧠 مثال واقعي:
طابور البنك أو الأتوبيس → أول واحد يدخل الطابور هو أول واحد يخلص ويمشي.

---

### 🔹 2. التمثيل (Representation)

الـ Queue ممكن تتعمل بـ:

* **Array (مصفوفة)**
* **Linked List**
* **Pointers & Structures**

في السيشن دي، هنستخدم **المصفوفة (Array)** لأنها أبسط في الفهم.

الـ Queue فيها مؤشرين مهمين:

* `front` → أول عنصر (نخرج منه)
* `rear` → آخر عنصر (ندخل فيه)

---

### 🔹 3. العمليات الأساسية (Basic Operations)

| العملية       | الوصف                     |
| ------------- | ------------------------- |
| **enqueue()** | إضافة عنصر في آخر الطابور |
| **dequeue()** | حذف أول عنصر من الطابور   |
| **peek()**    | عرض أول عنصر بدون حذفه    |
| **isFull()**  | التحقق إن الطابور ممتلئ   |
| **isEmpty()** | التحقق إن الطابور فاضي    |

---

### 🔹 4. الدوال واحدة واحدة

#### ✅ (1) `isFull()`

تتحقق إذا كان الطابور مليان.

```cpp
bool isFull() {
    if (rear == MAXSIZE - 1)
        return true;
    else
        return false;
}
```

---

#### ✅ (2) `isEmpty()`

تتحقق إذا كان الطابور فاضي.

```cpp
bool isEmpty() {
    if (front == -1 || front > rear)
        return true;
    else
        return false;
}
```

---

#### ✅ (3) `enqueue()` – إدخال عنصر

📋 الخطوات:

1. نتحقق إذا كان الطابور مليان.
2. لو فاضي أول مرة، نخلي `front = 0`.
3. نزود `rear` +1.
4. نحط العنصر الجديد في `queue[rear]`.

```cpp
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
    cout << "Inserted " << value << " into queue." << endl;
}
```

---

#### ✅ (4) `dequeue()` – حذف عنصر

📋 الخطوات:

1. نتحقق لو الطابور فاضي.
2. نعرض العنصر اللي عند `front`.
3. نزود `front` +1.
4. لو `front` عدّى `rear`، نرجع نعيدهم لـ -1.

```cpp
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!" << endl;
        return;
    }
    cout << "Deleted: " << queue[front] << endl;
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}
```

---

#### ✅ (5) `display()` – عرض العناصر

```cpp
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}
```

---

### 🔹 5. البرنامج الكامل

هتلاقيه في ملف سي بلص بلص في نفس الفولدر

---

### 🧩 6. ملاحظات مهمة

* لما `front` و `rear` يكونوا `-1` → معناها إن الـ Queue **فاضية**.
* لما `rear == MAXSIZE - 1` → معناها إن الـ Queue **مليانة**.
* كل عملية `dequeue` بتحرك الـ `front` خطوة لقدام.

---

## Tasks

### 🔹 **Task 1 – Trace the Operations**

**Given:**

```cpp
enqueue(10)
enqueue(20)
enqueue(30)
dequeue()
enqueue(40)
```

**Questions:**

1. Write down the content of the queue after each step.
2. Record the values of `front` and `rear` after every operation.
3. Which element was removed when `dequeue()` was called?

---

### 🔹 **Task 2 – Debug the Code**

Find and fix the logical errors in the following code snippet:

```cpp
void enqueue(int value) {
    if (rear == MAXSIZE)
        cout << "Queue Overflow";
    rear++;
    queue[rear] = value;
    if (front == 0)
        front = 1;
}
```

**Hint:**

* What should happen when the queue is empty for the first time?
* What condition really means “queue is full”?
* What is the correct initial value for `front`?

---

### 🔹 **Task 3 – Hand Simulation**

Simulate the following queue operations **manually** (as if you’re tracing the code step-by-step):

```
enqueue(5)
enqueue(10)
dequeue()
enqueue(15)
enqueue(20)
dequeue()
display()
```

**Write down:**

* The contents of the queue after each step.
* The values of `front` and `rear` after each operation.
* What will `display()` print in the end?

---

### 🔹 **Task 4 – Mini Project (Code Practice)**

Write a simple **C++ program** that:

* Implements the functions:

  * `enqueue()`
  * `dequeue()`
  * `display()`
* Uses an array of size **5**.
* Prints `"Queue Overflow!"` if the user tries to insert more than 5 elements.
* Prints `"Queue Underflow!"` if the user tries to delete from an empty queue.
* Prints clear messages like `"Deleted 10 from queue"` or `"Inserted 20 into queue"`.

---

### 🔹 **Task 5 – Conceptual Questions**

Answer briefly:

1. What is the main difference between a **Stack** and a **Queue**?
2. Why do we need both `front` and `rear` pointers in a queue?
3. What are **overflow** and **underflow** conditions?
4. When do both `front` and `rear` reset back to `-1`?
5. What’s the difference between `peek()` and `dequeue()`?

---
