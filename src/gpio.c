#include "../inc/gpio.h"

volatile int j;
//enable all the GPIO PINS
void gpio_enable(void) {
    volatile uint32_t* APB2 = CLK_APB2;
    *APB2 |= (0b100);


    //add a delay
    for (volatile int i = 0; i < 1000; i++) {
        //Do nothing.
    }
}

void gpio_setup(void) {
    gpio_enable();
    volatile uint32_t* GPIOA = (uint32_t *) GPIOA_BASE;
    //setup pin A5 to output push pull
    
    //set Mode to output 10mhz MODE
    *GPIOA |= (0b11 << 20);
    //set the output to push pull CNF 00
    *GPIOA &=  ~(0b11 << 22);
    
}   

