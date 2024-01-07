#include "../inc/stm32_startup.h"


uint32_t vectors[] __attribute__((section(".vector"))) = {
    //System Stuff
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)&SVCall_Handler,
    (uint32_t)&DebugMonitor_Handler,
    (uint32_t)0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,

    // "Normal" Interrupts
    (uint32_t)&WWDG_Handler,                  // 0
    (uint32_t)&PVD_Handler,                   // 1
    (uint32_t)&TAMPER_Handler,                // 2
    (uint32_t)&RTC_Handler,                   // 3
    (uint32_t)&FLASH_Handler,                 // 4
    (uint32_t)&RCC_Handler,                   // 5
    (uint32_t)&EXTI0_Handler,                 // 6
    (uint32_t)&EXTI1_Handler,                 // 7
    (uint32_t)&EXTI2_Handler,                 // 8
    (uint32_t)&EXTI3_Handler,                 // 9
    (uint32_t)&EXTI4_Handler,                 // 10
    (uint32_t)&DMA1C1_Handler,                // 11
    (uint32_t)&DMA1C2_Handler,                // 12
    (uint32_t)&DMA1C3_Handler,                // 13
    (uint32_t)&DMA1C4_Handler,                // 14
    (uint32_t)&DMA1C5_Handler,                // 15
    (uint32_t)&DMA1C6_Handler,                // 16
    (uint32_t)&DMA1C7_Handler,                // 17
    (uint32_t)&ADC12_Handler,                 // 18
    (uint32_t)&USBHP_Handler,                 // 19
    (uint32_t)&USBLP_Handler,                 // 20
    (uint32_t)&CANRX1_Handler,                // 21
    (uint32_t)&CANSCE_Handler,                // 22
    (uint32_t)&EXTI9_5_Handler,               // 23
    (uint32_t)&TIM1BRK_Handler,               // 24
    (uint32_t)&TIM1UP_Handler,                // 25
    (uint32_t)&TIM1TRGCOM_Handler,            // 26
    (uint32_t)&TIM1CC_Handler,                // 27
    (uint32_t)&TIM2_Handler,                  // 28
    (uint32_t)&TIM3_Handler,                  // 29
    (uint32_t)&TIM4_Handler,                  // 30
    (uint32_t)&I2C1EV_Handler,                // 31
    (uint32_t)&I2C1ER_Handler,                // 32
    (uint32_t)&I2C2EV_Handler,                // 33
    (uint32_t)&I2CER_Handler,                 // 34
    (uint32_t)&SPI1_Handler,                  // 35
    (uint32_t)&SPI2_Handler,                  // 36
    (uint32_t)&USART1_Handler,                // 37
    (uint32_t)&USART2_Handler,                // 38
    (uint32_t)&USART3_Handler,                // 39
    (uint32_t)&EXTI1510_Handler,              // 40
    (uint32_t)&RTCAlarm_Handler,              // 41
    (uint32_t)&USBWakeup_Handler,             // 42
    (uint32_t)&TIM9BRK_Handler,               // 43
    (uint32_t)&TIM8UP_Handler,                // 44
    (uint32_t)&TIM8TRGCOM_Handler,            // 45
    (uint32_t)&TIM8CC_Handler,                // 46
    (uint32_t)&ADC3_Handler,                  // 47
    (uint32_t)&FSMC_Handler,                  // 48
    (uint32_t)&SDIO_Handler,                  // 49
    (uint32_t)&TIM5_Handler,                  // 50
    (uint32_t)&SPI3_Handler,                  // 51
    (uint32_t)&UART4_Handler,                 // 52
    (uint32_t)&UART5_Handler,                 // 53
    (uint32_t)&TIM6_Handler,                  // 54
    (uint32_t)&TIM7_Handler,                  // 55
    (uint32_t)&DMA2C1_Handler,                // 56
    (uint32_t)&DMA2C2_Handler,                // 57
    (uint32_t)&DMA2C3_Handler,                // 58
    (uint32_t)&DMA2C45_Handler,               // 59
};

void Reset_Handler(void) {
    //copy .data section to SRAM
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata; /* How many bytes need to be transfered to SRAM. Access the value present at the _edata address which is the address.*/
    
    //pointer to store the address of where the data section starts.
    uint8_t *pDest = (uint8_t*)&_sdata; //start of sram

    uint8_t *pSource = (uint8_t*)&_data_loadaddr; //flash
    

    //copy the data from flash into ram
    for (uint32_t i = 0; i < size; i++) {
        *pDest++ = *pSource++;
    }
    //Init the .bss section to zero in SRAM
    //copy the data from flash into ram
    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    for (uint32_t i = 0; i < size; i++) {
        *pDest++ = 0;
    }
    //call main()
    (void)main();
}