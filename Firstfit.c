#include <stdio.h>

int main() {
    int b[10], p[10], nb, np, alloc[10];

    printf("Enter no. of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for (int i = 0; i < nb; i++) {
        printf("B%d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter no. of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for (int i = 0; i < np; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &p[i]);
        alloc[i] = -1;
    }

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                alloc[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }

    printf("\nPNo\tPSize\tBNo\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t%d\t", i + 1, p[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("NA\n");
    }

    return 0;
}
