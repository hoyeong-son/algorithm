#include <stdio.h>

// Definition for singly-linked list
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode *head) {
	struct ListNode *current = head;
	struct ListNode *prev = NULL;
	struct ListNode *next;
	
	while(current) {
		next = current->next; // 다음 노드 보존
		current->next = prev; // 링크 방향 반전
		prev = current; // prev 전진
		current = next; // current 전진
	}
	// while문 최종 상태 : prev = last node, current = NULL
	return prev;
}

int main() {
	struct ListNode *head;
	head = reverseList(head);
}
