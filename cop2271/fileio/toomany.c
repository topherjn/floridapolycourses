#include <stdio.h>

int main(void) {
    FILE *fp;
    int count = 0;

    while (!0) {
        fp = fopen("data.txt", "r");
        count++;
        if (fp == NULL) {
            printf("fopen failed at call #%d\n", count);
            break;
        }
        printf("Call #%d -> FILE* address: %p | fd: %d\n", count, (void*)fp, _fileno(fp));
    }

    return 0;
}