#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static int* col_at_row;
static int N;
static int solution_count;

static bool is_valid(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (col_at_row[i] == col || abs(col_at_row[i] - col) == row - i) {
			return false;
		}
	}

	return true;
}

static void dfs(int row) {
	if (row == N) {
		solution_count++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (is_valid(row, col)) {
			col_at_row[row] = col;
			dfs(row + 1);
		}
	}
}

int totalNQueens(int n) {
	N = n;
	col_at_row = (int*)malloc(sizeof(int) * n);
	solution_count = 0;

	dfs(0);

	free(col_at_row);

	return solution_count;
}
