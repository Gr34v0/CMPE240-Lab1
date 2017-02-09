/** 
* Lab 1 - GPIO Blinky
* - Drive an LED by GPIO
* - Developer - Christian Greaves
* - Date - 2/9/2017
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

    volatile uint32_t countValue = 160;

	// Select output mode and which pin to Drive
    gpio[GPFSEL0] |= (001 << 9);
        
    while (1)
    {       
        //toggle clear register for the chosen pin
        // GPIO3 bits 11-9  bit 001 = output
        gpio[GPSET0] |= (0 << 3);

        //apply a delay
        delay(countValue);

        //toggle set register for the chosen pin
        gpio[GPSET0] |= (1 << 3);

        //apply a delay
        delay(countValue);
    }
    
    return 0;
}
