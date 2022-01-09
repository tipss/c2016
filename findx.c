#include<stdio.h>
/*
 * Given a sorted number array in ascending, find index of two number, whose sum= X
 * E.g     1 2 3 4 5 6 7 
 * Find Sum   7.
 * Start l =1 + r=7= 8   
 *       l =2 + r=6 = 7 exits
*/
int findx(int A[], int size, int *first, int *second, int X) {
  	if(A== NULL)
		return 0;
	if(size < 2)
		return 0;
	int l=0;
	int r =size-1;

	while (l < r) {
    		if((A[l] + A[r]) == X) {
			*first  = l;
			*second = r;
			return 1;
		} else if((A[l] + A[r]) < X) {
			l++;
		} else {
			r--;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int      X = 0;
	int first  = 0;
	int second = 0;
	int size   = 9;
	int ret;
	
	printf("Input Array :");
	for (int i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
	printf ("Enter X, we will find two elements whose sum is X:");
	scanf("%d", &X);
	ret = findx (A, size, &first, &second, X);

	if (ret) {
		printf("A[%d= %d] + A[%d= %d]= %d\n", first, A[first], second, A[second], X);
	} else {
		printf("No match found\n");
	}
}
