#include <stdio.h>
#include <stdlib.h>

void fun(char *t, unsigned int *p) {
    printf("Inside Function\n");
  printf("sizeof t, as in t[40] is :%ld\n",sizeof(t));
  //Notices that this print size of pointer, which does not understand len of array
  printf("sizeof p, as in p[10] is :%ld\n",sizeof(p));
  //Notice that this prints size of pointer, which does not understand len of array.
    printf("Exit Function\n");
}

int main (int argc, char *argv[]) {
  char t[40];
  unsigned int *p[10];

  fun( t, p[0] );
  printf("sizeof(int):%ld\n",sizeof(int));
  printf("sizeof t, as in t[40] is :%ld\n",sizeof(t));
  // Notice that this prints size of array
  printf("sizeof p, as in p[10] is :%ld\n",sizeof(p));
  //Notices that this print 80, meaning 10 times the pointer size.

}
