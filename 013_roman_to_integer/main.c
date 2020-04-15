#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
	int arr[128] = {0};
	arr['I'] = 1;
	arr['V'] = 5;
	arr['X'] = 10;
	arr['L'] = 50;
	arr['C'] = 100;
	arr['D'] = 500;
	arr['M'] = 1000;
	int ret = 0;
	int len = strlen(s);
	for (int i=0; i<len; i++) {
		if (i+1<len && arr[s[i]]<arr[s[i+1]]) {
			ret -= arr[s[i]];
		} else {
			ret += arr[s[i]];
		}
	}
	return ret;
}

int main(int argc, char **argv) {
	printf("%d\n", romanToInt(argv[1]));
}
