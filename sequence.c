#include <stdio.h>
#include <stdlib.h>

//Kesavan T
//kethiruv@cisco.com

#define DR 0x1;
//Element of Linked list.
typedef struct elem_s {

  int start;
  int end;
  int diff;
  int flag; 
  struct elem_s *next;
} elem_t;

elem_t *new_elem(void) {
  elem_t *elem_p;
  elem_p = malloc(sizeof(elem_t));
  if (elem_p == NULL)
    {
      printf("Insufficient memory\n");
      return (NULL);
    }
  elem_p->next =0;
  elem_p->start=elem_p->end=elem_p->diff = 0;
  elem_p->flag =0;
  elem_p->flag |= DR;
  return elem_p;
}

/*
 * return valid elem_t pointer
 * return NULL : Failed to process or invalid input.
 * a pointer to array of sorted number in increasing order 
 * Range of number : range, must be greater than 0.
 */
elem_t *compress (int *a, int range) {
  int     begin  = 0;
  elem_t *elem_p = NULL;
  elem_t *prev   = NULL;
  elem_t *head;

  if (range <= 0){
    return NULL;
  }
 
  for (int i = 0; i < range; i++) {

    elem_p        = new_elem();
    elem_p->start = a[i];
    if(i+1 >= range) {
      elem_p->diff =0;
      elem_p->end = a[i];
      if(prev) {
	prev->next  = elem_p;
      } else {
	head = elem_p;
      }
      break;
    }
    elem_p->diff  = a[i+1] - a[i];

    //Find end of sequence with same difference
    while (i < (range-1) && elem_p->diff == (a[i+1] - a[i])) {
      printf("Debug: compressing  a[%d]= %d, a[%d]= %d, diff is %d\n", 
	     i, a[i], i+1, a[i+1], a[i+1]-a[i]);
      i++;
      if (i >= range) {
	printf("breaking i=%d, range =%d\n", i, range);
	break;
      }
    }
    elem_p->end = a[i];
    if (prev) {
      prev->next = elem_p;
    } else {
      head = elem_p;
    }
    prev   = elem_p;
    elem_p = NULL;
  }//End of Begin
  return head;
}




int main(int argc, char *argv[])  {

  int a[] = {1, 4, 7, 10, 11,12,14,16,17};
  int len = sizeof(a)/sizeof(a[0]);
  elem_t *p = compress(a,len);
  printf("Input Arrary size %d\n",len);

  while (p) {
    printf("%d %d d%d,\n", p->start,  p->end,p->diff);
    p = p->next;
  }
}
