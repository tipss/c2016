#include<stdio.h>

/* Dynamic programming
Input the total number of stairs.
This problem is clearly recursive.
The person can reach the Nth stair from the (N-1)th stair or (N-2)th stair.
Recursively call, ways(n) = ways(n-1) + ways(n - 2)
*/

int fib(int n) {
  if(n<=1)
    return n;
  return fib(n-1)+fib(n-2);
}  
int countWays(int s) {
  return fib(s+1);
}
int main () {
  int steps;
  scanf(“%d”,&steps);
  printf(“%d”, countWays(steps));
  return 0;
}
