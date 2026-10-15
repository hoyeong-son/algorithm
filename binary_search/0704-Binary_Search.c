#include <stdio.h>

int search(int* nums, int numsSize, int target) {
	int low = 0;
	int high = numsSize - 1;
	
	while (low <= high) {
		int mid = low + ((high - low) / 2);
       		if (nums[mid] == target) {
            		return mid;
		}
        	else if (nums[mid] < target) {
			low = mid + 1;
        	}
        	else {
            	high = mid - 1;
       		}
    	}

	return -1;
}

int main() {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = i * 2; 
	}

	int result = search(arr, 100, 20);
	printf("index : %d\n", result);	

	return 0;
}
