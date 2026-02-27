#include<stdio.h>

void modify_values(int num1, int num2);

int main(void)
{
    int num1 = 1;
    int num2 = 2;

    modify_values(num1,num2);

    printf("num1: %d and num2: %d in main()\n", num1, num2);

    return 0;
}

void modify_values(int num1, int num2)
{
    num1 = num1 + 100;
    num2 = num2 + 1000;

    printf("num1: %d and num2: %d in modify_values()\n", num1, num2);

    return;
}




