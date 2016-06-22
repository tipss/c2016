#include <stdio.h>
#include <stdlib.h>

typedef struct lln {
    int val;
    struct lln *next;
} lln_t; 

lln_t *head;

void Insert(lln **head, lln *node, int position) {
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

void delete_node (lln_t **head, lln_t *node) {
//TBD
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

int main(int argc, char *argv[]) {
/*
* LinkedList Operations
1. Insert or Delete at End,Beginning, Middle.
2. Count Nodes
3. Delete All.
*/
int i = 1;
lln_t *node;

for(i=1; i<=5; i++) {
    node       = (lln_t *)malloc( sizeof(lln_t) );
    node->next = NULL;
    node->val  = i;
    Insert(&head, node, 1);
}

print_ll(head);
delete_all(&head);
print_ll(head);
}
