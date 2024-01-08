#include "common_defines.h"

#define CLOCK_BASE_ADDRESS 0x40021000U
#define CLK_APB2 CLOCK_BASE_ADDRESS + 0x18
#define GPIOA_BASE 0x40010800U

/*
    Function Definitions.
*/

//Enable all gpio pins.

//LED2 is Pin A5

void gpio_setup(void);
void gpio_enable(void);
void gpio_pin_setup(void);