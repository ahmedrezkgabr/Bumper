################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO-program.c \
../LCD-program.c \
../POW_programe.c \
../main.c 

OBJS += \
./ADC_prog.o \
./DIO-program.o \
./LCD-program.o \
./POW_programe.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./DIO-program.d \
./LCD-program.d \
./POW_programe.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


