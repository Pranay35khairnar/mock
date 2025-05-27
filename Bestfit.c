#include <stdio.h>

int main() {
    int b[10], p[10], a[10];
    int nb, np;
    int i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for(i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for(i = 0; i < np; i++) {
        scanf("%d", &p[i]);
        a[i] = -1;
    }

    for(i = 0; i < np; i++) {
        int best = -1;

        for(j = 0; j < nb; j++) {
            if(b[j] >= p[i]) {
                if(best == -1 || b[j] < b[best]) {
                    best = j;
                }
            }
        }

        if(best != -1) {
            a[i] = best;
            b[best] -= p[i];
        }
    }

    printf("\nPNo\tPSize\tBNo\n");
    for(i = 0; i < np; i++) {
        printf("%d\t%d\t", i + 1, p[i]);
        if(a[i] != -1)
            printf("%d\n", a[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
