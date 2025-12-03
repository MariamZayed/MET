# **Binary Tree — Session**

## **1. Introduction to Binary Trees**
**Binary Tree** هي **هيكل بيانات (Data Structure)** مكوّن من مجموعة من العقد (nodes). كل **node** لها:
- قيمة (value)
- قد يكون لها **left subtree** و **right subtree**

وتعريف الـ **Binary Tree** نفسه Recursive لأن كل **subtree** يعتبر **Binary Tree**.

---

## **2. Binary Tree Terminology**

### **2.1 Root**
هي أول **node** في الـ tree، ومافيش ليها parent.

### **2.2 Parent & Child**
- أي **node** لها **subtrees** تعتبر **parent**.
- والعقد الموجودة في الـ subtrees تعتبر **children**.

### **2.3 Siblings**
عقد لها نفس **parent**.

### **2.4 Degree of a Node**
عدد الـ subtrees الخاصة بالـ node.
في الـ **Binary Tree** القيم دائمًا:  
0 → leaf  
1 → one child  
2 → two children

### **2.5 Leaf Node**
هي عقدة بدون children.

### **2.6 Branch Node**
هي أي node مش leaf.

### **2.7 Depth / Level**
عدد الحواف من الـ root لحد الوصول للـ node.

### **2.8 Height**
أطول مسار من الـ node لحد أي leaf.

### **2.9 Ancestor / Descendant**
- لو في path موجه من node لغيرها → الأولى **ancestor** والتانية **descendant**.

---

## **3. Special Forms of Binary Trees**

### **3.1 Strictly Binary Tree**
كل **non-leaf node** لها **2 children** بالضبط.  
عدد الـ nodes = (2 × عدد الـ leaves) − 1.

### **3.2 Complete Binary Tree**
كل الـ leaves على نفس الـ level.  
عدد الـ nodes = 2^(d+1) − 1

### **3.3 Almost Complete Binary Tree**
- الـ leaves موجودة إمّا على level d أو d−1
- مفيش فراغات في الشمال

---

## **4. Representing Binary Trees**

### **4.1 Array Representation**
ممتاز لو الـ tree **complete** أو **almost complete**.

مثلاً:
- لو الـ node في index = k  
  → left child في 2k+1  
  → right child في 2k+2

لكن بيعمل **wasted space** لو الـ tree مش كاملة.

### **4.2 Linked Representation**
الأفضل والأشهر.
كل **node** فيها:
- value  
- pointer → left child  
- pointer → right child  

---

## **5. Tree Traversal**

### **5.1 In-Order Traversal**
Left → Root → Right  
ينتج قيم مرتّبة تصاعديًا.

### **5.2 Pre-Order Traversal**
Root → Left → Right  
يستخدم كثير في عمل copy للـ tree.

### **5.3 Post-Order Traversal**
Left → Right → Root  
يستخدم في delete أو free للـ tree.

---

## **6. B+-Tree (Introduction)**

**B+-Tree** نوع خاص من **Balanced Tree** يُستخدم في:
- قواعد البيانات
- أنظمة الملفات

أهم صفاته:
- كل الـ leaves في نفس المستوى.
- كل node فيها:
  - عدد من **keys**
  - وعدد من **children references**

### **خصائص الـ B+-Tree**
- كل node غير الـ leaf فيها:  
  keys بين الـ children  
- الـ root ليه على الأقل childين.
- كل leaf فيها مفاتيح مرتّبة.
- كل search بياخد نفس عدد الـ disk accesses.

---

## **7. B+-Tree Insertion (Simplified Overview)**

1. ننزل للـ **leaf** المناسب.
2. لو فيه مكان → insert.
3. لو مليان → split.
4. لو split → نرفع key للـ parent.
5. لو الـ parent مليان → يحصل split تاني … وهكذا.

---

## **8. B+-Tree Deletion (Simplified Overview)**

1. نحذف الـ key من الـ leaf.
2. لو لسه مستوفي القواعد → خلاص.
3. لو بقى فيه نقص:
   - يا إما نعمل **redistribute** مع sibling
   - يا إما نعمل **merge**
4. نحدّث الـ parent بعد الدمج أو توزيع القيم.

---

## **9. Code Example for Binary Tree (C++)**
```cpp
#include <iostream>
using namespace std;

struct node {
    int value;
    node *left_child, *right_child;
};

node* new_node(int value) {
    node* tmp = new node();
    tmp->value = value;
    tmp->left_child = tmp->right_child = NULL;
    return tmp;
}

node* insert_node(node* root, int value) {
    if (root == NULL)
        return new_node(value);

    if (value < root->value)
        root->left_child = insert_node(root->left_child, value);
    else if (value > root->value)
        root->right_child = insert_node(root->right_child, value);

    return root;
}

void print(node* root) {
    if (root != NULL) {
        print(root->left_child);
        cout << root->value << " ";
        print(root->right_child);
    }
}

int main() {
    node* root = NULL;
    root = insert_node(root, 10);
    insert_node(root, 30);
    insert_node(root, 25);
    insert_node(root, 36);
    insert_node(root, 56);
    insert_node(root, 78);

    print(root);
    return 0;
}
```
<pre>
  10
                \
                30
               /  \
             25   36
                    \
                    56
                      \
                      78
</pre>
