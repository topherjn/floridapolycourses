#include<stdio.h>
#include"mysort.h"

int main(void)
{
    int array[10] = {3,5,1,7,8,9,4,5,3,6};

    sort(array, 10);

    for(int i = 0; i < 10; i++) 
        printf("%d ", array[i]);

    return 0;
}