# Recursion & Recurrence Sheet (Merge Sort & Quick Sort Focus)

## 📌 Overview
This sheet contains practice problems related to **recursion**, **recurrence relations**, and **divide & conquer algorithms** such as:
- Merge Sort
- Quick Sort

---
## 📚 Tasks

### Task 1
Solve the following recurrence:

T(n) = T(n − 1) + n

- Find the time complexity
- Write the expanded form

---

### Task 2
Solve:

T(n) = T(n − 1) + 2^n

- Identify if it is polynomial or exponential
- Find Big-O

---

### Task 3
Given:

T(n) = 6T(n/2) + n^2

- Use Master Theorem
- Determine the case
- Find the final complexity

---

### Task 4
Compare two algorithms:

T1(n) = 6T(n/2) + n^2 T2(n) = aT(n/4) + n^2

- Find the largest value of `a` such that T2 is faster than T1

---

### Task 5
Apply Master Theorem on:

T(n) = 16T(n/2) + (n log n)^4

- Identify a, b, f(n)
- Determine the case
- Write final Big-O

---

### Task 6
Solve:

T(n) = T(n/3) + T(2n/3) + O(n)

- Is this closer to Merge Sort or Quick Sort?
- Explain why
- Find the complexity

---

### Task 7
Explain the difference between:

T(n) = 2T(n/2) + n

and

T(n) = T(n-1) + n

- Which one is more efficient?
- Why?

---

## 🎯 Goal
After finishing this sheet, you should be able to:
- Identify recursion patterns
- Apply Master Theorem
- Distinguish between Merge Sort and Quick Sort behavior
