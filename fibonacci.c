#include <stdio.h>

// Remember it starts at index Zero
// Its a series
// f0= 0, f1=1, f2=1,f3=2,f4=3,f5=5...
// Generates nth FIBonacci sequence number
// fn = f(n-1) + f(n-2);
// n is the index of element in the series.
// return : value at the index n, after computing it.
int fib (int n) { 

  if(n <=1 )
    return n;

  return fib(n-1) + fib(n-2);

}

// 2^n complexity
int sumOfFib(n) {
  int sum=1;

  if(n <=1 )
    return n;
  for(int i=2; i<=n; i++) {
    sum +=fib(i);
    
  }
  return sum;
}

// log n complexity
// Use formula    SumFIB (n) =  f(n+2) - 1

int sumOfFib2(n){
  int sum = 0;
  if(n <=1 )
    return n;
  
  return (fib(n+2)-1);
}

int f[100] = { 0 };
int sumOfFib3 (n) {
  //fSUM = f(n+2)-1
  if(n <=1 )
    return n;
  
  if(f[n+2]) {
    return (f[n+2]-1);
  } else {
    printf("Computing\n");
    //Remember, do not store with -1, as this value is used for future computation
    f[n+2]= fib(n+2);
    return (f[n+2]-1);

  }
}

int main(int argc, char *argv[]) {

  for(int i=0; i<10; i++) {
    printf("    Fibonacci of %d:%d\n",i, fib(i));
    printf("SumFibonacci  of %d:%d\n",i, sumOfFib(i));
    printf("SumFibonacci2 of %d:%d\n",i, sumOfFib2(i));
    printf("SumFibonacci3 of %d:%d\n",i, sumOfFib3(i));
  }
} 
