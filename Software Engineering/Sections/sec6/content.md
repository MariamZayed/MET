# Critical Path Method - CPM


## أولاً: جدول المصطلحات والمختصرات الأساسية

| المصطلح بالعربي | Term in English | الاختصار | الشرح باختصار |
| :--- | :--- | :---: | :--- |
| النشاط | Activity | — | خطوة أو مهمة داخل المشروع تتطلب وقتاً وموارداً لتنفيذها. |
| الأنشطة السابقة | Predecessors | — | الأنشطة التي يجب أن تنتهي قبل أن يبدأ هذا النشاط. |
| المدة | Duration | — | الوقت المتوقع لإنهاء النشاط (بالأيام أو الأسابيع). |
| أبكر بداية | Earliest Start | ES | أول وقت ممكن أن يبدأ فيه النشاط بناءً على الأنشطة السابقة. |
| أبكر نهاية | Earliest Finish | EF | أول وقت ممكن أن ينتهي فيه النشاط ($\text{ES} + \text{Duration}$). |
| أخر بداية | Latest Start | LS | أخر وقت مسموح أن يبدأ فيه النشاط دون أن يؤخر المشروع ($\text{LF} - \text{Duration}$). |
| أخر نهاية | Latest Finish | LF | أخر وقت مسموح أن ينتهي فيه النشاط دون أن يؤخر المشروع. |
| الفائض / السماحية | Slack / Float | Slack | مقدار الوقت الذي يمكن أن يتأخر فيه النشاط دون تأخير المشروع الكلي ($\text{LS} - \text{ES}$). |
| المسار الحرج | Critical Path | — | أطول مسار متصل في الشبكة والأنشطة التي تقع عليه تكون سماحيتها صفراً ($\text{Slack} = 0$). |

---

## ثانياً: القوانين الأساسية مرتبة

1. **حساب التمرير الأمامي (Forward Pass - من اليسار لليمين):**
    للنشاط الأول في المشروع:<br>
   - $\text{ES} = 0$.<br><br>
    أبكر نهاية: <br>
   - $\text{EF} = \text{ES} + \text{Duration}$.<br><br>
    لأي نشاط تالي له أكثر من نشاط سابق:<br>
    - $\text{ES} = \max(\text{EF لكل الأنشطة السابقة المباشرة})$.
<br><br>

2. **حساب التمرير الخلفي (Backward Pass - من اليمين لليسار):**
    لأخر نشاط في المشروع:<br>
   -  $\text{LF} = \text{EF}$ (النهائية للمشروع).<br><br>
    أخر بداية:<br>
    - $\text{LS} = \text{LF} - \text{Duration}$.<br><br>
    لأي نشاط سابق يغذي أكثر من نشاط لاحق:<br>
   -  $\text{LF} = \min(\text{LS لكل الأنشطة اللاحقة المباشرة})$.<br><br>

3. **حساب السماحية (Slack):**
   * $\text{Slack} = \text{LS} - \text{ES}$ (أو $\text{LF} - \text{EF}$).

---

## ثالثاً: المثال الأول (معقد ومتداخل)

### 1. جدول مدخلات المثال الأول
| النشاط (Activity) | الأنشطة السابقة (Predecessors) | المدة (Duration) |
| :---: | :---: | :---: |
| A | — | 3 |
| B | A | 4 |
| C | A | 2 |
| D | B | 3 |
| E | C, D | 2 |

### 2. رسم شبكة المشروع (Network Diagram)
```text
[ A: تحليل ]
ES: 0 | EF: 3
  ├──> [ B: قاعدة البيانات ] ──> [ D: الـ Backend ]
  │    ES: 3 | EF: 7             ES: 7 | EF: 10 ────────┐
  │                                                   │
  └──> [ C: الواجهات UI ] ───────────────────────────> [ E: الربط النهائي ]
       ES: 3 | EF: 5                                  ES: 10 | EF: 12  <-- (نهاية المشروع)
```

### 3. خطوات التمرير الأمامي (Forward Pass)
* النشاط A: $\text{ES} = 0 \rightarrow \text{EF} = 0 + 3 = 3$.
* النشاط B: $\text{ES} = \text{EF لـ A} = 3 \rightarrow \text{EF} = 3 + 4 = 7$.
* النشاط C: $\text{ES} = \text{EF لـ A} = 3 \rightarrow \text{EF} = 3 + 2 = 5$.
* النشاط D: $\text{ES} = \text{EF لـ B} = 7 \rightarrow \text{EF} = 7 + 3 = 10$.
* النشاط E: يعتمد على C و D $\rightarrow \text{ES} = \max(\text{EF لـ C (5)}, \text{EF لـ D (10)}) = 10 \rightarrow \text{EF} = 10 + 2 = 12$.

### 4. خطوات التمرير الخلفي (Backward Pass) وحساب الـ Slack
* النشاط E (الأخير): $\text{LF} = 12 \rightarrow \text{LS} = 12 - 2 = 10 \rightarrow \text{Slack} = 10 - 10 = 0$.
* النشاط D: $\text{LF} = \text{LS لـ E} = 10 \rightarrow \text{LS} = 10 - 3 = 7 \rightarrow \text{Slack} = 7 - 7 = 0$.
* النشاط C: $\text{LF} = \text{LS لـ E} = 10 \rightarrow \text{LS} = 10 - 2 = 8 \rightarrow \text{Slack} = 8 - 3 = 5$.
* النشاط B: $\text{LF} = \text{LS لـ D} = 7 \rightarrow \text{LS} = 7 - 4 = 3 \rightarrow \text{Slack} = 3 - 3 = 0$.
* النشاط A: $\text{LF} = \min(\text{LS لـ B (3)}, \text{LS لـ C (8)}) = 3 \rightarrow \text{LS} = 3 - 3 = 0 \rightarrow \text{Slack} = 0 - 0 = 0$.

### 5. الجدول الشامل للمثال الأول
| النشاط | الأنشطة السابقة | المدة | ES | EF | LS | LF | Slack | الحالة |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| A | — | 3 | 0 | 3 | 0 | 3 | 0 | حرج (Critical) |
| B | A | 4 | 3 | 7 | 3 | 7 | 0 | حرج (Critical) |
| C | A | 2 | 3 | 5 | 8 | 10 | 5 | غير حرج |
| D | B | 3 | 7 | 10 | 7 | 10 | 0 | حرج (Critical) |
| E | C, D | 2 | 10 | 12 | 10 | 12 | 0 | حرج (Critical) |

### 6. المسار الحرج (Critical Path) للمثال الأول
الأنشطة التي تمتلك $\text{Slack} = 0$:
$$\text{A} \rightarrow \text{B} \rightarrow \text{D} \rightarrow \text{E}$$

---

## رابعاً: المثال الثاني (مثال متقدم وشامل)

### 1. جدول مدخلات المثال الثاني
| النشاط (Activity) | الأنشطة السابقة (Predecessors) | المدة (Duration) |
| :---: | :---: | :---: |
| P | — | 2 |
| Q | P | 3 |
| R | P | 5 |
| S | Q | 2 |
| T | R, S | 4 |

### 2. رسم شبكة المشروع (Network Diagram) للمثال الثاني
```text
[ P: البدء ]
ES: 0 | EF: 2
  ├──> [ Q: معالجة أولية ] ──> [ S: مراجعة ]
  │    ES: 2 | EF: 5             ES: 5 | EF: 7 ────────┐
  │                                                   │
  └──> [ R: اختبارات ] ───────────────────────────────> [ T: التسليم النهائي ]
       ES: 2 | EF: 7                                  ES: 7 | EF: 11 <-- (نهاية المشروع)
```

### 3. خطوات التمرير الأمامي (Forward Pass) للمثال الثاني
* النشاط P: $\text{ES} = 0 \rightarrow \text{EF} = 0 + 2 = 2$.
* النشاط Q: $\text{ES} = \text{EF لـ P} = 2 \rightarrow \text{EF} = 2 + 3 = 5$.
* النشاط R: $\text{ES} = \text{EF لـ P} = 2 \rightarrow \text{EF} = 2 + 5 = 7$.
* النشاط S: $\text{ES} = \text{EF لـ Q} = 5 \rightarrow \text{EF} = 5 + 2 = 7$.
* النشاط T: يعتمد على R و S $\rightarrow \text{ES} = \max(\text{EF لـ R (7)}, \text{EF لـ S (7)}) = 7 \rightarrow \text{EF} = 7 + 4 = 11$.

### 4. خطوات التمرير الخلفي (Backward Pass) وحساب الـ Slack للمثال الثاني
* النشاط T (الأخير): $\text{LF} = 11 \rightarrow \text{LS} = 11 - 4 = 7 \rightarrow \text{Slack} = 7 - 7 = 0$.
* النشاط R: $\text{LF} = \text{LS لـ T} = 7 \rightarrow \text{LS} = 7 - 5 = 2 \rightarrow \text{Slack} = 2 - 2 = 0$.
* النشاط S: $\text{LF} = \text{LS لـ T} = 7 \rightarrow \text{LS} = 7 - 2 = 5 \rightarrow \text{Slack} = 5 - 5 = 0$.
* النشاط Q: $\text{LF} = \text{LS لـ S} = 5 \rightarrow \text{LS} = 5 - 3 = 2 \rightarrow \text{Slack} = 2 - 2 = 0$.
* النشاط P: $\text{LF} = \min(\text{LS لـ Q (2)}, \text{LS لـ R (2)}) = 2 \rightarrow \text{LS} = 2 - 2 = 0 \rightarrow \text{Slack} = 0 - 0 = 0$.

### 5. الجدول الشامل للمثال الثاني
| النشاط | الأنشطة السابقة | المدة | ES | EF | LS | LF | Slack | الحالة |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| P | — | 2 | 0 | 2 | 0 | 2 | 0 | حرج (Critical) |
| Q | P | 3 | 2 | 5 | 2 | 5 | 0 | حرج (Critical) |
| R | P | 5 | 2 | 7 | 2 | 7 | 0 | حرج (Critical) |
| S | Q | 2 | 5 | 7 | 5 | 7 | 0 | حرج (Critical) |
| T | R, S | 4 | 7 | 11 | 7 | 11 | 0 | حرج (Critical) |

> **ملحوظة تعليمية هامة:** في هذا المثال الثاني، جميع الأنشطة تمتلك $\text{Slack} = 0$، مما يعني أن المشروع بالكامل عبارة عن مسارين حرجين متوازيين ومتساويين في المدة.

### 6. المسار الحرج (Critical Path) للمثال الثاني
المساران كلاهما حرجان:
1. $\text{P} \rightarrow \text{Q} \rightarrow \text{S} \rightarrow \text{T}$
2. $\text{P} \rightarrow \text{R} \rightarrow \text{T}$