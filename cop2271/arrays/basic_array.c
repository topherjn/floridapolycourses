#include<stdio.h>
#include<math.h>

int main(void)
{
    int num_array[5];

    num_array[0] = 23;
    num_array[1] = -45;
    num_array[2] = 100;
    num_array[3] = (int) (pow(2, 31) - 1);
    num_array[4] = 0;

    printf("%d\n", num_array[3]);

    return 0;
}