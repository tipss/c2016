#include <stdio.h>
#include <stdlib.h>
struct NumArray {
    int *nums;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	int i;
	if(!nums || numsSize == 0)
		return NULL;
	struct NumArray *n=(struct NumArray *)malloc(sizeof(struct NumArray));
	n->nums = (int *)malloc(sizeof(int) * numsSize);
	//memcpy(n->nums,nums, sizeof(int) * numsSize);
	for (i = 0; i < numsSize; i++) {
		n->nums[i] = nums[i];
	}
	return n;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	int k, res = 0;
	if (!numArray) {
		return (-1);
	}
	if (i < 0 || j < 0) {
		return (-1);
	}
    
	for(k=i; k <=j; k++) {
		res += numArray->nums[k];
		printf("k = %d res=%d\n",k,res);
	}
	return res;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	if(numArray) {
		free(numArray->nums);
		free(numArray);
	}
}

int main(int argc, char *argv[]) {
	int nums[] = {-2,0,3,-5,2,-1};

        // Your NumArray object will be instantiated and called as such:
	struct NumArray* numArray = NumArrayCreate(nums, 6);
 
	sumRange(numArray, 0,2);
	sumRange(numArray, 2,5);
	sumRange(numArray, 0,5);
	NumArrayFree(numArray);
}
