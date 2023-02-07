/*
 * OccupancyDetector.c
 *
 *  Created on: Jan 30, 2023
 *      Author: Caleb Amadoro
 */

#include<msp430.h>

int main (void)
{
    WDTCTL = WDTPW | WDTHOLD;       // Stop watch-dog timer
    PM5CTL0 &= ~LOCKLPM5;

    P4DIR &= ~BIT1;                 // Makes P4.1 an input
    P4REN |= BIT1;                  // Enable resistor on P4.1
    P4OUT |= BIT1;                  // Makes resistor on P4.1 to be pull-up resistor
    P2DIR &= ~BIT3;                 // Makes P2.3 an input
    P2REN |= BIT3;                  // Enable resistor on P2.3
    P2OUT |= BIT3;                  // Makes resistor on P2.3 to be pull-up resistor

    P6OUT &= ~BIT6;                 // Clear P6.6 to be a power off state
    P6DIR |= BIT6;                  // Set P6.6 to output direction
    P1OUT &= ~BIT0;                 // Clear P1.0 to be a power off state
    P1DIR |= BIT0;                  // Set P1.0 to output direction

    #define ARMED_STATE 0           // define three states armed, warning, and alert, to be 0, 1, and 2
    #define WARNING_STATE 1
    #define ALERT_STATE 2

    char state = ARMED_STATE;       // Initialize starting state as armed state
    int count = 0;                  // Initialize variable count to 0;

    while(1)
    {
        switch (state)
        {
            case ARMED_STATE:                           // In armed state
            {
                if (!(P2IN & BIT3))                     // If button 2.3 is pressed
                {
                    count = 0;                          // Set count to zero
                    state = WARNING_STATE;              // Move into the warning state
                }
                else                                    // Else
                {
                    P1OUT &= ~BIT0;                     // Turn off red LED
                    P6OUT |= BIT6;                      // Turn green LED on for 0.1s
                    __delay_cycles(100000);
                    P6OUT &= ~BIT6;                     // Turn green LED off for 3s
                    __delay_cycles(3000000);
                }
                break;
            }

            case WARNING_STATE:                         // In warning state
            {
                P6OUT &= ~BIT6;
                if (!(P2IN & BIT3))                     // If button 2.3 is pressed
                {
                    P1OUT ^= BIT0;                      // Toggle red LED every 0.5s
                    __delay_cycles(500000);
                    count ++;                           // Add 1 to count
                    if (count == 19)                    // If count hits 19 (20 cycles == 10 seconds)
                    {
                        count = 0;                      // Set count to zero
                        state = ALERT_STATE;            // Move into the alert state
                    }
                }
                else
                    state = ARMED_STATE;                // If button is let go, go back to armed state
                break;
            }

            case ALERT_STATE:                           // In alert state
            {
                if(!(P4IN & BIT1))                      // If button 4.1 is pressed
                {
                    state = ARMED_STATE;                // Go back to armed state
                }
                P1OUT |= BIT0;                          // Set red LED to on
                break;
            }
        }
    }
}

