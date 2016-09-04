#include <stdio.h>

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
  
} 
