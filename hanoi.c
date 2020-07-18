#include <stdio.h>
//Remember
/* 
 * F from
 * T to,
 * A auxilary 
 * p number plates.
 * Note A should be empty before calling this function.

 * FAT  A
*/

void TH(int p, char F, char T, char A) {

  /* no other work needed, so return */
  if (p==1) {
    printf("Move disk %d from %c to %c\n",p,F,T);
    return;
  }
  /*
   * Move n-1 plates to aux, so last plate you can actually move  to final target T.
   * Aux becomes your 'F' in next step
   */
  TH(p-1, F, A, T);
  /*
   * This print is symbolic to say we have moved last plate(single) to its final target T.
   */

  printf("Move disk %d from %c to %c\n",p, F , T);
  /*
   * Remove from Aux  and move to  target, use F as auxialary as its empty.
   */
  TH(p-1, A, T, F);
}

int main(int argc, char *argv[]) {
  int num_plates = 3;
  printf("Note: There are three towers, From, To and Auxilary, To is the right most tower");
  printf("Input Number of Plates %d(default) in the From tower \n",num_plates);
  //scanf("%d",&num_plates);
  TH(num_plates,'F','T','A');
  return (0);
}
