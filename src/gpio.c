#include "gpio.h"

//enable all the GPIO PINS
void gpio_enable(void) {
    volatile uint32_t* APB2 = CLK_APB2;
    *APB2 |= (0b1111111 << 2) | (0b1); 
}

void gpio_setup(void) {
    gpio_enable();
}