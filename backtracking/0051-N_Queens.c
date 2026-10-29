#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static char*** solutions;
static int solution_count;
static int solution_cap;

static int* col_at_row;
static int N;

char*** solveNQueens(int n, int* return_size, int** return_column_sizes);
static void dfs(int row);
static bool is_valid(int row, int col);
static void add_solution();

char*** solveNQueens(int n, int* return_size, int** return_column_sizes) {
	solution_cap = 16;
	solutions = (char***)malloc(sizeof(char**) * solution_cap);	
	solution_count = 0;

	col_at_row = (int*)malloc(sizeof(int) * n);
	N = n;

	dfs(0);

	free(col_at_row);

	*return_size = solution_count;
	*return_column_sizes = (int*)malloc(sizeof(int) * solution_count);
	for (int i = 0; i < solution_count; i++) {
		(*return_column_sizes)[i] = n;
	}

	return solutions;
}

static void dfs(int row) {
	if (row == N) {
		add_solution();
		return;
	}
	
	for (int col = 0; col < N; col++) {
		if (is_valid(row, col)) {
			col_at_row[row] = col;
			dfs(row + 1);
		}
	}
	
}

static bool is_valid(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (col_at_row[i] == col || abs(col_at_row[i] - col) == row - i)
		{ return false; }
	}
	
	return true;
}

static void add_solution() {
	if (solution_count == solution_cap) {
		solution_cap *= 2;
		solutions = (char***)realloc(solutions, sizeof(char**) * solution_cap);
	}

	char **new_board = (char**)malloc(sizeof(char*) * N);

	for (int row = 0; row < N; row++) {
		char *new_row = (char*)malloc(sizeof(char) * (N + 1));
		for (int i = 0; i < N; i++) {
			new_row[i] = '.';
		}
		new_row[N] = '\0';
		new_row[col_at_row[row]] = 'Q';

		new_board[row] = new_row;
	}

	solutions[solution_count++] = new_board;
}
