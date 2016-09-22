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

/* Breadth First Search */
elem_t *BFS(elem_t *r, int value) {
  elem_t *ret = NULL;
  /*
   * BFS :  1. Visit r
   2. Enqueue r
   3. Dequeue Until queue is empty
   4  For every dequeued node, visit it , and enqueue their ADJ nodes
  */

  if (r == NULL)
    return ret;
  printf("%d ", r->value);
  r->count = 1;
  enQueue(Q, r);

  while(QueueNotEmpty(Q)) {
    temp = deQueue(Q);
    if(temp->left && temp->left->count == 0) {
      printf("%d ", temp->left->value);
      temp->left->count = 1;
      enQueue(temp->left);
    }

    if(temp->right && temp->right->count == 0) {
      printf("%d ", temp->right->value);
      temp->right->count = 1;
      enQueue(temp->right);
    }
  }

  return ret;
}
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
/*
elem_t *bstInsert(elem_t *root, int val) {

  if (root == NULL) {
    root        = (elem_t *)malloc( sizeof(elem_t));
    root->left  = NULL;
    root->right = NULL;
    root->value = val;
    root->count = 1;
    printf("Insert value %d\n",val);
  } else {
    if(val > (root)->value) {
      printf("val(%d)> root->value(%d) insert at root->right\n",val, root->value );
      root->right  = bstInsert(root->right, val);
    } else if(val < (root)->value) {
      printf("val(%d) < root->value(%d) insert at root->left\n",val, root->value);
      root->left = bstInsert(root->left, val);
    } else {
      (root)->count++;
      printf("increment value %d by %d\n",val, (root)->count);
    }
  }
  return root;
}
*/

/* Find the Tree Height */
int maxDepth(elem_t *root) {
  int l,r,d;
  if(root == NULL)
    return 0;
  r = maxDepth(root->right);
  l = maxDepth(root->left);
  if (l > r){
    d = l+ 1;
  } else {
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
  int height,k;
  if (root == NULL)
    return;
  height = maxDepth(root);
  printf("Height %d\n", height);
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
  int count = 0;

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

  printf("Print LevelOrder:\n");
  printLevelOrder(root);
  printf("\nPrint PreOrder:\n");
  preOrderTraversal(root);
  printf("\nFind using DFS 4\n");
  lca = DFS(root,4);
  printf("\nDFS node with value 4 %s\n", lca?"FOUND":"NOT FOUND");

  printf("\nFind using DFS 4\n");
  preOrderTraversalCleanup(root);
 lca = DFS(root,4);
  printf("\nDFS node with value 4 %s\n", lca?"FOUND":"NOT FOUND");
  preOrderTraversalCleanup(root);


  printf("\nFind using DFS value 100\n");
  lca = DFS(root,100);
  printf("\nDFS node with value 100 %s\n", lca?"FOUND":"NOT FOUND");
  preOrderTraversalCleanup(root);

  printf("\nPrint PostOrder:\n");
  postOrderTraversal(root);

  printf("\nPrint InOrder:\n");
  inOrderTraversal(root);

  lca = LCA(root,2,4);
  if(lca)
    printf("Lowest Common Ancestor of nodes with value 2,4 is with value %d\n", lca->value);

  lca = LCA(root,6,8);
  if(lca)
    printf("Lowest Common Ancestor of nodes with value 6,8 is with value %d\n", lca->value);

  lca = findMaxValNode(root);
  if(lca)
    printf("MaxValue in the Tree %d\n",lca->value);
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
  int C[] = { 2,3,4,8,5,6,7};
	//int b = findMaxElem (A, 13);
	int b = findMaxElem2 (B, 7);
	printf("MaxElem index %d val %d\n", b, b?B[b]:b);

	testVariousTreeAPI(B,7);
}
