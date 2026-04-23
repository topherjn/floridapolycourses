#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    fprintf(fp, "foo world\n");
    fprintf(fp, "goodbye world\n");

    fprintf(stdout, "File contents written\n");

    fclose(fp);
    return EXIT_SUCCESS;
}