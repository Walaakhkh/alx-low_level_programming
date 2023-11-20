#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid
 * @gird: pointer to teh array
 * @height: rows numbers
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0 ; i < height ; i++)
		free(grid[i]);
	free(grid);
}
