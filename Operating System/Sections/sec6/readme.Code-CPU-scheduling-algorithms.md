## 🟦 **1. FCFS (First Come First Served)**

```c
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
```

🔹 بيطلب عدد الـ processes اللي هنتعامل معاها.
مثلاً لو كتبتي 3، يبقى عندنا P1 و P2 و P3.

---

```c
    int bt[n], wt[n], tat[n];
    float total_wt = 0, total_tat = 0;
```

🔹 بيعمل arrays:

* `bt[]` = burst time (مدة تنفيذ العملية)
* `wt[]` = waiting time (المدة اللي استنتها العملية قبل ما تبدأ)
* `tat[]` = turnaround time (من أول ما دخلت لحد ما خلصت)
  وكمان متغيرات لجمع المتوسط بعدين.

---

```c
    printf("Enter Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
```

🔹 بيدخّل وقت تنفيذ كل عملية واحدة واحدة.

---

```c
    wt[0] = 0; // first process waiting time = 0
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
```

🔹 أول عملية متستناش، فـ waiting time بتاعها = 0.
🔹 كل عملية بعدها بتستنى اللي قبلها تخلص:

> WT[i] = BT[i-1] + WT[i-1]

---

```c
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
```

🔹 كل عملية وقتها الكلي = وقتها + اللي استنته.

---

```c
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }
```

🔹 بيطبع جدول النتائج (burst, waiting, turnaround).
🔹 ويجمع المجموع الكلي علشان المتوسط.

---

```c
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
```

🔹 في الآخر بيحسب المتوسطات.

---

## 🟩 **2. SJF (Shortest Job First)**

```c
int bt[n], wt[n], tat[n], p[n];
```

🔹 `p[]` عشان نخزن ترتيب العمليات (P1, P2, ...).

---

```c
    // Sort by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
```

🔹 بيرتب العمليات حسب burst time من الأصغر للأكبر.
علشان الأقصر يتنفذ الأول.

---

```c
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
```

🔹 نفس فكرة FCFS، بس بعد ما رتبناهم.

---

```c
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
```

🔹 بيحسب turnaround لكل واحدة.

---

الباقي نفس الطباعة والحسابات زي FCFS.

---

## 🟨 **3. SRTF (Shortest Remaining Time First)**

```c
int at[n], bt[n], rt[n];
```

🔹 `at[]` = arrival time
🔹 `bt[]` = burst time
🔹 `rt[]` = remaining time (كل مرة بنقلل منه لما العملية تشتغل شوية)

---

```c
while (complete != n) {
    for (int j = 0; j < n; j++) {
        if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            shortest = j;
            check = 1;
        }
    }
```

🔹 هنا بيلف على كل العمليات ويشوف:

* هل وصلت؟
* هل وقتها المتبقي أقل من الباقيين؟
  لو آه → يشغلها.

---

```c
    if (check == 0) {
        t++;
        continue;
    }
```

🔹 لو مفيش عملية جاهزة في الوقت ده، يعدّي الزمن ثانية ويكمّل.

---

```c
    rt[shortest]--;
    if (rt[shortest] == 0) {
        complete++;
        finish_time = t + 1;
        wt[shortest] = finish_time - bt[shortest] - at[shortest];
    }
    t++;
```

🔹 بيقلل الوقت المتبقي للعملية اللي شغالة.
🔹 لما تخلص (`rt==0`):

* نحسب وقت الانتظار:
  `WT = finish - burst - arrival`

---

## 🟧 **4. Round Robin (RR)**

```c
int bt[n], at[n], wt[n], tat[n], rem_bt[n];
```

🔹 `rem_bt[]` = الوقت المتبقي من كل عملية (يتخصم منه كل ما تاخد quantum).

---

```c
printf("Enter Quantum Time: ");
scanf("%d", &qt);
```

🔹 بياخد زمن الـ quantum (قد إيه كل عملية تاخد قبل ما تسيب الدور).

---

```c
while (1) {
    int done = 1;
    for (int i = 0; i < n; i++) {
        if (rem_bt[i] > 0 && at[i] <= t) {
            done = 0;
            if (rem_bt[i] > qt) {
                t += qt;
                rem_bt[i] -= qt;
            } else {
                t += rem_bt[i];
                wt[i] = t - bt[i] - at[i];
                rem_bt[i] = 0;
            }
        }
    }
    if (done == 1)
        break;
}
```

🔹 اللوب دي هي قلب الجدولة:

* يلف على كل العمليات الجاهزة.
* لو العملية لسه فاضل فيها أكتر من quantum → يخصم quantum ويرجعها آخر الدور.
* لو خلصت في المدة دي → يحسب وقت الانتظار ويصفّر الوقت المتبقي.
* بيكرر الكلام ده لحد كل العمليات تخلص (`done == 1`).

---

```c
for (int i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    total_wt += wt[i];
    total_tat += tat[i];
}
```

🔹 بعد ما كله يخلص، يحسب الـ TAT وWT الإجمالي.

---

```c
printf("\nAverage Waiting Time = %.2f", total_wt / n);
printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
```

🔹 يطبع النتائج في الآخر.

---
