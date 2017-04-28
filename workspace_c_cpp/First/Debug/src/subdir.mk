################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Car.cpp \
../src/Vehicle.cpp \
../src/Wheel.cpp \
../src/main.cpp 

OBJS += \
./src/Car.o \
./src/Vehicle.o \
./src/Wheel.o \
./src/main.o 

CPP_DEPS += \
./src/Car.d \
./src/Vehicle.d \
./src/Wheel.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


