#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void hanoi(int count, char F, char T, char A){
   if(count < 1)
        return;
   if (count == 1) {
        printf("Move plate no %d, from %c to %c\n",count, F, T); 
        return;
    }

    hanoi(count-1, F,A,T);
    printf("Move plate no %d, from %c to %c\n", count, F,T);
    hanoi(count-1, A,T,F);
}


int main (int argc, char *argv[]) {

    hanoi(3,'F','T','A');
}
