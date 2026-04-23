#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    char word[64];
    while (fscanf(fp, "%63s", word) == 1) {
        printf("%s\n", word);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}