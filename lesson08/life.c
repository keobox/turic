#include <stdio.h>

#define GRID_COLS 20
#define GRID_ROWS 20
#define GRID_CELLS (GRID_COLS*GRID_ROWS)
#define ALIVE '*'
#define DEAD '.'

/* Translate the specified x,y grid point into the index in the
   linear array. This function implements wrapping, so both
   negative and positive coordinates that are out of the grid
   will wrap around */
int cell_to_index(int x, int y) {
    if (x < 0) {
        x = (-x) % GRID_COLS;
        x = GRID_COLS - x;
    }
    if (y < 0) {
        y = (-y) % GRID_ROWS;
        y = GRID_ROWS - y;
    }
    if (x >= GRID_COLS) x = x % GRID_COLS;
    if (y >= GRID_ROWS) y = y % GRID_ROWS;
    return y*GRID_COLS + x;
}

/* This function sets the specified cell at x,y to the specified state */
void set_cell(char* grid, int x, int y, char state) {
    grid[cell_to_index(x, y)] = state;
}

/* This function returns the state of the grid at x,y */
char get_cell(char* grid, int x, int y) {
    return grid[cell_to_index(x, y)];
}

/* Show the grid on the screen, clearing the terminal using the required
   VT100 escape sequence */
void print_grid(char* grid) {
    printf("\x1b[3J\x1b[H\x1b[2J"); // Clear screen
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            printf("%c", get_cell(grid, x, y));
        }
        printf("\n");
    }
}

/* Set all the grid cells to the specified state.
*/
void set_grid(char* grid, char state) {
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            set_cell(grid, x, y, state);
        }
    }
}

/* Return the numbers of living neighbors cells near x, y. */
int count_living_neighbors(char *grid, int x, int y) {
    int alive = 0;
    for (int yo = -1; yo <= 1; yo++) {
        for (int xo = -1; xo <= 1; xo++) {
            if (xo == 0 && yo == 0) continue;
            if (get_cell(grid, x+xo, y+yo) == ALIVE) alive++;
        }
    }
    return alive;
}

int main(void) {
    // char new_grid[GRID_CELLS];
    char old_grid[GRID_CELLS];
    set_grid(old_grid, DEAD);
    set_cell(old_grid, 10, 10, ALIVE);
    set_cell(old_grid, 10, 11, ALIVE);
    print_grid(old_grid);
    /* BEGIN Test count_living_neighbors */
    /* expected to print 1 */
    printf("%d\n", count_living_neighbors(old_grid, 10, 12));
    /* expected to print 2 */
    printf("%d\n", count_living_neighbors(old_grid, 9, 10));
    /* expected to print 1 */
    printf("%d\n", count_living_neighbors(old_grid, 10, 10));
    /* END   Test count_living_neighbors */
    return 0;
}
