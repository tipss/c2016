#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*
 * Compress string: e.g   caat  -> cat
                    e.g   cat   is -> cat is
 */
void compress (char *str) {
  /* Walk the string char by char, copy into new string */
  /* Inner loop counts repeat chars, when exits, copies number into string */
  int len = strlen(str);
  int i, j = 0;

  for (int i = 1; i <= len; i++) { 
    printf ("str[%d] = %c\n", i, str[i]);
    while (str[j] == str[i] && j >= 0) {
      i++;
      j--;
    }
    str[++j] = str[i];
  }
}

int main (int argc, char *argv[]) {
    
  char str[] = { "AABCCBCBA" };    

  printf("Input  %s\n", str);
  compress(str);
  printf("output:  %s\n", str);
    
}
