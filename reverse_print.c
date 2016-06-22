#include <stdio.h>

void p_reverse( int val) {
	if(val == 0)
		return;
	 printf("%d ",val);
	 p_reverse(val-1);
}

int main(int argc, char *argv[]) {
	int val = 9;
	printf("Print numbers in reverse order using recursion  input %d(default)",val);
	p_reverse(val);
	return (0);
}