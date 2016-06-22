#include <stdio.h>
#include <string.h>

//Practice Practice this
char *Reversed (char *in) {

char  temp;
char *start;
char *end ;

if(in == NULL ) {
	printf("NULL input\n");
	return NULL;
}

if(*in == 0) {
	printf("Empty string input\n");
	return NULL;
}


start = in;
end   = start + strlen(in) -1;

printf("Received %s start %s %p end %s %p\n", in, start, &start, end, &end);

while (end > start) {
	//Copy top char in temp
	temp  = *start;
	//Replace top char from end
   *start   = *end;
   //Replace end with temp
   *end =  temp;
   start++;
   end--;
}

printf("Reversed %s start %s %p end %s %p\n", in, start, &start, end, &end);
 return in;
}

int main(int argc, char *argv[]) {
	
char str1[] = {"123456789"};
char *str2  =  NULL;
char str3[] = {""};

printf("%s size %ld <Reversed> %s\n", str1, strlen(str1), Reversed(str1));	
Reversed(str2);
Reversed(str3);

}