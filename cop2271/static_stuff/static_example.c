#include <stdio.h>

void count_visits() {
    
    static int counter = 0; 

    counter++;
    printf("This function has been called %d times.\n", counter);
}

int main() {
    count_visits(); 
    count_visits(); 
    count_visits(); 

    return 0;
}