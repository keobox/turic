#include <stdio.h>

#define GRID_COLS 25
#define GRID_ROWS 25
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

    return 0;
}

/* This function sets the specified cell at x,y to the specified state */
void setcell(char* grid, int x, int y, int state) {
    grid[cell_to_index(x, y)] = state;
}

/* This function returns the state of the grid at x,y */
char getcell(char* grid, int x, int y) {
    return grid[cell_to_index(x, y)];
}

int main(void) {
    char grid[GRID_COLS * GRID_ROWS];
    setcell(grid, 10, 10, ALIVE);

    return 0;
}
