#include <stdio.h>

int main (int argc, char *argv[]) {
    int rear =9;
    int front = 0;
    int old;

    printf("-1    is 0x%x\n", -1);
    printf("-2    is 0x%x\n", -2);
    printf("-1<<1 is 0x%x\n", -1<<1);

for (int i=0; i<12; i++) {   
    old = rear;
    rear = (rear + 1)%10;
    printf("rear(%d)=%d  \n",old, rear); 
}

}
