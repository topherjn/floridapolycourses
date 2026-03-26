#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "mysort.h"

long long number_of_passes = 1;

// Function to check if the array is sorted in ascending order
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array randomly
void shuffle(int arr[], int n) {
    number_of_passes++;
    for (int i = 0; i < n; i++) {
        
        int randIndex = rand() % n;
        int temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }
    
}

// Bogosort: keep shuffling until sorted
void sort(int arr[], int n) {
    while (!isSorted(arr, n)) {
        shuffle(arr, n);
    }
}