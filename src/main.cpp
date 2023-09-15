// #include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }

#include "general.h"

extern volatile uint16_t counter;
extern volatile uint8_t mS_Timer_Flag;
uint8_t ten_mS_Timer = 0; 
uint8_t ten_mS_Timer_Flag = 0;

int main(void) 
{

//set RB5 as output
    DDRB |= 1 << DDB5; 

 //call TMR0 initialization function
    init_TC0();  


    sei(); 
 
    //PORTB ^= 1 << PORTB5;
    while (1)
    {
         if (mS_Timer_Flag == true)
         {
            ten_mS_Timer++;
            counter = 0;
            PORTB ^= 1 << PORTB5; //toggle LED on PORTB5
            mS_Timer_Flag = false;
          }
        
        if(ten_mS_Timer == 10)
        {
            ten_mS_Timer_Flag = true; 
        }
      
      
        //main loop
    }


}