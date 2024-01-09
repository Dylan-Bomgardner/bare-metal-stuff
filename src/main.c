/*
    Author: Dylan Bomgardner
*/

#include "../inc/main.h"
#include "../inc/stm32_startup.h"
#include "../inc/gpio.h"

void clock_enable(void) {
    //enable clock
    volatile uint32_t* CLK_CTL =  (uint32_t *) RCC_CR;
    volatile uint32_t* CLK_CFGR = (uint32_t *) 0x40021004;//RCC_CFGR;
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
    gpio_enable();
    gpio_setup(GPIO_PORTA, GPIO_PIN5, OUTPUT_PUPL, OUTPUT_50MHz);

    while(1) {

        //turn led on.
        gpio_set(GPIO_PORTA, GPIO_PIN5); 

        for (volatile int i = 0; i < 500000; i++) {

        }
        //turn led off.
        gpio_clear(GPIO_PORTA, GPIO_PIN5); 
        for (volatile int i = 0; i < 500000; i++) {

        }
    }
    return 0;
}
