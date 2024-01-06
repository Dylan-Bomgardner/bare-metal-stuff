#include "../inc/stm32_startup.h"


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