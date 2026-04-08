#include<stdio.h>
#include<malloc.h>

/* see slides for byte sizes and padding */
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

    /* extra stuff */
    /* Introduction to or refreshing on C structs and malloc */
    struct FatStruct *fatStructs = (struct FatStruct *) malloc(sizeof(struct FatStruct) * 10);

    int x = 0;

    for(struct FatStruct *p = fatStructs; p < (fatStructs + 10); p++)
    {
        p->d = 1.0;
        p->b = ++x;
        p->a = 'T';
        p->c = 'c';
    }

    for(struct FatStruct *p = fatStructs; p < (fatStructs + 10); p++)
    {
        printf("a: %c, b: %d, c: %c, d: %.1f\n", p->a, p->b, p->c, p->d);
    }

    free(fatStructs);
}