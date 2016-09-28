#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Replace repated chars with number , 
//representing number of time the char repeated, including spaces
//This works well, users responsibility to send string longer than needed
//Limitation : It does not add count, if its only one char.
//             Thus , size will not increase more than input str.
void compressWithCount(char *str) {
  char *dest = str;
  int j=0;
  int count =0;
  char num[10];
  int len = 0;
  
  while (*str) {
    //Skip Repeated Chars
    while (*str && *(str+1) && *str == *(str+1)) {
      count++;
      str++;
    }
    dest[j++]= *str;
    if (count) {
      len = sprintf(num, "%d",count+1);
      //Copy count
      printf("Copying number %d of len %ld\n",count, strlen(num));
      for (int i = 0; i < len; i++) {
	dest[j++] = num[i];
      }
      count = 0;
    } 
    str++;
  }
  dest[j] = '\0';
}

//Just remove anything repeated
void compress (char *str) {
  int j;
  char *dest = str;
  if(!str )
    return;

  while (*str) {
    while (*str && *(str+1) && (*str == *(str+1))) {
      //Skip,
      str++;
    }
    dest[j++] = *str;
    str++;
  }
  dest[j] = '\0';
}

//Just remove spaces
void removespace(char *str){
  int j = 0;
  char *dest= str;
  //Validate string for not null or not empty.
  // Maintain one index j copy only when needed;
  // In a while loop check for char being not null
  // Skip spaces.
  // When no space, start copying.

  while (*str) { //While its not a null char 
    while (*str && *str == ' ') { //While its spaces, skip to next char.
      str++;
    }
    //printf("Copied char %c\n",*str);
    //While its not a space char, copy it into new location indexed by j
    dest[j++]= *str;
    str++;
  }
  str[j] = '\0';
}

//Replace space with %20
int ReplaceSpaces (char *str,int size) {
   int j,i, count = 0,newsize=0;
   for (i = 0; i < size; i++) {
       if (str[i] == ' ') {
           count++;
       }
   } 

   newsize = size + (count * 3);
    j = newsize;
    str[j]    = '\0';
    //str[size] = ' ';
   for (i = size -1; i >= 0; i--) {
    //Replace space
       printf("char at s index %c\n",str[i]);
    if (str[i] == ' ') {
       printf("Replacing space at index %d\n",i);
       count++;
       str[j-1] = '0';
       str[j-2] = '2';
       str[j-3] = '%';
        j = j - 3;
    } else {
       printf("Found no-space at index %d\n",i);
       str[j-1] = str[i];    
       j = j -1;
    } 
   }
   printf("\n Len %d new size %d ReplaceSpaces%s\n",size, newsize, str);
    return newsize;
}

//Replace every space with the string given
void replaceSpaceWithSpecialStr (char *str, char *replace){
  int new_len,len, count = 0;
  //Because dest string length is greater than original string, 
  //a reverse walk is the best approach after securing dest string lenght
  // 1. Could spaces, estimate length
  // 2. Copy in reverse order.
  new_len = strlen(str);
  char *dest = str;
  char *in = str;
  while (*str) {
    while (*str && *str == ' ') {
      count++;
      str++;
    }
    str++;
  }
  str--;
  new_len += count * strlen(replace);
  
  dest[new_len] ='\0';
  printf("number of spaces = %d, strlen(str) %ld dest %s\n",count,strlen(str),dest);
  //Walk reverse.
  while (new_len >= 0) {
    printf("new_len = %d\n", new_len);
    if (*str == ' ') {
      len = strlen(replace);
      while(len){
	printf("len %d\n",len);
	dest[new_len--] = replace[--len];
      }
    } else {
      dest[new_len--] = *str;
    }
    printf("%s\n",in);
    str--;
  }

}


int main (int argc, char *argv[]) {

  char str1[100];
  char a[256] = {"Five Spaces In One Sentence "};
  printf("Enter String to Compress:\n");
  scanf("%[^\t\n]s", str1);
  printf("you entered : %s, len %ld\n", str1, strlen(str1));
  //removespace(str1);
  //printf("Space removed version: %s len \n",str1,strlen(str1));
  compressWithCount(str1);
  printf("Compressed string with count : str2 = %s\n",str1);
  //replaceSpaceWithSpecialStr(str1,"%20");
  //printf("Compressed version with counts: %s len %ld\n",str1, strlen(str1));
  //printf("In: %s\n Num New Len: %d \nNew Str %s", a, ReplaceSpaces(a, strlen(a)), a);

} 
