#include <stdio.h>
#include <math.h>

int is_prime(int n) {
	if (n<2) {
		return 0;
	}
	for(int i=2; i*i<=n; i++) {
		if(n%i==0)
			return 0;
		continue;
	}
	return 1;
}

int main() {
	unsigned n, count;
	while(1) {
		n = count = 0;
		printf("please input n:");
		scanf("%d", &n);
		
		for(int i=0; i<=n; i++)  {
			if(is_prime(i)) {
				printf("%d ", i);
				count ++;
			}
        }
		printf("\nthe count of primes = \t\t%f", ((double)count));
		printf("\nthe n/ln(n) = \t\t\t%f", n/log((double)n));
		printf("\n");
	}
}
