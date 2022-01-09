#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int size) {
    for (int i=0; i< size; i++) {
        printf("%d ",arr[i]); 
    }
    printf("\n");
}

int RemoveZeroes (int *arr, int size) {
        int j = 0;
	/*
	  0. Validate Input, Reject bad input
	  1. Loop Array 
	  1.1 Find Zero, Skip Copy
	  2. With new Size, Loop rest of the arry and set elements to zero
	  3. Return new size
	*/
	if (size <= 0) {
		return size;
	} 
	printArr(arr, size);
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) {
			arr[j++] = arr[i];   
		} 
	}

	while (j < size) {
		arr[j++] = 0;
	} 
	printf("j = %d\n",j);
	printArr(arr, size);
	printf("\n");
	return size;
}


int main (int argc, char *argv[]) {
	int size = 10;
	int a[] = {1,0,2,0,3,0,4,0,5,0};
	int b[] = {0,0,0,0,0,0,0,0,0,0};
	int c[] = {1,1,2,1,3,1,4,1,5,1};

	size = RemoveZeroes(a, size);
	size = RemoveZeroes(b, size);
	size = RemoveZeroes(c, size);
}
