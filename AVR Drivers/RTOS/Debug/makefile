################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RTOS_STACK/TIMER0/subdir.mk
-include RTOS_STACK/RTOS/subdir.mk
-include RTOS_STACK/GIE/subdir.mk
-include MCAL/WDT/subdir.mk
-include MCAL/USART/subdir.mk
-include MCAL/TWI/subdir.mk
-include MCAL/SPI_NEW/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/LED/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/EEPROM/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/BUZZER/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/STEPPER/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/DCMOTOR/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
RTOS.lss \

FLASH_IMAGE += \
RTOS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: RTOS.elf secondary-outputs

# Tool invocations
RTOS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,RTOS.map -mmcu=atmega32 -o "RTOS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

RTOS.lss: RTOS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S RTOS.elf  >"RTOS.lss"
	@echo 'Finished building: $@'
	@echo ' '

RTOS.hex: RTOS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex RTOS.elf  "RTOS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: RTOS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 RTOS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) RTOS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
