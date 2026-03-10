#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"mysort.h"

#define ARRAY_SIZE 12

/* function to print array */
void print_array(int *array, int size);

int main(void)
{
    srand((unsigned int) time(NULL));

    int array[ARRAY_SIZE];

    /* initialize array with random integers, 1 to 100 */
    for(int i=0; i<ARRAY_SIZE;i++) 
       array[i] = rand() % 100 + 1;

    //printf("i == %d outside of the loop.\n", i);

    //for(int i=0;i<ARRAY_SIZE;i++) array[i] = i;
    

    /* show array before sort */
    printf("Unsorted array: ");
    print_array(array, ARRAY_SIZE);

    /* call the sorting procedure */
    sort(array, ARRAY_SIZE);

    /* show the successful sort */
    printf("Sorted array: ");
    print_array(array, ARRAY_SIZE);

    printf("Sorted in %llu passes\n", number_of_passes);

    return 0;
}

void print_array(int *array, int size)
{
    for(int i = 0; i < size; i++) 
        printf("%d ", array[i]);
    printf("\n");
}