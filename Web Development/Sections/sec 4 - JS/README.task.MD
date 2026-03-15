
# JavaScript Hoisting & Scope – Task

## الفكرة العامة

في `JavaScript` في نوعين مهمين من الـ **Scope**:

### 1. Function Scope
المتغيرات المعرفة باستخدام `var` تكون داخل **function scope**  
يعني تظهر داخل الفنكشن بالكامل حتى لو اتعرفت داخل block.

### 2. Block Scope
المتغيرات المعرفة باستخدام:
- `let`
- `const`

تكون داخل **block scope** فقط (مثل `if`, `for`, `{}`).

---

## Hoisting

**Hoisting** هو رفع **declarations** إلى أعلى الـ `scope` قبل تنفيذ الكود.

| Type | Hoisted | Initial Value |
|-----|-----|-----|
| var | Yes | undefined |
| let | Yes | TDZ |
| const | Yes | TDZ |
| function declaration | Yes | full function |

---

# Tasks

# Task 1 – var Hoisting

```javascript
console.log(a);
var a = 10;
```

### Questions

1. What will be printed?
2. Rewrite the code after hoisting happens internally.

---

# Task 2 – let Hoisting

```javascript
console.log(b);
let b = 20;
```

### Questions

1. What happens when the code runs?
2. Why is it different from `var`?

---

# Task 3 – Function Hoisting

```javascript
sayHello();

function sayHello() {
    console.log("Hello Students");
}
```

### Questions

1. Will this code run successfully?
2. Explain why.

---

# Task 4 – Function Expression Hoisting

```javascript
sayHi();

var sayHi = function () {
    console.log("Hi");
};
```

### Questions

1. What will happen when this code runs?
2. Explain the reason.

---

# Task 5 – Function Scope

```javascript
function test() {

    if (true) {
        var x = 10;
    }

    console.log(x);
}

test();
```

### Questions

1. What will be printed?
2. Why can `x` be accessed outside the `if` block?

---

# Task 6 – Block Scope

```javascript
function test() {

    if (true) {
        let y = 20;
    }

    console.log(y);
}

test();
```

### Questions

1. What will happen when this code runs?
2. Why is it different from `var`?

---

# Task 7 – Scope with Loop

```javascript
for (var i = 0; i < 3; i++) {
}

console.log(i);
```

### Questions

1. What will be printed?
2. Why is `i` accessible outside the loop?

---

# Task 8 – Block Scope with Loop

```javascript
for (let j = 0; j < 3; j++) {
}

console.log(j);
```

### Questions

1. What will happen when this code runs?
2. Explain why.

---

# Task 9 – Hoisting inside Function Scope

```javascript
var num = 10;

function test() {

    console.log(num);

    var num = 5;
}

test();
```

### Questions

1. What will be printed?
2. Rewrite the function after hoisting.

---

# Bonus Task

Predict the output.

```javascript
let x = 1;

function test() {

    console.log(x);

    if (true) {
        let x = 2;
        console.log(x);
    }
}

test();
```

### Questions

1. What will be printed?
2. Explain the scope behavior.
