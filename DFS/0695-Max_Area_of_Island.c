#include <stdio.h>
#include <stdlib.h>

int dfs(int** grid, int row_size, int col_size, int r, int c) {
	if (r < 0 || r >= row_size || c < 0 || c >= col_size) { return 0; }
	if (grid[r][c] == 0) { return 0; }

	grid[r][c] = 0;

	return 1
		+ dfs(grid, row_size, col_size, r + 1, c)
		+ dfs(grid, row_size, col_size, r - 1, c)
		+ dfs(grid, row_size, col_size, r, c + 1)
		+ dfs(grid, row_size, col_size, r, c - 1);
}

int maxAreaOfIsland(int** grid, int row_size, int* grid_col_size) {
	int max_island_size = 0;

	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < grid_col_size[0]; c++) {
			if (grid[r][c] == 1) {
				int island_size = dfs(grid, row_size, grid_col_size[0], r, c);
				max_island_size = (island_size > max_island_size) ? island_size : max_island_size;
			}
		}
	}

	return max_island_size;
}
