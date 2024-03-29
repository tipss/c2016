#include <stdio.h>
#include <stdlib.h>


typedef struct nd_s {
  int val;
  struct nd_s *next;
} nd;


nd * merge(nd *a,  nd *b){

  nd *result= NULL;
  
  if(a == NULL) {
    return b;
  }
  if(b == NULL) {
    return a;
  }
  /* Remember logic : wait and recursively merge */
  if(a->val >= b->val) {
    result =a;
    result->next = merge(a->next,b);
  } else {
    result = b;
    result->next = merge(b->next,a);
  }
  return (result);
}


void print_ll(nd *node) {
  nd *tmp = node;

  printf("\n");
  while(tmp) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
  printf("\n");

}


/* 
 * LL has elements in ascending  order from head to tail 
 * 1 2 3 4 5 -> NULL
 * 6 7 8 9 -> NULL
 * 
 * Will be mergesd as 
 * 1 2 3 4 5 6 7 8 9 -> NULL
 */
int main (int argc, char *argv[]) {
  int i = 1;
  nd *node;
  nd *a = NULL;
  nd *b = NULL;
  for (i = 1; i <= 5; i++) {
    node       = (nd *)malloc( sizeof(nd) );
    node->next = a;
    a          = node;
    node->val  = i;
  }
  print_ll(a);

  for (i = 6; i <= 10; i++) {
    node       = (nd *)malloc( sizeof(nd) );
    node->next = b;
    b          = node;
    node->val  = i;
  }
  print_ll(b);
  node = merge(a,b);
  print_ll(node);
}
