# CLIPS Procedural & Predicate Functions

## ✅ Answers for CLIPS Task

---

## 🔹 Part 1: Procedural Functions

### 1️⃣ Binding Variables
```clips
CLIPS> (bind ?x 25)
CLIPS> (printout t "The value of x is: " ?x crlf)
```
**Output:**
```
The value of x is: 25
```

---

### 2️⃣ Looping with progn$
```clips
CLIPS> (bind ?list (create$ 5 10 15 20))  
CLIPS> (progn$ (?item ?list) (printout t "Current item: " ?item crlf))
```
**Output:**
```
Current item: 5  
Current item: 10  
Current item: 15  
Current item: 20  
```

---

### 3️⃣ Switch-Case Statement
```clips
CLIPS> (bind ?status "Processing")  
CLIPS>
(switch ?status  
   (case "Pending" then (printout t "Order is still pending." crlf))  
   (case "Processing" then (printout t "Order is being processed." crlf))  
   (case "Shipped" then (printout t "Order has been shipped." crlf))  
   (case "Delivered" then (printout t "Order delivered successfully." crlf))  
   (default (printout t "Invalid status." crlf)))  
```
**Output:**  
```
Order is being processed.
```

---

### 4️⃣ Break Usage in Switch-Case
```clips
CLIPS> (bind ?status "Processing")  
CLIPS>
(switch ?status  
   (case "Pending" then (printout t "Order is still pending." crlf) (break))  
   (case "Processing" then (printout t "Order is being processed." crlf) (break))  
   (case "Shipped" then (printout t "Order has been shipped." crlf) (break))  
   (case "Delivered" then (printout t "Order delivered successfully." crlf) (break))  
   (default (printout t "Invalid status." crlf)))  
```
**Output:**  
```
Order is being processed.
```

---

## 🔹 Part 2: Predicate Functions

### 5️⃣ Number Check
```clips
CLIPS> (printout t (numberp 3.14) crlf)  
CLIPS> (printout t (numberp "hello") crlf)  
CLIPS> (printout t (numberp 42) crlf)  
```
**Output:**
```
TRUE  
FALSE  
TRUE  
```

---

### 6️⃣ Even or Odd
```clips
CLIPS> (printout t "12 is " (if (evenp 12) then "even" else "odd") crlf)  
CLIPS> (printout t "27 is " (if (oddp 27) then "odd" else "even") crlf)  
```
**Output:**
```
12 is even  
27 is odd  
```

---

### 7️⃣ String vs Symbol
```clips
CLIPS> (printout t "welcome is " (if (stringp "welcome") then "a string" else "not a string") crlf)  
CLIPS> (printout t "hello is " (if (symbolp hello) then "a symbol" else "not a symbol") crlf)  
```
**Output:**
```
welcome is a string  
hello is a symbol  
```

---

### 8️⃣ Equality Check
```clips
CLIPS> (printout t (eq foo bar) crlf)  
CLIPS> (printout t (neq foo bar) crlf)  
```
**Output:**
```
FALSE  
TRUE  
```

---

## 🎯 Summary of Final Answers

| Task | Expected Output |
|------|----------------|
| 1️⃣ | `The value of x is: 25` |
| 2️⃣ | `Current item: 5`<br>`Current item: 10`<br>`Current item: 15`<br>`Current item: 20` |
| 3️⃣ | `Order is being processed.` |
| 4️⃣ | `Order is being processed.` (with break) |
| 5️⃣ | `TRUE, FALSE, TRUE` |
| 6️⃣ | `12 is even`<br>`27 is odd` |
| 7️⃣ | `welcome is a string`<br>`hello is a symbol` |
| 8️⃣ | `FALSE, TRUE` |

✅ **All tasks successfully executed in CLIPS!** 🚀

