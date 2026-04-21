#include<stdio.h>
#include<string.h>

#define SIZE 10
#define NUM_COMPONENTS 3

enum CompositionType {
    ICE,
    SILICATE,
    IRON
};

typedef struct asteroid
{
    char id[5];
    float distance;
    float mass;
    int composition[NUM_COMPONENTS];
    
} ASTEROID_T;

void print_asteroid(const struct asteroid *asteroid);
void print_asteroids(const ASTEROID_T *asteroids, int size);

int main(void)
{
    ASTEROID_T asteroids[SIZE] = {0};

    strcpy(asteroids[0].id,"1004");
    asteroids[0].distance = 2.45f;
    asteroids[0].mass = 1850.0f;
    asteroids[0].composition[ICE] = 15;
    asteroids[0].composition[SILICATE] = 55;
    asteroids[0].composition[IRON] = 30;

    print_asteroids(asteroids, SIZE);

    return 0;
}

void print_asteroid(const struct asteroid *pasteroid)
{
    printf("Asteroid ID %s:\n", pasteroid->id);
    printf("\tDistance: %.3f AU\n", pasteroid->distance);
    printf("\tMass: %.3f kg\n", pasteroid->mass);
    printf("\tIce: %d%%, Silicate: %d%%, Iron: %d%%\n", 
           pasteroid->composition[ICE], 
           pasteroid->composition[SILICATE], 
           pasteroid->composition[IRON]);
}

void print_asteroids(const ASTEROID_T *asteroids, int size)
{
    for(int i = 0; i < size; i++)
    {
        print_asteroid(&asteroids[i]);
    }
}