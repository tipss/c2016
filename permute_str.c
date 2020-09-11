#include <stdio.h>
#include <string.h>

/*
 * Note : in Permutation, position of an element is unique, 
          that makes it different from combination.
 * ab : ab, ba are permutations, 
 * But 'ab' is the combination, 
        as you can't call 'ba' as one more combination.
 */
/*
 * Given a string of n chars,taken r char at a time, find all permutation of string,
 *  The number of permutations of n objects taken r at a time is determined 
 *  by the following formula: P ( n , r ) = n! / ( n − r )! 
 *  n = 3, r = 3,
 *  3!/(3-3)! = (3 * 2 *1 * 1)/1 = 6
 *  exampe permutation of ABC are : ABC, ACB, CAB, CBA, BAC,BCA
 *  n = 3, r = 2
 *  3!/(3-2)! = 6/1 = 6
 *  AB AC BA BC CA CB
 *
 * Combination of a,b,c is   n! / [r! * (n-r)!] 
 *  n = 3, r = 3,
 *  3!/ 3! *(3-3)! = (3 * 2 *1 * 1)/3! = 1
 *  example combination of ABC are : ABC,  Note : BAC will not be another combination,
 *  n = 3, r = 2
 *  3!/ [2! *(3-2)!] = 6/2 = 3
 *  AB AC CB , Note BA is not another combination
 * 
 */
void swap_char(char *a, char *b){
  char t;
  t = *a;
  *a = *b;
  *b =t;
}
//recursion
void permute (char *str, int l, int r) {
  static int i = 1;
  if (l == r) {
    printf(" %d %s\n", i++, str);
  } else {
    for(int i=l; i <= r; i++) {
      swap_char(str+l, str+i);  // Swap char at location pointed by l
        permute(str,   l+1, r);   // Permute starting from next char of l
      swap_char(str+l, str+i);  // Restore the char at location pointed by l
      // before moving to replace with another char available
    }
  }
}
//Factorial of 0 and 1 is 1
int fact(int n) {
  if(n <= 1)
    return 1;
  return fact(n-1) * n;

}


/* This works also, its simple to read ad remember
void swap(char *str, int i, int j) {
  char t;
       t = str[i];
  str[i] = str[j];
  str[j] = t;
}

void per(char *str,int l,int r) {

  if (l == r) {
    printf("%s\n",str);
    return;

  } else {

    for (int i=l; i<r; i++) {
      swap(str, l,   i);
       per(str, l+1, r);
      swap(str, l,   i);
    }

  }
  return;
}


int main(int argc, char *argv[]){
  printf("Permutation of %s len %ld:\n", argv[1], strlen(argv[1]));
  per(argv[1],0,strlen(argv[1]));

}
*/

int main(int argc, char *argv[]) {
  char str[100];
  int len;
  int takenatatime=0;
  printf("Enter a string:");
  scanf("%s", str);
  printf("Items taken at a time :");
  scanf("%d",&takenatatime);
  printf("Permutation:\n");
  len = strlen(str);
  printf("expect %d! / (%d - %d)! = %d results\n", len, len, takenatatime, 
	 fact(len) / fact(len-takenatatime));
  permute(str,0,len - 1);
}
