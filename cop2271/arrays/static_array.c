#include <stdio.h>

int *demo_static_array();  
void print_array(int[], int);

int main(void)
{
    int *some_array = demo_static_array(); 

    print_array(some_array, 3);

    some_array = demo_static_array();  

    print_array(some_array, 3);

    return 0;
}

int *demo_static_array()
{
    static int a_static_array[] = {10, 20, 30};

    a_static_array[0]++;

    return a_static_array;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("demo_array[%d] = [%d]\n", i, array[i]);
    }
}