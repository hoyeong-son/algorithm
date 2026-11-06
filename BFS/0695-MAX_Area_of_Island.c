#include <stdio.h>

struct Point {
	int r;
	int c;
};

// Dequeue 시점에 방문 처리를 하면, 중복 방문으로 인해 큐에 동일 노드가 여러 번 쌓임
// 해결 : Enqueue와 함께 방문 처리를 하여 중복을 방지함
// 큐에 삽입된 총 노드의 개수(rear)가 섬의 크기

int bfs(int** grid, int row_size, int col_size, int r, int c) {
	int island_size = 0;
	struct Point queue[2500];
	int front = 0, rear = 0;

	queue[rear++] = (struct Point){r, c};
	grid[r][c] = 0;

	while (front < rear) {
		// dequeue
		struct Point cur = queue[front++];
		island_size++;
		
		// enqueue
		if (cur.r + 1 < row_size && grid[cur.r + 1][cur.c] == 1) {
			grid[cur.r + 1][cur.c] = 0;
			queue[rear++] = (struct Point){cur.r + 1, cur.c};
		}
		if (cur.r - 1 >= 0 && grid[cur.r - 1][cur.c] == 1) {
			grid[cur.r - 1][cur.c] = 0;
			queue[rear++] = (struct Point){cur.r - 1, cur.c};
		}
		if (cur.c + 1 < col_size && grid[cur.r][cur.c + 1] == 1) {
			grid[cur.r][cur.c + 1] = 0;
			queue[rear++] = (struct Point){cur.r, cur.c + 1};
		}
		if (cur.c - 1 >= 0 && grid[cur.r][cur.c - 1] == 1) {
			grid[cur.r][cur.c - 1] = 0;
			queue[rear++] = (struct Point){cur.r, cur.c - 1};
		}
	}
	
	return rear;
}

int maxAreaOfIsland(int** grid, int row_size, int* grid_col_size) {
	int col_size = grid_col_size[0];
	int max_island_size = 0;

	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			if (grid[r][c] == 1) {
				int island_size = bfs(grid, row_size, col_size, r, c);
				max_island_size = (max_island_size < island_size) ? island_size : max_island_size;
			}
		}
	}

	return max_island_size;
}
