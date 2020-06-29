#include <stdio.h>

/*
* Find needle in a haystack, standar C string.h function
*/
const char *my_strstr(const char *haystack, const char *needle) {

  printf("Input %s needle: %s\n",haystack, needle);
  if (haystack == NULL || needle == NULL) {
    return (NULL);
  }
  
  while (*haystack != '\0') {
    printf("starting at %c\n", *haystack);
    if (*haystack == *needle) {
      const char *h = haystack;
      const char *n = needle;
    printf("match starting at %c\n", *haystack);
      while (*n != '\0' && *n == *h) {
	n++;
	h++;
      }
      if (*n == '\0') {
	return ((const char *)haystack);
      }
    }
    haystack++;
  }
  return (NULL);
}

int main(int argc, char *argv[]) {
  char hay[100]    = {0};
  char needle[100] = {0};

  printf("Enter a string:\n");
  scanf("%s",hay);
  printf("Enter a string to find:\n");
  scanf("%s", needle);
  const char *ret = my_strstr(hay, needle);
  printf("Input %s, needle %s: %s\n", hay, needle, ret?ret:"NOT-FOUND");
}
