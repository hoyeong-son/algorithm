#include <stdio.h>
#include <stdbool.h>

// 이전 stack_implementation을 그대로 가져다 사용함.
// LIFO 구조만 사용하면 array를 쓰든 재귀함수를 쓰든 문제 해결 방법은 많다.

typedef struct StackType {
	char data[10001];
	int top_idx;
} StackType;

bool isEmpty(StackType *stk) {
	// 논리 연산자는 바로 bool 혹은 int로 return해도 된다.
	return stk->top_idx == -1;
}

void push(StackType *stk, char c) {
	stk->data[++(stk->top_idx)] = c;
}

void pop(StackType *stk) {
	// top_idx가 어디까지 유효한 데이터인지만 관리하면 된다.
	// stk->data[(stk->top_idx)--] = '\0';
	stk->top_idx--;
}

char top(StackType *stk) {
	return stk->data[(stk->top_idx)];
}

bool isValid(char *s) {

	StackType stk = { .top_idx = -1 };
	/*

	(문장이 끝날때까지 1, 2 과정 ('\0' 등장 전까지) 순차 반복)
	1. open bracket - push
	2. closed bracket
		2.1. stack empty : invalid 확인
		2.2. top 추출
		2.3. top, closed bracket 비교 검사
			- match -> pop
			- unmatch : invalid 확인
	
	3. unmatched open bracket 검사
		- 존재 시 : invalid
		- 없을 시 : valid 확인
	*/

	for (int i = 0; s[i] != '\0'; i++) {
		// open bracket - push
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			push(&stk, s[i]);
		}
		// closed bracket
		else {
			// stack empty - invalid
			if (isEmpty(&stk)) {
				return false;
			}
			
			// match - pop
			char t = top(&stk);
			if ((s[i] == ')' && t == '(') ||
			    (s[i] == '}' && t == '{') ||
			    (s[i] == ']' && t == '[')) {
				pop(&stk);
			}
			// unmatch - invalid
			else {
				return false;
			}
		}
	}
	
	// check unmatched open bracket
	return isEmpty(&stk);
}

int main() {
	char inputString[10001] = { '\0' };
	
	scanf("%s", inputString);
	
	if (isValid(inputString)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	return 0;
}
