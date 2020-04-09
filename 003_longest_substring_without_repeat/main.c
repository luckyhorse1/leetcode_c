#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
	int start=0, end=0, maxlen=0;
	int map[128] = {0};
	for(; *(s+end); end++) {
		if (map[*(s+end)] == 1) {
			while (map[*(s+end)] != 0) {
				map[*(s+start)] = 0;
				start++;
			}
		}
		map[*(s+end)] = 1;
		maxlen = maxlen>(end-start+1)? maxlen: (end-start+1);
	}
	return maxlen;
}

int lengthOfLongestSubstring2(char * s){
	int len=0, maxlen=0, index=0;
	int map[128];
	memset(map, 0xff, sizeof(map));
	for (; *s; s++) {
		if (map[*s] == -1) {
			len++;
		} else {
			if (index-map[*s] <= len) {
				len = index-map[*s];
			} else {
				len++;
			}
		}
		map[*s] = index++;
		maxlen = maxlen>len? maxlen: len;
	}
	return maxlen;
}

int main(int argc, char **argv){
	if (argc != 2) {
		fprintf(stderr, "usage: ./a.out string");
		exit(1);
	}
	printf("%d\n", lengthOfLongestSubstring(argv[1]));
	printf("%d\n", lengthOfLongestSubstring2(argv[1]));
	return 0;
}
