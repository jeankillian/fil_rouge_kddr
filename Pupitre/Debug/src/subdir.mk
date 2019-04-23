################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/pupitre.c 

OBJS += \
./src/pupitre.o 

C_DEPS += \
./src/pupitre.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

