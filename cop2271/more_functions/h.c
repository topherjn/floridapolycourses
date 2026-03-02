#include <stdio.h>

void draw_h(char grid[31][64], int row, int col, int size);

int main() {
    char grid[31][64];
    
    for (int r = 0; r < 31; r++) {
        for (int c = 0; c < 63; c++) {
            grid[r][c] = ' ';
        }
        grid[r][63] = '\0';
    }
    
    draw_h(grid, 15, 31, 8);
    
    for (int r = 0; r < 31; r++) {
        printf("%s\n", grid[r]);
    }
    
    return 0;
}

void draw_h(char grid[31][64], int row, int col, int size) {
    if (size == 0) return;
    
    for (int r = row - size; r <= row + size; r++) {
        grid[r][col - size] = '*';
        grid[r][col + size] = '*';
    }
    for (int c = col - size; c <= col + size; c++) {
        grid[row][c] = '*';
    }
    
    draw_h(grid, row - size, col - size, size / 2);
    draw_h(grid, row + size, col - size, size / 2);
    draw_h(grid, row - size, col + size, size / 2);
    draw_h(grid, row + size, col + size, size / 2);
}