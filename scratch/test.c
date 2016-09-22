#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char *t){
    
    printf("strlen t %ld, sizeof t= %ld\n",strlen(t), sizeof(t));
    }
int main(int argc, char *argv[]) {
    char t[10];
    printf("strlen t[10]= %ld sizeof(t) %ld\n",strlen(t),sizeof(t));
    sprintf(t,"%d",50);
    printf("strlen t[10]= %ld sizeof(t) %ld\n",strlen(t), sizeof(t));
    printf("Same print inside a function\n");
    fun(t);
}

