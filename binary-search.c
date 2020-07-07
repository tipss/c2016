#include <stdio.h>
#include <stdlib.h>
//Remember recursive
/*
* Given an asending sorted array of numbers in a, with start index 0, 
* end index length of array, find index of x in a, with
* log(n) order.
*/
int binSearch2 (int a[], int l, int r, int x) {
  int mid;

  if (r >= l) {
    mid = l + (r-l)/2;
    printf("looking for %d, mid %d, l=%d,r=%d\n",x,mid,l,r);
    if (a[mid] == x)
      return (mid);
    if (a[mid] > x)  //Meaning x lies at the right half section
      return   binSearch2(a, l, (mid - 1), x);
    return binSearch2(a, (mid + 1), r, x);    
  }
  return (-1); // Not found
}

/*
 * Given an array of infinite length, how to do binary search ?.
 * Step1. Since there is not upper bound, we have to come up with some number,
          Locate approximate range , then use the range as input to binary search
 * Step2. Do binary search with modified range
 * Return the index, else -1 if not found 
*/
int findInInfiniteArray(int *a, int key){
  int val = a[0];
  int   l = 0;
  int   r = 1; //approximated high end of array

  while (val < key) {
    l = r;
    r = 2 * r;
    val = a[r];
    printf("high %d\n",r);
  }
  return binSearch2(a,l,r,key);
}

int main ( int argc, char *argv[]) {
    
    int a[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(a)/sizeof(a[0]);
    printf("array size %d\n", len);
    printf("Index of %d is %d\n",5, binSearch2(a,0,len,5));
    printf("Index of %d is %d(In Infinite Array method)\n",1, findInInfiniteArray(a,1));
    printf("Index of %d is %d(In Infinite Array method)\n",8, findInInfiniteArray(a,8));
    printf("Index of %d is %d(In Infinite Array method)\n",5, findInInfiniteArray(a,5));
}
