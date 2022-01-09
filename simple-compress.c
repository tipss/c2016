#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_RLEN 50

/* 
   Compress string by replacing repeating characters 
   with number at the end of repetation 
   expects taht input string is succfiently long 2x just to 
   address strings where    no char repeats, after convertion 
   they become 2xlen , eg   abc  => a1b1c1
*/
void str_compress(char str[]) {
	
	char  *in = str;
	char tmp[100]; /* private copy while working is good, as it will allow you to walk original string */
	char *out = tmp;
	/*
	  Walk 1 char, copy, find cound of repeated char,copy that , and continue;
	*/
	while (*in) {
		out[0] = in[0];
		int count = 1;

		while (in[0] == in[1]) {
			count++;
			in++;
		}

		in++;
		out++;

		if (count > 1) {
			out += sprintf(out, "%d", count);
		}
	}
	out[0] = '\0';
	strcpy(str, tmp);
}


int main()
{
  char str[]  = "1111111111111111111geeksforgeeks";
  char str2[] = "AAAABBBCCCCCCDDDEFGHHIJJ";
  
  printf("InPut: %s\n", str2);
  str_compress(str2);
  printf("output: %s\n", str2);
}
