#include <stdio.h>

int strcmp(const char *s1, const char *s2);

int main(void)
{

    /* two C strings to compare */
    char word1[21];
    char word2[21];

    /* prompt the user for the first string */
    /* and capture it from stdin */
    printf("Enter the first string to compare: ");
    scanf("%s", word1);

    /* prompt the user for the second string */
    /* and capture it from stdin */
    printf("Enter the second string to compare: ");
    scanf("%s", word2);

    /* print out the return value of strcmp */
    printf("%d\n", strcmp(word1,word2));

    /* added to show the common syntax for 
       checking for equality 
       i.e. "word1 == word2?" doesn't work
       as expected in C */
    if(!strcmp(word1,word2))
    {
        printf("The two strings have the same characters!\n");
    }

    return 0;
}

/* advance the pointers until the strings no longer match 
   stop short when one or the other ends (s1 chosen here) */
int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    
    /* then return the difference in the ASCII value of 
    the dereferenced pointers to show the lexicographical order */
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}