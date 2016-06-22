#include <stdio.h>

void TH(int p, char F, char T, char A) {
	
  if (p==1) {
    printf("Move %d from %c to %c\n",p,F,T);
    return;
  }
  TH(p-1,F,A,T);
  printf("Move %d from %c to %c\n",p, F , T);
  TH(p-1,A,T,F);
}

int main(int argc, char *argv[]) {
  int num_plates=3;
  printf("Input Number of Plates %d(default)\n",num_plates);
  //scanf("%d",&num_plates);
  TH(num_plates,'F','T','A');
  return (0);
}
