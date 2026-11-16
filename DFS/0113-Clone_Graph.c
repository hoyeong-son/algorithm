#include <stdlib.h>
#include <stdbool.h>

/*
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 */


// Trial-1 : 이웃 노드를 먼저 생성하고 이후의 재귀(DFS) 방문에서 초기화
// 복제가 생성과 복사로 분리해 처리
// 우선 생성해버리는 이유로 cloned_nodes가 visited의 역할을 하지 못함
/*
void DFS(struct Node *node, struct Node **cloned_nodes, bool *visited) {
	if (visited[node->val]) { return; }
	
	// 방문 처리
	visited[node->val] = true;

	// 현재 노드 복사
	struct Node* clone = cloned_nodes[node->val];
	clone->val = node->val;
	clone->numNeighbors = node->numNeighbors;
	clone->neighbors = malloc(node->numNeighbors * sizeof(struct Node*));
	
	// 이웃 노드 생성 및 연결
	for (int i = 0; i < node->numNeighbors; i++) {
		int key = (node->neighbors)[i]->val;
		if (cloned_nodes[key] == NULL) {
			cloned_nodes[key] = malloc(sizeof(struct Node));
		}
		(clone->neighbors)[i] = cloned_nodes[key];
	}

	// 이웃 노드 DFS 탐색
	for (int i = 0; i < node->numNeighbors; i++) {
		DFS((node->neighbors)[i], cloned_nodes, visited);
	}
}

struct Node* cloneGraph(struct Node *node) {
	if (node == NULL) { return NULL; }

	struct Node* cloned_nodes[101];
	for (int i = 1; i <= 100; i++) {
		cloned_nodes[i] = NULL;
	}
	cloned_nodes[node->val] = malloc(sizeof(struct Node));
	
	bool visited[101] = { 0 };

	DFS(node, cloned_nodes, visited);

	return cloned_nodes[node->val];
}
*/

// Trial-2
struct Node* DFS(struct Node *node, struct Node **cloned_nodes) {
	// 이미 복제된 노드라면 기존 복제본 반환
	if (cloned_nodes[node->val] != NULL) {
		return cloned_nodes[node->val];
	}

	// 현재 노드 복제
	struct Node* clone = malloc(sizeof(struct Node));
	clone->val = node->val;
	clone->numNeighbors = node->numNeighbors;
	clone->neighbors = malloc(node->numNeighbors * sizeof(struct Node*));

	// 복제본 등록
	cloned_nodes[node->val] = clone;

	// 이웃 노드의 복제본을 재귀적으로 생성하거나 기존 복제본을 가져와 연결
	for (int i = 0; i < node->numNeighbors; i++) {
		(clone->neighbors)[i] = DFS((node->neighbors)[i], cloned_nodes);
	}

	return clone;
}

struct Node* cloneGraph(struct Node *node) {
	if (node == NULL) { return NULL; }

	struct Node* cloned_nodes[101];

	for (int i = 1; i <= 100; i++) {
		cloned_nodes[i] = NULL;
	}

	struct Node *clone = DFS(node, cloned_nodes);

	return clone;
}
