################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp 

OBJS += \
./src/main.o 

CPP_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/include/glib-2.0 -I"/home/konoha/eclipse-workspace/RPiGuitarFX/src/core/audio" -I"/home/konoha/eclipse-workspace/RPiGuitarFX/src/fx" -I"/home/konoha/eclipse-workspace/RPiGuitarFX/inc" -I/usr/local/include/ -I/usr/include/gtk-3.0 -O0 -g3 -pedantic -Wall -Wextra -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" `pkg-config --cflags --libs gtk+-3.0 jack` -I/usr/local/include/  -ljackcpp
	@echo 'Finished building: $<'
	@echo ' '


