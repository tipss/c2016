#include <stdio.h>
#include <stdlib.h>

//It has worst and average search complexity is O(n2).


void printA(int *a, int n) {
	for(int i=0;i<n;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

void bubbleSort(int *a,int n) {
	int t;
	printf("size %d\n",n);
	if(n <=1) {
		return;
	}

	for (int i=0; i < n-1; i++){ //Feeds value of i to the next loop
		for(int j=0; j < n-1-i; j++){ //Every loop move highest value to the 'right most' location.
			//Loop shrink every time by one element at right , which is sorted now.
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	printA(a,n);

}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5};
	int b[]={5,4,3,2,1};
	bubbleSort(a,sizeof(a)/sizeof(int));
	bubbleSort(b,sizeof(b)/sizeof(int));
}
