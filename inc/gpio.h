#include "common_defines.h"

#define CLOCK_BASE_ADDRESS 0x40021000U
#define CLK_APB2 CLOCK_BASE_ADDRESS + 0x18



/*
    Function Definitions.
*/

//Enable all gpio pins.
void gpio_setup(void);
void gpio_enable(void);