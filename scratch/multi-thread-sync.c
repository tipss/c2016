#include <iostream>
#include <fstream>
#include <pthread.h>
#include <signal.h>


pthread_cond_t cond[5] = {PTHREAD_COND_INITIALIZER,};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

using namespace std;

string gstr;

void* thread1(void*)
{
  do {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond[0],&mutex);
    cout <<"thread1 :"<<gstr<<endl;
    pthread_mutex_unlock(&mutex);
  }while(1);
}

void* thread2(void*)
{
  do{
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond[1],&mutex);
    cout <<"thread2 :"<<gstr<<endl;
    pthread_mutex_unlock(&mutex);
  }while(1);
}

void* thread3(void*)
{
  do{
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond[2],&mutex);
    cout <<"thread3 :"<<gstr<<endl;
    pthread_mutex_unlock(&mutex);
  }while(1);
}

void* thread4(void*)
{
  do{
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond[3],&mutex);
    cout <<"thread4 :"<<gstr<<endl;
    pthread_mutex_unlock(&mutex);
  }while(1);
}

void* thread5(void*)
{
  do{
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond[4],&mutex);
    cout <<"thread5 :"<<gstr<<endl;
    pthread_mutex_unlock(&mutex);
  }while(1);
}

int main()
{
  pthread_t t[5];
  void* (*fun[5])(void*);
  fun[0]=thread1;
  fun[1]=thread2;
  fun[2]=thread3;
  fun[3]=thread4;
  fun[4]=thread5;

  for (int i =0 ; i < 5; ++i)
    {
      pthread_create(&t[i],NULL,fun[i],NULL);
    }
  ifstream in;
  in.open("paragraph.txt");
  int i=0;
  while(in >> gstr)
    {

      pthread_cond_signal(&cond[i++]);
      if(i == 5)
	i=0;
      usleep(10);
    }
  for (int i =0 ; i < 5; ++i)
    {
      int ret = pthread_cancel(t[i]);
      if(ret != 0)
	perror("pthread_cancel:");
      else
	cout <<"canceled\n";
    }
  pthread_exit(NULL);
}
