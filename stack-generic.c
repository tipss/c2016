#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Implement a stack to store void pointers using array, allow dynamic array growth if size is less
 * Main operation include, PUSH and POP 
 * a single counter is maintained
 * its a LIFO(Last In First Out) data struct
 * like stack of plates in hotel
*/



typedef struct s_s {
  int index; //Keeps track of current index of top element
  int capacity; //Max capacity
  void **container;
} S;


S * initS(int capacity) {
  S *s = malloc(sizeof(S));
  s->container = malloc(capacity * sizeof(void**));
  s->capacity = capacity;
  s->index = 0;
  return s;
}


void push(S *s, void *item) {

  if (s->index < s->capacity)
    {
      printf("push at %d\n",s->index);
      s->container[s->index] = item;
      s->index += 1;
    } else{
    printf("Stack FULL\n");
  }
  return;
}

void *pop(S *s) {

  if(s->index == 0) {
    printf("Stack Empty\n");
    return NULL;
  }
  s->index--;
  printf("pop at %d\n",s->index);
  return s->container[s->index];
}



int main(int argc, char *argv[]){
  int *val;
  S *s = initS(10);

  for(int i=0;i<15;i++){

    push(s,(void *)&i);
  }

  for(int i=0;i<15;i++){

    val =(int *)pop(s);
  
    if(val){
      printf("%d ",*val);
    }
}

}
