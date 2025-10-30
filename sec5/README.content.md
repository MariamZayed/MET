## CLIPS OOP Content (COOL)

1. Defclss construct
2. Multiple inherertence
3. creating instance
4. pttern matching with obj patterns
5. Deleting instance

### 1. Defining Classes and Constructors (CLIPS)

**شرح:**
في CLIPS، بنستخدم `defclass` علشان نعرف كلاس جديد، و`slot` علشان نحدد الخصائص أو البيانات اللي الكائن هيحتفظ بيها. بعد كده بنستخدم `definstance` علشان ننشئ كائن من الكلاس ده.

```clips
(defclass Person
  (is-a USER)
  (slot name)
  (slot age))

(definstance obj of Person
  (name "Mariam")
  (age 25))
```
- شرح:
(is-a USER) معناها إن الكلاس اللي بننشئه بيكون نوع من أنواع الكلاسات القابلة للاستخدام في النظام، لإن USER هو كلاس أساسي موجود تلقائيًا في CLIPS، وكل الكائنات اللي بننشئها لازم تورث منه علشان النظام يقدر يتعامل معاها.


### 2. Multiple Inheritance

**شرح:**
CLIPS بيدعم الوراثة المتعددة، يعني ممكن كلاس يرث من أكتر من كلاس في نفس الوقت باستخدام `(is-a A B)`، والكائن اللي هينشأ من الكلاس ده هيقدر يستخدم كل الـ slots من الكلاسات الأب.

```clips
(defclass A
  (is-a USER)
  (slot a-feature))

(defclass B
  (is-a USER)
  (slot b-feature))

(defclass C
  (is-a A B)
  (slot c-feature))

```

### 3. Creating Instances

**شرح:**
لما نعرف كلاس، نقدر ننشئ منه أكتر من instance. الطريقة الأساسية لإنشاء instance في CLIPS هي باستخدام `make-instance`، ودي بتتم وقت التشغيل بشكل ديناميكي.

```clips
(defclass Car
  (is-a USER)
  (slot model))

(make-instance car3 of Car (model "Mercedes"))
```

### 4. Pattern Matching with Object Patterns

**شرح:**
القواعد في CLIPS بتستخدم `defrule` علشان تطابق كائنات بناءً على الكلاس والقيم، وده بيساعد في اتخاذ قرارات بناءً على بيانات الكائنات.

```clips
(defrule match-circle
  ?f <- (object (is-a Circle) (radius ?r)) ; ده اسم اوبجكت باترن 
                                            ; دور على اي انستانس عندك من كلاس سيركل ويكون عندها سلوت ( او بروبرتي) نوعها radius
                                           ; خلي بالك الاوبجكت ده باترن ماتشنج, يعني الجمله بتاعت اوبجكت از ا سيركل معناها = دور على اي انستانس عندك من كلاس سيركل 
  =>
  (printout t "It's a circle with radius " ?r crlf))

(defrule match-square
  ?f <- (object (is-a Square) (side ?s))
  =>
  (printout t "It's a square with side " ?s crlf))
```

### 5. Deleting Instances

**شرح:**
لو عايز تمسح instance معين من الميموري، بتستخدم الأمر `retract-instance`. وده مفيد لما تكون خلصت استخدام الكائن ومش محتاجه.

```clips
; Delete instance manually
(retract-instance car1)
```
