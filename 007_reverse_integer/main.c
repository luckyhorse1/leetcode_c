#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x){
    long val=0;
    int sign = x>=0? 1: -1;
    if (x == INT_MIN) return 0;
    if (x<0) x = -x;
    while (x!=0) {
        val = val*10 + x%10;
        x = x/10;
    }
    val = sign*val;
    if (val>INT_MAX || val <INT_MIN) {
        return 0;
    }
    return (int)val;
}

int main(int argc, char **argv) {
	printf("%d\n", reverse(atoi(argv[1])));
	return 0;
}
