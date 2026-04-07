#include <stdio.h>

static void swap(int *a, int *b);
static int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);

int main(void) {
    int arr[] = {21,2,13,3,1,5,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quicksort(arr, 0, n - 1);

    printf("\nAfter:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

static inline void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}