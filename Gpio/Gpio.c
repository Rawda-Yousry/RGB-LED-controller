/*
 * Gpio.c
 *
 *  Created on: Apr 14, 2023
 *      Author: Rawda Lenovo LapTop
 */


#include "Gpio.h"
#include "Gpio_Private.h"
#include "Utils.h"
#include "Bit_Operations.h"


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,uint8 DefaultState) {
  switch (PortName) {
    case GPIO_A:
      GPIOA_MODER &= ~(0x03 << (PinNum * 2));
      GPIOA_MODER |= (PinMode << (PinNum * 2));
      if(PinMode == GPIO_INPUT){
    	  GPIOA_PUPDR &= ~(0x03 << PinNum*2);
    	  GPIOA_PUPDR |= (DefaultState << PinNum*2);
      }
      else if(PinMode == GPIO_OUTPUT){
      GPIOA_OTYPER &= ~(0x01 << PinNum);
      GPIOA_OTYPER |= (DefaultState << PinNum);
      }

      break;
    case GPIO_B:
	  GPIOB_MODER &= ~(0x03 << (PinNum * 2));
	  GPIOB_MODER |= (PinMode << (PinNum * 2));

      if(PinMode == GPIO_INPUT){
    	  GPIOB_PUPDR &= ~(0x03 << PinNum*2);
		  GPIOB_PUPDR |= (DefaultState << PinNum*2);
      }
      else if(PinMode == GPIO_OUTPUT){
    	  GPIOB_OTYPER &= ~(0x01 << PinNum);
    	  GPIOB_OTYPER |= (DefaultState << PinNum);
      }
      break;
    case GPIO_C:
      // TODO:
    	if(PinMode == GPIO_INPUT){
    		GPIOC_PUPDR &= ~(0x03 << PinNum*2);
			GPIOC_PUPDR |= (DefaultState << PinNum*2);
    	}
    	else if(PinMode == GPIO_OUTPUT){
    		GPIOC_OTYPER &= ~(0x01 << PinNum);
			GPIOC_OTYPER |= (DefaultState << PinNum);
		}
      break;
    case GPIO_D:
      // TODO:
        GPIOD_MODER &= ~(0x03 << (PinNum * 2));
        GPIOD_MODER |= (PinMode << (PinNum * 2));

        if(PinMode == GPIO_INPUT){
        	GPIOD_PUPDR &= ~(0x03 << PinNum*2);
        	GPIOD_PUPDR |= (DefaultState << PinNum*2);
		}
		else if(PinMode == GPIO_OUTPUT){
			GPIOD_OTYPER &= ~(0x01 << PinNum);
			GPIOD_OTYPER |= (DefaultState << PinNum);
		}
      break;
    default:
      break;
  }
}

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data){
 //TODO: check if the pin is output
	uint8 check;
	switch(PortName){
	case GPIO_A:
		check = ((GPIOA_MODER )& ((0x03) << (PinNum*2)) ) >> (PinNum*2);
		if(check == 0x01){
				  GPIOA_ODR &= ~(0x1 << PinNum);
				  GPIOA_ODR |= (Data << PinNum);
				return OK;
			}
		else{
			return NOK;
		}
		break;
	case GPIO_B:
		  check = ((GPIOB_MODER )& ((0x03) << (PinNum*2)) ) >> (PinNum*2);
		  if(check == 0x01){
				  GPIOB_ODR &= ~(0x1 << PinNum);
				  GPIOB_ODR |= (Data << PinNum);
				  return OK;
			}
		  else{
			  return NOK;
		  }
		  break;
	case GPIO_C :
		  check = ((GPIOC_MODER )& ((0x03) << (PinNum*2)) ) >> (PinNum*2);
		  if(check == 0x01){
				  GPIOC_ODR &= ~(0x1 << PinNum);
				  GPIOC_ODR |= (Data << PinNum);
				  return OK;
			}
		  else{
			  return NOK;
		  }
		  break;
	case GPIO_D:
		  check = ((GPIOD_MODER )& ((0x03) << (PinNum*2)) ) >> (PinNum*2);
		  if(check == 0x01){
				  GPIOD_ODR &= ~(0x1 << PinNum);
				  GPIOD_ODR |= (Data << PinNum);
				  return OK;
			}
		  else{
			  return NOK;
		  }
		  break;
	default:
		return PORT_UNKNOWN;
		break;
	}
}

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum){
	uint8 pinRead = 0;
	switch(PortName){
	case GPIO_A:
			pinRead = READ_BIT(GPIOA_IDR,PinNum);
		break;
	case GPIO_B:
			  pinRead = READ_BIT(GPIOB_IDR,PinNum);
		 break;
	case GPIO_C :
			  pinRead = READ_BIT(GPIOC_IDR,PinNum);
		break;
	case GPIO_D:
			  pinRead = READ_BIT(GPIOD_IDR,PinNum);
		break;
	}
	return pinRead;
}
