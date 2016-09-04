#include <stdio.h>
#include <stdlib.h>

typedef struct lln {
    int val;
    struct lln *next;
} lln_t; 

lln_t *head;

void Insert (lln_t **head, lln_t *node, int position) {
lln_t *aux_node, *p_node = NULL;
int cur = 0;

if (*head == NULL){
    (*head) = node;
    (*head)->next = NULL;
    return;
}

if (position == 1) {
    node->next = (*head);
    (*head)    = node;
    return;
}

aux_node = (*head);

/* locate a node at position */
while (aux_node && (cur < position)) {
    p_node   = aux_node;
    aux_node = aux_node->next;
    cur++;
}

p_node->next = node;
if (aux_node) {
    node->next = aux_node;
}

}


/*
 * HEAD is not given , you delete node by copying value of next node to current node,
 * and deleting next node
 * Tip: Delete the next node
 */
void delete_node2 (lln_t *node) {
  if (!node) {
    return;
  }

  if (node->next)
  {
    node->val  = node->next->val;
    node->next = node->next->next;
    printf("Deleted node with value %d\n", node->next->val);
    free(node->next);
  } else {
    node->val = -1;
    printf("Can't delete, as next node is null, but marked as DUMMY\n");
  }
}

void delete_node (lln_t **head, int val) {
  lln_t *tmp, *tmp2;

  if (*head == NULL){
    return;
  }
  printf("delete_node: %d\n",val);
  tmp = *head;
  if ((*head)->val == val) {
    *head = (*head)->next;
    printf("Freeing head node with val %d\n", tmp->val);
    free(tmp);
    return;
  }

  while (tmp->next) {
    if(tmp->next->val == val) {
      tmp2= tmp->next;
      if(tmp2->next == NULL) {
	printf("Freeing last node\n");
	tmp->next = NULL;
      } else {
	tmp->next = tmp->next->next;
      }
      printf("Freeing node with val %d\n", tmp2->val);
      free(tmp2);
      return;
    }
    tmp = tmp->next;
  }
  printf("Node not found\n");
}

void delete_duplicate(lln_t **head) {
  lln_t *outer = *head;
  lln_t *inner; 
  int i = 0, j = 0;

  /* 1. Walk outerloop .
   * 2. Walk inner loop with rest of the node to find duplicate
   */
  while (outer) {
    i++;
    inner = outer;
    j = 0;
    while (inner) {
      j++;

      if (inner->next && inner->next->val == outer->val) {
	//Found duplicate
	printf("Found Duplicate nodes with index %d and index %d value %d\n",i, j, outer->val);
	inner->next = inner->next->next;
      } else {
	inner = inner->next;
      }
    }
    outer = outer->next;
  }  
}

void delete_all(lln_t **head) {

    lln_t *q, *tmp = *head;
    while (tmp) {
        q = tmp->next;
        printf("Freeing %d\n",tmp->val);
        free(tmp);
        tmp = q;
    }
    *head = NULL;
}

void print_ll(lln_t *node) {
    lln_t *tmp = node;

printf("\n");
 while(tmp) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
 }
 printf("\n");

}

/* Find kth element from the last */
int findKthLast (lln_t *node, int k) {
  lln_t *first, *second;
  /*
    Use two pointers, walk k elements, next walk till end while walking from head with another ptr
   */
  //Walk k elements first
  first = node;
  for (int i = 0; i < k; i++) {
    first = first->next;
    if (first == NULL)
      return (-1);
  }

  second = node;
  while (first) {
    first  = first->next;
    second = second->next;
  }  
  return second->val;
}

/*
 * Remember ********
 * Floyd Algorithm 
 * 1 = has loop, 
 *  0 = no loop
 * -1 = invalid input.
 */
int findLoop (lln_t *head) {
  lln_t *fastp, *slowp;
  int loop = 0;
  if (head == NULL) {
    return (-1);
  }
  fastp = head;
  slowp = head;
  // Check for NULL next pointers indicating no loop 
  while (slowp && fastp && fastp->next) {
    slowp = slowp->next;
    fastp = fastp->next->next;
    if (slowp == fastp) {
      loop = 1;
      printf("Found loop node-val %d\n", slowp->val);
      break;
    }
  }
 
  if (loop) {
    /* Find the loop length, by moving one step */
    fastp = fastp->next;
    while (slowp != fastp){
      fastp = fastp->next;
      loop++;
      printf("moving\n");
    }
  }
  return (loop); //No Loop
}

//Remember
/*
This trick might help you
there are three pointer ( prev, current, next)

next = current*
current* = prev
prev = current
current = next
NCPC
 */
void reverse (lln_t **head) {
  lln_t *current = *head;
  lln_t *next = NULL;
  lln_t *prev= NULL;
  
  while(current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
  printf("List reversed\n");

}

//TBD does not work
lln_t * reverse2(lln_t *head, lln_t *prev)
{
  lln_t *tmp = head->next;
  head->next = prev;
  if ( tmp != NULL) {
    reverse2(tmp, head);
  }
  return head;
}

int main(int argc, char *argv[]) {
/*
* LinkedList Operations
1. Insert or Delete at End,Beginning, Middle.
2. Count Nodes
3. Delete All.
*/
int    i = 1;
lln_t *node;
int    d = 0;
 lln_t *xnode; 
for (i=1; i <= 5; i++) {
    node       = (lln_t *)malloc( sizeof(lln_t) );
    node->next = NULL;
    node->val  = i;
    Insert(&head, node, 1);
    if(i==3) { //Some node copied for later use in 
      xnode = node;
    }
}

// Add Duplicate
for (i=1; i <= 5; i++) {
    node       = (lln_t *)malloc( sizeof(lln_t) );
    node->next = NULL;
    node->val  = i;
    //Insert(&head, node, 1);
}

//print_ll(head);
//head = reverse2(head, NULL);

print_ll(head);

reverse(&head);
 print_ll(head);
//Uncomment if you want this feature(Working)
//printf("Enter Kth Last Element index :");
//scanf("%d",&d);
//printf("\n");
//printf("Value of Kth Last %d\n", findKthLast(head,d));

delete_duplicate(&head);
print_ll(head);

//Create Loop and test code
node->next = head;
printf("Has %d length loop \n", findLoop(head));

//Undo loop
node->next = NULL;
print_ll(head);
printf("Has %d length loop now \n", findLoop(head));

print_ll(head);

delete_node2(xnode);

print_ll(head);

delete_node(&head, 8);
delete_node(&head, 1);
delete_node(&head, 3);
delete_node(&head, 5);

delete_all(&head);
print_ll(head);

}
