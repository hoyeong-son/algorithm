#include <stdio.h>

void selection_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[min_idx] > arr[j]) {
				min_idx = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

int main() {
	int a[10] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6};
	selection_sort(a, 10);
	
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}
