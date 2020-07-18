#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
*  1. An example of anagram, dog, god
*  2. Another example : cat act
*  3. All the chars must exit, but can be in any order.
* Steps to find if two strings are anagrams.:
*  1. Build an hash, count chars from str1
*  2. Use that hash, try decrement for every char that appeared. (it should not lead to -1)
*  3. Extend this logic to find anagrams in a string  
*/
int anagram (char *str1, char *str2 ,int len) {
  char t[256];
  int i;
  if (str1 == str2) {
    printf("Both str1(%s) and str2(%s) are same\n", str1, str2);
    return (-1);
  } 

  if (!str1  ||  !str2) {
    printf("Null input \n");
    return (-1);
  } 

  if (*str1 == 0) {
    printf("Str1 Empty\n");
    return (-1);
  }  
  printf("Testing Input string %s and %s are anagrams for len %d:", str1, str2, len);
  memset(t,0,256);
  i = 0;
  while (i < len) {
    //printf("Increment for  char %c at location %d\n",*str1, *str1);
    t[(*str1)]++; //Increment array element matching to char
    str1++;
    i++;
  } 

  i = 0;
  while (i < len) {
    //printf("Decrement for char %c at location %d\n",*str2, *str2);
    t[(*str2)]--;
    if (t[*str2] < 0)
      {
	printf("No\n");
	return (0);
      }
    str2++;
    i++;
  } 
  printf("Yes\n");
  return (1);
}

   int main (int argc, char *argv[]) {

       char str1[100]; 
       char str2[100]; 
       int ret, s1len, s2len;
       printf("Input a sentence and a strings, to test if sentence has anagrams of string:\n");    
       scanf("%s",str1);
       printf("\n");
       scanf("%s",str2);
       s1len = strlen(str1);
       s2len = strlen(str2);
       for (int i = 0; i< s1len; i++) {
       // Check if str1 has anagrams matching str2    
       // str1 may have multiple occurance of anagrams
       // Move one char starting from Left,until size is less than size of str2
       ret = anagram (&str1[i], str2, strlen(str2));
       if (ret) {
        printf("str1=%s has anagram of str2=%s, at location %d\n",str1,str2,i+1);    
       }

       if ((s1len - i) <= s2len)
            break;
       }
   }
