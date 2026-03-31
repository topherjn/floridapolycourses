#include <stdio.h>

int main()
{
    int grid[2][3] = {{1,2,3},{4,5,6}};

    int *p = (int *) grid;

    for(; p < (int *)grid + 2*3; p++)
    {
        printf("%p: %d\n", p, *p);
    }

    return 0;
}