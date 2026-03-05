#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"mysort.h"

void print_array(int *array, int size);

int main(void)
{
    srand((unsigned int) time(NULL));


    int array[10];

    for(int i=0; i<10;i++) array[i] = rand() % 100 + 1;

    printf("Unsorted array: ");
    print_array(array, 10);

    sort(array, 10);

    printf("Sorted array: ");
    print_array(array, 10);

    return 0;
}

void print_array(int *array, int size)
{
    for(int i = 0; i < 10; i++) 
        printf("%d ", array[i]);
    printf("\n");
}