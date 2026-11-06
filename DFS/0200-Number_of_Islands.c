#include <stdio.h>

// DFS
void visit_island(char** grid, int row_size, int col_size, int r, int c) {
	if (r < 0 || r >= row_size || c < 0 || c >= col_size) { return; }
	if (grid[r][c] == '0') { return; }

	grid[r][c] = '0';

	visit_island(grid, row_size, col_size, r + 1, c);
	visit_island(grid, row_size, col_size, r - 1, c);
	visit_island(grid, row_size, col_size, r, c + 1);
	visit_island(grid, row_size, col_size, r, c - 1);
}

int numIslands(char** grid, int row_size, int* grid_col_size) {
	int count_islands = 0;
	int col_size = grid_col_size[0];

	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			if (grid[r][c] == '1') {
				count_islands++;
				visit_island(grid, row_size, col_size, r, c);
			}
		}
	}

	return count_islands;
}
