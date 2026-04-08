#include<stdio.h>

struct FatStruct 
{
    char a;
    int b;
    char c;
    double d;
};

struct ThinStruct 
{
    double d;
    int b;
    char a;
    char c;
};

int main()
{

    struct FatStruct fatStruct;

    printf("%d\n", sizeof(fatStruct));

    struct ThinStruct thinStruct;

    printf("%d\n",sizeof(thinStruct));
}