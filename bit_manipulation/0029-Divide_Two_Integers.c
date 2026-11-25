#include <stdint.h>
#include <stdbool.h>

// restoring division algorithm
// (divisor == 0): 제약 조건이 없다면 예외 처리 필요

int divide(int dividend, int divisor) {
	bool negative_quotient = (dividend < 0) ^ (divisor < 0);
	// dividend, divisor의 절댓값
	uint64_t rem = (dividend < 0) ? (uint64_t)(-(int64_t)dividend) : (uint64_t)dividend;
	uint64_t d = (divisor < 0) ? (uint64_t)(-(int64_t)divisor) : (uint64_t)divisor;
	
	// divisor의 최초 정렬 위치를 상위 32비트로 설정
	d <<= 32;

	uint32_t q = 0;
	for (int i = 0; i < 32; i++) {
		q <<= 1;
		d >>= 1;
		if (rem >= d) {
			rem -= d;
			q |= 1;
		}
	}

	// 0x80000000u(2^31): signed 32비트 정수 범위의 경계값
	// 양수: 0x7FFFFFFF(2^31 - 1)로 대체
	// 음수: -2^31 표현 가능
	if (q == 0x80000000u) {
		return (negative_quotient ? -0x7FFFFFFF - 0x1 : 0x7FFFFFFF);
	}
	
	return (negative_quotient ? -(int)q : (int)q);
}
