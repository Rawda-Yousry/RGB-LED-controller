/*
 * Gpio.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Rawda Lenovo LapTop
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Std_Types.h"


/*PortName*/
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

/*PinMode*/
#define GPIO_INPUT  0x00
#define GPIO_OUTPUT 0x01
#define GPIO_AF     0x02
#define GPIO_ANALOG 0x03

/*DefaultState*/
#define GPIO_PUSH_PULL  0x00
#define GPIO_OPEN_DRAIN 0x01
#define NO_PULL_UP_OR_PULL_DOWN 0x00
#define PULL_UP 0x01
#define PULL_DOWN 0x10
#define RESERVED 0x03


/*Data*/
#define LOW  0x00
#define HIGH 0x01

#define OK  1
#define NOK  0

#define PORT_UNKNOWN 0


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState);

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data);

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum);

#endif /* GPIO_H_ */
