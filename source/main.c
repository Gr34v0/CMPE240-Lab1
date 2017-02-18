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

void delay(volatile uint32_t count)
{   
    volatile uint32_t x = 0;    //Volatile flag moves the uint32_t to RAM
                                //to disable compiler optimization.
	while (x != count)          //Loop 'count' number of times.
    {
        x += 1;  //Simple implementation. Count up to
                 //the number provided in the function call to waste time.
    }
}

int main()
{
    volatile uint32_t countValue = 900000; //Arbitrary number that, after testing,
                                           //turns out to be almost perfect for a 1 second
                                           //delay on a RPi3 proc @ stock clock speeds.

	// Select output mode and which pin to Drive
    gpio[GPFSEL0] |= (001 << 9);    //Output mode 001 put on pin 3
                                    //which is 9 bits over from the start
                                    //of the GPIO set 0.    
    while (1)
    {       
        //toggle clear register for the chosen pin
        // GPIO3 bits 11-9  bit 001 = output
        gpio[GPCLR0] |= (1 << 3);

        //apply a delay
        delay(countValue);

        //toggle set register for the chosen pin
        gpio[GPSET0] |= (0 << 3);

        //apply a delay
        delay(countValue);
    }
    return 0;
}