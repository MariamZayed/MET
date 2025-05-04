## 🟩 سكشن: الـ `deftemplate` في CLIPS

### 📌 تعريف:
الـ `deftemplate` هو طريقة لتعريف *structure* أو *نوع بيانات مخصص* في CLIPS، زي الـ struct في C أو class بسيط في لغات تانية. بنستخدمه علشان نحدد نوع الـ facts اللي هنستخدمها، وده بيساعد في تنظيم البيانات أكتر.

---

### 🧠 ليه بنستخدم `deftemplate`؟
في CLIPS، فيه نوعين من الـ facts:
- **Ordered facts**: مجرد قائمة من القيم (مثال: `(student ahmed 22)`).
- **Unordered facts**: بنستخدم فيها `deftemplate` علشان نحدد الحقول بالاسم (مثال: `(student (name ahmed) (age 22))`).

`deftemplate` بيسهل:
- التعامل مع البيانات.
- كتابة قواعد (rules) دقيقة.
- تقليل الغلط.

---

### 🛠️ الصيغة العامة:
```clips
(deftemplate template-name
   (slot slot-name-1)
   (slot slot-name-2)
   ...
)
```

---

### ✅ مثال بسيط:
```clips
(deftemplate student
   (slot name)
   (slot age)
   (slot grade)
)
```

ده بيعرّف نوع بيانات اسمه `student`، وليه 3 خصائص: الاسم، السن، والدرجة.

بعد كده نقدر نضيف fact بالشكل ده:
```clips
(assert (student (name "Ali") (age 21) (grade "A")))
```

---

### 🧩 أنواع الـ Slots:
1. **slot**: بياخد قيمة واحدة بس.
2. **multislot**: بياخد أكتر من قيمة (زي array أو list).

#### مثال على multislot:
```clips
(deftemplate course
   (slot name)
   (multislot students)
)
```

```clips
(assert (course (name "AI") (students "Ali" "Mona" "Sara")))
```

---

### 💡 نقدر كمان نحدد قيمة ابتدائية للـ slot:
```clips
(deftemplate student
   (slot name)
   (slot age (default 18))
   (slot grade (default "B"))
)
```

لو معملناش تحديد لقيمة عند الـ assert، CLIPS هيستخدم القيمة الإفتراضية اللي إحنا حطيناها.

---

### 🧪 استخدامه في القواعد:
بعد ما نعرف template ونضيف facts، نقدر نكتب rules تستخدم الـ slots دي.

```clips
(defrule honor-student
   (student (name ?n) (grade "A"))
   =>
   (printout t ?n " is an honor student!" crlf)
)
```

---

### 📋 ملخص سريع:
- `deftemplate`: لتعريف شكل البيانات.
- بيسمح باستخدام slots وmultislot.
- ممكن نحدد قيم افتراضية.
- بيسهل كتابة قواعد دقيقة وواضحة.
