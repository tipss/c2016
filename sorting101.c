/*
* selection, insertion, bubble, shell, quick,
* heap  
*/
#include <stdio.h>
#include <stdlib.h>

/*
 O(n2),  due to loop in loop of order n
 * constant space(in place sort).
 * its not adaptive, its fixed iteration always.
 * 
 */
void selection_sort(int count, int **in) {
  int t, *tmp = *in;
  for (int i = 0; i < count; i++) {
    for (int j = i+1; j < count; j++) {
      printf("i %d, j %d\n", i,j);
      if (tmp[i] > tmp[j]) {
	t      = tmp[j];
	tmp[j] = tmp[i];
	tmp[i] = t;
      }
    }
  }
}

/*
 * needs addition space, but time complexity is way better then shell sort,
 * uses divide and conqure
 */
void merge_sort(int count, int **in) {
  TBD
}

/*
 * its like insertion sort but with order logn 
 */
void shell_sort(int count, int **in) {
}

/*
 O(n2),  due to loop in loop of order n
 * constant space(in place sort).
 * its adaptive, based on the input.
 * 
 */
void insertion_sort(int count, int **in) {
}

/*
 O(n2),  due to loop in loop of order n
 * constant space(in place sort).
 * its adaptive, based on the input.
 * 
 */
void bubble_sort(int count, int **in) {
  int t, *tmp = *in;
  int swapped = 0;
  for (int i = 0; i < count; i++) {
    swapped = 0;
    for (int j = 0; j < count - i; j++) {
      printf("Buble i %d, j %d\n", i,j);
     
      if (tmp[j] > tmp[j+1]) {
	t      = tmp[j];
	tmp[j] = tmp[j+1];
	tmp[j+1] = t;
	swapped = 1;
      }
      
    }
    if (swapped == 0) {
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  int len, *my_input;
  printf("Enter number of elements:");
  scanf("%d",&len);
  
  if(len < 2) {
    return(0);
  }

  my_input = (int *)malloc(len * sizeof(int));
  for(int i=0; i<len; i++) {
    printf("Enter %dth element: ",i);
    scanf("%d", &my_input[i]);
  }
  //  selection_sort(len, &my_input);
  printf("Asending Order Sorted list: \n");
  for(int i=0; i<len; i++) {
    printf("%d, ", my_input[i]);
  }
  bubble_sort(len, &my_input);
  printf("Asending Order Sorted list: \n");
  for(int i=0; i<len; i++) {
    printf("%d, ", my_input[i]);
  }
  free(my_input);
}


