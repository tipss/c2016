#include <stdio.h>
#include <stdlib.h>

void compress(char *str) {
  int j = 0;
  char *dest = str;

  while(*str) {
    printf("Copied %c\n",*str);
    dest[j++]=*str;
    while(*str && *str == *(str +1)){
      str++;
      printf("Skipping %c\n",*str);
    }
    str++;
  }
  dest[j++]='\0';
}

int main(int argc, char *argv[]){
  char str[1000];
  printf("Enter a String to compress:");
  scanf("%[^\n]s",str);
  printf("\nYou Entered:%s\n",str);
  compress(str);
  printf("Compressed :%s\n",str);
 
}
