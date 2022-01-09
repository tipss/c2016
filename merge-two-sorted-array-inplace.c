#include <stdio.h>
#include <stdlib.h>

/*
 What is external sort ?.
 When you need to sort a large file say 20gig, 
 *its better to chunk the file into small pieces,
 * sort each chunk bring it into memory.
 * and send back to file.
 * at the end merge chunks one by one, at the end we have fully sorted file.
*/

/*
 * Merge two array sorted asending, into A, which has enough space
 * Trick: Since its in place merge, you can't overwrite A elements with B's.
 *        Reverse copy is the way to go for this case.
 * assume A has enough space and, merge into A, content of B
*/
void mergeInPlace (int A[], int B[], int a, int b) { 
	int   new_size = a + b;
	--a;
	--b;
	for (int i= new_size-1; i >= 0; i--) {
		if (a < 0 && b < 0) {
			printf("No more elements left to copy\n");
			return;
		}
		if (b < 0){
			printf("no more elements in b, no need to copy A, as they are already in place\n");
			return;
		}
		if (a >= 0  && A[a] > B[b]) { //Remember simple
			A[i] = A[a--];
		} else {
			A[i] = B[b--];      
		}
	}
	printf("a = %d, b = %d\n", a, b);
}

void printArray(int A[], int size) {
	printf("size %d: ", size);
	for (int i = 0; i< size; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main (int argc, char *argv[]) {
	//Ascending order array
	int A[10] = { 1,2,3,4,5,0,0,0,0,0};
	int B[5]  = { 1,2,3,4,5};

	int a = 5;
	int b = sizeof(B)/sizeof(int);
	printArray(A, a);
	printArray(B, b);
	mergeInPlace(A,B,a,b);
	printArray(A, (sizeof(A)/sizeof(int)));

}
