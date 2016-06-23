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

#define INORDER   0x1  //LDR
#define PREORDER  0x2  //DLR
#define POSTORDER 0x3  //LRD
/* O(n) */
void walk(struct TreeNode *root, int *a, int *idx ,int order) {
        if (root) {
        switch (order){	
	 case INORDER:
	   walk(root->left, a, idx, order);	
   	   a[(*idx)++] = root->val;
	   walk(root->right, a, idx, order);	
	   break;
	 case PREORDER:
   	   a[(*idx)++] = root->val;
	   walk(root->left, a, idx, order);	
	   walk(root->right, a, idx, order);	
	   break;
	 case POSTORDER:
	   walk(root->left, a, idx, order);	
	   walk(root->right, a, idx, order);	
   	   a[(*idx)++] = root->val;
	   break;
	}
       }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
	int *intarray,ix = 0;
	if (!root) {
	   printf("Received NULL root\n");
	   return NULL;
	}

	treeSize(root,returnSize);
	printf("\nReceived tree with %d elements\n", *returnSize);
	intarray = (int *)malloc(1+ sizeof(int) * (*returnSize));

	if (intarray == NULL)
	  return NULL;

        walk(root,intarray, &ix,PREORDER);
	return intarray;
}

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * inorderTraversal(struct TreeNode* root, int* returnSize) {
	int *intarray,ix = 0;
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

        walk(root,intarray, &ix,INORDER);
	return intarray;
}

int main(int argc, char *argv[]) {
int size = 0;
int *out;

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

out = inorderTraversal(&a, &size);
printf("\n InOrder");
for(int i=0; i<size; i++) {
   printf("%d, ", out[i]);
}

size=0;
out = preorderTraversal(&a, &size);
printf("\n PreOrder");

for(int i=0; i<size; i++) {
   printf("%d, ", out[i]);
}

}
