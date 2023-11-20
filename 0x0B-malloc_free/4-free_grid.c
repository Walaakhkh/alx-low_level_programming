#include "main.h"

/**
 * free_grid - free memory that previously allocated
 * @grid: pointer to teh array
 * @height: rows number
 */

void free_grid(int **grid, int height)
{
	int x;

	for (x = 0 ; x < height ; x++)
		free(grid[x]);
	free(grid);
}
