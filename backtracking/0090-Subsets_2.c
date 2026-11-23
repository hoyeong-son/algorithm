#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/* 시간복잡도 최악: O(n * 2^n) */

/*
 * 동일한 원소들에 대해서는 앞선 원소가 선택되지 않은 상태에서 뒤의 원소만 선택하는 경우를 가지치기한다.
 * 해당 문제에선 원소의 값이 -10 ~ 10으로 제한되므로 각 값의 선택 여부를 기록하는 별도의 배열을 사용하는 것도 가능하다.
 * 하지만 일반적인 경우에는 이 방식이 불가능하다.
 * 따라서 정렬을 하여 같은 원소들이 연속되게 배치되도록 만들었다.
 */

typedef struct {
	int* nums;
	int nums_size;
	int* return_column_sizes;
	int** results;
	int results_count;
} DFSArgs;

// prev_used : 상태 공간 트리 직전 단계의 선택 여부를 기록
void DFS(DFSArgs* args, uint16_t mask, int depth, bool prev_used) {
	if (args->nums_size == depth) {
		int element_count = 0;
		for (int i = 0; i < args->nums_size; i++) {
			if (mask & (1U << i)) {
				element_count++;
			}
		}
		int* subset = malloc(element_count * sizeof(int));
		
		int idx = 0;
		for (int i = 0; i < args->nums_size; i++) {
			if (mask & (1U << i)) {
				subset[idx++] = args->nums[i];
			}
		}

		args->results[args->results_count] = subset;
		(args->return_column_sizes)[args->results_count] = element_count;
		(args->results_count)++;
		return;
	}
	
	DFS(args, mask, depth + 1, false);

	if (depth > 0 && args->nums[depth] == args->nums[depth - 1] && !prev_used) {
		return;
	}
	DFS(args, mask | (1U << depth), depth + 1, true);
}

int cmp_asc(const void* a, const void* b) {
	int x = *(const int*)a;
	int y = *(const int*)b;
	return (x > y) - (x < y);
}

int** subsetsWithDup(int* nums, int nums_size, int* return_size, int** return_column_sizes) {
	qsort(nums, nums_size, sizeof(int), cmp_asc);

	int max_size = 1 << nums_size;
	int** results = malloc(max_size * sizeof(int*));
	*return_column_sizes = malloc(max_size * sizeof(int));

	DFSArgs args = {nums, nums_size, *return_column_sizes, results, 0};
	DFS(&args, 0, 0, false);

	*return_size = args.results_count;

	return results;
}
