#include<stdio.h>
#include<math.h>

int main(void)
{
    const int ARRAY_SIZE = 5;
    /* declare an array of integers */
    int num_array[5];

    /* assign values to the elements */
    num_array[0] = 23;
    num_array[1] = -45;
    num_array[2] = 100;
    num_array[3] = (int) (pow(2, 31) - 1);
    num_array[4] = 0;

    /* print out one element */
    printf("%d\n", num_array[3]);

    /* use an array initializer list to populate with floats */
    float measurements[] = {2.3,-1.0,3,3.14, -10.1};

    /* traverse, the array, printout out each value */
    for(int i = 0; i < 5; i++) 
        printf("num_array[%d] == %.1f\n", i, measurements[i]);

    /* array of characters */
    char symbols[ARRAY_SIZE];

    /* Get array elements from user input */
    for(int i = 0; i < ARRAY_SIZE; i++) 
    {
      printf("Type a symbol: ");
      scanf(" %c", &symbols[i]);  
    }

    /* print out symbols */
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%c", symbols[i]);
    }

    printf("\n");

    return 0;
}