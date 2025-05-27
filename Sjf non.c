#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], tw = 0, tt = 0, t;
    float aw, at;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // Sort burst times using selection sort
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
            }
        }
    }

    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        tw += wt[i];
        tt += tat[i];
    }

    aw = (float)tw / n;
    at = (float)tt / n;

    printf("Avg WT: %.2f\n", aw);
    printf("Avg TAT: %.2f\n", at);

    return 0;
}
