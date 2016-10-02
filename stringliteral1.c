#include <stdio.h>
#include <string.h>

void test(char *s6, char *s7){
printf("Inside test\n");	
printf("sizeof(s6(%s) = %ld==ptrlength) strlen(s6) = %ld  sizeof(s7(%s)) = %ld=prtlen strlen(s7) = %ld\n",\
s6,sizeof(s6), strlen(s6),s7, sizeof(s7),strlen(s7));
}

int main(int argc, char *argv[]) {
char s6[]= "hello", *s7= "hello";

printf("sizeof(s6 = %ld) strlen(s6)= %ld  sizeof(s7)=%ld strlen(s7) = %ld\n",\
 sizeof(s6), strlen(s6),sizeof(s7),strlen(s7)); 

test(s6,s7);
}
