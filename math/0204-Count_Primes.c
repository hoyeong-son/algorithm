#include <stdio.h>
#include <stdlib.h>

// Constraints : 0 <= n <= 5,000,000

int countPrimes(int n) {
	// char is_not_prime[5000001] = { 0 };

	char *is_prime = (char*)malloc(n+1);
	for (int i = 2; i <= n; i++) {
		is_prime[i] = 1;
	}

	// Sieve of Eratosthenes
	for (int i = 2; i * i <= n - 1; i++) {
		if (is_prime[i] == 0) continue;	

		for (int j = i * i; j <= n - 1; j += i) {
			is_prime[j] = 0;
		}
	}

	// count_prime
	int count = 0;
	for (int i = 2; i <= n - 1; i++) {
		if (is_prime[i] == 1) count++;
	}
	
	free(is_prime);
	return count;
}

int main() {
	int result10 = countPrimes(10);
	printf("%d\n", result10);

	int result0 = countPrimes(0);
	printf("%d\n", result0);
	
	int result1 = countPrimes(1);
	printf("%d\n", result1);
	
	return 0;
}
