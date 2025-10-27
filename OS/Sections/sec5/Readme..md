# 🧩 Session 5: CPU Scheduling Algorithms

## 🔹 Introduction

في أنظمة التشغيل، لما يكون في أكثر من process جاهزة إنها تتنفذ، الـ **CPU Scheduler** هو المسؤول يختار أي process تشتغل الأول.
الهدف من الاجوريزم دي هو تقليل **waiting time** و **turnaround time** وتحسين كفاءة استخدام المعالج.

---

## ⚙️ 1. First Come First Served (FCFS)

### 📘 Concept

الاجوريزم دي تعتبر أبسط نوع من أنواع الجدولة.
الـ processes بتتدخل في **Ready Queue** حسب وقت الوصول (**Arrival Time**)، واللي يدخل الأول يتنفذ الأول.

### ✅ Features

* Non-preemptive (يعني الـ process ما بتتقاطعش أثناء التنفيذ).
* سهل جدًا في التطبيق.
* ممكن يسبب **Convoy Effect**: لو process طويلة جات قبل باقي الـ processes، الباقيين هيستنو كتير.

### 🧮 Example

| Process | Arrival Time | Burst Time |   |
| ------- | ------------ | ---------- | - |
| P1      | 0            | 5          |   |
| P2      | 2            | 3          |   |
| P3      | 4            | 1          |   |

**Execution Order:** P1 → P2 → P3
**Waiting Time:**

* P1 = 0
* P2 = 3
* P3 = 4

---

## ⚙️ 2. Shortest Job First (SJF – Non-Preemptive)

### 📘 Concept

الاجوريزم دي بتختار الـ process اللي وقت تنفيذها (**Burst Time**) أقل من غيرها.
لو في أكتر من process جاهزة، الـ scheduler يختار الأقصر.

### ✅ Features

* Non-preemptive.
* بتقلل **Average Waiting Time** جدًا.
* عيبها إن لازم نعرف **Burst Time** مسبقًا.

### 🧮 Example

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| P1      | 0            | 8          |
| P2      | 1            | 4          |
| P3      | 2            | 2          |
| P4      | 3            | 1          |

**Execution Order:** P1 → P4 → P3 → P2
(حسب الأقصر فالأطول)

---

## ⚙️ 3. Shortest Remaining Time First (SRTF – Preemptive SJF)

### 📘 Concept

هو نفس فكرة SJF، بس **preemptive**.
يعني لو process جديدة دخلت ووقتها أقصر من الوقت المتبقي للـ process الحالية، المعالج يوقف اللي شغال ويشغل الجديد.

### ✅ Features

* Preemptive (بيسمح بالمقاطعة).
* بيقلل الـ **Average Waiting Time** أكتر من SJF.
* أكثر عدلاً مع الـ short processes.

### 🧮 Example

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| P1      | 0            | 8          |
| P2      | 1            | 4          |
| P3      | 2            | 2          |
| P4      | 3            | 1          |

**Execution Order:** P1 → P2 → P3 → P4 → (يرجع يكمل P1)

---

## ⚙️ 4. Round Robin (RR)

### 📘 Concept

دي أكثر الاجوريزم **fair**، وبتتعامل مع الـ processes كأنها في **دائرة**.
كل process بتاخد **time slice (quantum)** محدد، وبعدها تتحط في آخر الدور لو لسه مخلصتش.

### ✅ Features

* Preemptive.
* مناسب للأنظمة متعددة المستخدمين.
* الأداء يعتمد على حجم الـ quantum.

### 🧮 Example

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| P1      | 0            | 5          |
| P2      | 1            | 3          |
| P3      | 2            | 1          |

**Quantum = 2**
**Execution Order:** P1(2) → P2(2) → P3(1) → P1(3) → P2(1)

---

## 🔹 Comparison Table

| Algorithm   | Type           | Preemptive | Fairness | Efficiency         |
| ----------- | -------------- | ---------- | -------- | ------------------ |
| FCFS        | Simple         | ❌          | Low      | Low                |
| SJF         | Non-Preemptive | ❌          | Medium   | High               |
| SRTF        | Preemptive     | ✅          | Medium   | Very High          |
| Round Robin | Preemptive     | ✅          | High     | Depends on Quantum |

---

## 🎯 Task

**Task:**

1. Write a C++ program to simulate the **Round Robin Scheduling Algorithm**.
2. Use input from the user for:

   * Number of processes
   * Arrival time & Burst time for each process
   * Quantum time
3. Calculate and print:

   * Waiting Time for each process
   * Turnaround Time for each process
   * Average Waiting & Turnaround Time
4. Make sure all students use the same variable names so the results match.

---

✅ **Extra Task:**
Rewrite any SJF (non-preemptive) program you made before using **while loop** instead of **for loop**.
---
# معلومه اثرائيه

كلمة “Robin” لوحدها معناها:

اسم طائر (الـ robin bird 🐦)

أو اسم شخص (زي Robin Hood مثلًا)

أو حتى أحيانًا تُستخدم بمعنى بسيط في الشعر أو الأدب زي “اللحن” أو “النغمة” القديمة.

لكن في مصطلح “Round Robin” الكلمة ليها معنى اصطلاحي خاص، مش حرفي.
المعنى ده جه من التاريخ الفرنسي القديم.

أصل التعبير من كلمة فرنسية:

rond ruban
ومعناها شريط دائري أو ورقة التوقيعات الدائرية.

كان زمان لما مجموعة ناس يكتبوا شكوى أو عريضة للحكومة، كانوا يوقّعوا أسماءهم حوالين دايرة، مش تحت بعض — علشان محدش يعرف مين بدأها أو مين قائدهم.
وده هو أصل فكرة “Round Robin” = الكل يشارك في الدور بالتساوي 🔁

وبعد كده التعبير دخل للرياضة (بطولات Round Robin = الكل يلعب مع الكل)،
ومنها راح لعالم الـ Operating Systems بمعنى:

كل process تاخد دورها العادل في الدايرة، زي اللاعبين في البطولة بالظبط.

يعني "Robin" هنا مش المقصود بيها الاسم،
لكنها بقت جزء من مصطلح ثابت تاريخيًا بمعنى "التناوب العادل في دائرة"
