#include<stdio.h>
#include<string.h>

struct fraction
{
    int numerator;
    int denominator;
};

typedef struct student
{
    char name[10];
    double gpa;
} STUDENT_T;

int main(void)
{
    
    struct fraction half;

    half.numerator = 1;
    half.denominator = 2;

    printf("%d/%d\n", half.numerator, half.denominator);

    STUDENT_T s;
    strcpy(s.name,"Paul");
    s.gpa = 3.95;

    printf("%s %.3f\n", s.name, s.gpa);

    struct student *p = &s;

    printf("%s %.3f\n", p->name, p->gpa);

    return 0;
}