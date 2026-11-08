/*
* Return the minimum number of minutes that must elapse until no cell has a fresh orange.
* If this is impossible, return -1.
*/

typedef struct {
	int r;
	int c;
} Point;

int orangesRotting(int** grid, int row_size, int* grid_col_size) {
	int col_size = grid_col_size[0];
	Point queue[100];
	int front = 0, rear = 0;
	int fresh = 0;	

	// 시작점 enqueue, count fresh
	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			if (grid[r][c] == 2) {
				queue[rear++] = (Point){r, c};
			}
			else if (grid[r][c] == 1) {
				fresh++;
			}
		}
	}
	
	if (fresh == 0) { return 0; }
	
	// 다중 시작점 BFS
	int minutes = -1;
	while (front < rear) {
		minutes++;
		int level_size = rear - front;
		while (level_size > 0) {
			// dequeue
			int row = queue[front].r;
			int col = queue[front].c;
			front++;

			// enqueue, visit
			if (row + 1 < row_size && grid[row + 1][col] == 1) {
				grid[row + 1][col] = 2; // visit 처리
				fresh--;
				queue[rear++] = (Point){row + 1, col}; // enqueue
			}
			if (row - 1 >= 0 && grid[row - 1][col] == 1) {
				grid[row - 1][col] = 2;
				fresh--;
				queue[rear++] = (Point){row - 1, col};
			}
			if (col + 1 < col_size && grid[row][col + 1] == 1) {
				grid[row][col + 1] = 2;
				fresh--;
				queue[rear++] = (Point){row, col + 1};
			}
			if (col - 1 >= 0 && grid[row][col - 1] == 1) {
				grid[row][col - 1] = 2;
				fresh--;
				queue[rear++] = (Point){row, col - 1};
			}

			level_size--;
		}
	}

	// fresh 개수를 추적하여 전파 완료 여부를 판단하도록 변경
	/*
	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			if (grid[r][c] == 1) { return -1; }
		}
	}

	if (rear == 0) { return 0; }
	*/

	if (fresh != 0) { return -1; }
	return minutes;
}
