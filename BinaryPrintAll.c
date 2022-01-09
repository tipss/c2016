#include <stdio.h>
/* 
:Print all binary number , given number of bits.
Recursively 
*/
char A[6] = {0};
void Binary (int n) {

	if (n < 1) {
		printf("%s\n", A);
		return;
	}

	A[n-1] = '0';
	Binary(n-1);

	A[n-1] = '1';
	Binary(n-1);
}

int main (int argc, char *argv[]) {
  Binary(5);
}
