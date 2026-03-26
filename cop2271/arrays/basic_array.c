#include<stdio.h>
#include<math.h>

void print_array(int arr[], int size);
void show_array(float *arr, int size);
void pointer_print_arrays(char *parry, int size);

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


    /* use an array initializer list to populate with floats */
    float measurements[] = {2.3,-1.0,3,3.14, -10.1};

    /* array of characters (!= a string) */
    char characters[] = {'c', ':', '.', '\\', '#'};

    /* traverse, the array, printout out each value */
    print_array(num_array, ARRAY_SIZE);
    show_array(measurements,ARRAY_SIZE);
    pointer_print_arrays(characters, ARRAY_SIZE);

    printf("But sizeof() works in main: %d\n", sizeof(num_array));
    printf("(size of array X size of int == 5 * 4 bytes)\n");

    printf("We need to learn about C-type strings: %s\n", characters);

    /* finally, we can kludge element initialization (zeroing out) */
    double values[100] = {0};

    for(int i = 0; i < 100; i++) printf("[%.1f] ", values[i]);

    return 0;
}

void print_array(int *arr, int size)
{
    printf("The old-fashioned normal way:\n");

    for(int i = 0; i < size; ++i)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void show_array(float ar[], int size)
{
    printf("The brackets way plus a silly loop and increment\n");

    int i = 0;

    while(i < size)
    {
        float x = ar[i++];
        printf("%.3f\n", x);
       
    }
}

void pointer_print_arrays(char *parry, int size)
{
    printf("The pointer way:\n");

    for(char *p = parry; p < parry + size; p++)
    {
        printf("%c\n", *p);
    }

    printf("N.B. sizeof() doesn't give size due to \"array decay\"\n");
    printf("%d\n", sizeof(parry));
    printf("(The size of a pointer in C is always 8 bytes)\n");
}