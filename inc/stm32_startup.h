/*
    Author: Dylan Bomgardner
    Date: 1/4/2024
*/

#include "common_defines.h"

#define SRAM_START 0x20000000U
#define SRAM_SIZE  (48 * 1024) // 48KiB
#define SRAM_END   ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

void Reset_Handler(void);

//Allows programmer to override the function by using weak.
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
//Default handler for all system stuff as a weak.
void Default_Handler(void);

uint32_t vectors[] __attribute__((section(".vector"))) = {
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
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&NMI_Handler,


};

