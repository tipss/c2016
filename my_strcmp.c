#include <stdio.h>

int my_strcmp(const char *f1, const char *f2) {
  if (f1 == NULL && f2 == NULL){
    return (0); //both equal
  }
  if (f1 == NULL) {
    return (0 - *f2);
  }
  if (f2 == NULL) {
    return (0 - *f1);
  }
  while ( (*f1 != '\0' && *f2 != '\0')  && *f1 == *f2) {
    f1++;
    f2++;
  }
  if (*f1 == '\0' && *f2 == '\0') {
    return (0);
  }
  if (*f1 == '\0') {
    return (0 - *f2);
  }
  if (*f2 == '\0') {
    return (0 - *f1);
  }
  return (*f1 - *f2);
}

int main(int argc, char *argv[]) {
  char f1[100] = {0};
  char f2[100] = {0};
  int ret;
  printf("Enster first string\n");
  scanf("%s", f1);
  printf("Enster second string\n");
  scanf("%s", f2);
  ret = my_strcmp(f1, f2);
  if (ret == 0)
    printf("Return: %d equal\n", ret);
  if (ret < 0)
    printf("Return: %d less\n", ret);
  if (ret > 0)
    printf("Return: %d greater\n", ret);
  
  printf("Return: %d \n", ret);
    
}
