<p dir="rtl">
  
# **Binary Tree — Session**

## **1. Introduction to Binary Trees**
**Binary Tree**

هي **هيكل بيانات (Data Structure)** مكوّن من مجموعة من العقد (nodes). كل **node** لها:
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
عدد الـ subtrees او الاولاد الخاصة بالـ node. 
في الـ **Binary Tree** القيم دائمًا:  
0 → leaf  
1 → one child  
2 → two children
<pre>
يعني النود اللي ليها 2 أولاد → الديجري بتاعها = 2
لو ليها ولد واحد → الديجري = 1
لو مفيش ولا ولد → الديجري = 0 ودي اسمها Leaf Node

🎨 رسم توضيحي

A
      / | \
     B  C  D
       / \
      E   F

النود A: ليها 3 أبناء (B, C, D) → degree = 3

النود C: ليها 2 أبناء (E, F) → degree = 2

النود B: مفيش أبناء → degree = 0

النود E و F: degree = 0



---

Degree of a Tree

Degree of a Tree هو:
أكبر Degree موجودة بين كل النودز في الشجرة.

من الرسم اللي فوق:

A → degree = 3

C → degree = 2

B,E,F → degree = 0


أكبر رقم = 3
→ يبقى Degree of the Tree = 3


---

🎨 رسم تاني للتوضيح أكتر

X
         /   \
        Y     Z
             / \
            P   Q
               / \
              L   M

Y → degree = 0

P → degree = 0

L, M → degree = 0

Z → degree = 2

Q → degree = 2

X → degree = 2


أكبر Degree = 2
→ Degree of the Tree = 2
</pre>

### **2.5 Leaf Node**
هي اي نود بدون children.

### **2.6 Branch Node**
هي أي node مش leaf.

<pre>
  يعني:

لو ليها child واحد أو اثنين → تبقى Branch

لو مفيهاش children خالص → تبقى Leaf


🎨 مثال

A
      /   \
     B     C
          /
         D

A → branch (لها طفلين)

C → branch (له طفل واحد)

B و D → leafs
  
</pre>

### **2.7 Depth / Level**

<pre>
Depth (أو Level):
عدد الحواف edges من الـ root لحد ما نوصل للنود.

🎨 مثال

A
      /   \
     B     C
          /
         D

Depth(A) = 0

Depth(C) = 1

Depth(D) = 2


(كل خطوة بالحافة = +1)
</pre>

### **2.8 Height**

أطول مسار من الـ node لحد أي leaf.

<pre>
  🎨 مثال

A
      /   \
     B     C
          / \
         D   E
            /
           F

نحسب من تحت لفوق:

F → height = 0

D → height = 0

E → height = 1 (لأن تحتيها F)

C → height = 2 (C → E → F)

A → height = 3 (A → C → E → F)
</pre>

### **2.9 Ancestor / Descendant**
- لو في path موجه من node لغيرها → الأولى **ancestor** والتانية **descendant**.
<pre>
  لو في طريق (path) من نود لنود تحتها:

اللي فوق = ancestor

اللي تحت = descendant


🎨 مثال

A
      /   \
     B     C
          /
         D

A ancestor لـ C و D

C ancestor لـ D

D descendant لـ C ولـ A

B descendant لـ A
</pre>

---

## **3. Special Forms of Binary Trees**

### **3.1 Strictly Binary Tree**
كل **non-leaf node** لها **2 children** بالضبط.  
عدد الـ nodes = (2 × عدد الـ leaves) − 1.
<pre>

  كل non-leaf node عندها 2 children بالضبط.
مفيش نود Child واحد بس.

🎨 مثال Strictly Binary Tree

A
      /   \
     B     C
          / \
         D   E

ده Strict لأن:

A لها طفلين

C لها طفلين

B,D,E leafs (عادي)
  
</pre>
### **3.2 Complete Binary Tree**
كل الـ leaves على نفس الـ level.  
عدد الـ nodes = 2^(d+1) − 1
<pre>
  كل levels مليانة بالكامل

ماعدا الأخير

والـ leaves كلها على نفس الـ level


🎨 مثال Complete

A
      /   \
     B     C
    / \   / \
   D   E F   G

كل الليفز على نفس المستوى.
  
</pre>

### **3.3 Almost Complete Binary Tree**
- الـ leaves موجودة إمّا على level d أو d−1
- مفيش فراغات في الشمال
<pre>
  مفيش فراغات في الشمال
يعني بنملى من الشمال لليمين.


🎨 مثال Almost Complete

A
      /   \
     B     C
    / \   /
   D   E F

الـ level الأخير مش كامل
بس مفيش فراغ على الشمال
(لو كانت F على اليمين بس → غلط)
</pre>
---

## **4. Representing Binary Trees**

### **4.1 Array Representation**
ممتاز لو الـ tree **complete** أو **almost complete**.
<pre>
  بنخزن الشجرة في Array كده:

parent في index = k
→ left child في 2k+1
→ right child في 2k+2


🎨 مثال

A
      /   \
     B     C
    /
   D

Array:

index:  0  1  2  3  4  5  6
value:  A  B  C  D  -  -  -


لكن بيعمل **wasted space** لو الـ tree مش كاملة.
</pre>


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
<pre>
  الشجرة:

A
      /   \
     B     C
          / \
         D   E

الـ Pre-Order للنفس الشجرة:

A B C D E

لو هو عايز يعمل Copy:

يشوف A → يبني Root

يشوف B → يحطها شمال

يشوف C → يمين

يشوف D → شمال تحت C

يشوف E → يمين تحت C


وبكده يبني نفس الشجرة تمامًا.
</pre>

### **5.3 Post-Order Traversal**
Left → Right → Root  
يستخدم في delete أو free للـ tree.
<pre>
  
Left → Right → Root

وده بالضبط الترتيب المنطقي للحذف:

مينفعش يحذف Node قبل ما يحذف أولادها

لأن لو حذف الأب الأول → هيخسر الوصول للأبناء، وهيفضلوا في الذاكرة.


Post-Order يضمن إنه:

1. يحذف الفروع اللي تحت


2. وبعدين يحذف الأب



وده نفس ترتيب الـ free للذاكرة.


---

🎨 مثال

A
      /   \
     B     C
          / \
         D   E

Post-Order Traversal:

B  D  E  C  A

وده نفس ترتيب الحذف:

1. يحذف B


2. يحذف D


3. يحذف E


4. يحذف C


5. في الآخر يحذف A
  
</pre>

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
</p>
