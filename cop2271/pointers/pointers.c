#include<stdio.h>

void no_swap(int left, int right);
void swap_for_reals(int *left, int *right);

int main(void)
{
    int capacity;

    capacity = 4;

    int *p;

    p = &capacity;

    printf("%d\n", *p);

    (*p)++;

    printf("%d\n", capacity);

    *p++;

    printf("%d %d\n", capacity, *p);

    return 0;
}

void no_swap(int left, int right)
{

}

void swap_for_reals(int *left, int *right)
{

}

