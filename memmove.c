#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
– If they do not overlap, you can copy in any direction
– If they do overlap, find which end of dest overlaps 
  with the source and choose the direction of copy accordingly.
– If the beginning of dest overlaps, copy from end to beginning
– If the end of dest overlaps, copy from beginning to end
*/
void mymove(void *dst , void *src, int size) {
  char *d =(char *)dst;
  char *s =(char *)src;

  if( size <= 0 || !dst || !src) {
    printf("invalid input\n");

    return;
  }

  if (d == s) {
    printf("dst %p src %p Equal PTRs no need to copy\n",d,s);
    return;
   }

  for (int i = 0; i < size; i++) {

    if(d == s+i ) {
      printf("Overlap detected at index %d  BEGINNING of DST overlaps, Copy  End-to-End\n",i);
      for(i=size-1; i>=0; i--) {
	d[i] = s[i];
      }
      return;
    }
  }
 
 for (int i = 0; i < size; i++) {
    if(s == d+i) {
      printf("Overlap detected at index %d  END of destination overaps, Copy Beg-to-Beg\n",i);
      for (i = 0; i<size; i++) {  
	d[i] = s[i];
      }
      return;
    }
 }
  
}


int main (int argc, char *argv[]) {
  char src[100] = {"123456789"};
  char *dst;
  int len = strlen(src);
  printf("src %s len %d\n",src,len);
  dst = ((char *)dst+8);
  mymove((void *)dst,(void *)(src),len);
  printf("src %s, dst(+8) %s %d\n",src,dst,len);
 
  // dst = ((char *)dst-8);
    //mymove((void *)dst,(void *)(src),len+1);
  //printf("src %s, dst(+8) %s %d\n",src,dst,len);
 

}
