/*
 * Given root nodes of two binary search tree, find if both are identical in value and node hirerachy
 */
//Rememver
//recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  node_s {
  struct node_s *left;
  struct node_s *right;
  int val;
  int count;
} node_t;

void tree_print(node_t *n) {
  if (!n) {
    printf("end\n");
    return;
  }
  printf("%d %p, ", n->val, n);
  tree_print(n->left);
  tree_print(n->right);
}
void tree_insert(node_t **in, int val) {
  node_t *n = *in;
  if (n == NULL) {
    n = (node_t *)malloc(sizeof(node_t));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->count = 0;
    *in = n;
    printf("inserting val %d %p\n", val, n);
  } else if(val < n->val) {
    printf("looking left val %d %p\n", val, n);
    tree_insert(&n->left, val);
  } else if(val > n->val) {
    printf("looking right val %d %p\n", val, n);
    tree_insert(&n->right, val);
  } else {
    n->count++;
    printf("Duplicate key %d == %d\n", val, n->val);
  }
}
/*
 * return 1 : not same
 * return 0 : same
 */

int same_tree(node_t *n1, node_t *n2) {
  /* Recursively compare tree elements for structure and value both */
  if((n1 && !n2) || (n2 && !n1)) {
    printf("n1(%s) n2(%s)\n", n1?"":"NULL", n2?"":"NULL");
    return 1;
  }
  if(!n1 && !n2) {
    printf("End of compare, both nodes are NULL\n");
    return (0);
  }
  printf("going left\n");
  if (same_tree(n1->left,  n2->left) != 0) {
    return (1);
  }
  printf("going right\n");
if (same_tree(n1->right,  n2->right) != 0){
    return (1);
  }
  
  if(n1->val != n2->val) {
    printf("%d != %d\n", n1->val, n2->val);
    return 1;
  } else {
    printf("%d == %d\n", n1->val, n2->val);
    
  }
  return (0);
}
int main(int argc, char *argv[]) {
  node_t *n1 = NULL;
  node_t *n2 = NULL;
  node_t *tmp = NULL;
  int a1[] = {1,2,3,4,5,6,7};
  int a2[] = {1,2,3,4,5,6,7};
  
  for (int i = 0; i< sizeof(a1)/sizeof(int); i++) {
      tree_insert(&n1, a1[i]);
      printf("Done insert val %d at %p\n", a1[i], n1);
  }
  
  for (int i = 0; i< sizeof(a2)/sizeof(int); i++) {
      tree_insert(&n2, a2[i]);
      printf("Done insert val %d at %p\n", a2[i], n2);
  }
  printf("\n n1 printed:%p\n", n1);
  tree_print(n1);
  printf("\n n2 printed:%p\n", n2);
  tree_print(n2);
  printf("Comparing trees:\n");
  printf("n1 and n2 are same tree:%s\n",
	 same_tree(n1, n2) == 0?"TRUE":"FALSE");
}
