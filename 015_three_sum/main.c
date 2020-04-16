#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int **ret = malloc(sizeof(int*)*numsSize*numsSize);
    *returnColumnSizes = malloc(sizeof(int)*numsSize*numsSize);
    qsort(nums, numsSize, sizeof(int), compare);
    int pre = INT_MIN;
    int index=0;
    for (int i=0; i<=numsSize-3; i++) {
        if (nums[i] == pre) continue;
        pre = nums[i];
        int target = -nums[i];
        int start = i+1, end = numsSize-1;
        while (start < end) {
            if (nums[start]+nums[end] == target) {
                ret[index] = malloc(sizeof(int)*3);
                ret[index][0] = nums[i];
                ret[index][1] = nums[start];
                ret[index][2] = nums[end];
                (*returnColumnSizes)[index] = 3;
                index++;
                while (nums[start]==nums[++start] && start<end);
                while (nums[end]==nums[--end] && start<end);
            } else if (nums[start]+nums[end]<target) {
                start++;
            } else {
                end--;
            }
        }
    }
    *returnSize = index;
    return ret;
}

int main(void) {
	int nums[] = {-1, 0, 1, 2, -1, -4};
	int retSize, *retCSize;
	int **ret = threeSum(nums, 6, &retSize, &retCSize);
	int len = 0;
	int **p = ret;
	while (*p) {
		p++;
		len++;
	}
	for (int i=0; i<len; i++) {
		for (int j=0; j<3; j++) {
			printf("%d, ", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}
