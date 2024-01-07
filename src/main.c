/*
    Author: Dylan Bomgardner
*/

#include "main.h"
#include "stm32_startup.h"

void clock_enable(void) {
    //enable clock
    volatile uint32_t* CLK_CTL =  (uint32_t *) RCC_CR;
    volatile uint32_t* CLK_CFGR = (uint32_t *) RCC_CFGR;
    //Turn the HSI clock on.
    *CLK_CTL |= HSION;
    //wait for it to not be busy
    while( (*CLK_CTL & HSIRDY) == BUSY);
    
    //do the pll stuff after the input clock becomes stable (ready flag)
    //reference manual 8.2.3

    //configure pll
    *CLK_CFGR |= PLL_HSISRC;
    *CLK_CFGR |= HSI_TIMES_5;
    //enable pll
    *CLK_CTL |= PLLENABLE;

    while ( (*CLK_CTL & PLLRDY) == BUSY);
    
    *CLK_CFGR |= PLL_SELECT;

    while ( (*CLK_CFGR & (0b11 << 2)) != (0b10 << 2));

    return; 
}
int main() {
    clock_enable();
    gpio_setup();
    //gpio_enable();
    
    while(1) {

    }
    return 0;
}
