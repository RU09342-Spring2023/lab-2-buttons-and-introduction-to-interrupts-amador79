/*
 * OccupancyDetector.c
 *
 *  Created on: Jan 30, 2023
 *      Author: Caleb Amadoro
 */


#define ARMED_STATE 0           //defining the three states of system and assigning them to numbers 0,1,2
#define WARNING_STATE 1
#define ALERT_STATE 2

P4DIR &= ~BIT1;                 // Makes P4.1 an input
P4REN |= BIT1;                  // Enable resistor on P4.1
P4OUT &= ~BIT1;                 // Makes resistor on P4.1 to be pull-down resistor

P6OUT &= ~BIT6;                 // Clear P6.6 to be a power off state
P6DIR |= BIT6;                  // Set P6.6 to output direction
P1OUT &= ~BIT0;                 // Clear P1.0 to be a power off state
P1DIR |= BIT0;                  // Set P1.0 to output direction

char state = ARMED_STATE;

while(1)
{
  switch (state) {
    case ARMED_STATE:
    {
        // Do something in the ARMED state
        // If something happens, you can move into the WARNING_STATE
        // state = WARNING_STATE
    }
    case WARNING_STATE:
    {
        // Do something in the WARNING_STATE
    }
    case ALERT_STATE:
    {
        // Do something in the ALERT_STATE
    }
  }
}
