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

//Remember, its works
// Also n%2 prints 1 for odd number and zero for even number
void bin(unsigned n)
{
  /* step 1 */
  if (n > 1)
    bin(n/2);
 
  /* step 2 */
  printf("%d", n % 2);
}

/*
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
  printf("swapped Odd Even bits : %d\n",swapOddEvenBits(num));
  printf("Find number bit flip required to make two numbers equal: Enter two number:");
  scanf("%d",&a);
  printf("\n");
 scanf("%d",&b);

 printf("\nNum of bit flips needed to make them equal %d\n",bitSwapRequired(a,b));
 for (int i=0;i< 32;i++){
   bin(i);
   printf("\n");
 }
}
