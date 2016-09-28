#include <stdio.h>
#include <stdlib.h>



/*
 * Given two numbers find, how many bit flips are needed to make them equal
 * Note: doing an     XOR , like A XOR B will give you number of 1's in location where
 * each number differ. If you count those number, you will find number of bits to flip. 
*/

int bitSwapRequired(int a, int b) {
  int c = a ^ b;
  int count =0;
  while(c != 0) {
    count += c&0x01;
    c = c >> 1;
  }
  return count;
}

void printBinary(int num){

  /* Prints in reverse direction
  while (num) {
    if (num & 1)
      printf("1");
    else
      printf("0");

    num >>= 1;
  }
  printf("\n");

  */

  // Use recursion to fix this
  if(num == 0) {
    printf("0");
    return;
  } else if(num == 1) {
    printf("1");
    return;
  }
  printBinary(num>>=1);
  if((num & 0x01) == 0) {
    printf("0");
  } else {
    printf("1");
  }
}

/*
 *   copy value of odd to even, eg. 0th bit value to 1st bit, 1stbit value to 2ndbit
 *   use a mask 0x1010 get odd bits
 *                3210  (1 and 3 bits)
 *      (x & 0x1010) >> 1 will make 1 move to 0, 3 move to 2(even).
 *  Similarl mask 0x0101  get even bits
 *                  3210  (0 and 2) bits
 *     (x & 0101) <<1 will make 0 move to 1, 2 move to 3
 * OR the above result  
 */
int swapOddEvenBits (int x){

  return (  ((x & 0xaaaaaaaa)>>1) | ((x&55555555)<<1));
}

/*
* Node if a number if power of two, it will have only 1 bit whose value will be 1
* On that number if we do n-1, it will flip all the bits, & operation on that
* will lead to zero
*/
int main (int argc, char *argv[]) {
  int num  = 0;
  int a, b;
  printf("Enter a number to check if its power of two:");
  scanf("%d",&num);
  printf("\n");
  if((num & (num-1)) == 0)
    {
      printf("its a power of two\n");
    }
  else {
                    
    printf("its not a power of two\n");
                    
  }
  printBinary(num);
  printf("\n");
  printf("swapped Odd Even bits : %d\n",swapOddEvenBits(num));
  printf("Find number bit flip required to make two numbers equal: Enter two number:");
  scanf("%d",&a);
  printf("\n");
 scanf("%d",&b);
 printf("\n");
 printf("\n");
 printBinary(a);
 printf("\n");
 printBinary(b);
 printf("\nNum of bit flips needed to make them equal %d\n",bitSwapRequired(a,b));

}
