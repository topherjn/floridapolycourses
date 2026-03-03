#include<stdio.h>
int fibo(int nth_fibonacci);

int main(void)
{
    for(int i = 1; i < 20; i++) printf("%d\n", fibo(i));

    double phi = 0.0;

    
    for(int i = 3; i < 20; i++)
    {
        phi = (double) fibo(i) / fibo(i-1);
        printf("%f\n", phi);
    }

    return 0;
}

int fibo(int nth_fibonacci)
{
    /* base cases, i.e. starting place of sequence */
    
    if(nth_fibonacci <= 1) return 0;
    if(nth_fibonacci == 2) return 1;

    /* recursive part */
    return fibo(nth_fibonacci - 1) + fibo(nth_fibonacci -2);
}