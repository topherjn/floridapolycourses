#include <stdio.h>

#define SIZE 10

/* ---------------------------------------------------------------------------
 * initialize_sensors
 * Populates all four parallel arrays with asteroid telemetry data.
 * Parameters:
 *   ids[]       - asteroid ID numbers
 *   distances[] - distance from Earth in AU
 *   masses[]    - mass in kg (x10^9)
 *   comp[][3]   - composition: columns are Ice%, Silicate%, Iron%
 *   size        - number of asteroids
 * --------------------------------------------------------------------------- */
void initialize_sensors(int ids[], float distances[], float masses[],
                         int comp[][3], int size) {
    // Asteroid IDs
    ids[0]=1004; ids[1]=1007; ids[2]=1001; ids[3]=1009; ids[4]=1003;
    ids[5]=1006; ids[6]=1000; ids[7]=1008; ids[8]=1002; ids[9]=1005;

    // Distances in AU — closest is index 3 (0.31), not index 0
    distances[0]=2.45; distances[1]=5.80; distances[2]=1.17;
    distances[3]=0.31; distances[4]=3.92; distances[5]=4.66;
    distances[6]=1.88; distances[7]=6.10; distances[8]=2.73;
    distances[9]=0.95;

    // Masses in kg (x10^9) — most massive is index 1, not index 0
    masses[0]=1850.0; masses[1]=4200.0; masses[2]=730.0;
    masses[3]=310.0;  masses[4]=2960.0; masses[5]=510.0;
    masses[6]=1420.0; masses[7]=3780.0; masses[8]=890.0;
    masses[9]=2100.0;

    // Composition: Ice%, Silicate%, Iron% — each row sums to 100
    comp[0][0]=15; comp[0][1]=55; comp[0][2]=30;
    comp[1][0]=5;  comp[1][1]=20; comp[1][2]=75;
    comp[2][0]=40; comp[2][1]=45; comp[2][2]=15;
    comp[3][0]=60; comp[3][1]=30; comp[3][2]=10;
    comp[4][0]=10; comp[4][1]=35; comp[4][2]=55;
    comp[5][0]=25; comp[5][1]=50; comp[5][2]=25;
    comp[6][0]=35; comp[6][1]=40; comp[6][2]=25;
    comp[7][0]=5;  comp[7][1]=15; comp[7][2]=80;
    comp[8][0]=50; comp[8][1]=35; comp[8][2]=15;
    comp[9][0]=20; comp[9][1]=45; comp[9][2]=35;
}

/* ---------------------------------------------------------------------------
 * find_closest
 * Finds and returns the INDEX of the asteroid with the smallest distance.
 * Parameters:
 *   distances[] - distance array
 *   size        - number of asteroids
 * Returns: index of the closest asteroid
 * --------------------------------------------------------------------------- */
int find_closest(float distances[], int size) {
    // TODO: Track the index of the minimum distance found so far.
    //       Loop through the array and update it when you find something smaller.
    //       Return the index (not the distance value itself).
    return 0; // replace this
}

/* ---------------------------------------------------------------------------
 * sort_threats
 * Sorts all four arrays in DESCENDING order by mass using Selection Sort.
 * Whenever two masses are swapped, the corresponding ids, distances,
 * and ENTIRE ROW of comp must be swapped to keep the data linked.
 * Parameters: all four arrays and size
 * --------------------------------------------------------------------------- */
void sort_threats(int ids[], float distances[], float masses[],
                  int comp[][3], int size) {
    // TODO: Outer loop — find the position of the maximum mass
    //       in the unsorted portion (indices i through size-1).
    //
    //       Inner loop — scan for the max_idx.
    //
    //       If max_idx != i, perform four swaps:
    //         1. Swap masses[i]     and masses[max_idx]
    //         2. Swap distances[i]  and distances[max_idx]
    //         3. Swap ids[i]        and ids[max_idx]
    //         4. Loop k from 0 to 2: swap comp[i][k] and comp[max_idx][k]
}

/* ---------------------------------------------------------------------------
 * print_grid
 * Prints the full sorted asteroid list, one asteroid per line.
 * Parameters: all four arrays and size
 * --------------------------------------------------------------------------- */
void print_grid(int ids[], float distances[], float masses[],
                int comp[][3], int size) {
    // TODO: Loop through all asteroids and printf each one.
    //       Format: ID: %d, Dist: %.2f, Mass: %.2f, Ice: %d%%, Silicate: %d%%, Iron: %d%%
    //       Access composition columns as comp[i][0], comp[i][1], comp[i][2]
}

/* ---------------------------------------------------------------------------
 * main
 * --------------------------------------------------------------------------- */
int main(void) {
    // Array declarations — do not modify these
    int   ids[SIZE];
    float distances[SIZE];
    float masses[SIZE];
    int   composition[SIZE][3];

    // Step 1: Load data
    initialize_sensors(ids, distances, masses, composition, SIZE);

    // Step 2: Find and report the closest threat
    int closest = find_closest(distances, SIZE);
    printf("=== Closest Threat ===\n");
    printf("ID: %d\n",           ids[closest]);
    printf("Distance: %.2f AU\n", distances[closest]);
    printf("Mass: %.2f\n",        masses[closest]);
    printf("Ice: %d%%  Silicate: %d%%  Iron: %d%%\n",
           composition[closest][0],
           composition[closest][1],
           composition[closest][2]);

    // Step 3: Sort by mass and display full grid
    sort_threats(ids, distances, masses, composition, SIZE);
    printf("\n=== Threats Sorted by Mass (Highest to Lowest) ===\n");
    print_grid(ids, distances, masses, composition, SIZE);

    return 0;
}