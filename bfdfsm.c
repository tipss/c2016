#include <stdio.h>

typedef enum { DOWN   = 1, UP, INIT } STATES;
typedef enum { E_DOWN = 1, E_UP, E_INIT ,E_TMR} EVENTS;

int bfd_DOWN();
int bfd_UP();
int bfd_INIT();

int (* state[])(void) =  {NULL, bfd_DOWN, bfd_UP, bfd_INIT};

typedef struct tra_s {
  STATES src_state;
  EVENTS rcvd_event;
  STATES next_state;
} tra_t;

tra_t tra[] = {
  {DOWN, E_DOWN, INIT},
  {DOWN, E_UP,   DOWN},
  {DOWN, E_INIT, UP},
  {DOWN, E_TMR, DOWN},

  {UP,   E_UP,   UP},
  {UP,   E_INIT, UP},
  {UP,   E_DOWN, DOWN},
  {UP,   E_TMR,  DOWN},

  {INIT, E_DOWN, INIT},
  {INIT, E_UP,   UP},
  {INIT, E_INIT, UP},
  {INIT, E_TMR,  DOWN},
};

int bfd_DOWN ( ) { 
  printf("BFD in DOWN state");
  return 0;
}

int bfd_UP ( ) { 
  printf("BFD in UP state");
  return 0;
}

int bfd_INIT ( ) { 
  printf("BFD in INIT state");
  return 0;
}

STATES lookup_new_state(STATES curr_state, EVENTS rcvd_event) {
  tra_t tmp;
  int i;
  for(i=0; i<9; i++) {
    tmp = tra[i];
    if(tmp.src_state == curr_state) {
      if(tmp.rcvd_event == rcvd_event)
	return tmp.next_state;
    }
  }
  return 0;
}

int readEventFromMessageQueue() {
  int num;
  printf("Enter DOWN(1), UP(2), INIT(3), TMR(4)\n");
  scanf("%d",&num);;
  printf("You entered %d\n", num );
  return num ;
};

int main (int arggc, char *argv[]) {
  STATES curr_state = INIT;
  EVENTS rcvd_event;
  int (* state_func) (void);

  for(;;) {
    state_func = state[curr_state];
    state_func();
    printf("In state %d \n",curr_state);
    rcvd_event = readEventFromMessageQueue();
    printf("Received BFD EVENT %d", rcvd_event);  
    curr_state = lookup_new_state(curr_state, rcvd_event);
  }
  return 0;
}
