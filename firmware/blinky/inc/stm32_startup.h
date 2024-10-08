/*
    Author: Dylan Bomgardner
*/

#include "common_defines.h"

#define SRAM_START 0x20000000U
#define SRAM_SIZE  (20 * 1024) // 48KiB
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


//Default handler for all system stuff as a weak.
void Default_Handler(void);



