#include <stdio.h>
 
int main(void) {
    char buf[256];
    char newtext[256];
 
    /* Read and display */
    FILE *fp = fopen("sample.txt", "r");
    fgets(buf, sizeof(buf), fp);
    fclose(fp);
    printf("File contains: %s\n", buf);
 
    /* Prompt user for text to append */
    printf("Enter text to append: ");
    fgets(newtext, sizeof(newtext), stdin);
 
    /* Append to file */
    fp = fopen("sample.txt", "a");
    fprintf(fp, "%s", newtext);
    fclose(fp);
 
    printf("Done.\n");
    return 0;
}