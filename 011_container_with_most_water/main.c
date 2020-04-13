#include <stdio.h>

#define min(a,b) ((a)>(b) ? (b) : (a))

int maxArea(int *height, int heightSize) {
	int maxArea = 0;
	int cur = 0;
	int start=0, end=heightSize-1;
	while (start < end) {
		cur = min(height[start], height[end]) * (end - start);
		maxArea = maxArea>cur? maxArea: cur;
		if (height[start]>height[end]) {
			end--;
		}else {
			start++;
		}
	}
	return maxArea;
}

int main(int argc, char **argv) {
	int arr[9] = {1,8,6,2,5,4,8,3,7};
	printf("%d\n", maxArea(arr, 9));
}
