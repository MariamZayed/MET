## 👨‍🏫 **CLIPS - شرح Object-Oriented Programming (OOP)**

---

### 1. تعريف الكلاسات (defclass)

CLIPS بتدعم الـ Object-Oriented Programming باستخدام `defclass`.

**مثال:**

```clips
(defclass X (is-a USER)
   (slot a)
   (slot b)
   (slot c)
)
```

* `defclass`: لإنشاء class.
* `(is-a USER)`: كل الكلاسات لازم ترث من USER أو من Class تاني.
* `slot`: المتغيرات اللي بنخزن فيها القيم.

---

### 2. إنشاء Instances باستخدام Rule

نستخدم `(make-instance)` عشان ننشئ object من class معين داخل قاعدة (rule).

**مثال:**

```clips
(defrule r5
  =>
  (make-instance [x1] of X (a 20)(b 3))
  (make-instance [x2] of X (a 40)(b 5))
  (make-instance [x3] of X (a 10)(b 4))
  (make-instance [y1] of Y (d 50))
  (make-instance [y2] of Y (d 20))
  (make-instance [z1] of Z (a 70))
)
```

* `[x1]`: اسم الـ instance.
* `of X`: من أي class.
* `(a 20)`: القيمة اللي هتتحط في slot `a`.

---

### 3. استرجاع Instances (Matching)

#### Q2: استرجاع الـ Instances اللي ليها نفس القيمة في `X.a` و `Y.d`

```clips
(defrule r1
  (object (is-a X) (a ?n1))
  (object (is-a Y) (d ?n1))
  =>
  (printout t ?n1 crlf)
)
```

#### Q3: استرجاع أي instance من X أو Y

```clips
(defrule r2
  ?inst <- (object (is-a X | Y))
  =>
  (printout t ?inst crlf)
)
```

#### Q4: استرجاع كل الـ instances ما عدا X

```clips
(defrule r3
  ?inst <- (object (is-a ~X))
  =>
  (printout t ?inst crlf)
)
```

#### Q5: طباعة كل الـ instances في النظام

```clips
(defrule r4
  ?inst <- (object)
  =>
  (printout t ?inst crlf)
)
```

---

### 4. حذف الـ Instances

#### Q6: حذف كل instances من Y

```clips
(defrule delete
  ?inst <- (object (is-a Y))
  =>
  (unmake-instance ?inst)
  (printout t "this instance was deleted " ?inst crlf)
)
```

---

### 5. تعديل الـ Instances

#### عن طريق `send`:

```clips
(send [c1] put-age 20)
```

#### أو عن طريق `modify-instance`:

```clips
(modify-instance c1 (age 20))
```

---

### Q4: Output لقانون ضرب قيمتين من instance

```clips
(defrule r3
  (object (is-a A) (n1 ?a) (n2 ?b))
  =>
  (printout t ?a "x" ?b "=" (* ?a ?b) crlf)
)
```

**Output:**

```
5 x 6 = 30
2 x 3 = 6
```

---

### Q5: تعريف كلاس student وكلاس dept اللي بيرث منه

```clips
(defclass student (is-a USER)
  (slot name)
  (slot age)
  (slot address)
)

(defclass dept (is-a student)
  (slot deptname)
  (slot group)
)
```

---

### Q6: قاعدة لإنشاء Instances من student و dept

```clips
(defrule r2
  =>
  (make-instance [y1] of student (name ahmed) (age 44) (address tanta))
  (make-instance [y2] of dept (deptname cs) (group two))
  (make-instance [y3] of dept (deptname it) (group one) (age 23) (name Mohamed))
)
```

---

### ملاحظات إضافية:

* لازم تعمل `(reset)` بعد تعريف القواعد والـ classes.
* استخدم `(run)` لتفعيل القواعد.

---

لو حابب تضيف تمرين عملي أو عايز أجهزلك كويز على الكلام ده، بلغني!
