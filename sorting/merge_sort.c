#include <stdio.h>
#include <stdlib.h>

/* merge sort */
/*
* Recursion Depth : O(log N)
* Merge Operations per level : O(N)
* Time Complexity : O(N log N)
*/

static void merge(int arr[], int low, int mid, int high, int sorted[]) {
	int lp = low;
	int hp = mid + 1;
	int sp = low;

	while (lp <= mid && hp <= high) {
		if (arr[lp] <= arr[hp]) { // stable sort 유지를 위해 low array에서 먼저 추출
			sorted[sp++] = arr[lp++];
		}
		else {
			sorted[sp++] = arr[hp++];
		}
	}

	while (lp <= mid) {
		sorted[sp++] = arr[lp++];
	}

	while (hp <= high) {
		sorted[sp++] = arr[hp++];
	}

	for (int i = low; i <= high; i++) {
		arr[i] = sorted[i];
	}
}

static void sort(int arr[], int low, int high, int sorted[]) {
	if (low >= high) return; // Conquer : 혼자 남은 데이터는 이미 정렬된 상태로 간주

	// Divide : 데이터의 원소가 1개만 남을 때까지 절반으로 나눔
	int mid = low + (high - low) / 2;
	sort(arr, low, mid, sorted);
	sort(arr, mid + 1, high, sorted);
	
	// Merge : 나뉘었던 두 부분을 순차적으로 합침
	merge(arr, low, mid, high, sorted);
}

int mergeSort(int arr[], int size) {
	// 임시 배열 할당은 1회만 실행
	// 공간 복잡도 : O(n)
	int* sorted = (int*)malloc(sizeof(int) * size);
	if (size < 0 || !sorted) return 0;

	sort(arr, 0, size - 1, sorted);
	
	free(sorted);
	return 1;
}

int main() {
	int a[10] = {10, 9, 8, 7, 6, 5, 4, 1, 2, 3};
	mergeSort(a, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}
