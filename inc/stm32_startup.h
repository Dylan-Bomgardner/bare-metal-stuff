/*
    Author: Dylan Bomgardner
*/

#include "common_defines.h"

#define SRAM_START 0x20000000U
#define SRAM_SIZE  (48 * 1024) // 48KiB
#define SRAM_END   ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END



//GET THESE SYMBOLS FROM THE LINKER
extern uint32_t _etext; //End of text section
extern uint32_t _sdata; //Start of data section in sram
extern uint32_t _edata; //End of data section in sram
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _data_loadaddr; //where data was loaded into flash.


//Main declaration.
int main(void);

void Reset_Handler(void);
//Allows programmer to override the function by using weak.
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMonitor_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

// Normal Interrupts
void WWDG_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 0
void PVD_Handler(void) __attribute__((weak, alias("Default_Handler")));                 // 1
void TAMPER_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 2
void RTC_Handler(void) __attribute__((weak, alias("Default_Handler")));                 // 3
void FLASH_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 4
void RCC_Handler(void) __attribute__((weak, alias("Default_Handler")));                 // 5
void EXTI0_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 6
void EXTI1_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 7
void EXTI2_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 8
void EXTI3_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 9
void EXTI4_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 10
void DMA1C1_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 11
void DMA1C2_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 12
void DMA1C3_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 13
void DMA1C4_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 14
void DMA1C5_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 15
void DMA1C6_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 16
void DMA1C7_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 17
void ADC12_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 18
void USBHP_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 19
void USBLP_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 20
void CANRX1_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 21
void CANSCE_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 22
void EXTI9_5_Handler(void) __attribute__((weak, alias("Default_Handler")));             // 23
void TIM1BRK_Handler(void) __attribute__((weak, alias("Default_Handler")));             // 24
void TIM1UP_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 25
void TIM1TRGCOM_Handler(void) __attribute__((weak, alias("Default_Handler")));          // 26
void TIM1CC_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 27
void TIM2_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 28
void TIM3_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 29
void TIM4_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 30
void I2C1EV_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 31
void I2C1ER_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 32
void I2C2EV_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 33
void I2CER_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 34
void SPI1_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 35
void SPI2_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 36
void USART1_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 37
void USART2_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 38
void USART3_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 39
void EXTI1510_Handler(void) __attribute__((weak, alias("Default_Handler")));            // 40
void RTCAlarm_Handler(void) __attribute__((weak, alias("Default_Handler")));            // 41
void USBWakeup_Handler(void) __attribute__((weak, alias("Default_Handler")));           // 42
void TIM9BRK_Handler(void) __attribute__((weak, alias("Default_Handler")));             // 43
void TIM8UP_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 44
void TIM8TRGCOM_Handler(void) __attribute__((weak, alias("Default_Handler")));          // 45
void TIM8CC_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 46
void ADC3_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 47
void FSMC_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 48
void SDIO_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 49
void TIM5_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 50
void SPI3_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 51
void UART4_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 52
void UART5_Handler(void) __attribute__((weak, alias("Default_Handler")));               // 53
void TIM6_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 54
void TIM7_Handler(void) __attribute__((weak, alias("Default_Handler")));                // 55
void DMA2C1_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 56
void DMA2C2_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 57
void DMA2C3_Handler(void) __attribute__((weak, alias("Default_Handler")));              // 58
void DMA2C45_Handler(void) __attribute__((weak, alias("Default_Handler")));             // 59
//Default handler for all system stuff as a weak.
void Default_Handler(void);



