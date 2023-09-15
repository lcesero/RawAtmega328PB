

#include "general.h"


#define mS_timer 1000


volatile uint16_t counter = 0;
volatile uint8_t mS_Timer_Flag = false;
volatile uint16_t TickCount = 0; 


void init_TC0(void)
{
 
    // Set the Timer Mode to CTC
    TCCR0A |= (1 << WGM01);
 
    // Set the value that you want to count to. each count is 1/16MHz 62.5nS * 200 = 12.5uS
     OCR0A = 0xC8;  
 
    //Set the ISR OMPA vect
    TIMSK0 |= (1 << OCIE0A);    
 
    // set prescaler to 8 and start the timer
    TCCR0B |= (1 << CS01);  // each count is now 8 times longer. 12.5nS * 8 = 100uS
    ///PORTB ^= 1 << PORTB5;
}

ISR (TIMER0_COMPA_vect)  
{
    //event to be executed every 100us*MyTimerConstant
    TickCount++;
    
    counter++;

    if (counter == mS_timer)
     {
        mS_Timer_Flag = true;
        //counter = 0;
        //PORTB ^= 1 << PORTB5; //toggle LED on PORTB5
     }
     //PORTB ^= 1 << PORTB5;
     
}



