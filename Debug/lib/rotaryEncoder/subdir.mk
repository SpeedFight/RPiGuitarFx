################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/rotaryEncoder/rotaryencoder.c 

OBJS += \
./lib/rotaryEncoder/rotaryencoder.o 

C_DEPS += \
./lib/rotaryEncoder/rotaryencoder.d 


# Each subdirectory must supply rules for building sources it contributes
lib/rotaryEncoder/%.o: ../lib/rotaryEncoder/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/glib-2.0 -I"/home/konoha/eclipse-workspace/RPiGuitarFX/src/core/controllers" -I/usr/include/gtk-3.0 -I/usr/local/include/ -I"/home/konoha/eclipse-workspace/RPiGuitarFX/inc" -I"/home/konoha/eclipse-workspace/RPiGuitarFX/src/fx" -I"/home/konoha/eclipse-workspace/RPiGuitarFX/src/core/audio" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"  `pkg-config --cflags --libs gtk+-3.0 jack` -I/usr/local/include/  -ljackcpp
	@echo 'Finished building: $<'
	@echo ' '


