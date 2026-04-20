#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    /* canonical C string */
    char word[20];
    
    strcpy(word,"Hello, strings.");

    printf("%s\n", word);

    printf("Number of characters: %d\n",strlen(word));

    /* this is immutable */
    char *string = "Bonjour";
    char *greeting = "Bonjour";
    char salutation[] = "Bonjour";

    printf("%p %p %p\n", string, greeting, salutation);

    greeting = salutation;

    printf("%p %p %p\n", string, greeting, salutation);

    printf("%s has %d letters in it\n", string, strlen(string));

    for(int i = 0; word[i] != '\0'; i++)
    {
        if(word[i] == '.') word[i] = '!';
        printf("%c ", word[i]);
        
    }

    //string[0] = 'T';

    printf("%s", string);

    char combine[20] = "port";
    strcat(combine, "manteau");

    printf("\n%s\n", combine);

    char *dupe = strdup("Hello, world!");

    printf("%s, %d\n", dupe, strlen(dupe));

    free(dupe);

    return 0;
}