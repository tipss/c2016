#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef union IP {
  unsigned int ip;
  struct {
    unsigned char d;
    unsigned char c;
    unsigned char b;
    unsigned char a;
  } ip2;
} ipu;


void print_num_to_ip_string(unsigned int num) {
  //Convert number into 4 bytes,
  unsigned char ip[4];

  ip[0]= num      & 0xff;
  ip[1]= num >>8  & 0xff;
  ip[2]= num >>16 & 0xff;
  ip[3]= num >>24 & 0xff;
  printf("%d.%d.%d.%d\n",ip[3],ip[2],ip[1],ip[0]);
}


void generate_ip_address_list (unsigned int subnet, unsigned int mask) {
  /* 
   * Use the mask and mask subnet,
   * increment the value until you hit the maximum number in that subnet range.
   */

  int shift = (32 - mask);
  int maskbit =  0xffffffff << (32 -mask);
  subnet = maskbit & subnet;
  subnet = (subnet >> shift);
  for(int i=0; i<10; i++){
    subnet +=1;
    print_num_to_ip_string(((subnet) << shift));
  }
}

int main (int argc, char *argv[]) {
  unsigned int num,mask;
  ipu u;
  printf("ENTER a number in hex, :");
  scanf("%x",&num);
  printf("InLine Coverstion to dotted IP : %d.%d.%d.%d\n",
	 ((unsigned char *)&num)[3],
	 ((unsigned char *)&num)[2],
	 ((unsigned char *)&num)[1],
	 ((unsigned char *)&num)[0]);
  print_num_to_ip_string(num);
  u.ip = num;
  printf("Using IP/Union Struct Coverstion to dotted IP : %d.%d.%d.%d\n", 
	 u.ip2.a, u.ip2.b, u.ip2.c, u.ip2.d);
  printf("ENTER mask len :");
  scanf("%d",&mask);

  generate_ip_address_list(num,mask);

}
