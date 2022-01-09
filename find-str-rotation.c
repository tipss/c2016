
#include <stdio.h>
#include <string.h>
/*
 Given , say s1= waterbottle
             s2= terbottlewa
 Find if s2 is a rotation of s1

 Logic:    strcat(s1,s1)= waterbottlewaterbottle
           use strstr to find substring 's2' in the above.
 */
int isRot(char *s1, char *s2) {
	char *substr = NULL;
	char  temp[100] = { 0 };

	//TBD length must be same
	//Must use temp string to safely concat two same strings(Remember)
	strcpy(temp,s1);
	strcat(temp,s1);
	printf("new modified string is :%s, will find substring %s \n",temp,s2);
	substr = strstr(temp, s2);
	if(substr) {
		return 1;
	} else {
		return 0;
	}
}

int main(int argc, char *argv[]) {
	char s1[100] = { 0};
	char s2[50]  = {0};
	int ret=0;
	printf("Enter first string:\n");
	scanf("%s", s1);
	printf("Enter second string which is rotation of first string:\n");
	scanf("%s", s2);
	ret = isRot(s1, s2);
	printf("\nResult %d\n",ret);
}
