################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rotaryEncoder/rotaryencoder.c 

OBJS += \
./rotaryEncoder/rotaryencoder.o 

C_DEPS += \
./rotaryEncoder/rotaryencoder.d 


# Each subdirectory must supply rules for building sources it contributes
rotaryEncoder/%.o: ../rotaryEncoder/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"  `pkg-config --cflags --libs gtk+-3.0 jack` -I/usr/local/include/  -ljackcpp
	@echo 'Finished building: $<'
	@echo ' '


