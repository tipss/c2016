#include <stdio.h>
#include <stdlib.h>

/*http://www.geeksforgeeks.org/majority-element/ */
/*
 * Trie vs Tree:
 *Trie is an ordered tree structure, which is used mostly for storing strings (like words in dictionary) in a compact way. In a trie, every node (except the root node) stores one character. By traversing up the trie from a leaf node to the root node, a string can be constructed.
 */
typedef struct elem_t {
	int     value;
	int     count;
	struct elem_t *left;
	struct elem_t *right;

} elem_t;
/* 
 * DFS : Depth First Search: Used to traverse a Graph(not tree),
 *       which needs additional precaution to not revist the same node,
 *       a marker is kept for each node visited.
 *	pre-order tree traversal is a form of DFS.
 *      In DFS, as its not a tree, we should remember node visited to avoid loops
 *      Start with some key value to find,, start from some node r.
 *      Steps 1. Visit node r
 *            2. Iterate through all adjacent nodes of r.(in case of tree, it will be left and right)            3. For every adjacent node found(n), visit it, but iterate all its adj-nodes, before
                 going to the next adjacent node of r.
* This can also be used to find if there exits a route between two nodes.
* first node you pass as start and use it as root,  second node as usual.
	   
*/
elem_t * DFS(elem_t *r,int value){
  elem_t *ret = NULL;
  if(r == NULL)
    return NULL;
  printf("%d ",r->value);
  if(r->value == value){
    return r;
  }
  r->count = 1; //Visited this node
  //Iterate through adjacent nodes of r.
  if(r->left && r->left->count == 0)
    ret = DFS(r->left, value);
  if(!ret && r->right && r->right->count == 0)
    ret = DFS(r->right, value);
  return ret;
}

#define INT_MIN 0
#define INT_MAX 0xffff

int findMax(elem_t *root) {
  int max=0;
  int l,r;
  if (root == NULL)
    return INT_MIN;
  l = findMax(root->left);
  r = findMax(root->right);

  if(l > r)
    max = l;
  else 
    max = r;
  if(root->value > max)
    max = root->value;
  return max;

}


int findMax2(elem_t *root){
  if (root == NULL)
    return (INT_MIN);
  if(root->right == NULL)
    return (root->value);
  return findMax2(root->right);
}

/* This work in any binary tree, does not ncesessarily be a binarysearch tree, were
left subtree has lower values 
*/
int findMin(elem_t *root) {
  int min=0;
  int l,r;
  if (root == NULL)
    return INT_MAX;
  l = findMin(root->left);
  r = findMin(root->right);

  if(l < r)
    min = l;
  else 
    min = r;
  if(root->value < min)
    min = root->value;
  return min;

}
/*
 findMin2 : Left most node which does not have left child
 * This only works in 'Binary Search Tree 
*/
int findMin2(elem_t *root){
  if(root == NULL){
    return INT_MAX;
  }
  if(root->left == NULL)
    //Found min
    return root->value;
  return findMin2(root->left);
}


/* Count the number of nodes in tree including root */
int sizeoftree (elem_t *root) {

  if(root == NULL) {
    return 0;
  }
  return 1+ sizeoftree(root->left) + sizeoftree(root->right);
}

/* Print TREE contents by using pre-order traversal method( DLR)*/
void preOrderTraversal(elem_t *root) {
  if (!root)
    return;
  printf("%d ", root->value);
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

/* Print TREE contents by using pre-order traversal method( DLR)
 * Can be used  as cleanup, after DFS, or other routines which mark
 * contents
*/

void preOrderTraversalCleanup(elem_t *root) {
  if (!root)
    return;
  printf("%d(%d) ", root->value,root->count);
  root->count = 0;
  preOrderTraversalCleanup(root->left);
  preOrderTraversalCleanup(root->right);
}

//LRD
void postOrderTraversal(elem_t *root) { 
  if(!root)
    return;
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  printf("%d ",root->value);
}


void inOrderTraversal(elem_t *root) {
  if(!root)
    return;
  inOrderTraversal(root->left);
  printf("%d ",root->value);
  inOrderTraversal(root->right);
}

/* Unbalanced Insert, Count is kept to find if there are elements
 * that repeated
 */
void bstInsert(int key, struct elem_t **root) {

  if ( NULL == *root )
    {
      *root = (struct elem_t*) malloc( sizeof( struct elem_t ) );
      (*root)->value = key;
      (*root)->left = NULL;    
      (*root)->right = NULL;
      (*root)->count = 0;
      printf("Inserting key %d\n",key);
    }
  else if(key < (*root)->value)
    {
      bstInsert( key, &(*root)->left );
    }
  else if(key > (*root)->value)
    {
      bstInsert( key, &(*root)->right );
    } 
  else 
    {
      printf("Duplicate key %d\n",key);
      (*root)->count++;
    }
}

/* Height of Tree : from a given node to the deeptest node 
   Depth of Tree : From root to given node 
   Height = Depth for a given tree from 'root'
*/
/* Find the Tree Height , when balancedCheck is 1, it will 
* be similar to isBalanced(), ret -1 meaning not balanced
*/
int maxDepth(elem_t *root, int balancedCheck) {
  int l,r,d;
  if(root == NULL)
    return 0;
  r = maxDepth(root->right, balancedCheck);
  l = maxDepth(root->left, balancedCheck);

  if(balancedCheck ==1  && (r == -1 || l == -1))
    return (-1);
  if (l > r){
    if((balancedCheck == 1) && (l-r > 1)){
      return (-1);
    }
    d = l+ 1;
  } else {
    if( (balancedCheck == 1) && (r-l > 1))
      return (-1);
    d = r + 1;
  }
  return (d);
}

/* Remeber This. 
 *  You print only when you reach 'level==1',
 *  How you reach ?: Recusrse left and right.
*/
void printPerLevel(elem_t *root,int level) {
  if (root == NULL || level == 0)
    return;
  if(level == 1) {
    printf("%d ",root->value);
  } else {
    printPerLevel(root->left,  level-1);
    printPerLevel(root->right, level-1);
  }
}

void printLevelOrder (elem_t *root) {
  int height, k;
  if (root == NULL)
    return;
  height = maxDepth(root,0);
  printf("      Tree Height %d\n", height);
  for (int i = 1; i <= height; i++) {
    k= height - i;
    while (k>0) {
      printf("%c",' ');
      k--;
    }
    printPerLevel(root, i);
    printf("\n");
  }
}

/* Find Lowest Common Ancestor of elements a and b starting from root node 
 * Remeber : 
*/
elem_t * LCA (elem_t *root, int a, int b) {
  elem_t *left;
  elem_t *right;
  if(!root || root->value == a || root->value == b)
    return root;
  if(root->left)
    left = LCA(root->left, a, b);
  if(root->right)
    right= LCA(root->right, a, b);
  if(left && right)
    return root;
  if(left)
    return left;
  return right;

}


/* Given an unsorted array of number, find a number that repeats more than half the size of array
* Method 1: Two Loops  O(n^2)
* Input A integer array of size 'n'
* Return -1: invalid input
*        -2: No MaxElem found, or no element repeats more than n/2 times
*         index: Valid index of number which repeats more than n/2 times
*/
int findMaxElem(int A[], int n) {
  int count = 0;
  printf("Array Count %d\n",n);
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

	
  elem_t *lca, *root=NULL;
  int count = 0;

  if (n <= 0) {
    return (-1);
  }	
  /*
   * While you insert element into b.tree, if element already exist, 
   * just increment count.
   */
  for (int i = 0; i < n; i++) {
	
    bstInsert(A[i], &root);
    printf("Insert i=%d, count %d n/2 = %d root 0x%p\n",i, root->count,n/2,root);
    if (root->count > n/2) {
      return i;
    }
  }
 return (-2);
}

/* Find node whose value is highest in the tree */
elem_t *findMaxValNode(elem_t *root) {
  elem_t *r, *l,*max;

  if(!root)
    return NULL;
  max = root;
  r = findMaxValNode(root->right);
  l = findMaxValNode(root->left);
  
  if(r && r->value > max->value) {
    max = r;
  }
  if(l && l->value > max->value)
    max = l;

  return max;
}

void testVariousTreeAPI(int A[], int n) 
{
  elem_t *lca = NULL; 
  elem_t *root = NULL;
  int count  = 0;
  int height = 0;
  if (n <= 0) {
    return;
  }	
  /*
   * While you insert element into b.tree, if element already exist, 
   * just increment count.
   */
  for (int i = 0; i < n; i++) {	
    bstInsert(A[i], &root);
  }

  printf("Max value in the tree :%d\n", findMax(root));
  printf("Min value in the tree :%d\n", findMin(root));

  printf("Max value in the bin-search-tree :%d\n", findMax2(root));
  printf("Min value in the bin-search-tree :%d\n", findMin2(root));
 
 printf("Print LevelOrder:\n");
  printLevelOrder(root);
  printf("\nPrint PreOrder:\n");
  preOrderTraversal(root);

  printf("\nPrint PostOrder:\n");
  postOrderTraversal(root);

  printf("\nPrint InOrder:\n");
  inOrderTraversal(root);
  printf("Search using DepthFirstSearch for value 4 :\n");
  lca = DFS(root, 4);
  printf("\nDFS node with value 4 %s\n", lca?"FOUND":"NOT FOUND");
  preOrderTraversalCleanup(root);

  lca = LCA(root,2,4);
  if(lca)
    printf("\nLowest Common Ancestor of nodes with value 2,4 is with value %d\n", lca->value);

  lca = LCA(root,6,8);
  if(lca)
    printf("\nLowest Common Ancestor of nodes with value 6,8 is with value %d\n", lca->value);

  lca = findMaxValNode(root);
  if(lca)
    printf("\nMaxValue in the Tree %d\n",lca->value);
  printf("\nChecking is this tree balanced( heigt of l-subtree and r-subtree can differ at most by 1\n");
  height = maxDepth(root,1);
  if(height >= 0) {
    printf("Its a balanced TREE %d\n",height);
    
  } else {

    printf("Not a balanced tree, %d\n",height);
}
}


int main(int argc, char *argv[]) {
  /* Note: If you pass an sorted list to BST Insert,
   * Tree HEIGHT will increase at same rate, like linked list,
   * This is normal behavior, thats why you need RedBlack tree or AVL tree
   * where in L and R sub trees are balanced to at most 1 different in height.
   * Put different Array, and watch the output.
   */
  int A[] = { 9,7,6,5, 1,2,3,4,5,6,7,7,7,7,7,7,7,7 };
  int B[] = { 5,7,3,8,2,4,6};
  int C[] = { 9,12,15,2,3,4,8,5,6,7,1};
  int b = findMaxElem (A, sizeof(A)/sizeof(int));
	//int b = findMaxElem2 (C, 13);
	printf("MaxElem index %d val %d\n", b, b?B[b]:b);

  testVariousTreeAPI(C,sizeof(C)/sizeof(int));
}
