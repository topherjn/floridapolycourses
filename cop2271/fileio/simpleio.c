#include <stdio.h>

int main(void) {
    char buf[256];
    int i;

    /* Read */
    FILE *fp = fopen("sample.txt", "r");
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    /* Modify */
    for (i = 0; buf[i]; i++)
        if (buf[i] == 'h') buf[i] = 'H';

    /* Write back */
    fp = fopen("sample.txt", "w");
    fprintf(fp, "%s", buf);
    fclose(fp);

    return 0;
}