#include<stdio.h>

void reverse_print(char str[], int index);
int count_paths(int rows, int cols);
int peasant_multiply(int a, int b, int accumulator);


int main(void)
{
    char *my_string = "A man, a plan, a canal: Panama.";

    reverse_print(my_string, 0);


    printf("\n%d\n", count_paths(4,5));

    printf("%d\n", peasant_multiply(7,3,0));

    int arr[10];

    cantor(arr, 0, 10 );

    return 0;
}

void reverse_print(char str[], int index) {
    if (str[index] == '\0') return;
    reverse_print(str, index + 1);
    printf("%c", str[index]);
}

int count_paths(int rows, int cols) {
    if (rows == 1 || cols == 1) {
        printf("Row %d, Column %d; returning 1\n", rows, cols);
        return 1;
    }

    printf("Tracing row %d, column %d\n", rows, cols);

    return count_paths(rows - 1, cols) + count_paths(rows, cols - 1);
}

int peasant_multiply(int a, int b, int accumulator) {
    if (a == 0) return accumulator;
    if (a % 2 != 0) accumulator += b;
    return peasant_multiply(a / 2, b * 2, accumulator);
}

