#include <stdio.h>
#include <string.h>


//Assume string has enough length to replace with '%20' char
void replacespace (char *str) {
  int len, newlen, j, space_count=0;
  char *tmp;
  if (!str) {
    return;
  }
  //1. Scan and find number of spaces and estimate the size of the new string
  len = strlen(str);
  tmp = str;
  while(*tmp) {
    if(*tmp == ' ') {
      space_count++;
    }
    tmp++;
  }
  printf("len %d, space-count %d, new len %d\n", len, space_count, len + 2*space_count);
  //2. Copy from end of the string
  str[newlen-1] = '\0';
  j= newlen = len + 2 * space_count;
  for (int i = len-1; i >= 0; i--) {
    if (str[i] == ' ') {
      str[--j] = '0';
      str[--j] = '2';
      str[--j] = '%';
    }
    else {
      str[--j] =  str[i];
    }
  }
}


int main(int argc, char *argv[]) {

  char str[33] = {" this has five spaces "};
  printf("input :%s\n",str);
  replacespace(str);
  printf("o-put :%s\n",str);
}
