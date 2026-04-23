#include <stdio.h>
#include <string.h>

int my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);

int main(void)
{
    /* strlen test */
    char word[] = "Hello";
    printf("my_strlen: %d, strlen: %zu\n", my_strlen(word), strlen(word));

    /* strcpy test */
    char dest[20];
    my_strcpy(dest, "Hello");
    printf("my_strcpy: %s\n", dest);

    /* strcat test */
    char combined[20] = "Hello, ";
    my_strcat(combined, "world!");
    printf("my_strcat: %s\n", combined);

    return 0;
}

/* create your functions starting here */
