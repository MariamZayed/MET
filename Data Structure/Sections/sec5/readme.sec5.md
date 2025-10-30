#  Continue - Stack Applications

##  Introduction

النهارده هنعمل **تطبيقين أساسيين** على الـ **Stack** علشان نفهم إزاي الكمبيوتر بيتعامل مع المعادلات الحسابية (Expressions):

1. **تحويل Infix → Postfix**
2. **تقييم Postfix**
---

## 🧠 مين اللي بيحوّل من Infix إلى Postfix؟

التحويل من **Infix → Postfix** مش الإنسان هو اللي بيعمله في العادة،
ده جزء من **الـ Compiler أو الآلة الحاسبة (Calculator)**.
إحنا كطلبة أو مبرمجين بنتعلم نعمل التحويل ده **علشان نفهم ازاي الماشين بتفكر**.

التحويل بـ Stack هو **محاكاة لطريقة الآلة الحاسبة في تنفيذ المعادلات**،
لأن الماشين مش بتفهم الـ Infix (زي `A+B*C`) بشكل مباشر.
هي بتحوله إلى صيغة أسهل للمعالجة — زي **Postfix (ABC*+)** أو أحيانًا **Prefix (+A*BC)**.

---

## 🧮 معلومة إثرائية: إمتى بنستخدم الـ Prefix؟

الـ **Prefix** (زي `+A*BC`) بيتستخدم في بعض **المعالجات القديمة أو في التفسير الشجري للعمليات**،
زي لما بنبني **Expression Trees** أو في **Compilers** علشان التقييم recursive.
لكن في أغلب تطبيقاتنا البرمجية الحديثة، **Postfix** هو الأسهل والأكثر شيوعًا.

---

## 📘 هنعمل إيه في السيشن دي

1. تحويل Expression من **Infix → Postfix (By Hand)**
2. **Evaluate Postfix (By Hand)**
3. **تطبيق عملي بالـC++**
4. **Tasks للتدريب**

---

## 🔹 Step 1 — تحويل Expression من Infix إلى Postfix (By Hand)

### 🧠 الفكرة ببساطة

احنا بنمشي على المعادلة من الشمال لليمين،
وكل مرة بنشوف رمز (رقم أو حرف أو عملية)، نقرر نوديه فين:
يا في الـ **Postfix**، يا في الـ **Stack**.

---
### ⚙️ القاعدة العامة

1. **لو الرمز Operand (زي A أو 3)** → نحطه على طول في **Postfix**.
2. **لو الرمز Operator (زي + أو * أو -)** →

   * لو الـStack فاضي → نحطه في الـStack.
   * لو مش فاضي → نقارن **أولوية العملية الجديدة** باللي فوق الـStack.

     * لو العملية الجديدة **أعلى أولوية** → نحطها في الـStack.
     * لو اللي فوق الـStack **أعلى أو مساوي** → نطلعه (`pop`) ونضيفه في الـPostfix،
       وبعدين نحط العملية الجديدة في الـStack.
3. **لو لقيت ( → حطها في الـStack.**
4. **لو لقيت ) → طلع كل العمليات من الـStack لحد ما توصل لـ (.**
5. **وفي الآخر**، بعد ما تخلص كل الرموز،
   اطلع كل العمليات اللي لسه في الـStack وضيفها في الآخر.

---

### 🧮 Example 1

**Expression:**

```
(A + B) * C
```

| Symbol | Action                          | Stack | Postfix |
| ------ | ------------------------------- | ----- | ------- |
| (      | نحطه في الـStack                | (     | —       |
| A      | Operand → نحطه في الـPostfix    | (     | A       |
| +      | نحطه في الـStack                | ( +   | A       |
| B      | Operand → نحطه في الـPostfix    | ( +   | AB      |
| )      | نطلع كل العمليات لحد ( → نضيف + | —     | AB+     |
| *      | Stack فاضي → نحطه               | *     | AB+     |
| C      | Operand → نحطه في الـPostfix    | *     | AB+C    |
| —      | نخلص → نطلع اللي في الـStack    | —     | AB+C*   |

✅ **Postfix النهائي = AB+C***

---

### 🧮 Example 2

**Expression:**

```
A + B * C
```

| Symbol | Action                       | Stack | Postfix |
| ------ | ---------------------------- | ----- | ------- |
| A      | Operand → نحطه في الـPostfix | —     | A       |
| +      | Stack فاضي → push(+)         | +     | A       |
| B      | Operand → نحطه في الـPostfix | +     | AB      |
| *      | أعلى أولوية من + → push(*)   | + *   | AB      |
| C      | Operand → نحطه في الـPostfix | + *   | ABC     |
| —      | نطلع كل العمليات             | —     | ABC*+   |

✅ **Postfix النهائي = ABC*+**

---

## ⚙️ Step 2 — Evaluate Postfix (By Hand)

### 🧠 الفكرة ببساطة

احنا بنمشي على الـPostfix من الشمال لليمين،
وكل مرة بنشوف **رمز** نعمل الآتي:

| الحالة                             | الإجراء                                                                         |
| ---------------------------------- | ------------------------------------------------------------------------------- |
| لو الرمز **Operand** (رقم أو قيمة) | نحطه في الـStack                                                                |
| لو الرمز **Operator** (زي + - * /) | نطلع آخر قيمتين من الـStack (pop)، نطبق العملية، ونحط الناتج الجديد في الـStack |

وفي الآخر، أول قيمة في الـStack هتكون هي **النتيجة النهائية**.

---

### 🧮 Example 1

**Expression:**

```
2 3 4 + * 5 -
```

| Step | Symbol | Action            | Stack   |
| ---- | ------ | ----------------- | ------- |
| 1    | 2      | Operand → push(2) | [2]     |
| 2    | 3      | Operand → push(3) | [2,3]   |
| 3    | 4      | Operand → push(4) | [2,3,4] |
| 4    | +      | 3+4=7 → push(7)   | [2,7]   |
| 5    | *      | 2×7=14 → push(14) | [14]    |
| 6    | 5      | Operand → push(5) | [14,5]  |
| 7    | -      | 14−5=9 → push(9)  | [9]     |

✅ **Final Result = 9**

---

### 🧮 Example 2

**Expression:**

```
5 6 2 + * 3 -
```

| Step | Symbol | Action             | Stack   |
| ---- | ------ | ------------------ | ------- |
| 1    | 5      | push(5)            | [5]     |
| 2    | 6      | push(6)            | [5,6]   |
| 3    | 2      | push(2)            | [5,6,2] |
| 4    | +      | 6+2=8 → push(8)    | [5,8]   |
| 5    | *      | 5×8=40 → push(40)  | [40]    |
| 6    | 3      | push(3)            | [40,3]  |
| 7    | -      | 40−3=37 → push(37) | [37]    |

✅ **Final Result = 37**

---

## 💻 Step 3 — Evaluate Postfix using Stack (C++)

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

    for (char c : exp) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int result;

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

    cout << "\nResult: " << s.top() << endl;
    return 0;
}
```

🧾 **Example Input/Output**

```
Enter the postfix expression: 245+*
Result: 18
```

---

## 💻 Step 4 — تحويل Infix إلى Postfix باستخدام Stack (C++)

```cpp
#include <iostream>
#include <stack>
#include <cctype> // for isalnum()

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
    cout << "Enter infix expression: ";
    cin >> exp;

    string postfix = "";

    for (char c : exp) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // pop '('
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
Enter infix expression: a+b*c
Postfix Expression: abc*+
```

---
## تاسك مش الزامي بس ضروري للفهم

 a. **Manual Conversion** → حوّل بيدك:

   * `(a+b)*(c-d)`
   * `A+B*C-D/E`
   * `(5+9)*2-4`

 b. **Manual Evaluation** → قيّم بيدك:

   * `23*54*+9-`
   * `82/3-32*+`
   * `562+*3-`
---

##  Tasks

1. **While Loop Conversion** → استخدم `while` بدل `for` في الكودين.

2. **Debugging Practice** → جرّب إدخال:

   * `(a+b)*c)`
   * `a+b*)c(`
     وخلي الكود يطبع `"Invalid Expression"` لو الأقواس مش مظبوطة.

3. **Combined Project** → برنامج واحد:

   * يحوّل Infix → Postfix
   * يقيّم Postfix
   * يطبع النتيجة النهائية

**Example:**

```
Input: (2+3)*4
Output:
Postfix: 23+4*
Result: 20
```
