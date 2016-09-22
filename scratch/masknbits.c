#include<stdio.h>
#include<stdlib.h>

/* Given two integers,
*  1. Mask n bits from int A into int B starting at location x of B
*/

unsigned int copynbits(unsigned int src, unsigned int dst,unsigned int n, unsigned int x){
   //Generate mask 
   int mask = (src & ((0x1 << n)-1)) << (x+n-1);
   int clearMask = dst & ~((0x1 << n) - 1) << (x+n-1);
   return (mask | clearMask);
}

int binary_conversion(int num)

{
  if (num == 0)
    {
      return 0;
    }
  else
    {
      return (num % 2) + 10 * binary_conversion(num / 2);
    }
}

void printBinary(unsigned int n) {

  if (n==0) {
    return;
  }

  printBinary((n >>= 1));
  if (n&0x1) {
    printf("1");
  } else {
    printf("0");
  } 
} 
 int main (int argc, char *argv[]) {
     int d1, d2, d3, x, n;
 printf("input two numbers:");    
 scanf("%d",&d1);
 scanf("%d",&d2);
 printf("input n bits to copy:");
 scanf("%d",&n);
 printf("input destination location x to copy in to second number:");
 scanf("%d",&x);
 printf("Input Numbers 0x%x and 0x%x, mask %d bits of second number starting from %d\n",d1,d2,n,x);
 printf("Binary\n");
 for(int i=0;i<d1;i++)
 { 
   //printf("%d \n",binary_conversion(i));
 }
 printf("%d \n",binary_conversion(d1));
 printf("%d \n",binary_conversion(d2));
 d3 = copynbits(d1,d2,n,x);
 printf("----------------\n");
 printf("%d \n",binary_conversion(d3));
 printBinary(d3);
 } 
