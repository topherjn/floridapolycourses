#include<stdio.h>

void modify_for_reals(int *param1, int *param2);

int main(void)
{
    int num1 = 0, num2 = 1;

    printf("Value held at num1: %d ", num1);
    printf(" Value held at num2: %d ", num2);


    printf("\nThe address of num1: %p", &num1);
    printf(" The address of num2: %p\n", &num2);

    modify_for_reals(&num1,&num2);

    printf("Value held at num1 after call: %d ", num1);
    printf(" Value held at num2 after call: %d ", num2);
    printf("\n");

    return 0;
}

void modify_for_reals(int *param1, int *param2)
{

    printf("Value held at param1: %d ", *param1);
    printf(" Value held at param2: %d ", *param2);


    printf("\nThe address held in param1: %p", param1);
    printf(" The address held in param2: %p\n", param2);
 
    printf("\nThe address of param1: %p", &param1);
    printf(" The address of param2: %p\n", &param2);

    *param1 = 1337;
    *param2 = 732;

     return;
}
