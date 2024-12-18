################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/gpio_driver.c \
../Driver/Src/rcc_driver.c 

OBJS += \
./Driver/Src/gpio_driver.o \
./Driver/Src/rcc_driver.o 

C_DEPS += \
./Driver/Src/gpio_driver.d \
./Driver/Src/rcc_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Test/STM32_Study/02.GPIO/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/gpio_driver.cyclo ./Driver/Src/gpio_driver.d ./Driver/Src/gpio_driver.o ./Driver/Src/gpio_driver.su ./Driver/Src/rcc_driver.cyclo ./Driver/Src/rcc_driver.d ./Driver/Src/rcc_driver.o ./Driver/Src/rcc_driver.su

.PHONY: clean-Driver-2f-Src

