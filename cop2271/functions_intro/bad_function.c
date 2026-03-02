#include<stdio.h>

void process_rectangle(void);
int calculate_rectangle_area(int width, int height); 
    
int main(void)
{
    process_rectangle();

    int width, height;

    printf("Enter the width and height of a rectangle: ");
    scanf("%d%d", &width, &height);

    printf("The area of the rectangle is: %d\n", calculate_rectangle_area(width,height));

    return 0;
}

/* This is awful.  A function should have a single well-defined
task. Interaction with the user should be done elsewhere. */
void process_rectangle() {
    int w, h;

    printf("Enter the height and witdth of a rectangle: ");
    scanf("%d %d", &w, &h);
    int area = w * h;
    printf("The area is %d\n", area);
}

int calculate_rectangle_area(int width, int height) {
    return width * height;
}