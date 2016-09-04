/*This code describes the state machine for a very basic car radio system. It is basically an infinite loop that reads incoming events. The state machine is only 2 states: radio mode, or CD mode. The event is either a mode change from radio to cd back and forth, or a go to next (next preset for radio or next track for CD).
*/
/********************************************************************/
#include <stdio.h>

/********************************************************************/
typedef enum {
        ST_RADIO,
        ST_CD
} STATES;

typedef enum {
        EVT_MODE,
        EVT_NEXT
} EVENTS;

EVENTS readEventFromMessageQueue(void);

/********************************************************************/
int main(void)
{
  /* Default state is radio */  
  STATES state = ST_RADIO;
  int stationNumber = 0;
  int trackNumber = 0;

  /* Infinite loop */
  while(1)
  {
    /* Read the next incoming event. Usually this is a blocking function. */
    EVENTS event = readEventFromMessageQueue();

    /* Switch the state and the event to execute the right transition. */
    switch(state)
    {
      case ST_RADIO:
        switch(event)
        {
          case EVT_MODE:
            /* Change the state */
            state = ST_CD;
            break;
          case EVT_NEXT:
            /* Increase the station number */
            stationNumber++;
            break;
        }
        break;

      case ST_CD:
        switch(event)
        {
          case EVT_MODE:
            /* Change the state */
            state = ST_RADIO;
            break;
          case EVT_NEXT:
            /* Go to the next track */
            trackNumber++;
            break;
        }
        break;
    }
  }
}
