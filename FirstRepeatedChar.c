#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Same logic works for display repeated char in a string 
 * At the end of walk, walk the hash , and print repeated chars.
 */
void findFirstNonRepeatedChar(char *str) {
	/*
	 * 1. Store in hash repeated char,
	 * 2. Walk string char by char , and see if you hit count 1.
	 */
	int c[256];
	
	for (int i = 0; i < 256; i++){
		c[i] = 0;
	}
	for (int i = 0; i < strlen(str); i++){
		c[str[i]] += 1;
	}
	for (int i = 0; i < strlen(str); i++) {
		if(c[str[i]] == 1){
			printf("First non repeated char is \'%c\' in str %s\n", str[i], str);
			break;
		};
	}
}


/*
1. API to find First repeated char
    1.1  Validate Input
    1.2  Walk input char by char, Increment counter indexed by 256 char array  
    1.3  Note first repeat of char and return the locations 
*/
void findRepeatedChar(char *str) {
	int c[256];
	int loc = 0;
	char temp;
	
	for (int i = 0; i < 256; i++) {
		c[i] = 0;
	}
	printf("Input Str %s strlen %lu\n", str, strlen(str));
	for (int i = 0; i < strlen(str); i++) {
		c[str[i]] += 1;
		if (c[str[i]] == 2) {
			printf("%c(value %d) = %d Repeated\n",str[i], str[i], c[str[i]]);    
		} else {
			printf("%c(value %d) = %d\n",str[i], str[i], c[str[i]]);    
		}
	}   
}

/* Use bit Map  if we only have 32 unique chars , e.g a-z, or A-Z */
void findRepeatedChar2(char *str) {
	unsigned int val = 0;
  
	printf("sizeof(bitMap) %lu\n",sizeof(val));
	for (int i=0; i<strlen(str); i++) {
		if((val & (1 << (str[i] - 'a'))) > 0) {
			printf("%c[value %d] repeated at location %d bitmask 0x%x\n", str[i], str[i]-'a', i, val);
		} else {
			val |= (1 << (str[i] - 'a'));
			printf("%c(value %d) 1st seen at location %d bitmask 0x%x\n", str[i], str[i]-'a', i, val);
		}
	}
}

int main (int argc, char *argv[]) {
	char *str = "acba";
	//findRepeatedChar(str);
	findRepeatedChar2(str);
	findFirstNonRepeatedChar(str);
}
