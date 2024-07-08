##First Command
AC=arm-none-eabi-gcc
LN=-T stm32f401cc_linkerscript.ld -nostdlib
##first rule to generate main.o
## to use variable -> $(variable name)
## to use dependency name inside the command -> $^
## to use target name inside the command -> $@

main.o:main.c
	$(AC) -c $^ -o $@
	
	
mrcc.o:MRCC_Program.c
	$(AC) -c $^ -o $@
	
	
mgpio.o:MGPIO_Program.c
	$(AC) -c $^ -o $@
	

stm32f401_startupfile.o:stm32f401_startupfile.c
	$(AC) -c $^ -o $@


file.elf:
	$(AC) *.o $(LN) -o $@

file.map:
	$(AC) *.o $(LN) -Wl,-Map=file.map $@

	
all:main.o mrcc.o mgpio.o stm32f401_startupfile.o file.elf  file.map

clean:
	rm -fr *.o  file.elf file.map
