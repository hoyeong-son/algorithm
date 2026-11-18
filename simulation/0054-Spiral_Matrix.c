#include <stdlib.h>

/*
Given an m x n matrix, return all elements of the matrix in spiral order.
1 <= m, n <= 10 : empty matrix 예외 처리 불필요
*/

/* 
 * 핵심 로직:
 * 가로(col_steps) 한 줄을 탐색하면 해당 row는 완료되므로, 
 * 이어지는 세로 탐색 범위(row_steps)가 1 감소한다. (반대 경우도 동일)
 */

typedef struct {
	int r;
	int c;
} Pos;

int* spiralOrder(int** matrix, int matrix_size, int* matrix_col_size, int* return_size) {
	*return_size = matrix_size * (*matrix_col_size);
	int* answer = (int*)malloc(sizeof(int) * (*return_size));
	int answer_count = 0;

	int row_steps = matrix_size;
	int col_steps = *matrix_col_size;
	const int dr[4] = {0, 1, 0, -1};
	const int dc[4] = {1, 0, -1, 0};
	int current_dir = 0;
	Pos current_pos = {0, -1};
	
	while (answer_count < (*return_size)) {
		for (int i = 0; i < col_steps; i++) {
			current_pos.r += dr[current_dir];
			current_pos.c += dc[current_dir];
			answer[answer_count++] = matrix[current_pos.r][current_pos.c];
		}
		row_steps--;
		current_dir = (current_dir + 1) % 4;

		for (int i = 0; i < row_steps; i++) {
			current_pos.r += dr[current_dir];
			current_pos.c += dc[current_dir];
			answer[answer_count++] = matrix[current_pos.r][current_pos.c];
		}
		col_steps--;
		current_dir = (current_dir + 1) % 4;
	}

	return answer;
}
