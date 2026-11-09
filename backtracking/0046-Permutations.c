#include <stdlib.h>
#include <stdbool.h>

/*
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.
*/

typedef struct {
	int* nums;
	int nums_size;
	int** results;
	int result_count;
	int* permutation;
	bool* is_used;
} DFSContext;

void DFS(DFSContext* ctx, int depth) {
	if (depth == ctx->nums_size) {
		// add result
		for (int i = 0; i < ctx->nums_size; i++) {
			ctx->results[ctx->result_count][i] = ctx->permutation[i];
		}
		ctx->result_count++;
		
		return;
	}

	for (int idx = 0; idx < ctx->nums_size; idx++) {
		if (!ctx->is_used[idx]) { // 유효성 검사
			ctx->is_used[idx] = true;
			ctx->permutation[depth] = ctx->nums[idx];

			DFS(ctx, depth + 1);

			ctx->is_used[idx] = false;
		}
	}
}

int** permute(int* nums, int nums_size, int* return_size, int** return_column_sizes) {
	// 정답 개수 산출 (n!)
	*return_size = 1;
	for (int i = 2; i <= nums_size; i++) { (*return_size) *= i; }
	
	// Context 초기화 및 메모리 할당
	DFSContext* ctx = (DFSContext*)malloc(sizeof(DFSContext));
	ctx->nums = nums;
	ctx->nums_size = nums_size;
	ctx->result_count = 0;

	ctx->results = (int**)malloc(sizeof(int*) * (*return_size));
	for (int i = 0; i < (*return_size); i++) {
		ctx->results[i] = (int*)malloc(sizeof(int) * nums_size);
	}

	ctx->permutation = (int*)malloc(sizeof(int) * nums_size);
	ctx->is_used = (bool*)calloc(nums_size, sizeof(bool));

	// 탐색 수행
	DFS(ctx, 0);

	// 반환 데이터 구성
	*return_column_sizes = (int*)malloc(sizeof(int) * (*return_size));
	for (int i = 0; i < (*return_size); i++) {
		(*return_column_sizes)[i] = nums_size;
	}

	int** results = ctx->results;

	// 임시 자원 해제
	free(ctx->permutation);
	free(ctx->is_used);
	free(ctx);

	return results;
}
