#include <stdio.h>

//Note String pointers value, are in Data Section if not allocated memory
char * getDataStr(void) {
	char *str = "Hello";
	return str;
}
//Note: String Arrays are stored in Stack Section of Memory
//      Stack defined in an API can't be referenced outside, as stacks get deleted 
//      once function returns.
char * getStackStr(void) {
	char str[] = {"Hello"};
	return str;
}
int main(int argc, char *argv[]) {
	int i=1;
	enum { truee, falsee };
	//Data Section Print
	printf("Data Section : ptr-val %p %s\n",(void *)getDataStr(), getDataStr());
	//Stack Section Print
	printf("Stack Section : ptr-val %p %s\n",(void *)getStackStr(), getStackStr());
	
	printf("enum true = %d, false =%d\n", truee, falsee);
   //Note: Continue statement will evalute to while() before 
	// continue. 
   do
   {
      printf("%d\n", i);
      i++;
      if (i < 15)
        continue; //Will evaluate while
   } while (false);

   //Note: break statement will break loop, and 
   //does not evalute bottom while() condition
   do
   {
      printf("%d\n", i);
      i++;
      if (i < 15)
        break; //will exit do-while loop.
   } while (true);
/* 
http://www.geeksforgeeks.org/output-of-a-program-set-1/
Display Hex notation of negative and positive numbers,when
they are multiplied by 2 by left bit shift till there max
For 4byte int,   valid number range is  -2^31 to 2^31-1
*/
	for(i=0;i<32;i++) {
		printf("shift %-12d %-12d = 0x%-12x %-12d = 0x%-12x\n",i, -1<<i, -1<<i, 1<<i, 1<<i);
	}
}