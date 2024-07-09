################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/BUZZER/BUZZER_Program.c 

OBJS += \
./MCAL/BUZZER/BUZZER_Program.o 

C_DEPS += \
./MCAL/BUZZER/BUZZER_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/BUZZER/%.o: ../MCAL/BUZZER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


