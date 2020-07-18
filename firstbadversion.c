#include <stdio.h>
#include <stdbool.h>
int bad_ver = 0;

bool isBadVersion(int n) {
  //Customer implements this,
  if (n > bad_ver) {
    printf("%d bad\n", n);
    return true;
  }
  printf("%d good\n", n);
  return false;
}


/*
 * Important: Remember this  Computers in O(logn)
 * Once a bad version no is detected, everything after that is a bad version.
 */
int firstBadVersion(int n) {
  int left  = 1;
  int right = n;
  int mid;
  while(left < right) {
    mid = left + (right - left)/2;
    if(isBadVersion(mid)) {
      right = mid;
    } else {
      left = mid+1;
    }
  }
  printf("left %d, right %d, mid %d\n", left, right, mid);
  return left;
}

int main(int argc, char *argv[]) {
  int ver = 0;
  //Finds in O(logn) first bad version
  printf("Input version number:");
  scanf("%3d",&ver);
  printf("Input start of bad version number:");
  scanf("%3d",&bad_ver);
  
  printf("Bad version number detected starting %d\n", firstBadVersion(ver));
  //Other approach is O(n) where, it walks till 1000 linearly.
}
