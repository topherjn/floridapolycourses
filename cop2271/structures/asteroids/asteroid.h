#define SIZE 10
#define NUM_COMPONENTS 3

enum CompositionType {
    ICE,
    SILICATE,
    IRON
};

struct asteroid
{
    char id[5];
    float distance;
    float mass;
    int composition[NUM_COMPONENTS];
    
};

typedef struct asteroid ASTEROID_T;

void print_asteroid(const ASTEROID_T *asteroid);
void print_asteroids(const ASTEROID_T *asteroids, int size);