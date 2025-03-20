# **📌 مواضيع سكشن اليوم في JavaScript**

## **1️⃣ المقدمة**
- لمحة سريعة عن JavaScript وأهميتها.
- كيف تعمل JavaScript داخل المتصفح؟

## **2️⃣ المتغيرات في JavaScript وال Hoisting**
- تعريف المتغيرات (`var`, `let`, `const`).
- الفرق بين كل نوع من المتغيرات.
- مفهوم الـ Hoisting وكيف يؤثر على JavaScript.

## **3️⃣ Data Types**
- أنواع البيانات في JavaScript.

## **4️⃣ Functions**
- تعريف الدوال وأنواعها.

## **5️⃣ DOM**
- كيفية التعامل مع عناصر الصفحة برمجيًا.

<br>

# **🟢 1. مقدمة سريعة عن JavaScript**  
- JavaScript هي **لغة برمجة ديناميكية** تُستخدم في المتصفحات لتطوير الويب.  
- تعمل على المتصفح **(Client-Side)**، لكنها تُستخدم أيضًا على السيرفر مع Node.js.  
- **نموذج التنفيذ (Execution Model)** في JavaScript يعتمد على **المفسر (Interpreter)** وليس المترجم (Compiler).  

---
<br>

# **🟠 2. المتغيرات في JavaScript وال Hoisting**  
💡 JavaScript تدعم **3 أنواع من المتغيرات**:  
`var`, `let`, `const`


💡 **ما هو Hoisting؟**  
- **قبل تنفيذ أي كود، المتصفح يرفع جميع المتغيرات والدوال إلى أعلى الـ Scope.**  
- **لكن كل نوع من المتغيرات يتعامل مع Hoisting بطريقة مختلفة!**  
- **الدوال المعرّفة بـ `function` يتم رفعها بالكامل، بينما `function expressions` لا يتم رفعها كدوال.**  
- **TDZ = Temporal Dead Zone**

📌 **مثال عملي يوضح Hoisting مع `var`, `let`, `const`**  

```js
console.log(x); // ✅ undefined (لأن var يتم رفعه بدون قيمته)
console.log(y); // ❌ ReferenceError (لأن let في TDZ)
console.log(z); // ❌ ReferenceError (لأن const في TDZ)

var x = 5;
let y = 10;
const z = 15;
```

🎯 **كيف تفهم JavaScript هذا الكود قبل التنفيذ؟**  

```js
var x;  // ✅ يتم رفع تعريف var ويكون `undefined`
let y;  // ✅ يتم رفع let لكنه في TDZ
const z; // ✅ يتم رفع const لكنه في TDZ

console.log(x); // ✅ undefined
console.log(y); // ❌ ReferenceError
console.log(z); // ❌ ReferenceError

x = 5;
y = 10;
z = 15;
```

| النوع  | هل يتم رفعه؟ | هل يمكن استخدامه قبل التعريف؟ | القيمة الأولية |
|--------|------------|---------------------------|---------------|
| `var`   | ✅ نعم | ⚠️ نعم، لكن قيمته `undefined` | `undefined` |
| `let`   | ✅ نعم، لكنه في **TDZ** | ❌ لا، يعطي `ReferenceError` | لا قيمة |
| `const` | ✅ نعم، لكنه في **TDZ** | ❌ لا، يعطي `ReferenceError` | لا قيمة |

---

### **🟣 4. Hoisting مع الدوال (Functions)**  
💡 **الدوال في JavaScript نوعان:**  

#### **1️⃣ Function Declaration (يتم رفعها بالكامل):**  

```js
sayHello(); // ✅ تعمل بدون مشكلة!

function sayHello() {
    console.log("Hello, world!");
}
```
✅ **JavaScript ترفع الدالة بالكامل، لذلك يمكن استدعاؤها قبل تعريفها.**  

---

#### **2️⃣ Function Expression (لا يتم رفعها كدالة، فقط كمتغير):**  

```js
sayHi(); // ❌ TypeError: sayHi is not a function

var sayHi = function() {
    console.log("Hi!");
};
```
🚨 **لماذا الخطأ؟**  
لأن **المتغير `sayHi` يتم رفعه لكن بدون قيمته (undefined)، فلا يمكن استدعاؤه كدالة!**  

---

### **🟤 5. Scope في JavaScript (تأثير Hoisting داخل الـ Scope)**  

📌 **3 أنواع للـ Scope في JavaScript**:  
1️⃣ **Global Scope**: متغير متاح في كل مكان.  
2️⃣ **Function Scope**: متغير معرّف داخل دالة، لا يمكن الوصول إليه خارجها.  
3️⃣ **Block Scope** (`let`, `const` فقط!): المتغير متاح فقط داخل `{}` التي عُرِّف فيها.  

**var يتجاهل if, while, for لكنه يحترم الفانكشن.**
**let و const يحترموا أي {} سواء كانت في if, while, for, أو حتى فانكشن.**
<br>

🔹 **مثال عملي**:

```js
function test() {
    if (true) {
        var x = 10;
        let y = 20;
        const z = 30;
    }
    console.log(x); // ✅ 10 (لأن var ليس له Block Scope)
    console.log(y); // ❌ ReferenceError (لأن let له Block Scope)
    console.log(z); // ❌ ReferenceError (لأن const له Block Scope)
}
test();
```

🎯 **النتيجة**:
- `var` لا يحترم `Block Scope` ويظل متاحًا داخل الدالة.
- `let` و `const` يظلان محصورين في `{}` فقط.

---

### **🟠 6. Execution Context و Memory Allocation (تخزين المتغيرات في الذاكرة)**  
💡 **كيف يتم تنفيذ الكود في JavaScript؟**  

#### **1️⃣ Creation Phase (مرحلة الإنشاء):**  
   - رفع (`Hoisting`) جميع المتغيرات (`var`, `let`, `const`) والدوال (`function`).  
   - تخصيص `undefined` للمتغيرات المعرّفة بـ `var`.  
   - `let` و `const` تبقى في **Temporal Dead Zone (TDZ)** حتى يتم تعريفها.  
   
#### **2️⃣ Execution Phase (مرحلة التنفيذ):**  
   - يتم تنفيذ الكود سطرًا بسطر.  
   - القيم الفعلية تُخزن في الذاكرة عند وصول البرنامج إليها.

📌 **مثال يوضح كيف يتم التعامل مع المتغيرات في الذاكرة**:

```js
console.log(a); // ✅ undefined (لأن var تم رفعه)
console.log(b); // ❌ ReferenceError (لأن let في TDZ)

var a = 10;
let b = 20;
```

🔹 **ما يحدث في الميموري:**

| المتغير | المرحلة الأولى (Hoisting) | المرحلة الثانية (بعد التنفيذ) |
|---------|----------------|----------------|
| `var a` | `undefined` | `10` |
| `let b` | **TDZ** | `20` |

---

## **🎯 خلاصة **
- JavaScript ترفع تعريف المتغيرات والدوال قبل التنفيذ.
- `var` يُرفع لكن بدون قيمته (`undefined`).
- `let` و `const` يتم رفعهم لكن يبقوا في **Temporal Dead Zone** حتى يصلهم التعريف.
- `function` يتم رفعها بالكامل، لكن `function expressions` لا يتم رفعها كدوال.
- `var` ليس له Block Scope، بينما `let` و `const` لهما.

🔥 **كده عندك محتوى شرح مرتب وكامل لسكشن JavaScript مع التركيز على Hoisting!** 🚀


---
<br>

# **🟢 3. أنواع البيانات (Data Types) في JavaScript**

📌 **JavaScript تحتوي على نوعين أساسيين من البيانات:**
1. **Primitive Types (أنواع بسيطة)**
2. **Reference Types (أنواع مرجعية)**

---

## **🔹 3.1. Primitive Data Types**  
☑️ **هي أنواع يتم تخزين قيمها مباشرة في الميموري، ويتم التعامل معها كقيم منفصلة.**  

| النوع | الوصف | مثال |
|-------|------|------|
| `Number` | أعداد صحيحة أو عشرية | `let x = 10;` |
| `String` | نصوص | `let name = "Mariam";` |
| `Boolean` | قيم منطقية | `let isHappy = true;` |
| `Undefined` | متغير تم تعريفه بدون قيمة | `let x;` |
| `Null` | قيمة فارغة مقصودة | `let y = null;` |
| `Symbol` | معرف فريد | `let sym = Symbol("id");` |
| `BigInt` | أعداد كبيرة جدًا | `let bigNumber = 9007199254740991n;` |

✍ **مثال عملي:**
```js
let age = 25; // Number
let name = "Mariam"; // String
let isStudent = false; // Boolean
let address; // Undefined
let empty = null; // Null
let uniqueId = Symbol("id"); // Symbol
let largeNumber = 123456789012345678901234567890n; // BigInt
```

---

## **🔹 3.2. Reference Data Types**  
☑️ **هي أنواع يتم تخزينها في الميموري كمراجع (References) وليس كقيم مباشرة.**  

| النوع | الوصف | مثال |
|-------|------|------|
| `Object` | كائن يحتوي على أزواج `key-value` | `let user = { name: "Mariam", age: 30 };` |
| `Array` | مصفوفة من القيم | `let numbers = [1, 2, 3, 4];` |
| `Function` | دالة | `function sayHello() { console.log("Hello"); }` |

✍ **مثال عملي:**
```js
let person = {   // ده اوبجت والي تحت دول ال properties 
    name: "Mariam",
    age: 25,
};

let numbers = [10, 20, 30];

function greet() {
    console.log("Hello, world!");
}
```

---
<br>


# **🟠 4. الدوال (Functions) في JavaScript**

📌 **الدوال هي كتل من التعليمات القابلة لإعادة الاستخدام.**

## **🔹 4.1. أنواع الدوال في JavaScript**

### **1️⃣ Function Declaration **
```js
function greet(name) {
    return `Hello, ${name}!`;
}
console.log(greet("Mariam")); // Hello, Mariam!
```

### **2️⃣ Function Expression (تخزين الدالة في متغير)**
```js
const greet = function(name) {
    return `Hello, ${name}!`;
};
console.log(greet("Mariam"));
```

### **3️⃣ Arrow Function (الدوال السهمية - ES6)**
```js
const greet = (name) => `Hello, ${name}!`;
console.log(greet("Mariam"));
```

---

## **🔹 4.2. الفرق بين Function Declaration و Function Expression**

| النوع | يتم رفعه (Hoisting)؟ | يمكن استدعاؤه قبل التعريف؟ |
|------|------------------|----------------------|
| `Function Declaration` | ✅ نعم | ✅ نعم |
| `Function Expression` | ❌ لا | ❌ لا |

✍ **مثال عملي يوضح الفرق:**
```js
sayHello(); // ✅ تعمل بدون مشكلة!
function sayHello() {
    console.log("Hello!");
}

sayHi(); // ❌ TypeError: sayHi is not a function
var sayHi = function() {
    console.log("Hi!");
};
```

---
<br>

# **🔵 5. التعامل مع الـ DOM (Document Object Model)**

📌 **الـ DOM هو الواجهة التي تسمح لنا بالتفاعل مع عناصر الـ HTML باستخدام JavaScript.**

## **🔹 5.1. تحديد عناصر HTML في JavaScript**

### **1️⃣ `getElementById()` - تحديد عنصر باستخدام الـ ID**
```js
let title = document.getElementById("main-title");
console.log(title.textContent);
```

### **2️⃣ `getElementsByClassName()` - تحديد عناصر باستخدام الـ Class**
```js
let items = document.getElementsByClassName("list-item");
console.log(items[0].textContent);
```

### **3️⃣ `querySelector()` و `querySelectorAll()`**
```js
let firstItem = document.querySelector(".list-item"); // عنصر واحد فقط
let allItems = document.querySelectorAll(".list-item"); // جميع العناصر المطابقة
```

---

## **🔹 5.2. تعديل محتوى العناصر**

### **1️⃣ تغيير النص داخل عنصر HTML**
```js
document.getElementById("main-title").textContent = "Welcome to JavaScript!";
```

### **2️⃣ تغيير HTML داخل عنصر**
```js
document.getElementById("content").innerHTML = "<strong>Bold Text</strong>";
```

---

## **🔹 5.3. تعديل الأنماط (CSS) باستخدام JavaScript**
```js
document.getElementById("main-title").style.color = "red";
document.getElementById("main-title").style.fontSize = "24px";
```

---

## **🔹 5.4. التعامل مع الأحداث (Events)**

📌 **الأحداث تُستخدم لجعل الصفحات تفاعلية.**

### **1️⃣ إضافة حدث إلى عنصر باستخدام `addEventListener`**
```js
document.getElementById("myButton").addEventListener("click", function() {
    alert("تم الضغط على الزر!");
});
```

### **2️⃣ التعامل مع الحدث داخل دالة مستقلة**
```js
function showMessage() {
    alert("مرحبًا بك في JavaScript!");
}
document.getElementById("myButton").addEventListener("click", showMessage);
```

---

## **🎯 خلاصة**
- **أنواع البيانات** تنقسم إلى Primitive و Reference.
- **الدوال** في JavaScript لها أنواع مختلفة مثل `Function Declaration` و `Function Expression` و `Arrow Function`.
- **التعامل مع الـ DOM** يسمح بتغيير محتوى الصفحة وتعديل الأنماط وإضافة أحداث تفاعلية.

🔥 **كده عندك محتوى شرح مرتب وكامل لأساسيات JavaScript مع التركيز على DOM!** 🚀
