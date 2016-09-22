#include <stdio.h>
#include <stdlib.h>
#include <string.h>






typedef struct node_t {
    int val;
    struct node_t *next;
    } node;



//Find Kth to last element

//Given head, for unsorded Linked List, remove duplicate nodes
void rem_duplicates(node *nd) {
    //Use two pointer method.
  node *current = nd;
  node *next = nd;

  while(current) {

    next = current;
    while (next && next->next && current->val == next->next->val){
      if(next->next->next)
           next->next = next->next->next;
      else 
	next->next = NULL;
      next = next->next;
      //You can use temp and free nodes TBD
    }
    current= current->next;
  }
    
}


void print_ll(node *nd){
  printf("Printing linked list:");
  while (nd) {
    printf("%d ",nd->val);
    nd = nd->next;
  }

}

void insert(node **nd, int val) {
  node *new = malloc(sizeof(node));
  node *temp = *nd;
  node *prev = NULL;

  new->val = val;
  new->next = NULL;
  if(*nd == '\0')
    {
      printf("Insert root node\n");
      *nd = new;
      return;
    } 
  //Insert at the end of list
  while(temp){
    prev = temp;
    temp = temp->next;
  }
  if (prev) {
    printf("Insert non root node\n");
    prev->next =new;
  } else {

    printf("Error\n");
  }
  return;
}


int main(int argc, char *argv[]) {
  node *root = NULL;
  int val;
  printf("Insert nodes into linked list:");
  for(int i=0; i<10; i++) {
    scanf("%d",&val);
    insert(&root,val);
  }
  printf("Printing\n");
  print_ll(root);
  rem_duplicates(root);
  printf("Duplicates removed:");
  print_ll(root);
  printf("\n");

}
