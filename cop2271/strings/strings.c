#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    /* the basis of a C-type string is an array of characters*/
    char word[20];
    
    /* strcpy will copy the characters of the string literal into
       the character array */
    strcpy(word,"Hello, strings.");
    /* strcpy (and many other string.h functions) will place
       the nul termination character ('\0' aka ASCII 0) in the correct
       place */

    /* percent s is the placeholder for strings */
    printf("%s\n", word);

    /* strlen tells you how many characters are in the string,
       not counting the nul termination character */
    printf("Number of characters: %zu\n",strlen(word));
    /* zu is used as the placeholder because technically 
       strlen returns a size_t.  %d would work most of 
       the time but it's not official */

    /* these are immutable */
    char *string = "Bonjour";
    char *greeting = "Bonjour";
    /* and they will often point to the same address in the 
       data segment, though this depends on compiler and optimations
       (the practice is called "string literal pooling") */
    /* this is mutable */
    char salutation[] = "Bonjour";

    /* proof of the above */
    printf("%p %p %p\n", string, greeting, salutation);

    /* the pointers themselves can be assigned to other 
       char addresses (i.e. other strings in this case) */
    greeting = salutation;

    /* proof of the above */
    printf("%p %p %p\n", string, greeting, salutation);

    printf("%s has %d letters in it\n", string, strlen(string));

    /* demonstration that char array word is mutable */
    /* what is the reason for the loop condition? */
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(word[i] == '.') word[i] = '!';
        printf("%c ", word[i]);
        
    }

    /* the string called "string" is NOT mutable,
       and attempting the following as undefined 
       behavior */
    //string[0] = 'T';

    printf("\n%s", string);

    /* strcat is how you concatenate (literally: "chaining together")*/
    char combine[20] = "concat";
    strcat(combine, "enate");

    printf("\n%s\n", combine);

    /* strncpy */
    char source[20] = "copythisstring";
    char destination[20];

    strncpy(destination, source, 19);
    destination[19] = '\0';

    printf("DESTINAION: %s\n", destination);

    /* strdup is not standard C, but is often available 
       unlike the other string functions, it creates space
       for the string is it assigned */
    char *dupe = strdup("Hello, world!");

    printf("%s, %zu\n", dupe, strlen(dupe));

    /* but the created space is dynamic and should be freed
       when you're done using it */
    free(dupe);

    return 0;
}