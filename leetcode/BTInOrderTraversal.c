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

/* InOrder Non Recursive using Morris  method
 What is inorder mean ?.
 Process nodes in  Left Sub Tree, Current, Right Sub Tree.  
 So when we visit 'LST, we need to remember how to come back to 'Current', so stack is used to remeber,
 or recursion does the similar thing. Now without the help of any accessories we have Morris method,
 1. Where in  before we visit LST, we store 'Current' in a Predecessor.right node found in that LST
 (Which should be NULL).
 2. When we actually visit another current node,whose predecessor.right is not NULL
    (as its been used to store current) we reset value to NULL.as it should be pointing to 'current' now. 

current = root;  
while (!current) {

if (!current->left) {  // LST is not there
	visit(current);
	current = current->right;
} else { //LST is there, and this needs be visited first
        //Store current in pref.right 
        pred = findPred(current); 
	if(!pred->right) {
	     pred->right = current;
	     current = current->left;
	}
	else 
	{
            //Reset Stored current 
	    pred->right = NULL;
	    visit(current);
	    current = current->right;
	}
}
  
current  = root;
while curent
if current.left
    predecessor = findPredecessor(current)
    if predecessor.right
        predecessor.right = NULL
	visit current
        current = current->right;
    else 
        precessor.right = current;
        current = current->left;
else
   visit current,
   current  = current.right
*/

//Non Recursive InOrder(L, D, R), 
void walkInOrder(struct TreeNode *root, int *a, int *idx ,int order) 
{
  struct TreeNode *pred, *current = root;
  while (current) {
    if (current->left) {  //Move to LST 
      // Find predecessor(MAX in LST)
      pred = current->left;
      while (pred->right != NULL && pred->right != current)
	pred = pred->right;
      
      if(pred->right == NULL) {  //Store current, move left
	pred->right = current;
	current     = current->left;
      }
      else {//Reset Stored current ,visit L, move right
	  pred->right = NULL;
	  a[(*idx)++] = current->val;
	  current     = current->right;
      }
    } else { 
      a[(*idx)++] = current->val;  //Visit D and move to RST
      current     = current->right;
    }
  }
}


//Non Recursive PostOrder(L, R, D), 
void walkPostOrder(struct TreeNode *root, int *a, int *idx ,int order) 
{
  struct TreeNode *pred, *current = root;
  while (current) {
    if (!current->left) {  // LST is not there, so visit current, then RST
      printf("a[%d]=%d\n", *idx, current->val);
      a[(*idx)++] = current->val;
      current = current->right;
    } else { //LST is there, and this needs be visited first

      // Find predecessor(MAX in LST)
      pred = current->left;
      while(pred->right != NULL && pred->right != current)
	pred = pred->right;
      
      if(!pred->right) {  //Store current
	pred->right = current;
	current = current->left;
      }
      else 
	{
	  //Reset Stored current 
	  pred->right = NULL;
	  a[(*idx)++] = current->val;
	  current = current->right;
	}
    }
  }
}


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

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    
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

        walkInOrder(root, intarray, &ix,INORDER);
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
  printf("\n InOrder: ");
  for(int i=0; i<size; i++) {
    printf("%d, ", out[i]);
  }
  free((void *)out);

  size=0;
  out = preorderTraversal(&a, &size);
  printf("\n PreOrder: ");
  for(int i=0; i<size; i++) {
    printf("%d, ", out[i]);
  }
  free((void *)out);

  size=0;
  out = postorderTraversal(&a, &size);
  printf("\n PostOrder: ");
  for(int i=0; i<size; i++) {
    printf("%d, ", out[i]);
  }
  free((void *)out);

}
