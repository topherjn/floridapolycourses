#include<stdio.h>
#include<string.h>

int main(void)
{
    /* canonical C string */
    char word[20];
    word[0]='\0';

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

    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i] == '.') word[i] = '!';
        printf("%c ", word[i]);
        
    }

    //string[0] = 'T';

    printf("%s", string);

    return 0;
}