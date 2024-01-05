/* 
Author: Dylan Bomgardner
Based On: https://medium.com/@csrohit/writing-linker-script-for-stm32-arm-cortex-m3-%EF%B8%8F-fdc2acaaddcc
*/

/*
    Different Commands
    Entry - Set the entry point address information in the header of elf
            Reset Handler is our entry point, since it is the first piece of code to run.

    Memory - Target different memory segments present in the target
    
    Sections - Create different output sections in the final elf
               Instruct linker how to merge sections to output sections.
*/

/*
    ENTRY SECTION
*/
ENTRY(Reset_Handler)

/*
    MEMORY SECTION
*/
MEMORY
{
    FLASH (rx)  : ORIGIN=0x0800000,    LENGTH = 256K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 48K
}

/*
    SECTIONS SECTION ;)
*/











