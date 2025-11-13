#include <stdio.h>

int main() {
    int n, qt;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rem_bt[n], st[n], ft[n], wt[n], tat[n];
    int started[n];
    float total_wt = 0, total_tat = 0;

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i];
        started[i] = 0;
    }

    printf("Enter Quantum Time: ");
    scanf("%d", &qt);

    int t = 0, complete = 0;

    while (complete != n) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {
                executed = 1;
                if (!started[i]) {
                    st[i] = t;
                    started[i] = 1;
                }

                if (rem_bt[i] > qt) {
                    t += qt;
                    rem_bt[i] -= qt;
                } else {
                    t += rem_bt[i];
                    rem_bt[i] = 0;
                    ft[i] = t;
                    tat[i] = ft[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    complete++;
                }
            }
        }
        if (!executed) t++;
    }

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nPro\tAT\tBT\tST\tFT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], st[i], ft[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}
