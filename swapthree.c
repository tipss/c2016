#include <stdio.h>

void swapThree(int *a, int *b, int *c)
{
  // Store sum of all in a
  *a = *a + *b + *c;  // (a = 60)
  
  // After this, b has value of a
  *b = *a - (*b+*c);  // (b = 60 – (20+30) =10)
  
  // After this, c has value of b
  *c = *a - (*b+*c);  // (c = 60 – (10 + 30) = 20)
  
  // After this, a has value of c
  *a = *a - (*b+*c);   //(a = 60 – (10 + 20) = 30)
}

int main(int argc, char *argv[]) {
  int a = 10;
  int b = 20;
  int c = 30;
  
  printf("Before Swap a=%d, b=%d, c=%d\n", a, b, c);
  swapThree(&a, &b, &c);
  printf("After Swap a=%d, b=%d, c=%d\n", a, b, c);
}
