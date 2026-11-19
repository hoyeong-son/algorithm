#include <stdint.h>

/*
 * Constraints:
 * 0 <= n <= 2^31 - 2
 * n is even
 */

// Constraints -> MSB, LSB = 0

// Solution-1 : loop
// Time Complexity : O(w)
/*
int reverseBits(int n) {
	int answer = 0;
	for (int i = 1; i <= 15; i++) {
		answer |= ((!!(n & (1 << i))) << (31 - i));
		answer |= ((!!(n & (1 << (31 - i)))) << i);
	}

	return answer;
}
*/

// Solution-2 : Divide and Conquer
// Time Complexity : O(log w)
int reverseBits(int n) {
	uint32_t convert = (uint32_t)n;
	
	convert = (convert & 0x55555555) << 1 | (convert & 0xAAAAAAAA) >> 1;
	convert = (convert & 0x33333333) << 2 | (convert & 0xCCCCCCCC) >> 2;
	convert = (convert & 0x0F0F0F0F) << 4 | (convert & 0xF0F0F0F0) >> 4;
	convert = (convert & 0x00FF00FF) << 8 | (convert & 0xFF00FF00) >> 8;
	convert = convert << 16 | convert >> 16;

	return (int)convert;
}
