#include<stdio.h>
#include <stdbool.h>
#include <string.h>

/* Must have matching character counts , position may not match */
bool anagram (char *str1, char *str2) {
    int A[256];
    int i = 256;

    /* Logic 
       count each char in string1 using CHAR hash/array 
       decrement for each char in string2 using same CHAR hash/array 
       If char count is less than zero, indicating that there was no matching char
       in previous string, so return false

       At the end return TRUE.
    */

    if( str1 == NULL || str2 == NULL){
        printf("Invalid Input strings \n");
        return false;    
    }

    if ( *str1 == 0 || *str2 == 0){
        printf("Empty Input strings \n");
        return false;    
    }
    printf("%ld %ld\n",strlen(str1),strlen(str2));
    //Initialize array to zero val
    for(i=0; i < 256; i++) {
        A[i] = 0;
    }

    //Loop until NULL char
    while (*str1) {
        A[*str1]++; 
        printf("%d ",*str1);
        ++str1;
    }

    printf("\n");
    //Loop until NULL char
    while (*str2) {
        printf("%d ",*str2);
        A[*str2]--; 
        if(A[*str2] < 0)
            return false;
        ++str2;
    }
    return true;    
}

int main(int argc, char *argv[])
{
    char str1[256]; 
    char str2[256]; 

    printf("Enter String1 for Anagram Test:");    
    gets(str1);
    printf("Enter String2 for Anagram Test:");    
    gets(str2);
    printf("Input %s and %s \n",str1,str2 );
    printf("%s and %s are %s anagram",str1,str2, anagram(str1,str2) ? " ":"NOT");
}



