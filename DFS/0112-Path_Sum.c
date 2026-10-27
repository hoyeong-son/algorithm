#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}

// DFS - recursion
// 재귀 호출 스택의 LIFO 구조를 통해 깊이 우선 탐색(DFS)가 구현된다.
bool hasPathSum(struct TreeNode* root, int targetSum) {
	if (root == NULL) { return false; }
	
	int current_val = targetSum - (root->val);
	if (root->left == NULL && root->right == NULL) { return current_val == 0; } // leaf node

	return hasPathSum(root->left, current_val) || hasPathSum(root->right, current_val);
}

/*
* 재귀 흐름

* leaf node 까지 재귀 호출이 쌓인다.
* leaf node 에서 current_val == 0 성립 시 true 반환이 앞선 호출로 전파된다.
* 각 호출은 자식 함수의 반환값을 평가하고, true라면 상위 호출에도 true를 반환한다.
* 모든 경로에서 조건을 만족하지 못하면 최종적으로 false를 반환한다.
*/
