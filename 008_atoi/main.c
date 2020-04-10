#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char *str) {
	char *s = str;
	long val = 0;
	int sign = 1;
	if (*s == '\0') return 0;
	while (*s == ' ') s++;
	if (*s == '+' || *s == '-') {
		sign = *s=='+'? 1: -1;
		s++;
	}
	if (!isdigit(*s)) return 0;
	while (isdigit(*s)) {
		val = val*10 + *s - '0';
		if (sign==1 && val >= INT_MAX) return INT_MAX;
		if (sign==-1 && -val <= INT_MIN) return INT_MIN;
		s++;
	}
	return sign>0 ? val : -val;
}

int main(int argc, char **argv) {
	printf("%d\n", myAtoi(argv[1]));
	return 0;
}
