#include "common_defines.h"

#define CLOCK_BASE_ADDRESS 0x40021000U
#define CLK_APB2 CLOCK_BASE_ADDRESS + 0x18


#define GPIO_BASE (0x40010800U)
#define GPIO_PORTA (GPIO_BASE)
#define GPIO_PORTB (GPIO_BASE + 0x400 * 2)
#define GPIO_PORTC (GPIO_BASE + 0x400 * 3)
#define GPIO_PORTD (GPIO_BASE + 0x400 * 4)
#define GPIO_PORTE (GPIO_BASE + 0x400 * 5)
#define GPIO_PORTF (GPIO_BASE + 0x400 * 6)
#define GPIO_PORTG (GPIO_BASE + 0x400 * 7)

#define GPIO_PIN0  0U
#define GPIO_PIN1  1U
#define GPIO_PIN2  2U
#define GPIO_PIN3  3U
#define GPIO_PIN4  4U
#define GPIO_PIN5  5U
#define GPIO_PIN6  6U
#define GPIO_PIN7  7U
#define GPIO_PIN8  8U
#define GPIO_PIN9  9U
#define GPIO_PIN10 10U
#define GPIO_PIN11 11U
#define GPIO_PIN12 12U
#define GPIO_PIN13 13U
#define GPIO_PIN14 14U
#define GPIO_PIN15 15U


typedef struct GPIO_TypeDef {
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t LCKR;
    uint32_t AFIO_EVCR;
}GPIO_TypeDef;

typedef enum GPIO_Speed {
    INPUT,
    OUTPUT_10MHz,
    OUTPUT_2MHz,
    OUTPUT_50MHz
} GPIO_Speed;

typedef enum GPIO_Conf {
    INPUT_ANALOG      = 0b00,
    INPUT_FLOATING    = 0b01,
    INPUT_PUPD        = 0b10,
    OUTPUT_PUPL       = 0b00,
    OUTPUT_ODRAIN     = 0b01,
    OUTPUT_ALT_PUPL   = 0b10,
    OUTPUT_ALT_ODRAIN = 0b11
} GPIO_Conf;

/*
    Function Definitions.
*/

//Enable the GPIO Clock
void gpio_enable(void);

// Setup a GPIO Pin
void gpio_setup(uint32_t GPIO_PORT, uint8_t GPIO_PIN, GPIO_Conf GPIO_Conf, GPIO_Speed GPIO_SPEED);

//Set a GPIO Pin to 1
void gpio_set(uint32_t GPIO_PORT, uint8_t GPIO_PIN);

//Set a GPIO Pin to 0
void gpio_clear(uint32_t GPIO_PORT, uint8_t GPIO_PIN);