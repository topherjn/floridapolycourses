#include <stdio.h>
#include <stdlib.h>

#define ID_LEN         16
#define LINE_BUF      128
#define NUM_COMPONENTS  3

typedef enum {
    ICE      = 0,
    SILICATE = 1,
    IRON     = 2
} Component;

typedef struct {
    char  id[ID_LEN];
    float distance;                    /* AU */
    float mass;
    int   composition[NUM_COMPONENTS]; /* indexed by Component enum */
} Asteroid;

int count_lines(FILE *fp);
int load_asteroids(FILE *fp, Asteroid *arr, int capacity);


int main(void) {

    FILE *fp = fopen("asteroids.dat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file.\n");
        return 1;
    }

    /* First pass: count lines so malloc gets the exact right size. */
    int count = count_lines(fp);
    rewind(fp);  /* reset cursor to byte 0 for the second pass */

    Asteroid *field = (Asteroid *)malloc(count * sizeof(Asteroid));
    if (field == NULL) {
        fprintf(stderr, "Error: malloc failed.\n");
        fclose(fp);
        return 1;
    }
    
    int loaded = load_asteroids(fp, field, count);
    fclose(fp);

    printf("Loaded %d asteroids.\n\n", loaded);

    for (int i = 0; i < loaded; i++) {
        Asteroid *a = &field[i];
        printf("--- Asteroid %d ---\n", i + 1);
        printf("  ID       : %s\n",      a->id);
        printf("  Distance : %.2f AU\n", a->distance);
        printf("  Mass     : %.2f\n",    a->mass);
        printf("  Ice      : %d%%\n",    a->composition[ICE]);
        printf("  Silicate : %d%%\n",    a->composition[SILICATE]);
        printf("  Iron     : %d%%\n\n",  a->composition[IRON]);
    }

    free(field);
    return 0;
}

/* Count non-empty lines; caller must rewind() after. */
int count_lines(FILE *fp) {
    char line[LINE_BUF];
    int  count = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
        if (line[0] != '\n' && line[0] != '\0')
            count++;
    return count;
}

/* Parse up to 'capacity' asteroids from fp into the array.
   Returns the number of records successfully loaded. */
int load_asteroids(FILE *fp, Asteroid *arr, int capacity) {
    char line[LINE_BUF];
    int  count = 0;
    while (count < capacity && fgets(line, sizeof(line), fp) != NULL) {
        Asteroid *a = &arr[count];
        int fields = sscanf(line, "%15[^,],%f,%f,%d,%d,%d",
                            a->id, &a->distance, &a->mass,
                            &a->composition[ICE],
                            &a->composition[SILICATE],
                            &a->composition[IRON]);
        if (fields == 6)
            count++;
    }
    return count;
}