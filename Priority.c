#include <stdio.h>

int main() {
    int n, bt[10], pr[10], wt[10], tat[10], temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d] - BT: ", i + 1);
        scanf("%d", &bt[i]);
        printf("P[%d] - Priority: ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sort based on priority (lower number = higher priority)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                // Swap priority
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                // Swap burst time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    // Waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBT\tPri\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\n", i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAvg WT = %.2f", avg_wt / n);
    printf("\nAvg TAT = %.2f\n", avg_tat / n);

    return 0;
}
