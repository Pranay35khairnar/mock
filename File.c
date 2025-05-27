#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");  // Source file
    fp2 = fopen(argv[2], "w");  // Destination file

    if (!fp1 || !fp2 || argc != 3) {
        printf("error");
        return 1;
    }

    char c;
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
