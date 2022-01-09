#include <stdio.h>
#include <stdlib.h>
/*
 * Given a number, find sum of its digits until it turns into single digit.
 * e.g 1234 = 1+2+3+4=10=1+0=1 
 */
int sumofdigits(int n) {
	int sum = 0;
	if (n < 10) {
		return n;
	}
	while (n > 0 || sum > 9) {
		if (n == 0) { //move to next level of sum
			n = sum;
			sum = 0;
		}
		sum += n%10;
		n = n/10;
	}
	return sum;
}

//Using Recursion
int sumofdigits_r(int n) {
	int sum = 0;
	if(n < 10)
		return n;
	while (n > 0 || sum > 9) {
		if (n == 0) { //move to next level of sum
			return sumofdigits_r(sum);
		}
		sum += n%10;
		n = n/10;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	int num = 0;
	printf("Enter a number:");
	scanf("%d",&num);
	printf("Sum of digits of %d=%d\n",num, sumofdigits_r(num));
}
