#include <stdio.h>

#define GRID_COLS 25
#define GRID_ROWS 25
#define ALIVE '*'
#define DEAD '.'

/* This function sets the specified cell at x,y to the specified state */
void setcell(char* grid, int x, int y, int state) {
    grid[y * GRID_COLS + x] = state;
}

/* This function returns the state of the grid at x,y */
char getcell(char* grid, int x, int y) {
    return grid[y * GRID_COLS + x];
}

int main(void) {
    char grid[GRID_COLS * GRID_ROWS];
    setcell(grid, 10, 10, ALIVE);

    return 0;
}
