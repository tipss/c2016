#include <stdio.h>
#include <stdlib.h>

/*
* Given an asending sorted array of numbers in a, with start index 0, 
* end index length of array, find index of x in a, with
* log(n) order.
*/
int binSearch (int a[], int l, int r, int x) {
    int mid;

    if(l <= r) {

    mid = l + (r-1)/2;
    printf("looking for %d, mid %d\n",x,mid);
    if (a[mid] == x)
            return (mid);
    if (a[mid] < x)  //Meaning x lies at the right half section
    {
      return binSearch(a,mid + 1,r,x);
    }
 
    return binSearch(a,l, mid - 1,x);
    
    }
    return (-1); // Not found
}



int main ( int argc, char *argv[]) {
    int a[] = {1,2,3,4,5,6,7,8};
    printf("sizeof(a) %ld, sizeof(int) %ld\n", sizeof(a), sizeof(int));
    printf("Index of %d is %d\n",5, binSearch(a,0,8,5));
}
