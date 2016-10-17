/*
* Author : Thippanna Hongal
 This program demonstrate how two threads can signal each other, so that only one thread
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

void *threadCount1();
void *threadCount2();
int  count = 0;
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6

int main(int argc, char *argv[])
{
   pthread_t thread1, thread2;
   int i;
   pthread_create( &thread1, NULL, &threadCount1, NULL);
   pthread_create( &thread2, NULL, &threadCount2, NULL);
   printf("%s getpid = %u pthread_self = %u\n",
	  __FUNCTION__, (unsigned int)getpid(), (unsigned int)pthread_self());
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   printf("Final count: %d\n",count);

   exit(EXIT_SUCCESS);
}

// Write numbers 1-3 and 8-10 as permitted by threadCount2()

void *threadCount1()
{
   printf("%s getpid = %u pthread_self = %u\n",
	  __FUNCTION__, (unsigned int)getpid(), (unsigned int)pthread_self());
   for(;;)
   {
      // Lock mutex and then wait for signal to relase mutex
      pthread_mutex_lock( &count_mutex );

      // Wait while threadCount2() operates on count
      // mutex unlocked if condition varialbe in threadCount2() signaled.
      pthread_cond_wait( &condition_var, &count_mutex );
      count++;
      printf("Counter value threadCount1: %d\n",count);

      pthread_mutex_unlock( &count_mutex );

      if(count >= COUNT_DONE) return(NULL);
    }
}

// Write numbers 4-7

void *threadCount2()
{
   printf("%s getpid = %u pthread_self = %u\n",
	  __FUNCTION__, (unsigned int)getpid(), (unsigned int)pthread_self());
    for(;;)
    {
       pthread_mutex_lock( &count_mutex );

       if( count < COUNT_HALT1 || count > COUNT_HALT2 )
       {
          // Condition of if statement has been met. 
          // Signal to free waiting thread by freeing the mutex.
          // Note: threadCount1() is now permitted to modify "count".
          pthread_cond_signal( &condition_var );
       }
       else
       {
          count++;
          printf("Counter value threadCount2: %d\n",count);
       }

       pthread_mutex_unlock( &count_mutex );

       if(count >= COUNT_DONE) return(NULL);
    }

}
