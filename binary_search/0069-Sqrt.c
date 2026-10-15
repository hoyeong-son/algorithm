#include <stdio.h>

int mySqrt(int x) {
	int low = 0;
	int high = 46340; // floor(sqrt(INT_MAX)) = 46340, preventing (mid * mid) overflow

	while (low <= high) {
		int mid = low + ((high - low) / 2);
		int mid_square = mid * mid;
		if (mid_square < x) low = mid + 1;
		else if (mid_square > x) high = mid - 1;
		else return mid;
	}

	return high;
}

int main() {
	int result = mySqrt(2147483647);
	printf("%d\n", result);

	return 0;
}
