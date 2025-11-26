#  Stack (Linked List), Doubly Linked List, Circular Linked List

## **Table of Contents**
- Stack using Linked List  
- Doubly Linked List (DLL)  
- Circular Linked List (CLL)  
- Tasks  

---

## **1. Stack Using Linked List**

### **1.1 What is a Stack?**
الـ **Stack** هو هيكل بيانات من نوع **LIFO – Last In First Out**.  
يعني آخر عنصر يدخل هو أول عنصر يطلع.

### **1.2 Why use Linked List to implement Stack?**
لأن الـ **Linked List** بتسمح بإضافة وحذف العناصر في الـ **Head** بسرعة بدون إعادة تخصيص للذاكرة.

### **1.3 Operations**
- **push()**: إضافة عنصر فوق الستاك  
- **pop()**: إزالة عنصر من فوق الستاك  
- **peek()**: عرض أعلى عنصر بدون حذفه  


**Push Operation:**
- بنعمل **new node**
- الـ **new node->next** بيشاور على **head**
- الـ **head** بيتحدث للـ **new node**

**Pop Operation:**
- لو الـ **head = NULL** يبقى الستاك فاضي  
- بنشاور على **head->next** كـ **new head**
---
## **1.3 Code – Stack using Linked List**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// push operation
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// pop operation
int pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }
    Node* temp = top;
    int popped = temp->data;
    top = top->next;
    delete temp;
    return popped;
}

// peek operation
int peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return -1;
    }
    return top->data;
}
```
---
## **2. Doubly Linked List (DLL)**

### **2.1 What is a DLL?**
هو **Linked List** فيه كل **node** تحتوي:
- **data**
- **next pointer**
- **prev pointer**

كل **node** مرتبطة باللي بعدها واللي قبلها:  
```

NULL <- prev | data | next -> node2 ...

```

### **2.3 Advantages**
- سهولة **traversal** في الاتجاهين  
- **delete** أسرع لأن عندك **prev pointer**  
- ممكن **insert before** بسهولة  

### **2.4 Disadvantages**
- بياخد مساحة زيادة بسبب **prev pointer**  
- محتاج تحديث لنقطتين في كل عملية **insert/delete**
---
## **2.5 Code – Insertions in DLL**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// insert at front
void insertFront(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// insert at end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// insert before a given node
void insertBefore(Node*& head, Node* nextNode, int data) {
    if (nextNode == NULL)
        return;

    Node* newNode = new Node();
    newNode->data = data;

    newNode->prev = nextNode->prev;
    newNode->next = nextNode;

    if (nextNode->prev != NULL)
        nextNode->prev->next = newNode;
    else
        head = newNode;

    nextNode->prev = newNode;
}
```

---

## **3. Circular Linked List (CLL)**

### **3.1 What is a Circular Linked List?**
هو **Linked List** آخر **node** فيه بتشاور على أول **node** مش على **NULL**.

```

node1 -> node2 -> node3 -> back to node1

```

### **3.3 Advantages**
- ممكن تبدأ من أي **node** وتتلف لحد ما ترجع لها  
- مفيد في **Round Robin Scheduling**  
- مفيد في **queue implementation**  

---
## **3.4 Code – Circular Linked List**

```cpp
#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

// insert in empty list
CNode* addToEmpty(int data) {
    CNode* temp = new CNode();
    temp->data = data;
    temp->next = temp;
    return temp;
}

// insert at beginning
CNode* addBegin(CNode* last, int data) {
    if (last == NULL)
        return addToEmpty(data);

    CNode* temp = new CNode();
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    return last;
}

// insert at end
CNode* addEnd(CNode* last, int data) {
    if (last == NULL)
        return addToEmpty(data);

    CNode* temp = new CNode();
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;
    return last;
}

// insert after specific node
CNode* addAfter(CNode* last, int data, int item) {
    if (last == NULL)
        return NULL;

    CNode* p = last->next;

    do {
        if (p->data == item) {
            CNode* temp = new CNode();
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;

            return last;
        }
        p = p->next;
    } while (p != last->next);

    cout << "Item not found\n";
    return last;
}

```
---
## **4. Tasks (English Only)**

### **Task 1**

Write a full **menu-driven C++ program** for a stack using linked list:

1. push
2. pop
3. peek
4. display

---

### **Task 2**

Write C++ functions to:

1. Insert at front in DLL
2. Insert at end
---

### **Task 3**

Write a full C++ program for Circular Linked List supporting:

1. addToEmpty
2. addBegin
3. addEnd
4. addAfter

---

### **Task 4**

Explain:

1. Why deletion is faster in DLL
2. Why CLL is ideal for CPU Round Robin scheduling

---

