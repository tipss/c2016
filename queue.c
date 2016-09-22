#include <stdio.h>
#include <stdlib.h>

typedef struct Q_s {
  int front;
  int rear;
  int capacity;
  int size;
  int *a;
} Q;

Q *initQ(int capacity){

  Q *q = NULL;
  q =  (Q *)malloc(sizeof(Q));
  q->capacity = capacity;
  q->a = malloc(sizeof(int) * capacity);
  q->front =q->size = 0;
  q->rear = q->capacity -1;
  return q;
}

int isEmpty(Q *q){
  
  return (q->size == 0);

}

int isFull (Q *q) {
  return (q->size == q->capacity);
}

// Queue inserts at the end of array pointed by rear
int enqueue(Q *q,  int val) {
  if (!q || isFull(q))
    return (-1);
  q->rear = (q->rear +1) % (q->capacity); //This gurantees circular queue. 
  q->a[q->rear] = val;
  q->size++;
  return 0;
}

int dequeue(Q *q, int *val){
  if(!q || val == NULL || isEmpty(q)) {
    return (-1);
  }
  *val = q->a[q->front];
  q->size -= 1;
  q->front = (q->front + 1) % q->capacity;
  return (0);

}

typedef struct elem_t {
	int     value;
	int     count;
	struct elem_t *left;
	struct elem_t *right;

} elem_t;


/* Breadth First Search */
elem_t *BFS(elem_t *r, int value) {
  elem_t *temp, *ret = NULL;
  int val = 0;
  Q *q= initQ(100);
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
  enqueue(q, (unsigned int)&r);

  while (!isEmpty(q)) {
    dequeue(q,&val);
    temp = (elem_t *)val;
    if(temp->left && temp->left->count == 0) {
      printf("%d ", temp->left->value);
      temp->left->count = 1;
      enqueue(q, (unsigned int)&(temp->left));
    }

    if (temp->right && temp->right->count == 0) {
      printf("%d ", temp->right->value);
      temp->right->count = 1;
      enqueue(q, (unsigned int)&(temp->right));
    }
  }
  free(q);
  return ret;
}

int main (int argc, char *argv[]) {

  //Test queue
  Q *q = initQ(10);
  int val=0;
  int ret;
  for (int i=0; i<15; i++) {
    ret = enqueue(q,i);
    if(ret != 0){
      printf("Queue is full at i= %d\n", i);
    }
  }
  printf("Dequeueing:");
  while(!isEmpty(q)){
    dequeue(q, &val);
    printf("%d ",val);
  }
  printf("\nRepear Enqueue and Dequeue Again\n");
  for (int i=0; i<15; i++) {
    ret = enqueue(q,i);
    if(ret != 0){
      printf("Queue is full at i= %d\n", i);
    }
  }
  printf("Dequeueing:");
  while(!isEmpty(q)){
    dequeue(q, &val);
    printf("%d ",val);
  }
  printf("\n");
  free(q);
}
