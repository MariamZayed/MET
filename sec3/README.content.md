## Procedural Functions

### 1️⃣ `bind` – تخزين قيمة في متغير
**بتستخدم لتخزين قيمة في متغير محلي (Local Variable).**

```clips
(bind ?x 10)
(printout t "قيمة x: " ?x crlf)
```

🔹 `bind` بتعمل **إسناد لقيمة لمتغير** (`?x`).
🔹 `?x` بياخد القيمة `10`.
🔹 `printout` بيطبع: `قيمة x: 10`

⚠️ **`?x` متغير محلي، مش هيكون متاح خارج السكوب اللي اتعرف فيه.**
## الفرق بين `bind` و `assert` في CLIPS

### 🔹 `bind` لا يُضيف المتغيرات إلى قاعدة الحقائق او ال فاكت بايز
في CLIPS، عند استخدام `bind` لتعريف متغير، فإنه يكون **محليًا ومؤقتًا** أثناء تنفيذ الجملة، ولا يتم تخزينه في قاعدة الحقائق (Facts Base). بمجرد انتهاء تنفيذ الأمر، يختفي المتغير.

### 📌 الفرق بين `bind` و `assert`

| الخاصية        | `bind` (المتغيرات) | `assert` (الـ Facts) |
|---------------|-----------------|------------------|
| **التخزين**  | مؤقت، يختفي بعد التنفيذ | يتم تخزينه في قاعدة الحقائق |
| **الاستخدام** | داخل نفس الجملة أو القاعدة فقط | يمكن استرجاعه عبر `facts` أو `retract` |
| **الرؤية**   | محلية (Local) | عامة (Global) |
| **طريقة التعريف** | `(bind ?x 10)` | `(assert (age 25))` |

---

### 📌 توضيح بالمثال
#### **1️⃣ تعريف متغير باستخدام `bind` (لا يتم تخزينه في الـ Facts)**
```clips
CLIPS> (bind ?list (create$ 1 2 3 4))
(1 2 3 4)
CLIPS> (facts)
CLIPS> ;; لا يوجد أي حقائق جديدة لأن ?list ليس Fact
```
❌ **المتغير ليس جزءًا من قاعدة الحقائق، ويختفي بعد التنفيذ.**

---

#### **2️⃣ إضافة بيانات إلى قاعدة الحقائق باستخدام `assert`**
```clips
CLIPS> (assert (numbers (create$ 1 2 3 4)))  
CLIPS> (facts)
f-0     (initial-fact)  
f-1     (numbers (1 2 3 4))  ;; تم تخزين القائمة داخل الـ Facts Base
```
✅ **هنا `numbers` أصبحت جزءًا من قاعدة الحقائق، ويمكن استرجاعها لاحقًا.**

---

### 🔹 متى تستخدم `bind` ومتى تستخدم `assert`؟
- **استخدم `bind`** إذا كنت تريد تخزين قيمة **مؤقتة أثناء التنفيذ**، مثل متغير داخل دالة.
- **استخدم `assert`** إذا كنت تريد تخزين بيانات **بشكل دائم في قاعدة الحقائق** لاستخدامها لاحقًا في القواعد (Rules).

---

### ✅ مراجعة الـ Facts المخزنة
لمعرفة البيانات المخزنة داخل قاعدة الحقائق، استخدم:
```clips
(facts)
```

---

بهذا الشكل، يمكنك التمييز بين `bind` و `assert` بسهولة أثناء البرمجة في CLIPS! 🚀

---

### 2️⃣ `progn` – تنفيذ مجموعة أوامر معًا
**progn اختصار لـ "PROceed Group of iNstructions"** <br>
**بتستخدم لتنفيذ كوماند أو أكتر من كوماند بشكل متتابع.**

```clips
(progn
   (printout t "Hello" crlf)
   (printout t "World!" crlf))
```
🔹 النتيجة:
```text
Hello
World!
```

---

### 3️⃣ `progn$` – 
**progn$ شبه progn، بس هى مختصه تتعامل مع الليست او (Multifield Values).** 

### مثال 1
```clips
(bind ?list (create$ 1 2 3 4))  ;; عملنا قائمة فيها 1, 2, 3, 4
                                ;; لما بعوز اعمل ليست بستخدم كوماند كرييت

(progn$ (?item ?list)
   (printout t "item: " ?item crlf)
)
```
**الكود ده عامل زي بايثون كالاتي**
```python
for item in list:
    print("item:", item)
```
**خد بالك: بروجن لما بتتعمل مع ليست اخرها كبرامترز تاخد 2 برامتر بس, الليست والايتيم بتاعها**

### مثال 2
```clips
(progn$ (?item ?list)
   (printout t "القيمة الحالية: " ?item crlf)
   (bind ?square (* ?item ?item))
   (printout t "مربع القيمة: " ?square crlf)
)
```
النتيجة
```clips
recent value = 1
square value = 1
recent value = 2
square value = 4
recent value = 3
square value = 9
recent value = 4
square value = 16
```
---

### 4️⃣ `switch` – تنفيذ تعليمات بناءً على قيمة
**بتعمل زي `switch-case` في لغات البرمجة الأخرى.**

```clips
(switch (bind ?x 2)
   (case 1 then (printout t "X is One" crlf))
   (case 2 then (printout t "X is Two" crlf))
   (case 3 then (printout t "X is Three" crlf))
   (default (printout t "X is Unknown" crlf)))
```
🔹 الناتج:
```text
X is Two
```

---

### 5️⃣ `break` – الخروج من `switch` أو `loop`
في CLIPS، الـ switch بيشتغل بشكل مشابه جدًا للـ switch في لغات زي C و Java، لكن الفرق هنا إنك لو معملتيش break، هيكمل تنفيذ باقي الحالات حتى لو إحداها اتحققت!
**بتستخدم لإنهاء التنفيذ مبكرًا.**

```clips
(switch (bind ?x 2)
   (case 2 then
      (printout t "X is Two" crlf)
      (break))  ;; خروج من switch
   (case 3 then (printout t "X is Three" crlf)))
```

---

## Predicate Functions

خد بالك لو في حرف ال p
ده معناها هنقارن قيمه واحده بس, قيمة واااحده بس
مش قيمتين

### 1️⃣ `numberp` – هل القيمة رقم؟
```clips
(numberp 10)   ;; → TRUE
(numberp 3.14) ;; → TRUE
(numberp "abc") ;; → FALSE
```

---

### 2️⃣ `float` – هل القيمة رقم عشري؟
```clips
(float 10)   ;; → FALSE
(float 3.14) ;; → TRUE
```

---

### 3️⃣ `lexemep` – هل القيمة نص أو رمز؟
```clips
(lexemep "Hello") ;; → TRUE
(lexemep foo)     ;; → TRUE
(lexemep 100)     ;; → FALSE
```

---

### 4️⃣ `stringp` – هل القيمة نص (String)؟
```clips
(stringp "Hello") ;; → TRUE
(stringp foo)     ;; → FALSE
```

---

### 5️⃣ `symbolp` – هل القيمة رمز (Symbol)؟
```clips
(symbolp foo)     ;; → TRUE
(symbolp "Hello") ;; → FALSE
```

---

### 6️⃣ `evenp` – هل العدد زوجي؟
```clips
(evenp 4)  ;; → TRUE
(evenp 7)  ;; → FALSE
```

---

### 7️⃣ `oddp` – هل العدد فردي؟
```clips
(oddp 4)  ;; → FALSE
(oddp 7)  ;; → TRUE
```

---

### 8️⃣ `multifieldp` – هل القيمة متعددة الحقول؟
```clips
(multifieldp (create$ 1 2 3))  ;; → TRUE
(multifieldp 10)               ;; → FALSE
```

---

### 9️⃣ `eq` – هل القيمتين لرموز متساويتين؟
خد بالك بين الرموز مش النصوص

```clips
(eq foo foo)     ;; → TRUE
(eq "hello" "hello") ;; → FALSE
```

---

### 🔟 `neq` – هل القيمتين مختلفتين؟
```clips
(neq foo bar)     ;; → TRUE
(neq foo foo)     ;; → FALSE
```