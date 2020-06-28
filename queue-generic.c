#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct q_s {
  void **container;
  int capacity;
  int size;
  int front;
  int rear;
} q_t;



q_t * initq (int capacity) {
  q_t *q = malloc(sizeof(q_t));
  printf("sizeof(void *)=%ld,sizeof(void**)=%ld\n",sizeof(void *),sizeof(void**));
  q->container = malloc(sizeof(void**) * capacity);
  q->capacity  = capacity;
  q->size  = 0;
  q->front = 0;
  q->rear  = q->capacity - 1; //This is important, as we increment when enqueue is done

  return q;
}

int isEmpty(q_t *q){
  
  return (q->size == 0);

}

int isFull (q_t *q) {
  return (q->size == q->capacity);
}

//Double the capacity
void resizeContainer(q_t *q){

  void** tmpContainer = malloc(sizeof(void**) * q->capacity * 2);
  memcpy(tmpContainer, q->container,  sizeof(void**)*q->capacity);
  free(q->container);
  q->container = tmpContainer;
  q->capacity *= 2;
  printf("Resized queue to %d\n",q->capacity);
}

int enqueue(q_t * q, void *item){
  if(q->size == q->capacity) {

    resizeContainer(q);
  }
  q->rear = (q->rear+1) % q->capacity;
  q->container[q->rear] = item;
  q->size++;
  printf("enqueued now size is %d rear %d\n", q->size,q->rear);
  return 0;
}

void * dequeue(q_t *q) {
  int front;
  if(q->size == 0) {
    printf("Nothing to Dequeue\n");
    return NULL;
  }
  front    = q->front;
  q->front = (q->front + 1) % q->capacity;
  q->size--;
  printf("dequeued now size is %d front %d\n", q->size, q->front);
  return q->container[front];
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
  q_t *q= initq(100);
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
  enqueue(q, (void *)r);

  while (!isEmpty(q)) {
    temp = (elem_t *)dequeue(q);
    if(temp->left && temp->left->count == 0) {
      printf("%d ", temp->left->value);
      temp->left->count = 1;
      enqueue(q, (void *)(temp->left));
    }

    if (temp->right && temp->right->count == 0) {
      printf("%d ", temp->right->value);
      temp->right->count = 1;
      enqueue(q, (void *)(temp->right));
    }
  }
  free(q);
  return ret;
}


int main(int argc, char *argv[]) {

  //Test queue implementation.

  q_t *q = initq(10);
  char *str;
  for (int i=0; i<15; i++) {
    str = malloc(4 * sizeof(char));
    sprintf(str," %d ",i);
    enqueue(q,(void *)str);
  }

  for (int i=0; i<15; i++) {
    str = (char *)dequeue(q);
    if(str)
      printf("%s",str);
  }

  //TBD test BFS here after inserting elements in a temp tree

}
