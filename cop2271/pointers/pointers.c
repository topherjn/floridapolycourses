#include<stdio.h>
#include<stdint.h>

void no_swap(int left, int right);
void swap_for_reals(int *left, int *right);

int main(void)
{
    int score = 83;
    int level = 10;

    /* print out the memory locations for the integers */
    printf("The addresses of score and level in main():\n");
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

    int *pscore = &score;
    int *qscore = pscore;

    (*qscore)++;

    printf("%d %d\n", *pscore, score);
    

    return 0;
}

void no_swap(int left, int right)
{
    printf("In function (these mem addresses are differnt from score and level):\n");
    printf("%p\n", &left);
    printf("%p\n", &right);
    int temp = left;
    left = right;
    right = temp;
}

void swap_for_reals(int *left, int *right)
{
    printf("For real (the addresses in these parameters are the same as score's and level's):\n");
    printf("%p\n", left);
    printf("%p\n", right);
   
    int temp = *left;
    *left = *right;
    *right = temp;
}

