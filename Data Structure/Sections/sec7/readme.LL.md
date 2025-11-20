## 🎯 **Session 7 – Linked List Data Structure**

### 🔹 1. مقدمة

الـ **Linked List** هي **هيكل بيانات ديناميكي (Dynamic Data Structure)** يعني الحجم بتاعه **بيتغيّر أثناء التشغيل** على عكس الـ Array.

بتتكون من مجموعة عقد (Nodes) وكل Node فيها:

* **data** → قيمة
* **next** → Pointer بيشاور على العقدة اللي بعدها

> ❗ الميزة الأساسية:
> الـ Linked List مش محتاجة مساحة متواصلة في الذاكرة.

---

### 🔹 2. مكونات الـ Node

```cpp
struct Node {
    int data;      // القيمة
    Node* next;    // عنوان العقدة اللي بعدها
    int key;       // اختياري
};
```
>## 🌟 **1) كلمة `next` متعرّفة في اللغة؟**
>
>لأ طبعًا، **مش كلمة محجوزة** في C++ ولا ليها معنى خاص.
>
>هي **مجرد اسم variable**…
>يعني كإنك كتبت:
>
>```cpp
>int age;
>int number;
>Node* pointer;
>```
>
>
>نفس الفكرة، **next** اسم اختياري، الناس بتستخدمه لأن:
>
>* بيعبر عن وظيفته (العقدة اللي “بعدها”)
>* مفهوم في الـ Linked List
>
>لكن تقدر تسميه أي حاجة:
> ```cpp
> Node* nxt;
> Node* link;
> Node* baba_ghanoog;
> ```
>
> كل ده عادي ويشتغل.
>
> ---
>
> ## 🌟 **2) ليه مسمّيينها `key` مش `id`؟**
>
> الاتنين صح… بس فيه فرق بسيط في الاستخدام العام:
>
> ### 🧷 **key**
>
> * منتشر أكتر في **هياكل البيانات** (Data Structures)
> * زي: linked list, maps, trees, hash tables
> * معناها “مفتاح” بنوصل بيه للـ data
> * مش لازم يبقى رقم—ممكن يبقى string أو أي حاجة
>
> ### 🧷 **id**
>
> * معناها “هوية”
> * غالبًا بيبقى رقم مميز لكل عنصر
> * مرتبط أكتر بالـ **objects** أو الـ **database records**
>
> ### المختصر:
>
> * **key** مصطلح “علمي/أكاديمي” في هياكل البيانات.
> * **id** مصطلح “عملي” في التطبيقات.
>
> تقدر جدا تعمل ال struct كده:
>
> ```cpp
> struct Node {
>     int id;
>     int data;
>     Node* next;
> };
> ```
<br>
<br>
<br>

### 🔹 3. رسمة الـ Linked List 

```
[Data | Next] → [Data | Next] → [Data | Next] → NULL
```

* **head** → أول Node في الـ list
* **NULL** → نهاية الـ list

---

### 🔹 4. أنواع Linked Lists

| النوع                    | الوصف                        |
| ------------------------ | ---------------------------- |
| **Singly Linked List**   | اتجاه واحد → next بس         |
| **Doubly Linked List**   | اتجاهين → next & prev        |
| **Circular Linked List** | آخر Node بيشاور على أول Node |

في السيشن ديه هنشرح **Singly Linked List**.

---

### 🔹 5. العمليات الأساسية (Basic Operations)

| العملية           | معناها                     |
| ----------------- | -------------------------- |
| **insertFirst()** | إضافة Node في أول الـ list |
| **deleteFirst()** | حذف أول Node               |
| **find(key)**     | البحث عن عنصر معين         |
| **delete(key)**   | حذف Node حسب الـ key       |
| **display()**     | عرض كل العناصر             |
| **reverse()**     | قلب ترتيب الـ list         |

---

## 🔥 6. الشرح العملي للعمليات

### ✅ (1) **insertFirst() – إضافة في أول الليست**

📌 الخطوات:

1. نعمل Node جديدة
2. نخلي `newNode->next = head`
3. نخلي `head = newNode`

```cpp
void insertFirst(int key, int data) {
    Node* link = new Node();
    link->key = key;
    link->data = data;
    link->next = head;   // ربطها بالأولى
    head = link;         // تبقى أول عنصر
}
```

---

### ✅ (2) **deleteFirst() – حذف أول عنصر**

```cpp
Node* deleteFirst() {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    return temp;
}
```

---

### ✅ (3) **find(key) – البحث عن عنصر**

```cpp
Node* find(int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}
```

---

### ✅ (4) **delete(key) – حذف عنصر حسب الـ key**

```cpp
Node* delet(int key) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return NULL; // مش موجود

    if (current == head) {
        head = head->next;
    } else {
        previous->next = current->next;
    }

    return current;
}
```

---

### ✅ (5) **display() – عرض عناصر الليست**

```cpp
void printList() {
    Node* ptr = head;
    cout << "List: ";
    while (ptr != NULL) {
        cout << "(" << ptr->key << ", " << ptr->data << ") → ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
```

---

### ✅ (6) **reverse() – قلب الليست بالكامل**

📌 الطريقة الشهيرة → 3 pointers

```cpp
void reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
```

---

## 🧩 8. Tasks

## **Task 1 – Trace the Operations**

Given the following operations:

```
insertFirst(1,10)
insertFirst(2,20)
insertFirst(3,30)
deleteFirst()
insertFirst(4,40)
```

**Write:**

1. The shape of the linked list after *each* operation
2. What the **head pointer** is pointing to after each step

---

## **Task 2 – Debugging**

Fix the following buggy `find()` function:

```cpp
Node* find(int key){
    Node* current = NULL;
    while(current->key != key){
        current = current->next;
    }
    return current;
}
```

---

## **Task 3 – Manual Simulation**

Perform the following operations manually:

```
insertFirst(10)
insertFirst(20)
insertFirst(30)
deleteFirst()
insertFirst(40)
reverse()
display()
```

**Write:**

1. The linked list after each operation
2. The value that was deleted
3. The final output of `display()`

---

## **Task 4 – Conceptual Questions**

Answer the following:

1. Why is a Linked List considered a dynamic data structure?
2. What is the difference between an Array and a Linked List?
3. What happens if we forget to update the **head** after deleting the first node?
4. Why is searching in a Linked List **O(n)**?
5. What is the difference between `deleteFirst()` and `delete(key)`?

---
## 🎯 **Session 7 – Linked List Data Structure**

### 🔹 1. مقدمة

الـ **Linked List** هي **هيكل بيانات ديناميكي (Dynamic Data Structure)** يعني الحجم بتاعه **بيتغيّر أثناء التشغيل** على عكس الـ Array.

بتتكون من مجموعة عقد (Nodes) وكل Node فيها:

* **data** → قيمة
* **next** → Pointer بيشاور على العقدة اللي بعدها

> ❗ الميزة الأساسية:
> الـ Linked List مش محتاجة مساحة متواصلة في الذاكرة.

---

### 🔹 2. مكونات الـ Node

```cpp
struct Node {
    int data;      // القيمة
    Node* next;    // عنوان العقدة اللي بعدها
    int key;       // اختياري
};
```
>## 🌟 **1) كلمة `next` متعرّفة في اللغة؟**
>
>لأ طبعًا، **مش كلمة محجوزة** في C++ ولا ليها معنى خاص.
>
>هي **مجرد اسم variable**…
>يعني كإنك كتبت:
>
>```cpp
>int age;
>int number;
>Node* pointer;
>```
>
>
>نفس الفكرة، **next** اسم اختياري، الناس بتستخدمه لأن:
>
>* بيعبر عن وظيفته (العقدة اللي “بعدها”)
>* مفهوم في الـ Linked List
>
>لكن تقدر تسميه أي حاجة:
> ```cpp
> Node* nxt;
> Node* link;
> Node* baba_ghanoog;
> ```
>
> كل ده عادي ويشتغل.
>
> ---
>
> ## 🌟 **2) ليه مسمّيينها `key` مش `id`؟**
>
> الاتنين صح… بس فيه فرق بسيط في الاستخدام العام:
>
> ### 🧷 **key**
>
> * منتشر أكتر في **هياكل البيانات** (Data Structures)
> * زي: linked list, maps, trees, hash tables
> * معناها “مفتاح” بنوصل بيه للـ data
> * مش لازم يبقى رقم—ممكن يبقى string أو أي حاجة
>
> ### 🧷 **id**
>
> * معناها “هوية”
> * غالبًا بيبقى رقم مميز لكل عنصر
> * مرتبط أكتر بالـ **objects** أو الـ **database records**
>
> ### المختصر:
>
> * **key** مصطلح “علمي/أكاديمي” في هياكل البيانات.
> * **id** مصطلح “عملي” في التطبيقات.
>
> تقدر جدا تعمل ال struct كده:
>
> ```cpp
> struct Node {
>     int id;
>     int data;
>     Node* next;
> };
> ```
<br>
<br>
<br>

### 🔹 3. رسمة الـ Linked List 

```
[Data | Next] → [Data | Next] → [Data | Next] → NULL
```

* **head** → أول Node في الـ list
* **NULL** → نهاية الـ list

---

### 🔹 4. أنواع Linked Lists

| النوع                    | الوصف                        |
| ------------------------ | ---------------------------- |
| **Singly Linked List**   | اتجاه واحد → next بس         |
| **Doubly Linked List**   | اتجاهين → next & prev        |
| **Circular Linked List** | آخر Node بيشاور على أول Node |

في السيشن ديه هنشرح **Singly Linked List**.

---

### 🔹 5. العمليات الأساسية (Basic Operations)

| العملية           | معناها                     |
| ----------------- | -------------------------- |
| **insertFirst()** | إضافة Node في أول الـ list |
| **deleteFirst()** | حذف أول Node               |
| **find(key)**     | البحث عن عنصر معين         |
| **delete(key)**   | حذف Node حسب الـ key       |
| **display()**     | عرض كل العناصر             |
| **reverse()**     | قلب ترتيب الـ list         |

---

## 🔥 6. الشرح العملي للعمليات

### ✅ (1) **insertFirst() – إضافة في أول الليست**

📌 الخطوات:

1. نعمل Node جديدة
2. نخلي `newNode->next = head`
3. نخلي `head = newNode`

```cpp
void insertFirst(int key, int data) {
    Node* link = new Node();
    link->key = key;
    link->data = data;
    link->next = head;   // ربطها بالأولى
    head = link;         // تبقى أول عنصر
}
```

---

### ✅ (2) **deleteFirst() – حذف أول عنصر**

```cpp
Node* deleteFirst() {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    return temp;
}
```

---

### ✅ (3) **find(key) – البحث عن عنصر**

```cpp
Node* find(int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}
```

---

### ✅ (4) **delete(key) – حذف عنصر حسب الـ key**

```cpp
Node* delet(int key) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return NULL; // مش موجود

    if (current == head) {
        head = head->next;
    } else {
        previous->next = current->next;
    }

    return current;
}
```

---

### ✅ (5) **display() – عرض عناصر الليست**

```cpp
void printList() {
    Node* ptr = head;
    cout << "List: ";
    while (ptr != NULL) {
        cout << "(" << ptr->key << ", " << ptr->data << ") → ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
```

---

### ✅ (6) **reverse() – قلب الليست بالكامل**

📌 الطريقة الشهيرة → 3 pointers

```cpp
void reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
```

---

## 🧩 8. Tasks

## **Task 1 – Trace the Operations**

Given the following operations:

```
insertFirst(1,10)
insertFirst(2,20)
insertFirst(3,30)
deleteFirst()
insertFirst(4,40)
```

**Write:**

1. The shape of the linked list after *each* operation
2. What the **head pointer** is pointing to after each step

---

## **Task 2 – Debugging**

Fix the following buggy `find()` function:

```cpp
Node* find(int key){
    Node* current = NULL;
    while(current->key != key){
        current = current->next;
    }
    return current;
}
```

---

## **Task 3 – Manual Simulation**

Perform the following operations manually:

```
insertFirst(10)
insertFirst(20)
insertFirst(30)
deleteFirst()
insertFirst(40)
reverse()
display()
```

**Write:**

1. The linked list after each operation
2. The value that was deleted
3. The final output of `display()`

---

## **Task 4 – Conceptual Questions**

Answer the following:

1. Why is a Linked List considered a dynamic data structure?
2. What is the difference between an Array and a Linked List?
3. What happens if we forget to update the **head** after deleting the first node?
4. Why is searching in a Linked List **O(n)**?
5. What is the difference between `deleteFirst()` and `delete(key)`?

---
