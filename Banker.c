#include <stdio.h>

int main() {
    int n, r, alloc[10][10], max[10][10], need[10][10], avail[10];
    int f[10], ans[10], idx = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter maximum matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (int i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    for (int i = 0; i < n; i++) {
        f[i] = 0;
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int canRun = 1;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < r; j++) {
                        avail[j] += alloc[i][j];
                    }
                    ans[idx++] = i;
                    f[i] = 1;
                }
            }
        }
    }

    int safe = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            safe = 0;
            break;
        }
    }

    if (safe) {
        printf("\nSafe Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", ans[i]);
        }
        printf("\n");
    } else {
        printf("\nSystem is not in a safe state.\n");
    }

    return 0;
}
