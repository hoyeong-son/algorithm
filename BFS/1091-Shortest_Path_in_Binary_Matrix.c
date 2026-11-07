#include <stdio.h>

// BFS
// 탐색 종료 조건 : n-1, n-1 방문

typedef struct {
	int r;
	int c;
} Point;

int shortestPathBinaryMatrix(int** grid, int grid_size, int* grid_col_size) {
	if (grid[0][0] == 1) { return -1; }
	if (grid_size == 1) { return 1; }

	Point queue[10000];
	int front = 0, rear = 0;
	queue[rear++] = (Point){0, 0};
	grid[0][0] = 1;

	int level_count = 0;

	int dr[8] = {1, -1, 0, 0, 1, 1, -1, -1};
	int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};

	while (front < rear) {
		level_count++;
		int level_size = rear - front;
		while (level_size > 0) {
			// dequeue
			int row = queue[front].r, col = queue[front].c;
			front++;

			// enqueue, 방문처리, 종료 검사
			for (int i = 0; i < 8; i++) {
				int new_r = row + dr[i], new_c = col + dc[i];
				if (new_r >= 0 && new_r < grid_size && new_c >= 0 && new_c < grid_size && grid[new_r][new_c] == 0) {
					if (new_r == grid_size - 1 && new_c == grid_size - 1) { return level_count + 1; }
					queue[rear++] = (Point){new_r, new_c};
					grid[new_r][new_c] = 1;
				}
			}

			level_size--;
		}
	}

	return -1;
}

