#include <stdio.h>

#define SIZE 81
#define MAX_DEPTH 5 

void cantor(char grid[MAX_DEPTH][SIZE + 1], int start, int end, int depth) {
    if (end - start < 2 || depth >= MAX_DEPTH) return;
    
    int third = (end - start + 1) / 3;
    int left_mid = start + third;
    int right_mid = end - third;
    
    for (int r = depth; r < MAX_DEPTH; r++) {
        for (int c = left_mid; c <= right_mid; c++) {
            grid[r][c] = ' ';
        }
    }
    
    cantor(grid, start, left_mid - 1, depth + 1);
    cantor(grid, right_mid + 1, end, depth + 1);
}

int main() {
    char grid[MAX_DEPTH][SIZE + 1];
    
    for (int r = 0; r < MAX_DEPTH; r++) {
        for (int c = 0; c < SIZE; c++) {
            grid[r][c] = '_';
        }
        grid[r][SIZE] = '\0';
    }
    
    cantor(grid, 0, SIZE - 1, 1);
    
    for (int r = 0; r < MAX_DEPTH; r++) {
        printf("%s\n", grid[r]);
    }
    
    return 0;
}