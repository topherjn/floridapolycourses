#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Write a file
    FILE *fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        perror("Could not open file for writing");
        return EXIT_FAILURE;
    }

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "Line %d\n", i);
    }
    fclose(fp);

    // Read it back
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        perror("Could not open file for reading");
        return EXIT_FAILURE;
    }

    char buffer[64];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    if (ferror(fp)) {
        perror("Read error");
    }

    fclose(fp);
    return EXIT_SUCCESS;
}