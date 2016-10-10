#include <stdio.h>
// or isBitSet()
int getBit (int in, int index) {
  if ((in & (0x1 << index)) == 0)
    return 0;
  else 
    return 1;
}

int setBit (int in, int index) {
  return (in | (0x1 << index));
}

int clearBit (int in, int index) {
  int mask = ~(0x1 << index);
  return (in & mask);
}

int bitCount(unsigned int n) {
  int count =0;
  while (n){
    count += n&0x1;
    n>>=1;
  }
  return count;
}

void printBin(int n) {
  if(n > 1)
    printBin(n/2);
  printf("%d", n%2);

}


//SetBit , where the bit is inside an array or integer
void  SetBit( int A[],  int k )
{
  A[k/32] |= 1 << (k%32);  // Set the bit at the k-th position in A[i]
}
//ClearBit : where the bit is inside an array of integer
void  ClearBit( int A[],  int k )                
{
  A[k/32] &= ~(1 << (k%32));
}



void printTwoSetBitNums(int n)
{
  // Initialize higher of two sets bits
  int x = 1;
  int num;
 
  // Keep reducing n for every number
  // with two set bits.
  while (n > 0)
    {
      // Consider all lower set bits for
      // current higher set bit
      int y = 0;
      while (y < x)
        {
	  // Print current number
	  num = (1 << x) + (1 << y);
	  printBin(1<< x);
	  printf(" %d \n",1<<x);

	  printBin(1<<y);
	  printf(" %d \n---\n",1<<y);

	  printBin(num);
	  printf( " %d \n\n",num);
 
	  // If we have found n numbers
	  n--;
	  if (n == 0)
	    return;
 
	  // Consider next lower bit for current
	  // higher bit.
	  y++;
        }
 
      // Increment higher set bit
      x++;
    }
}
 
/* Find Bit pattern in an array of int bytes */
//Look for solution here
//http://stackoverflow.com/questions/1284581/finding-a-bit-pattern-in-a-32bit-unsigned-integer
int main (int argc, char *argv[]) {
  int i = 0xff;
  printf("i= 0x%x RightMost Bit %s\n",i,getBit(i,0)?"SET":"UNSET");
  printf("i= 0x%x LeftMost Bit %s\n",i,getBit(i,sizeof(i)*8)?"SET":"UNSET");
  i = 0;

  printf("i= 0x%x RightMost Bit %s\n",i,getBit(i,0)?"SET":"UNSET");
  printf("i= 0x%x LeftMost Bit %s\n",i,getBit(i,sizeof(int)*8)?"SET":"UNSET");
  printf("i= 0x%x RightMost SetBit 0x%x\n",i,setBit(i,0));
  printf("i= 0x%x LeftMost SetBit 0x%x\n",i,setBit(i,8*sizeof(int)-1));
  i = 0xffff;
  printf("i= 0x%x LeftMost ClearBit 0x%x\n",i,clearBit(i,8*sizeof(int)-1));
  for (i = 0; i< 20; i++) {
    printf("\ni = %d, bit count %d  ",i,bitCount(i));
    printBin(i);
    
  }

  printf("\nPrinting first 4 number whose 2 bits are set:\n");
  //Print 4 number whose 2 bits are set,starting from number zero
 printTwoSetBitNums(4);
 
} 
