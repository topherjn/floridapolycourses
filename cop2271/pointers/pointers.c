#include<stdio.h>
#include<stdint.h>

void no_swap(int left, int right);
void swap_for_reals(int *left, int *right);

int main(void)
{
    int score = 83;
    int level = 10;

    /* print out the memory locations for the integers */
    printf("%p\n", &score);
    printf("%p\n", &level);

    /* attempt to swap, but not really */
    no_swap(score, level);

    printf("After fake swap:\n");

    printf("Score: %d\n", score);
    printf("Level: %d\n", level);
    
    /* swap for real */
    swap_for_reals(&score, &level);
    
    printf("After real swap:\n");

    printf("Score: %d\n", score);
    printf("Level: %d\n", level);
    

    return 0;
}

void no_swap(int left, int right)
{
    int temp = left;
    left = right;
    right = temp;
}

void swap_for_reals(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

