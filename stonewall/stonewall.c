#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int stone_wall ( int H[], int N ) {
		int i, j, count;
		count = N;
		int* b = (int*)malloc(N*sizeof(int));
		memset(b, 0, N);

		b[0] = H[0];
		j=0;


		for (i=1; i<N; i++) {
				while(j>=0) {
						if (b[j] == H[i]) {
								count--;
								break;
						}
						else if (b[j] > H[i]) {
								b[j--] = 0;
						}
						else {  /* b[j] < H[i] */
								b[++j] = H[i];
								break;
						}
				}
				b[++j] = H[i];
		}
		return count;
}


int main() {
		int H[10] = {4,5,6,7,8,8,7,6,5,4};
		int result = stone_wall(H, 10);
		printf("%d\n", result);

}
