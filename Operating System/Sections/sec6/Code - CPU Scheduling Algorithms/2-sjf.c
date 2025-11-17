#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], st[n], ft[n], wt[n], tat[n], completed[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;  // P1, P2, P3...
        printf("P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        completed[i] = 0;
    }


    // Step 1: Sort by arrival time (زي FCFS بالظبط)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {

                int temp;

                temp = at[i];  at[i] = at[j];  at[j] = temp;
                temp = bt[i];  bt[i] = bt[j];  bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;

            }
        }
    }

    int time = 0, done = 0;

    // اختيار أقصر Burst من اللي وصلوا
    while (done < n) {

        int idx = -1;
        int minBT = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        // لو معنديش عملية وصلت لسه → الوقت يمشي
        if (idx == -1) {
            time++;
            continue;
        }

        st[idx] = time;
        ft[idx] = time + bt[idx];
        tat[idx] = ft[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        time = ft[idx];
        completed[idx] = 1;
        done++;
    }

    // Output
    printf("\nProcess\tAT\tBT\tST\tFT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], st[i], ft[i], wt[i], tat[i]);
    }

    return 0;
}
