#include <stdio.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
	int index=0, maxlen=0, start=0;
	while (s[index]) {
		// odd center expand
		int left = index;
		int right = index;
		while (left>=0 && s[right] && s[left] == s[right]) {
			left--;
			right++;
		}
		if (maxlen < (right-left-1)) {
			maxlen = right-left-1;
			start = left+1;
		}

		// even center expand
		left = index;
		right = index+1;
		if (s[right] && s[left]==s[right]) {
			while (left>=0 && s[right] && s[left] == s[right]) {
            	left--;
            	right++;
        	}
			if (maxlen < (right-left-1)) {
           	 	maxlen = right-left-1;
            	start = left+1;
  	      	}
		}
		index++;
	}

	char *ret = malloc(maxlen*sizeof(char)+1);
	int i=0;
	for (i=0; i<maxlen; i++) {
		ret[i] = s[start+i];
	}
	ret[maxlen] = '\0';
	return ret;
}


char *longestPalindrome2(char *s) {
	int index=0, left=0, right=0, maxlen=0, start=0;
	while (s[index]) {
		left = index-1;
		right = index;
		while (s[right] == s[index]) {
			right++;
		}
		index = right;
		while (left>=0 && s[right] && s[left] == s[right]) {
			left--;
			right++;
		}
		if (maxlen<(right-left-1)) {
			maxlen = right-left-1;
			start = left+1;
		}
	}
	
	char *ret = malloc(maxlen+1);
	ret[maxlen] = '\0';
	for (int i=0; i<maxlen; i++) {
		ret[i] = s[start+i];
	}
	return ret;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "usage: ./a.out string");
		exit(1);
	}
	
	char *ret1 = longestPalindrome(argv[1]);
	printf("%s\n", ret1);
	char *ret2 = longestPalindrome2(argv[1]);
	printf("%s\n", ret2);
	return 0;
}
