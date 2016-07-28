#include <stdio.h>
#include <string.h>
/* 
* 1. Walk an string array char by char, count spaces
* 2. Now set the size of new array, as you get to replace every space with %20
* 3. Walk string back wards and replace spacw with %20
*/


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

int main(int argc , char *argv[]) { 
    char a[256] = {"Five Spaces In One Sentence "};
    printf("In: %s\n Num New Len: %d \nNew Str %s", a, ReplaceSpaces(a, strlen(a)), a);
}

