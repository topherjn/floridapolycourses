#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int roll_die();
double calculate_distance(double x1, double y1, double x2, double y2);
char to_uppercase(char letter);
int is_leap_year(int year);

int main() {
    srand((unsigned int)time(NULL));

    int die_roll = roll_die() + roll_die();

    printf("%d\n", die_roll);

    double dist = calculate_distance(0.0, 0.0, 3.0, 4.0);
    printf("Distance between (0,0) and (3,4): %.2f\n", dist);

    char lower = 'g';
    char upper = to_uppercase(lower);
    printf("Uppercase of %c is %c\n", lower, upper);

    int test_year = 2024;
    int leap_status = is_leap_year(test_year);
    printf("Is %d a leap year? %d\n", test_year, leap_status);

    return 0;
}

int roll_die()
{ return (rand() % 6) + 1; }


double calculate_distance(double x1, double y1, double x2, double y2) {
    double x_diff = x2 - x1;
    double y_diff = y2 - y1;
    return sqrt(pow(x_diff, 2.0) + pow(y_diff, 2.0));
}

char to_uppercase(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter - 32;
    }
    return letter;
}

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}