/* Question: Generate all permutations of a string. 
  * E.g. if the string is 'abc', we would have 
  * { 'abc', 'acb', 'bac', 'bca', 'cab', 'cba'}
  */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
*  Given an string 'a' , swap its chars at locations i and j
*/
 void my_swap_char(char *a , int i, int j) { 
     char x;
     x    = a[i];
     a[i] = a[j];
     a[j] = x;     
 }   
/*
* Input str: Valid NULL terminated string, 
* Input l: start index,
* Input r: end index.
*/
 void my_permutation(char *str, int l, int r) {
    int i;
    /* Handle invalid inputs*/
    if (str == NULL) {
        printf("Invalid input\n");
        return;
    } 
    
    if (l < 0){
        printf("Invalid start index\n");
        return;
    }
    
    if (r < 0) {
        printf("Invalid end index\n");
    }
    
    /* Print an unique string here as output */
    if (l == r) {
        out_count++;
        printf("%s out_count %d\n", str, out_count);
        return;
    }
    
    for(i = l; i < r; i++) {
        my_swap_char(str, l, i);
        my_permutation(str, l+1, r);
        my_swap_char(str, l, i);
    }
    return;
 }

int main() {
    char str[] = { "abc" };
    printf("Calling my permuation function for the string value %s\n", str);
    my_permutation(str, 0, strlen(str));
    return 0;
}
