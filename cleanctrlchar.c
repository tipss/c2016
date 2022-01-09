#include <stdio.h>
#include <stdlib.h>



void cleanctrlchar(char in[]) {
	char *tmp = in;
	while (*in) {
		printf("%c=%d\n",*in, (unsigned int)*in);
		if(*in <= 122 && *in >= 48) {
			tmp[0] = *in;
			tmp++;
		}
		in++;
	}
}
int main(int argc, char *argv[]) {

	char ent[101] = {0};
	printf("Enter a string:");
	scanf("%100s", ent);
	printf("Before: %s\n", ent);
	cleanctrlchar(ent);
	printf("After: %s\n", ent);
}
