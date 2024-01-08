#include "common_defines.h"

#define CLOCK_BASE_ADDRESS 0x40021000U
#define CLK_APB2 CLOCK_BASE_ADDRESS + 0x18
#define GPIOA_BASE 0x40010800U

typedef struct GPIO {
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t LCKR;
    uint32_t AFIO_EVCR;
}GPIO;


/*
    Function Definitions.
*/

//Enable all gpio pins.

//LED2 is Pin A5

void gpio_setup(void);
void gpio_enable(void);
void gpio_pin_setup(void);

void gpio_set(uint8_t GPIO_PORT, uint8_t GPIO_PIN);
void gpio_clear(uint8_t GPIO_PORT, uint8_t GPIO_PIN)