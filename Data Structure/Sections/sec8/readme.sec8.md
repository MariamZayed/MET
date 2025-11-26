#  Stack (Linked List), Doubly Linked List, Circular Linked List

## **Table of Contents**
- Stack using Linked List  
- Doubly Linked List (DLL)  
- Circular Linked List (CLL)  
- Tasks  

---

## **1. Stack Using Linked List**

### **1.1 revm of a Stack?**
الـ **Stack** هو هيكل بيانات من نوع **LIFO – Last In First Out**.  
يعني آخر عنصر يدخل هو أول عنصر يطلع. وكان عندنا متغير اسمه Top.

### **1.2 Why use Linked List to implement Stack?**
لأن الـ **Linked List** بتسمح بإضافة وحذف العناصر في الـ **Head** بسرعة بدون إعادة تخصيص للذاكرة.

### **1.3 Operations**
- **push()**: إضافة عنصر فوق الستاك  
- **pop()**: إزالة عنصر من فوق الستاك  
- **peek()**: عرض أعلى عنصر بدون حذفه  


**Push Operation:**
- بنعمل **new node**
- الـ **new node->next** بيشاور على **top**
- الـ **top** بيتحدث للـ **new node**

**Pop Operation:**
- لو الـ **top = NULL** يبقى الستاك فاضي  
- لو مش فاضي: يبقى بنشاور على **top->next** كـ **new node**
- خلي بالك تاني, اما بنضيف هنضيف من عند التوب, والتوب هنا هى الاول بتاعت الليست. بنعمل كده ليه؟ عشان عملية الادخال والمسح تبقى اسرع, لأننا عارفين مكان التوب ديما في اللينكد ليست.
---
## **2. Doubly Linked List (DLL)**

### **2.1 What is a DLL?**
هو **Linked List** فيه كل **node** تحتوي:
- **data**
- **next pointer**
- **prev pointer**

كل **node** مرتبطة باللي بعدها واللي قبلها:  
```

node1 <- prev | data | next -> NULL ...

```

### **2.3 Advantages**
- سهولة **traversal** في الاتجاهين  
- ال delete وال insert اسرع 

### **2.4 Disadvantages**
- بياخد مساحة زيادة بسبب **prev pointer**  
- محتاج تحديث لنقطتين في كل عملية **insert/delete**
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

