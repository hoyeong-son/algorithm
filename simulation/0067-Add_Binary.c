#include <string.h>
#include <stdlib.h>

// 전가산기의 회로도를 흉내낸 코드이다.
// (a xor b) xor C_in : Sum
// (a and b) or ((a xor b) and C_in) : C_out

char* addBinary(char* a, char* b) {
	char* pa = a + strlen(a) - 1;
	char* pb = b + strlen(b) - 1;
	
	int max_length = (strlen(a) > strlen(b) ? strlen(a) : strlen(b));
	char* result = malloc(max_length + 2);
	char* presult = result;

	char carry = 0;

	while (pa >= a || pb >= b || carry) {
		char bit_a = (pa >= a) ? (*pa-- - '0') : 0;
		char bit_b = (pb >= b) ? (*pb-- - '0') : 0;
		
		// Sum
		char bit_p = bit_a ^ bit_b ^ carry;
		// Carry_out
		carry = (bit_a & bit_b) | ((bit_a ^ bit_b) & carry);

		*presult = (char)(bit_p + '0');
		presult++;
	}
	
	*presult = '\0';

	char* left = result;
	char* right = presult - 1;
	while (left < right) {
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}

	return result;
}
