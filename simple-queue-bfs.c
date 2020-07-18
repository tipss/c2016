#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
  int val;
  void *data;
  struct node_s *next;
} node_t;

typedef struct q_s {
  node_t *head;
  node_t *tail;
} q_t;

q_t local = { 0 };
q_t *my_q = &local;

int dequeue(int *val, void **out) {
  /* remove node from head and adjust new head */
  if(my_q->head == NULL || my_q->tail == NULL){
    return (-1);
  }
  *val = my_q->head->val;
  *out = my_q->head->data;
  node_t *tmp = my_q->head;

  if (my_q->head == my_q->tail ) {
    my_q->head = my_q->tail = NULL;
  } else {
    my_q->head = my_q->head->next;
  }
  free(tmp);
  return (0);
}

int enqueue(int val, void *in) {
  /* add new nodes to tail and adjust tail */
  node_t *tmp = malloc(sizeof(node_t));
  tmp->next = tmp->data = NULL;
  tmp->val  = val;
  tmp->data = in;
  
  if (my_q->head == NULL || my_q->tail == NULL) {
    my_q->head = my_q->tail = tmp;
    return 0;
  }
  my_q->tail->next = tmp;
  my_q->tail = tmp;
  return (0);
}

typedef struct tnode_s {
  int val;
  struct tnode_s *left;
  struct tnode_s *right;
  int visit;
  int count;
} tnode_t;

tnode_t t = { 0 };
//t.val   = 10;
//t.visit = 0;
//t.count = 0;

/* Breadth First Search */
tnode_t *BFS(tnode_t *r, int value) {
  int val = 100;
  tnode_t *tmp = NULL;
  /*
   * BFS :  1. Visit r
   2. Enqueue r
   3. Dequeue Until queue is empty
   4  For every dequeued node, visit it , and enqueue their ADJ nodes
  */
  if(!r) {
    return NULL;
  }
  r->visit = 1;
  enqueue(val, r);
  
  while (my_q->head) {
    dequeue(&val, (void *)&tmp);
      if(tmp->val == value){
	printf("Found value %d in %p\n", value, r);
	return (r);
      }
    if (tmp->left && tmp->left->visit == 0) {
      tmp->left->visit = 1;
      enqueue(val, tmp->left);
    }
    if (tmp->right && tmp->right->visit == 0) {
      tmp->right->visit = 1;
      enqueue(val, tmp->right);
    }
  }
  return (NULL);
}


void bst_insert(tnode_t **root, int val) {
  tnode_t *tmp = NULL;
  if (*root == NULL) {
    tmp = malloc(sizeof(tnode_t));
    tmp->val   = val;
    tmp->left  = tmp->right = NULL;
    tmp->visit = 0;
    tmp->count = 0;
    *root = tmp;
    return;
  }
  
  tmp = *root;
  if (val < tmp->val) {
    bst_insert(&(tmp->left), val);
  } else if (val > tmp->val) {
    bst_insert(&(tmp->right), val);
  } else {
    tmp->count++;
  }
}

int main(int argc, char *argv[]) {
  int val = 0;
  t.val = 10;
  tnode_t *tmp = NULL;
  tnode_t *res = NULL;
  
  // Test queue implementation.
  for (int i = 0; i < 15; i++) {
    enqueue(i, &t);
  }
  
  for (int i = 0; i<15; i++) {
    dequeue( &val, (void *)&tmp);
    printf("%d  t.val %d\n " ,val, tmp->val);
  }

  tmp = NULL;
  for (int i = 0; i < 15; i++) {
    bst_insert(&tmp, i);
  }

  for (int i = 0; i< 15; i++) {
    res = BFS(tmp, i);
    if(res) {
      printf("%p tmp->val %d\n", res, res->val);
    } else {
      printf("Value %d not found\n",i);
    }
  }
}
 
