#include <stdio.h>
void reverseString(char *str) {
	if (*str)
	{
		reverseString(str+1);
		printf("%c", *str);
	}
}
void p_reverse( int val) {
	if(val == 0)
		return;
	 printf("%d ",val);
	 p_reverse(val-1);
}

int main(int argc, char *argv[]) {
	int val = 9;
	char str[]={"knuj"};
	printf("Print numbers in lower order using recursion  input %d(default)",val);
	p_reverse(val);
	printf("Reverse of : %s is : ",str);
	reverseString(str);
	printf("\n");
	return (0);
}
