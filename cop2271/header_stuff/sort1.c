#include<stdio.h>
#include "mysort.h"

long long number_of_passes = 0;
int number_of_swaps = 0;

void print_number_of_swaps();

void sort(int *numbers, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++) 
        {
            number_of_passes++;
            if(numbers[j] > numbers[j+1])
            {
                number_of_swaps++;
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    print_number_of_swaps();
}

void print_number_of_swaps()
{
    printf("The number of swaps was %d\n", number_of_swaps);
}