/** 
* Lab 1 - GPIO Blinky
* - Drive an LED by GPIO
* - Developer - 
* - Date - 
* 
*/
#include "gpio.h"

// Write a function that will delay for n loops
// to satisfy timing constraints given in lab. 
// ....beware compiler optimization....
void delay(uint32_t count)
{   
    uint32_t x = 0;
	while (x < count) //loop x times
             // 1200MHz. 4 instructions/cycle. loop 40 cycles
    {
        x = x + 1;
    } 
}

int main()
{
	// Select output mode and which pin to Drive
    GPIO[GPFSEL1] |= (001 << 21);
        
    while (1)
    {       
        //toggle clear register for the chosen pin
        // GPIO17 bits 23-21  bit 001 = output
        GPIO[GPCLR0] |= (1 << 17);

        //apply a delay
        delay(160);

        //toggle set register for the chosen pin
        GPIO[GPSET1] |= (0 << 17);

        //apply a delay
        delay(160);
    }
    
    return 0;
}
