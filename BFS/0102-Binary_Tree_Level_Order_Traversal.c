#include <stdio.h>
#include <stdlib.h>

/* Level Order Traversal for Binary Tree */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* return_size, int** return_column_sizes) {
	*return_size = 0;
	if (root == NULL) {
		*return_column_sizes = NULL;
		return NULL;
	}

	int result_capacity = 16;
	int **result = (int**)malloc(sizeof(int*) * result_capacity);
	*return_column_sizes = (int*)malloc(sizeof(int) * result_capacity);
	int result_count = 0;

	struct TreeNode* queue[2000];
	int front = 0, rear = 0;
	queue[rear++] = root;

	// BFS
	while (front != rear) {
		int level_size = rear - front;
		int* level_values = (int*)malloc(sizeof(int) * level_size);

		for (int i = 0; i < level_size; i++) {
			struct TreeNode* node = queue[front++];
			level_values[i] = node->val;
			if (node->left) {
				queue[rear++] = node->left;
			}
			if (node->right) {
				queue[rear++] = node->right;
			}
		}

		if (result_count == result_capacity) {
			result_capacity *= 2;
			result = (int**)realloc(result, sizeof(int*) * result_capacity);
			*return_column_sizes = (int*)realloc(*return_column_sizes, sizeof(int) * result_capacity);
		}

		(*return_column_sizes)[result_count] = level_size;
		result[result_count++] = level_values;
	}

	*return_size = result_count;
	return result;
}
