ENTRY(Reset_Handler)


MEMORY  /* memory describtions */
{
    FLASH(rx) : ORIGIN = 0x08000000 ,LENGTH = 256K
    SRAM(rwx) : ORIGIN = 0x20000000 ,LENGTH = 20K
}

SECTIONS
{
  .text :
  {
   s_text = . ;
   *(isr_section)
   *(.text)
   *(.rodata)
   e_text = . ;
  }> FLASH  /*>vma AT>LMA*/  /*>FLASH AT>FLASH*/  /*>FLASH*/
  .data :
  {
    s_data = . ;
     *(.data)
	 . = ALIGN(4);
	e_data = . ;  
  }>SRAM  AT >FLASH
  .bss :
  {
   s_bss = . ;
  *(.bss)
   e_bss = . ;
  }>SRAM




}