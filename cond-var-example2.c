#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *function_p0();
void *function_p1();
int  count = 0;
#define COUNT_DONE  10

int main(int argc, char *argv[])
{
   pthread_t thread1, thread2;

   pthread_create( &thread1, NULL, &function_p0, NULL);
   pthread_create( &thread2, NULL, &function_p1, NULL);

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   printf("Final count: %d\n",count);

   exit(EXIT_SUCCESS);
}

// Write numbers 1-3 and 8-10 as permitted by functionCount2()
#define GoAllowP0 0x001
#define GoAllowP1 0x010
#define TRUE      0x100

int enter = 0;
int OtherProcess = 1; //Other Process is running

void *function_p0()
{
   for(;;)
   {
     enter |= GoAllowP1;
     //Wait until p1 signaled you GoAhead, and p1 himself is not working
     while ((((enter & GoAllowP0) == 1) && (enter & GoAllowP1) == 0) || 
       (OtherProcess == 0) ){

      //Critical
       enter |= TRUE;;
      //End of Critical, allow other process now
      enter &= ~GoAllowP0;
      enter |= GoAllowP1;

      printf("%s Counter value : %d 0x%x\n", __FUNCTION__, count, enter);
      if (count >= COUNT_DONE) return(NULL);
     }
   }
}


void *function_p1()
{
  for(;;)
    {
      enter |= GoAllowP0;
      //Wait until p0 signaled you GoAhead, and p0 himself is not working
     while ((((enter & GoAllowP1) == 1) && (enter & GoAllowP0) == 0) || 
       (OtherProcess == 0) ){
       //Critical
       enter &= ~(TRUE);
	//End of critical section, allow other process now
	enter |= GoAllowP0;
	printf("%s Counter value : %d 0x%x\n",__FUNCTION__, count, enter);
	if (count >= COUNT_DONE) return(NULL);
      }
    }
}
