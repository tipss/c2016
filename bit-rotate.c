#include <stdio.h>

void printBits(size_t const size, void const * const ptr) {
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;

  for (i = size-1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  puts("");
}

int main(void) {
  int num = 0;
  printf("Enter a number to rotate: ");
  scanf("%d",&num);
  printf("Your entered: %d ", num);
  printBits(sizeof(num),&num);
}
