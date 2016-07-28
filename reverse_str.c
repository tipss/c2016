#include <stdio.h>
#include <string.h>

//Practice Practice this
void Reversed (char *in) {

  char  temp;
  char *end ;

  if(in == NULL ) {
    printf("NULL input\n");
    return;
  }

  if(*in == 0) {
    printf("Empty string input\n");
    return;
  }


  end = in;
  while (*end) {
   end++;
  }
  --end; 

  while (end > in) {
    //Copy top char in temp
    temp  = *in;
    //Replace top char from end
    *in   = *end;
    //Replace end with temp
    *end =  temp;
    in++;
    end--;
  }
}

int main(int argc, char *argv[]) 
{
	
  char str1[] = {"123456789"};
  char *str2  =  NULL;
  char str3[] = {""};

  printf("%s size %ld <Reversed> ", str1, strlen(str1));
  Reversed(str1);

  printf("%s\n", str1);	
  Reversed(str2);
  Reversed(str3);

}
