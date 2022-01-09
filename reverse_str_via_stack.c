#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str) {
	char *end = str;
	char *beg = str;
	char t;
  
	printf("%s %s\n", __FUNCTION__, str);
	while (*str) {
		end = str;
		str++;
	}
	printf("End is %c\n", *end);
  
	while (end > beg) {
		printf("beg %c end %c\n", *beg, *end);
		t    = *end;
		*end  = *beg;
		*beg  = t;
    
		printf("beg %c end %c\n\n", *beg, *end);
		end--;
		beg++;
	}
}

// Remember
//This is char storage stack
typedef struct my {
	int index;
	int capacity;
	char * data;
} my_stack;

my_stack stack = { 0, 100, NULL };

void init( ) {
	stack.data = malloc(100 * sizeof(char));
}

void push(char in) {
	stack.data[stack.index] = in;
	stack.capacity--;
	stack.index++;
}

char pop(void) {
	stack.capacity++;
	stack.index--;
	return stack.data[stack.index];
}

int main(int argc, char *argv[]) {
	char  str[1000];
	int   i;
	void *t;
	char tmp;
	
	init();
	printf("Enter string:");
	scanf("%s", str);
  
	printf("You Entered string: %s", str);
	reverse(str);
	printf("reverse %s\n", str);

	for (i = 0; i < strlen(str); i++) {
		push(str[i]);
	}
  
	for (i = 0; i < strlen(str); i++) {
		str[i] = pop();
	}
	printf("reverse(using char stack)  %s\n", str);
}
