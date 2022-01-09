#include <stdio.h>
#include <stdlib.h>
/*
e.g 
Input number
987654321
987654321=> 0
98765432=> 1
9876543=> 12
987654=> 123
98765=> 1234
9876=> 12345
987=> 123456
98=> 1234567
9=> 12345678
0=> 123456789
 */

/* Reverse digit like mirror   123 will become 321,
*  e.g 5225 will become 5225, ! so a palindrome test can be done using this */

void reverse(int input) {
	int rightdigit;
	int sum = 0;
	while (input >0) {
		printf("%d=> %d\n", input, sum);
		rightdigit = input % 10;
		printf("%d,", rightdigit);
		sum = sum * 10 + rightdigit;
		input = input/10;
	}
	printf("%d=> %d\n", input, sum);
  
}

int main(int argc, char *argv[]) {
	unsigned int d = 0;
	printf("Input number \n");
	scanf("%d", &d);
	reverse(d);
}
