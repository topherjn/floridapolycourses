#include<stdio.h>
void foo();

int main(void)
{
    foo();

    return 0;
}

void foo()
{
    foo();
}