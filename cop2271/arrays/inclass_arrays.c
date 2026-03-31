#include<stdio.h>
#include<math.h>

int main(void)
{
    const int ARRAY_SIZE = 5;

    int num_array[ARRAY_SIZE];

    num_array[0] = 23;
    num_array[1] = -45;
    num_array[2] = 51;
    num_array[3] = (int) (pow(2, 31) - 1);
    num_array[4] = 1;


   
    printf("%p\n", num_array);
    printf("%p\n", &num_array[0]);

    printf("%p\n", &num_array[3]);

     
    return 0;
}