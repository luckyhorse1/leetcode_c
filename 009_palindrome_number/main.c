#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
	if (x<0) return false;
	char arr[100];
	int count=0;
	while (x!=0) {
		arr[count++] = x%10;
		x/=10;
	}
	for (int i=0; i<count/2; i++) {
		if (arr[i] != arr[count-i-1]) return false;
	}
	return true;
}

bool isPalindrome2(int x) {
	if (x<0) return false;
	int k = x;
	long temp=0;
	while (k!=0) {
		temp = temp*10 + k%10;
		k/=10;
	}
	return temp==x;
}

int main(int argc, char **argv) {
	printf("%d\n", isPalindrome(atoi(argv[1])));
	printf("%d\n", isPalindrome2(atoi(argv[1])));
}
