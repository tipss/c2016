#include <stdio.h>
#include <string.h>








void reverse (char *str, char *end) {
  char temp;
  printf("In %s \n", str);
  while (str && end && str < end) {
    temp = *end;
    *end = *str;
    *str = temp;
    str++;
    end--;
  }
  printf("out %s \n",str);
}

/*
 * Reverse string word by word
*/
void reverse_string(char *str) {
  char *temp = str;
  char *end;
  char *beg;

  printf ("Input :%s\n", str);
  beg = str;

  while (*temp) {
    temp++;
    if (*temp == '\0') {
      reverse(beg, temp-1);

    } else if(*temp == ' ') {
      reverse(beg, temp - 1 );
      beg = temp + 1;
    }
  }
  reverse (str, temp-1);
}


int main(int argc, char *argv[]) {

  char str[] = "first second third";  //Should become : third second first 
  reverse_string(str);
  printf("Output : %s\n",str);
}


