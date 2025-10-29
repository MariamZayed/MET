# 🧱 continue - Stack Applications


## 📘 Postfix Evaluation Algorithm

### Idea

الـ **Postfix** expressions سهل جدًا تتقييم باستخدام Stack، لأن كل ما تلاقي Operator بتطبّقه على آخر اتنين Operands اتضافوا في الـ Stack.

### Algorithm Steps

1. امشي على الـ expression من الشمال لليمين.
2. لو الـ token **Operand** → اعمله `push` في الـ Stack.
3. لو الـ token **Operator** →

   * اعمل `pop` لآخر قيمتين.
   * نفّذ العملية (`calc(op1, op2)`).
   * اعمل `push` للنتيجة.
4. بعد ما تخلص، القيمة الوحيدة اللي فاضلة في الـ Stack هي **النتيجة**.

### Example

Expression: `234+*5-`

الخطوات:

```
2 → push  
3 → push  
4 → push  
+ → pop(4,3) = 7 → push(7)  
* → pop(7,2) = 14 → push(14)  
5 → push  
- → pop(5,14) = 9 → push(9)
```

✅ الناتج النهائي = `9`

⏱ **Time Complexity:** O(n)

---

## 🧮 Postfix Evaluation (C++)

```cpp
#include <iostream>
#include <stack>
#include <cmath>     // for pow()
#include <cctype>    // for isdigit()

using namespace std;

int main() {
    stack<int> s;
    string exp;
    cout << "Enter the postfix expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int op1, op2, result;
            op1 = s.top(); s.pop();
            op2 = s.top(); s.pop();

            switch (c) {
                case '+': result = op2 + op1; break;
                case '-': result = op2 - op1; break;
                case '*': result = op2 * op1; break;
                case '/': result = op2 / op1; break;
                case '%': result = op2 % op1; break;
                case '^': result = pow(op2, op1); break;
                default: 
                    cout << "Invalid operator\n";
                    return 1;
            }
            s.push(result);
        }
    }

    cout << "\nThe result of expression " << exp << " = " << s.top() << endl;
    return 0;
}
```

🧾 **Example Input/Output**

```
Enter the expression: 245+*
The result of expression 245+* = 18
```

🧾 **Example Input/Output**

```
Enter the postfix expression: 245+*
The result of expression 245+* = 18
```

---

## 🧭 Infix to Postfix Conversion (C++)

```cpp
#include <iostream>
#include <stack>
#include <cctype>    // for isalnum()

using namespace std;

int priority(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '^') return 3;
    return 0;
}

int main() {
    stack<char> s;
    string exp;
    cout << "Enter the infix expression: ";
    cin >> exp;

    string postfix = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') s.pop();
        } else {
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "\nPostfix Expression: " << postfix << endl;
    return 0;
}
```

🧾 **Example Input/Output**

```
Enter the infix expression: a+b*c
Postfix Expression: abc*+
```

---

## 🎯 Tasks — Stack Applications

### 🧩 **Task 1 — While Loop Conversion**

Convert both **Infix-to-Postfix** and **Postfix Evaluation** programs to use `while` loops instead of `for` loops.

###\ **Task 2 — Convert by Hand**

Manually convert the following **Infix expressions** into **Postfix** form using the algorithm steps (on paper first):

1. `(a+b)*(c-d)`
2. `A+B*C-D/E`
3. `(5+9)*2-4`
---

### **Task 3 — Evaluate Manually**

Evaluate these **Postfix expressions** step by step using a simulated stack (on paper):

1. `23*54*+9-`
2. `82/3-32*+`
3. `562+*3-`

---

### **Task 4 — Debugging Practice**

Run the program with **invalid parentheses** expressions, like:

* `(a+b)*c)`
* `a+b*)c(`

Then modify the program so it prints:

```
Invalid Expression
```

if parentheses are mismatched.

---

###  **Task 5 — Combined Project**

Write a single program that:

1. Converts an **Infix expression** into **Postfix**.
2. Evaluates the **Postfix** result and prints the final value.

**Example:**

```
Input: (2+3)*4
Output:
Postfix: 23+4*
Result: 20
```
