#include <stdio.h>
#include <stdlib.h>

/*
 * Given a string s1 and string s2, find first occurance of string s2 in s1.
 * Can't use string.h library
 */



char * mysubstr(char *s1, char *s2) {

	char *o,*start,*i;
	// Outer loop moves char by char for s1,
	// Inner loop walks to see if chars in s2 match in s1.
	o = s1;
	i = s2;
	while (*o) {
		printf("working with s1=%s\n",o);
		start = o;
		while (*o && *i && *i == *o ) {
			i++;
			o++;
		}
		if (*i == '\0') {
			//Reached end of inner string matching with outer string.
			return start;
		}
		i = s2;
		o++;
	}
	return NULL;
}

int main (int argc, char *argv[]) {
	char s1[100];
	char s2[100];
	char *ret = NULL;

	printf("Enter string s1:");
	scanf("%s",s1);
	printf("\n");
	printf("Enter string s2(substring):");
	scanf("%s",s2);
	printf("\n");
	ret=mysubstr(s1,s2);
	if(ret)
	{
		printf("s1=%s has substring s2=%s at %s\n",s1,s2,ret);
	}
}
