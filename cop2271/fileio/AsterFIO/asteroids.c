#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE           10
#define NUM_COMPONENTS 3
#define ID_LEN         9    /* 8 printable chars + NUL terminator */
#define MAX_LINE      128   /* max characters per input line      */
#define DATA_FILE     "asteroids.dat"

/* ===========================================================================
 * ENUM – composition indices
 * =========================================================================== */
typedef enum {
    ICE      = 0,
    SILICATE = 1,
    IRON     = 2
} Component;

/* ===========================================================================
 * STRUCT – one asteroid / threat record
 * =========================================================================== */
typedef struct {
    char  id[ID_LEN];
    float distance;                    /* AU */
    float mass;
    int   composition[NUM_COMPONENTS]; /* indexed by Component enum */
} Asteroid;

/* ===========================================================================
 * FUNCTION PROTOTYPES
 * =========================================================================== */
int       load_sensors(const char *filename, Asteroid *field, int max_size);
Asteroid *find_closest(Asteroid *field, int size);
void      sort_threats(Asteroid *field, int size);
void      print_asteroids(const Asteroid *field, int size);

/* ===========================================================================
 * MAIN
 * =========================================================================== */
int main(void) {
    Asteroid field[SIZE];

    int count = load_sensors(DATA_FILE, field, SIZE);

    printf("Loaded %d asteroid(s) from '%s'.\n\n", count, DATA_FILE);

    Asteroid *closest = find_closest(field, count);
    printf("=== Closest Threat ===\n");
    printf("ID: %s\n",            closest->id);
    printf("Distance: %.2f AU\n", closest->distance);
    printf("Mass: %.2f\n",        closest->mass);
    printf("Ice: %d%%  Silicate: %d%%  Iron: %d%%\n",
           closest->composition[ICE],
           closest->composition[SILICATE],
           closest->composition[IRON]);

    sort_threats(field, count);
    printf("\n=== Threats Sorted by Mass (Highest to Lowest) ===\n");
    print_asteroids(field, count);

    return 0;
}

/* ===========================================================================
 * FUNCTION DEFINITIONS
 * =========================================================================== */

/*
 * load_sensors – open filename and parse comma-separated asteroid records.
 *
 * Expected line format (one asteroid per line):
 *   id,distance_AU,mass,ice%,silicate%,iron%
 *   e.g.  AST-1004,2.45,1850.0,15,55,30
 *
 * Lines whose first non-whitespace character is '#' are treated as comments
 * and skipped. Blank lines are also skipped.
 *
 * Returns the number of records successfully loaded (0 .. max_size).
 * Prints an error message and exits if the file cannot be opened.
 */
int load_sensors(const char *filename, Asteroid *field, int max_size) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: could not open data file '%s'.\n", filename);
        exit(1);
    }

    int   count = 0;
    char  line[MAX_LINE];
    int   line_num = 0;

    while (count < max_size && fgets(line, sizeof(line), fp)) {
        line_num++;

        /* Skip comment lines and blank lines */
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r') {
            continue;
        }

        char  tmp_id[ID_LEN];
        float dist, mass;
        int   ice, silicate, iron;

        int fields = sscanf(line, "%8[^,],%f,%f,%d,%d,%d",
                            tmp_id, &dist, &mass, &ice, &silicate, &iron);

        if (fields != 6) {
            fprintf(stderr,
                    "Warning: line %d malformed (got %d field(s)), skipping: %s",
                    line_num, fields, line);
            continue;
        }

        /* Validate composition percentages sum to 100 */
        if (ice + silicate + iron != 100) {
            fprintf(stderr,
                    "Warning: line %d composition does not sum to 100 (%d+%d+%d), skipping.\n",
                    line_num, ice, silicate, iron);
            continue;
        }

        strncpy(field[count].id, tmp_id, ID_LEN - 1);
        field[count].id[ID_LEN - 1]            = '\0';
        field[count].distance                   = dist;
        field[count].mass                       = mass;
        field[count].composition[ICE]           = ice;
        field[count].composition[SILICATE]      = silicate;
        field[count].composition[IRON]          = iron;

        count++;
    }

    /* If we filled the array, check whether unread data lines remain. */
    if (count == max_size) {
        char peek[MAX_LINE];
        while (fgets(peek, sizeof(peek), fp)) {
            if (peek[0] == '#' || peek[0] == '\n' || peek[0] == '\r') continue;
            fprintf(stderr,
                    "Warning: field capacity (%d) reached; additional records in '%s' were ignored.\n",
                    max_size, filename);
            break;
        }
    }

    fclose(fp);
    return count;
}

/* Returns a pointer to the closest asteroid in the array. */
Asteroid *find_closest(Asteroid *field, int size) {
    Asteroid *min = &field[0];
    for (int i = 1; i < size; i++) {
        if (field[i].distance < min->distance) {
            min = &field[i];
        }
    }
    return min;
}

/* Selection sort – highest mass first. Swaps whole structs. */
void sort_threats(Asteroid *field, int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (field[j].mass > field[max_idx].mass) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            Asteroid temp   = field[i];
            field[i]        = field[max_idx];
            field[max_idx]  = temp;
        }
    }
}

void print_asteroids(const Asteroid *field, int size) {
    const char *labels[NUM_COMPONENTS] = {"Ice", "Silicate", "Iron"};
    for (int i = 0; i < size; i++) {
        printf("ID: %s, Dist: %.2f, Mass: %.2f, ",
               field[i].id, field[i].distance, field[i].mass);
        for (Component k = ICE; k < NUM_COMPONENTS; k++) {
            printf("%s: %d%%", labels[k], field[i].composition[k]);
            if (k < NUM_COMPONENTS - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}
