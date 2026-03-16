#include <stdio.h>

void carpet(char grid[27][28], int row, int col, int size);

void carpet(char grid[27][28], int row, int col, int size) {
    if (size < 3) return;
    
    int sub = size / 3;
    
    for (int r = row + sub; r < row + 2 * sub; r++) {
        for (int c = col + sub; c < col + 2 * sub; c++) {
            grid[r][c] = ' ';
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            carpet(grid, row + i * sub, col + j * sub, sub);
        }
    }
}

int main() {
    char grid[27][28];
    
    for (int r = 0; r < 27; r++) {
        for (int c = 0; c < 27; c++) {
            grid[r][c] = '*';
        }
        grid[r][27] = '\0';
    }
    
    carpet(grid, 0, 0, 27);
    
    for (int r = 0; r < 27; r++) {
        printf("%s\n", grid[r]);
    }
    
    return 0;
}