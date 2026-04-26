#include <stdio.h>

int strcmp(const char *s1, const char *s2);

int main(void)
{

    char *word1 = "apple";
    char *word2 = "apples";

    printf("\n%d\n", strcmp(word1,word2));

    return 0;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}