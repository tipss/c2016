#include <stdio.h>

/* Attempt to access memory location which its not supposed to 
* access(like read only moemory) 
*/
int main (int argc, char *argv[]) {
    
char *s = "hello world";
int *ptr = NULL;
//1
*s   = 'H';  //Creates BUS error, memory alignment requirements not met
              //Wrong kind of address 
             // assigning char to a string ?
//2
*ptr = 1;  //Creates Segmentation Fault, Writing to invalid address
          // Various reason can cause segmentation fault
          //Using Null Ptr
          //overflowing buffer
          //using uninitialized ptr
         //Using a pointer to , that was de allocated 
//3
main(0,NULL);  //Leads to stack overflow, leading to segmentation fault 
}
