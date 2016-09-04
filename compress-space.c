#include <stdio.h>
#include <stdlib.h>


void compress(char *str) {
  int num_space = 0;
  int j = 0;
  char *dest = str;
  if (!str) {
    return ;
  }

  //1. Result will be equal or less than equal size of incoming string
  //   so no need to worry about size of new string
  //2. Walk, and copy only what is needed using inner counter into dest string

  while (*str) {
    // Skip spaces, but only copy one space
      while (*str && *str == ' ')
      {
	num_space++;
	str++;
      }

    if (num_space ) {
      printf("num_spaces %d %c\n", num_space, *str);
      num_space = 0;
      dest[j++] = ' ';
    }
 
    dest[j++] = *str;
    str++;
    
  }
  dest[j++] = '\0';
  
}


int main(int argc, char *argv[]) {
  char str[] = {"  I   have    more    spaces "};
  printf("input %s\n", str);
  compress(str);
  printf("output %s\n", str);
  
}
