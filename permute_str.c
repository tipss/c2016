#include <stdio.h>
#include <string.h>
/*
 * Given a string of n chars,taken n char at a time, find all permutation of string,
 * The number of permutations of n objects taken r at a time is determined 
 * by the following formula: P ( n , r ) = n ! ( n − r ) ! 
 * A code have 4 digits in a specific order, the digits are between 0-9.
 *  n = 3, r = 3,
 *  3!(3-3)!= 3 * 2 *1 * 1= 6
 *  ABC : ABC, ACB, CAB, CBA, BAC,BCA
*/


void swap_char(char *a, char *b){
  char t;
  t = *a;
  *a = *b;
  *b =t;
}

void permute (char *str, int l, int r) {
  static int i=1;
  if(l == r) {
    printf(" %d %s\n", i++, str);
  } else {
    for(int i=l; i <= r; i++) {
      swap_char(str+l, str+i);
      permute(str,l+1,r);
      swap_char(str+l, str+i);
    }
  }
}
//Factorial of 0 and 1 is 1
int fact(int n) {
  if(n <= 1)
    return 1;
  return fact(n-1) * n;

}

int main(int argc, char *argv[]) {
  char str[100];
  int len;
  printf("Enter a string:");
  scanf("%s", str);
  printf("Permutation:\n");
  len = strlen(str);
  printf("expect %d! * (%d - %d)! = %d results\n",len,len,len,fact(len));
  permute(str,0,len - 1);
}
