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

void gpio_setup(uint32_t GPIO_PORT, uint8_t GPIO_PIN, GPIO_Conf GPIO_Conf, GPIO_Speed GPIO_SPEED) {
    volatile GPIO_TypeDef* GPIO = (GPIO_TypeDef*) GPIO_PORT;
    uint8_t cr_offset = (GPIO_PIN % 8) * 4; 
    uint32_t pin_config = ((GPIO_Conf << 2) | GPIO_SPEED) << cr_offset;
    uint32_t mask = ~(0b1111 << cr_offset);

    //Depending on which pin, choose the low or the high register
    if (GPIO_PIN <= 7) {
        GPIO->CRL &= mask;
        GPIO->CRL |= pin_config;        
    }
    else {
        GPIO->CRH &= mask;
        GPIO->CRH |= pin_config;
    }

    //config should be done
}

void gpio_set(uint32_t GPIO_PORT, uint8_t GPIO_PIN) {
    volatile GPIO_TypeDef* GPIO = (GPIO_TypeDef*) GPIO_PORT;
    GPIO->ODR |= (1 << GPIO_PIN);
}

void gpio_clear(uint32_t GPIO_PORT, uint8_t GPIO_PIN) {
    volatile GPIO_TypeDef* GPIO = (GPIO_TypeDef*) GPIO_PORT;
    GPIO->ODR &= ~(1 << GPIO_PIN);
}

