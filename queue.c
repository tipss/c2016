#include <stdio.h>
#include <stdlib.h>

typedef struct Q_s {
	int front;
	int rear;
	int capacity;
	int size;
	int *a;
} Q;

Q *initQ(int capacity) {

	Q *q = NULL;
	q =  (Q *)malloc(sizeof(Q));
	q->capacity = capacity;
	q->a = malloc(sizeof(int) * capacity);
	q->front =q->size = 0;
	q->rear = q->capacity -1;
	return q;
}

int isEmpty(Q *q) {
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
  if (!q || val == NULL || isEmpty(q)) {
    return (-1);
  }
  *val = q->a[q->front];
  q->size -= 1;
  q->front = (q->front + 1) % q->capacity;
  return (0);

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
