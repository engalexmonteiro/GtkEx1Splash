################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GtkEx1Splash.c 

OBJS += \
./src/GtkEx1Splash.o 

C_DEPS += \
./src/GtkEx1Splash.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" `pkg-config --cflags --libs gtk+-2.0`
	@echo 'Finished building: $<'
	@echo ' '


