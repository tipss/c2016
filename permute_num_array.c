#include <stdio.h>

void swap(int *a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

/*
 * Swap each element with available elements in each iteration.
 * When swapped, recurese with permute for the rest of the array
 * Running time is n factorial
 */
void permute(int *a, int l, int r) { 

  if (a == NULL) { 
    return;
  }

  if ( l == r-1) {
    for(int i = 0; i < r; i++){
      printf("%d ", a[i]);
    }
    printf("\n");
  } else {
    for (int i=l; i < r; i++) {
      swap(a, l+1, i);
      permute(a, l+1, r);
      swap(a, l+1, i);
    }
  }
}

int main(int argc, char *argv[]) {
  int a[] = {1,2,3,4,5};
  int size = sizeof(a)/sizeof(a[0]);

  //Prints all permutations of given number array
  permute(a,0,size);

}
