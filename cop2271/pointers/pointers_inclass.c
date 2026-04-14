#include <stdio.h>

void resetValue(int x) {
    x = 0;
}

int main() {
    
    int status = 100;
    
    printf("Initial status: %d\n", status);
    
    // This call does not modify 'status' in main
    resetValue(status);
    
    printf("Final status:   %d\n", status);
    
    return 0;
}