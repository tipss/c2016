#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* O(n) */
void treeSize(struct TreeNode *root,int *size) {
	if (root && size) {
 	   (*size)++; 
           treeSize(root->left, size) ;
	   treeSize(root->right, size);
	}
}

/* O(n) */
void walkinorder(struct TreeNode *root, int *a, int *idx) {
        if (root) {
	 walkinorder(root->left, a, idx);	
	//Remember how to increement pointer here
   	 a[(*idx)++] = root->val;
	 walkinorder(root->right, a, idx);	
	}
}

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * inorderTraversal(struct TreeNode* root, int* returnSize) {
	int n = 0, *intarray,ix = 0;
   /*
    0  compute size of tree, so you can allocate arrary
    1. InOrder means LDR traversal 
    2. If root not null 
       a.call recursively root->left
       b.process root
       c.call recursively root->right
    */ 
	if (!root) {
	   printf("Received NULL root\n");
	   return NULL;
	}

	treeSize(root,returnSize);
	printf("Received tree with %d elements\n", *returnSize);
	intarray = (int *)malloc(1+ sizeof(int) * (*returnSize));

	if (intarray == NULL)
	  return NULL;

        walkinorder(root,intarray, &ix);
	return intarray;
}

int main(int argc, char *argv[]) {
int size = 0;
int *inorderarray;

/*
  1 a
    \
     2 b
    /
   3 c
*/
struct TreeNode a ,  b , c;
a.val = 1;
b.val = 2;
c.val = 3;

a.left  = NULL;
a.right = &b;

b.right= NULL;
b.left = &c;

c.right = NULL;
c.left  = NULL;

inorderarray = inorderTraversal(&a, &size);
printf("\n");
for(int i=0; i<size; i++) {
   printf("%d, ", inorderarray[i]);
}
printf("\n");

}
