/*
* Author : Thippanna Hongal
*  This program demonstrate how two threads can signal each other, so that only one thread
 * works at a time.
 * In this example a counter 'count' is used as shared variable 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;

void *ConditionalCount();
void *Count();

/* Protected global variable(critical section) */
int  count = 0;
#define COUNT_HALT1  3
#define COUNT_HALT2  6

int main(int argc, char *argv[])
{
   pthread_t thread1, thread2;
   int i;
   int count_done = 10;
   /* To avoid race condition we need mutex variable across two threads to share
    * a protected data 
    */
   pthread_create( &thread1, NULL, &ConditionalCount, &count_done);
   pthread_create( &thread2, NULL, &Count           , &count_done);
   printf("%s getpid = %u pthread_self = %u\n",
	  __FUNCTION__, (unsigned int)getpid(), (unsigned int)pthread_self());
   /* Wihtout this main thread or main() will exit leaving running thread exectuting */
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   printf("Final count: %d\n",count);

   exit(EXIT_SUCCESS);
}

// Write numbers 1-3 and 8-10 as permitted by Count()

void *ConditionalCount(void *var)
{
  int count_done = *(int *)var;
  printf("%s getpid = %u pthread_self = %u\n",
	 __FUNCTION__, (unsigned int)getpid(), (unsigned int)pthread_self());
  for(;;)
    /*
     * Needed if thread wants to work , and wait for condition again.
     * In general implemtation(restart cases) this for is not recessary,
     * as it will start working only after some conditions are 
     * met (which are signaled by other threads)
     */
    {
      // Lock mutex and then wait for signal to relase mutex
      pthread_mutex_lock( &count_mutex );
      // Wait while Count() operates on count
      // mutex unlocked if condition varialbe in Count() signaled.
      pthread_cond_wait( &condition_var, &count_mutex );
      count++;
      printf("Counter value ConditionalCount: %d\n",count);

      pthread_mutex_unlock( &count_mutex );

      if (count >= count_done) return(NULL);
    }
  pthread_exit(NULL);
}

// Write numbers 4-7

void *Count(void *in) {
  int count_done = *(int *)in;
  
  printf("%s getpid = %u pthread_self = %u\n",
	 __FUNCTION__, (unsigned int)getpid(), (unsigned int)pthread_self());
  for(;;)
    {
      pthread_mutex_lock( &count_mutex );

      if( count < COUNT_HALT1 || count > COUNT_HALT2 )
	{
          // Condition of if statement has been met. 
          // Signal to free waiting thread by freeing the mutex.
          // Note: ConditionalCount() is now permitted to modify "count".
          pthread_cond_signal( &condition_var );
	}
      else
	{
          count++;
          printf("Counter value Count: %d\n",count);
	}

      pthread_mutex_unlock( &count_mutex );

      if (count >= count_done) return(NULL);
    }
  pthread_exit(NULL);

}
