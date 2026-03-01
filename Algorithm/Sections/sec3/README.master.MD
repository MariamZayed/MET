Here you go — clean Markdown, ready to copy-paste into `README.md`.

---

# Master Method

## 1. General Recursion Form

The Master Method solves recurrences of the form:

```math
T(n) = aT(n/b) + f(n)
```

Where:

* `a ≥ 1` → number of subproblems
* `b > 1` → size reduction factor
* `f(n)` → cost of work outside recursive calls

---

## 2. Magical Formula (Critical Exponent)

The **magical formula** is:

```math
n^{\log_b a}
```

This value is used to compare with `f(n)`.

---

## 3. The Three Cases

Let:

```math
Magical Formula = n^{\log_b a}
```

---

### Case 1: Magical Formula > f(n)

If:

```math
f(n) = O(n^{\log_b a - \epsilon}) \quad \text{for some } \epsilon > 0
```

Then:

```math
T(n) = \Theta(n^{\log_b a})
```

✔ The recursive part dominates.

Magical formula used:

```math
n^{\log_b a}
```

---

### Case 2: Magical Formula = f(n)

If:

```math
f(n) = \Theta(n^{\log_b a} \log^k n)
```

Then:

```math
T(n) = \Theta(n^{\log_b a} \log^{k+1} n)
```

✔ Both parts grow at the same rate (add one extra log).

Magical formula used:

```math
n^{\log_b a}
```

---

### Case 3: Magical Formula < f(n)

If:

```math
f(n) = \Omega(n^{\log_b a + \epsilon})
```

(with regularity condition satisfied)

Then:

```math
T(n) = \Theta(f(n))
```

✔ The non-recursive work dominates.

Magical formula used:

```math
n^{\log_b a}
```

---

## 4. Order of Growth (Smallest → Largest)

```math
\log(\log n)
<
\log n
<
n
<
n\log n
<
n^2
<
n^3
<
2^n
<
n!
```

Use this order to compare `f(n)` with the magical formula.

---
<br>
<h1>Task:</h1>
- Solve Master theory questions in the book 
