#include <stdio.h>
#include <stdlib.h>

/*http://www.geeksforgeeks.org/majority-element/ */

typedef struct elem_t {
	int     value;
	int     count;
	elem_t *left;
	elem_t *right;

} elem_t;

elem_t *bstInsert(elem_t **root, int val) {

	elem_t *tmp;

	if (root == NULL) {
		tmp        = (elem_t *)malloc( sizeof(elem_t));
		tmp->left  = NULL;
		tmp->right = NULL;
		tmp->value = val;
		tmp->count = 1;
		*root      = tmp;
		return tmp;
	} else {

		if(val > root->value) {
			root->left  = bstInsert(root->right, val);
		} else if(val < root->value) {
			root->right = bstInsert(root->left, val);
		} else {
			root->count++;
			return root;
		}
	}

}

/* Method 1: Two Loops  O(n^2)
* Input A integer array of size 'n'
* Return -1: invalid input
*        -2: No MaxElem found, or no element repeats more than n/2 times
*         index: Valid index of number which repeats more than n/2 times
*/
int findMaxElem(int A[], int n) {

	int count = 0;

	if (n <= 0) {
		return (-1);
	}	

	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < n; j++) {
			if (A[j] == A[i]) {
				count++;
				if (count > n/2) {
					return j;
				}
			}
		}
	}
	return (-2);
}

/* 
* Method 2: Binary Tree Insert  O(n^2)
* Input A integer array of size 'n'
* Return -1: invalid input
*        -2: No MaxElem found, or no element repeats more than n/2 times
*         index: Valid index of number which repeats more than n/2 times
*/
int findMaxElem2(int A[], int n) {

	

	int count = 0;

	if (n <= 0) {
		return (-1);
	}	
/*
* While you insert element into b.tree, if element already exist, 
* just increment count.
*/
for (int i = 0; i < n; i++) {
	
	bstInsert(A[i], &count);
	if (count > n/2) {
		return i;
	}
}
return (-2);
}


int main(int argc, char *argv[]) {

	int A[] = { 1,2,3,4,5,6,7,7,7,7,7,7,7,7 };
	int b = findMaxElem(A, 13);
	printf("MaxElem index %d val\n", b, b?A[b]::b);
}