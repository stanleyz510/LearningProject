#include <stdio.h>

unsigned long long factorial(int n) {
	return n==0 ? 1 : n * factorial(n-1);
}

int main() {
	int n;
	while(1) {
		printf("Please input a n for n! :");
		scanf("%d", &n);
		printf("The factorial of %d is %llu\n", n, factorial(n));

	}
}
