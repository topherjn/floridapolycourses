#include <stdio.h>

void print_matrix(int matrix[][3]);
void print_3Dmatrix(int matrix[][3][4]);

int main(void)
{
    int matrix[2][3];

    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            matrix[row][col] = col;
        }
    }

    print_matrix(matrix);

    int matrix3D[2][3][4];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++)
                matrix3D[i][j][k] = i + j + k;  // fixed

    print_3Dmatrix(matrix3D);

    return 0;
}

void print_matrix(int matrix[][3])
{
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void print_3Dmatrix(int matrix[][3][4])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Layer %d:\n", i);
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}