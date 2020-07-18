#include <stdio.h>

/*
 * Logic here is compare each octet(seperated by .) at a time.
 * This logic can be applied in many cases where you convert a string to a number 
 */
char *compareVer(char *v1,char *v2) {
  char *gr = ">";
  char *le = "<";
  char *eq = "==";

  int num1 = 0;
  int num2 = 0;

  while (*v1 && *v2){

    while (*v1 && *v1 != '.'){
      num1= num1*10 + (*v1 - '0'); //Remember this (convert string number into number )
      v1++;
    }

    while (*v2 && *v2 != '.'){
      num2= num2*10 + (*v2 - '0');
      v2++;
    }


    if (num1 > num2) {
      printf("%d > %d\n",num1, num2);
      return gr;
    } else if (num1 < num2){
      printf("%d < %d\n",num1, num2);
      return le;
    } else {
      printf("%d == %d\n",num1, num2);
      num1 = 0;
      num2 = 0;
      v1++;
      v2++;
    }
  }
  return eq;
}

int main(int argc, char *argv[]){
  char *v1 = "321.10.9.1";
  char *v2 = "321.10.1.0";
  printf("%s is %s than %s",v1,compareVer(v1,v2),v2);
}
