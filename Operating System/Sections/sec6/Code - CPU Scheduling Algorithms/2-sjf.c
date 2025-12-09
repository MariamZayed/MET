#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], st[n], ft[n], wt[n], tat[n], completed[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        completed[i] = 0;
    }

    int time = 0, done = 0;

    while (done < n) {
        int idx = -1;
        int minBT = 100000; // رقم كبير كبديل لـ INT_MAX

        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

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

    printf("\nProcess\tAT\tBT\tST\tFT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], st[i], ft[i], wt[i], tat[i]);
    }

    return 0;
}
