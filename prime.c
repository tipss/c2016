#include <stdio.h>
#include <stdlib.h>
/*
 * A number which is only divisible by 1 or itself is a a prime number.
 * e.g 2, 3,5, 7, 11 13 17
 * 2 is the only even and smallest prime number
 */
int isPrime(int n) {
	if (n == 2)
		return 1;
	if (n == 1)
		return 0;
	for (int i = 2; i < n; i++) {
		if(n%i == 0)
			/* Not a prime */
			return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	printf("isPrime:?:%d\n",isPrime(num));
}
