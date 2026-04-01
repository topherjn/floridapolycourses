#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wait_for_step() {
    printf("Press [Enter] to continue, or [q] to quit to menu: ");
    int ch = getchar();
    if (ch == 'q' || ch == 'Q') {
        while (getchar() != '\n'); // Clear the buffer
        printf("\n*** ABORTING DEMO ***\n");
        return 0; // Return 0 to signal an early exit
    }
    if (ch != '\n') {
        while (getchar() != '\n'); // Clear buffer if they typed other random keys
    }
    return 1; // Return 1 to continue
}

void print_array(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void generate_data(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 90 + 10;
    }
}

void demo_bubble_sort(int arr[], int size) {
    printf("\n*** BEGINNING BUBBLE SORT ***\n");
    print_array(arr, size);
    if (!wait_for_step()) return;

    for (int i = 0; i < size - 1; i++) {
        printf("\n--- STARTING PASS %d ---\n", i + 1);
        print_array(arr, size);
        if (!wait_for_step()) return;

        for (int j = 0; j < size - 1; j++) {
            printf("\n  -> Comparing index %d (%d) and index %d (%d)\n", 
                   j, arr[j], j + 1, arr[j + 1]);
            
            if (arr[j] > arr[j + 1]) {
                printf("  -> %d > %d. Swapping!\n", arr[j], arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                print_array(arr, size);
            } else {
                printf("  -> No swap needed.\n");
            }
            if (!wait_for_step()) return;
        }
    }
    printf("\n*** BUBBLE SORT COMPLETE ***\n");
    print_array(arr, size);
}

void demo_selection_sort(int arr[], int size) {
    printf("\n*** BEGINNING SELECTION SORT ***\n");
    print_array(arr, size);
    if (!wait_for_step()) return;

    for (int i = 0; i < size - 1; i++) {
        printf("\n--- STARTING PASS %d (Finding min for index %d) ---\n", i + 1, i);
        print_array(arr, size);
        if (!wait_for_step()) return;

        int min_idx = i;
        printf("\n  -> Assuming current min is at index %d (%d)\n", min_idx, arr[min_idx]);

        for (int j = i + 1; j < size; j++) {
            printf("  -> Scanning index %d (%d). ", j, arr[j]);
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                printf("New minimum found!\n");
            } else {
                printf("Not smaller.\n");
            }
            if (!wait_for_step()) return;
        }

        printf("\n  -> End of pass. Swapping index %d (%d) with index %d (%d)\n", 
               i, arr[i], min_idx, arr[min_idx]);
        
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        
        print_array(arr, size);
        if (!wait_for_step()) return;
    }
    printf("\n*** SELECTION SORT COMPLETE ***\n");
    print_array(arr, size);
}

void demo_insertion_sort(int arr[], int size) {
    printf("\n*** BEGINNING INSERTION SORT ***\n");
    print_array(arr, size);
    if (!wait_for_step()) return;

    for (int i = 1; i < size; i++) {
        printf("\n--- STARTING PASS %d (Evaluating index %d: %d) ---\n", i, i, arr[i]);
        print_array(arr, size);
        if (!wait_for_step()) return;

        int position_found = 0;
        for (int j = i; j > 0 && !position_found; j--) {
            printf("\n  -> Comparing index %d (%d) with left neighbor index %d (%d)\n", 
                   j, arr[j], j - 1, arr[j - 1]);
            
            if (arr[j] < arr[j - 1]) {
                printf("  -> %d < %d. Swapping backward!\n", arr[j], arr[j - 1]);
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                print_array(arr, size);
                if (!wait_for_step()) return;
            } else {
                printf("  -> %d is >= %d. Position found. Ending pass.\n", arr[j], arr[j - 1]);
                position_found = 1;
                if (!wait_for_step()) return;
            }
        }
    }
    printf("\n*** INSERTION SORT COMPLETE ***\n");
    print_array(arr, size);
}

int main() {
    srand(time(NULL));
    int data[5];
    int choice = 0;

    while (choice != 4) {
        printf("\n======================================================\n");
        printf(" SORTING ALGORITHM DEMONSTRATOR\n");
        printf("======================================================\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Quit\n");
        printf("Select an option (1-4): ");

        int items_read = scanf("%d", &choice);
        
        // Unconditionally clear the input buffer after reading
        while (getchar() != '\n');

        if (items_read != 1) {
            printf("Invalid input. Please enter a number.\n");
            choice = 0; // Reset choice so the loop continues safely
        } else if (choice == 1) {
            generate_data(data, 5);
            demo_bubble_sort(data, 5);
        } else if (choice == 2) {
            generate_data(data, 5);
            demo_selection_sort(data, 5);
        } else if (choice == 3) {
            generate_data(data, 5);
            demo_insertion_sort(data, 5);
        } else if (choice != 4) {
            printf("Invalid choice. Please select 1-4.\n");
        }
    }

    return 0;
}