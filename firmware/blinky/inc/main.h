/*
    Author: Dylan Bomgardner
*/

/*
    Clock Registers
*/
#define CLOCK_BASE_ADDRESS 0x40021000U
//Clock Control Register
#define RCC_CR CLOCK_BASE_ADDRESS
//Clock Configuration Register
#define RCC_CFGR CLOCK_BASE_ADDRESS + 0x4

#define HSION  (1U << 0)
#define HSIRDY (1U << 1)


#define PLLSRC (16)
#define PLL_HSISRC (0U << PLLSRC)

#define PLLMUL 18U
#define HSI_TIMES_5 (0b1000 << PLLMUL)

#define PLLON 24U
#define PLLENABLE (1U << PLLON)

#define PLLRDY (1 << 25U)

#define PLL_SELECT 0b10

#define BUSY 0U
//GPIO CLock Control
#define RCC_APB2 

#define PLL_MULT 0b0111 //8mhz * 9 = 72mhz


