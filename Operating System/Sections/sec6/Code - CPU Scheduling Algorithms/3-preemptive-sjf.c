#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], st[n], ft[n], wt[n], tat[n];
    int completed = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Remaining time
        st[i] = -1;    // Start time not set yet
    }

    int t = 0; // الوقت الحالي
    while (completed != n) {
        int idx = -1;
        int min_rt = INT_MAX;

        // نختار العملية اللي وصلت وأقل وقت متبقي
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            t++; // مفيش عملية جاهزة، نزود الزمن
            continue;
        }

        if (st[idx] == -1) st[idx] = t; // تحديد وقت بدء أول مرة

        rt[idx]--; // تنفيذ العملية وحدة زمنية
        t++;

        if (rt[idx] == 0) {
            ft[idx] = t; // وقت الانتهاء
            tat[idx] = ft[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            total_wt += wt[idx];
            total_tat += tat[idx];
            completed++;
        }
    }

    printf("\nPro\tAT\tBT\tST\tFT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], st[i], ft[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
