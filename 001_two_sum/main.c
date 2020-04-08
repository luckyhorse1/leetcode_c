#include <stdio.h>
#include <stdlib.h>

typedef struct object_ object;

struct object_ {
	int index;
	int val;
};

int compare(const void *a, const void *b) {
	return ((object*)a)->val - ((object*)b)->val;
}

int *twosum(int *nums, int numsSize, int target, int *returnSize) {
	int i;
	object *objs = malloc(numsSize*sizeof(*objs));
	for (i=0; i<numsSize; i++) {
		objs[i].index = i;
		objs[i].val = nums[i];
	}

	qsort(objs, numsSize, sizeof(*objs), compare);

	int *ret = malloc(2*sizeof(int));
	i = 0;
	int j = numsSize-1;
	while (i<j) {
		int diff = target - objs[i].val;
		if (diff>objs[j].val) {
			while (++i<j && objs[i].val == objs[i-1].val) {}
		} else if (diff<objs[j].val) {
			while (i<--j && objs[j].val == objs[j+1].val) {}
		} else {
			ret[0] = objs[i].index;
			ret[1] = objs[j].index;
			*returnSize = 2;
			return ret;
		}
	}
	*returnSize = 0;
	return NULL;
}

int main(void) {
	int arr[4] = {6,4,3,2};
	int returnSize;
	int *ret = twosum(arr, 4, 8, &returnSize);
	if (ret != NULL) {
		printf("%d %d\n", ret[0], ret[1]);
	}
	return 0;
}
