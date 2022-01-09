#include <stdio.h>
#include <stdlib.h>

/*
 * Input a and b are null terminated string
 * return 0 both string are same
 *        -1 if a is greater than b
 *         1 if a is smaller than b 
 *         -5 If error
*/
int compare (char *a, char *b) {
	if (a == NULL || b == NULL) {
		return (-5);
	}
	while (*a && *b) {
		if (*a == *b){
			a++;
			b++;
		} else if (*a > *b){
			return (-1);// a is greater.
		} else {
			return (1);
		}    
	} //End of While.

	if ((*a == '\0') && (*b =='\0')) {
		return (0);// a==b
	} else if (*b =='\0'){
		return (-1);//a is greater
	}
	return (1); //a is less
}

int main(int argc, char *argv[]) {
	char a[100];
	char b[100];

	printf("Input string a:");
	scanf("%s",a);
	printf("Input string b:");
	scanf("%s",b);
	printf("compare output %d\n",compare(a,b));
}
