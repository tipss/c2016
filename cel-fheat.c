#include <stdio.h>

int main(int argc, char *argv[]) {
 int x;
char c;
//Remember float here
float farn = 70, cel;
 int upper = 120;
c='A';

printf("c = %d %c \n",c,c);
printf("Test inline assignment in C\n Help\b");
if( (x=5) == 5)
	printf("Inline assigned x=%d\n",x);

 while (farn <= upper)
 {
  cel =  (farn - 32) / 9 * 5 ;
  printf("celsius %f Fahrenheit %f\n",cel,farn);
  farn += 5;
 }
}
