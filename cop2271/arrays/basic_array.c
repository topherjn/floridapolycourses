#include<stdio.h>
#include<math.h>

void print_array(int arr[], int size);
void show_array(int *arr, int size);

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

    /* traverse, the array, printout out each value */
    show_array(num_array,ARRAY_SIZE);

    /* array of characters */
    char symbols[ARRAY_SIZE];

  
    return 0;
}

void print_array(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void show_array(int *ar, int size)
{
    int i = 0;

    while(i < size)
    {
        int x = ar[i++];
        printf("%d\n", x);
       
    }
}