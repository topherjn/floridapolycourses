#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int find_max(int arr[], int size);
int find_max_idx(int arr[], int size);

int main(void)
{
    /* Generate a random array of integers for demo */
    srand((time_t) time(NULL));

    int numbers[8];

    printf("Randomly generated array:\n");

    for(int i = 0; i < 8; i++)
    {
        numbers[i] = (rand() % 201) - 100;
        printf("[%d]", numbers[i]);
    }

    /* Ask for the max value in an array */
    printf("\n\nThe max value is %d\n", find_max(numbers, 8));

    /* Ask for the index of the max value in the array */
    /* (For more complex data types in the future you'll usually do it 
        in this more indirect way)*/
    int index_of_max = find_max_idx(numbers, 8);

    printf("\nnumbers[%d] has the max value of %d\n\n", 
        index_of_max, numbers[index_of_max]);
    return 0;
}

int find_max(int arr[], int size)
{  
    /* if you start at the beginning and check
       each value one at a time, then when you're
       at the beginning the first element is both 
       the max and min value you have seen so far */
    int max = arr[0];

    for(int i = 1; i < size; i++)
        /* first value that is bigger than 
           current max becomes new max*/
        if(arr[i] > max) max = arr[i];

    return max;
}

int find_max_idx(int arr[], int size)
{
    /* same as regular max, but everything is done
       through indices */
    int max_idx = 0;
    
    for(int i = 0; i < size; i++)
        if(arr[i] > arr[max_idx]) max_idx = i;

    return max_idx;
}