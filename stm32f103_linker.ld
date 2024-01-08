/* 
Author: Dylan Bomgardner
Based On: https://www.youtube.com/watch?v=B7oKdUvRhQQ&list=PLERTijJOmYrDiiWd10iRHY0VRHdJwUH4g&index=4&ab_channel=FastbitEmbeddedBrainAcademy
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
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 20K/*48K*/
}

/*
    SECTIONS SECTION ;)
*/

__max_heap_size  = 0x400; /* Symbol declaration not a variable.*/
__max_stack_size = 0x200;
SECTIONS
{
    
    .text :
    {
        /* Put the .vector section before the text section.*/
        KEEP(*(.vector))
        /* Consider .text and .rodata of all input files */
        *(.text)
        *(.rodata)
        . = ALIGN(4);      /* Assign the location to an aligned value.*/
        _etext = .; /* Assign the current address at the end of .rodata to this symbol. */
    }> FLASH
    /* }> FLASH AT> FLASH */
    /* }> vma AT> lma */
    /* virtual memory address AT load memory address*/
    .data :
    {
        _sdata = .;
        *(.data)
        . = ALIGN(4); 
        _edata = .;
    }>SRAM AT> FLASH

    _data_loadaddr = LOADADDR(.data);

    .bss :
    {
        _sbss = .;
        /* Include COMMON in the bss */
        *(.bss)
        *(COMMON)
        . = ALIGN(4); 
        _ebss = .;
    }>SRAM
    /* Only has vma so no flash. */
}










