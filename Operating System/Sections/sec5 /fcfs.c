#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], st[n], ft[n], wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort by Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    // Calculate Start Time and Finish time for the first process
    st[0] = at[0];
    ft[0] = st[0] + bt[0];

    // Calculate st and ft for the rest of the processes
    for (int i = 1; i < n; i++) {
        // if the i pro came when the cpu is empty, then pro is starting immediately
        if (at[i] > ft[i - 1])
            st[i] = at[i];
        else
            st[i] = ft[i - 1];
        ft[i] = st[i] + bt[i];
    }

    // Calculate TAT and WT
    // {Turnaround Time} = {Finish Time} - {Arrival Time}
    for (int i = 0; i < n; i++) {
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
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
