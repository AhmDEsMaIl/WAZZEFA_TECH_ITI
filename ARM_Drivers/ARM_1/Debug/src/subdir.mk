################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HDAC_Program.c \
../src/HEXPARSING_program.c \
../src/HIR_Program.c \
../src/HLEDMRX_Program.c \
../src/HS2P_Program.c \
../src/KEYPAD_Program.c \
../src/LCD_Program.c \
../src/MDMA_Proram.c \
../src/MEXTI_Config.c \
../src/MEXTI_Program.c \
../src/MFDI_Program.c \
../src/MGPIO_Program.c \
../src/MNVIC_Program.c \
../src/MRCC_Program.c \
../src/MSPI_Program.c \
../src/MSTK_Program.c \
../src/MTFT_Program.c \
../src/MUART_Program.c \
../src/SRTOS_Program.c \
../src/_initialize_hardware.c \
../src/_write.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/HDAC_Program.o \
./src/HEXPARSING_program.o \
./src/HIR_Program.o \
./src/HLEDMRX_Program.o \
./src/HS2P_Program.o \
./src/KEYPAD_Program.o \
./src/LCD_Program.o \
./src/MDMA_Proram.o \
./src/MEXTI_Config.o \
./src/MEXTI_Program.o \
./src/MFDI_Program.o \
./src/MGPIO_Program.o \
./src/MNVIC_Program.o \
./src/MRCC_Program.o \
./src/MSPI_Program.o \
./src/MSTK_Program.o \
./src/MTFT_Program.o \
./src/MUART_Program.o \
./src/SRTOS_Program.o \
./src/_initialize_hardware.o \
./src/_write.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/HDAC_Program.d \
./src/HEXPARSING_program.d \
./src/HIR_Program.d \
./src/HLEDMRX_Program.d \
./src/HS2P_Program.d \
./src/KEYPAD_Program.d \
./src/LCD_Program.d \
./src/MDMA_Proram.d \
./src/MEXTI_Config.d \
./src/MEXTI_Program.d \
./src/MFDI_Program.d \
./src/MGPIO_Program.d \
./src/MNVIC_Program.d \
./src/MRCC_Program.d \
./src/MSPI_Program.d \
./src/MSTK_Program.d \
./src/MTFT_Program.d \
./src/MUART_Program.d \
./src/SRTOS_Program.d \
./src/_initialize_hardware.d \
./src/_write.d \
./src/main.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/stm32f4xx_hal_msp.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


