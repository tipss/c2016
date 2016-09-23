/* code with memory leak 
gcc -o leak ./leak.c
Use valgrind tool to check memory leak as below::wq

valgrind --leak-check=full ./leak
*/
#include <stdio.h>
#include <stdlib.h>
 
 int main(void)
 {
         int *ptr = (int*)malloc(10);
          
              return 0;
 }
