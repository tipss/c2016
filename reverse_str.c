#include <stdio.h>
#include <string.h>

int isPalindrome (char *str) {
	//Logic is walk from two ends of string back into center
	//Compare char by char to see if they are 
	char *end = str;
	if (str  == NULL)
		return 0;
	while (*end) {
		end++;
	}
	end--;
  
	while (end > str){
		if(*end != *str){
			printf("Mismatch %c and %c\n",*end,*str);
			return 0;
		}
		end--;
		str++;
	}
	return 1;
}

//Practice Practice this, not fit to reverse a string,
//use string-reversal program, this is good for a word reversal
void Reversed (char *in) {

	char  temp;
	char *end ;

	if (in == NULL ) {
		printf("NULL input\n");
		return;
	}

	if (*in == 0) {
		printf("Empty string input\n");
		return;
	}

	end = in;
	while (*end) {
		end++;
	}
	--end; 

	while (end > in) {
		temp  = *in;
		*in   = *end;
		*end =  temp;
		in++;
		end--;
	}
}

//Palindrome and Reverse string.
//Note, given a linked list,you can check if list forms a palindrome,
//That is different problem
int main(int argc, char *argv[]) 
{
	char  str1[] = {"123456789"};
	char *str2   =  NULL;
	char  str3[] = {""};
	char  str[1000];
	int   ret;
  
	printf("%s size %ld <Reversed> ", str1, strlen(str1));
	Reversed(str1);
	printf("%s\n", str1);  
	Reversed(str2);
	Reversed(str3);
	printf("Enter a string to check if its palindrome:");
	scanf("%s",str);
  
	ret = isPalindrome(str);
	printf("Its a %s palindrome\n",(ret==1) ? "":"not ");
}
