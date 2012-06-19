#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 2000;

int main() {
    char* s = (char*)malloc(sizeof(char) * MAX);
    printf("Please input the string:");
    scanf("%s", s);
    
	int i, offset, count, start, length;
	i = offset = count = start = length = 0;
	int size = strlen(s);
	printf("%d %d %s", i, size, s);
	while(i < size) {
		// condition 1, the "aa" type
		offset = 0;
		while(i-offset >= 0 && i+offset+1 <= size-1) {
			if (s[i-offset] == s[i+offset+1]) {
				count++;
				if ((i+offset+1) - (i-offset) > length) {
					start = i-offset;
					length = (i+offset+1) - (i-offset);
				}
				offset++;
				printf("%d", offset);
			}
		}

		// condition 2, the "aba" type
		offset = 0;
		while(i-offset-1 >= 0 && i+offset+1 <= size-1) {
			if (s[i-offset-1] == s[i+offset+1]) {
				count++;
				if ((i+offset+1) - (i-offset-1) > length) {
					start = i-offset-1;
					length = (i+offset+1) - (i-offset-1);
				}
				offset++;
				printf("%d", offset);
			}
		}

		i++;
		printf("%d", i);
	}
	printf("We found %d palindrome in total\n", count);
	printf("The longest palindrome is:");
	for(i=0; i<length; i++) {
		printf("%c", s[start+i]);
	}

    // printf("%s", s);
}
