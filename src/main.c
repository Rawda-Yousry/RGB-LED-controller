#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "Gpio_Private.h"
#include "Bit_Operations.h"
#include "stdio.h"

int main(){
	Rcc_Init();
	Rcc_Enable(RCC_GPIOB);

	Gpio_ConfigPin(GPIO_B,3,GPIO_INPUT,PULL_UP);

	for(unsigned long k = 5 ; k<=7; k++){
	Gpio_ConfigPin(GPIO_B,k,GPIO_OUTPUT,GPIO_PUSH_PULL);
	}

	uint8 pinReadPrevious,pinReadCurrent;
	uint8 counter = 0 ;
	boolean flag = 0;
	uint32 i = 0;
	uint8 l; // for the return of writepin function

	while(1){

		if(counter> 7){
			counter = 0;
		}
		//debounce feature
		pinReadPrevious = Gpio_ReadPin(GPIO_B,3);
		for(i = 0; i < 5000; i++);
		pinReadCurrent = Gpio_ReadPin(GPIO_B,3);

		if((pinReadCurrent == 0) &&(pinReadPrevious == pinReadCurrent)){
				flag = 1;
				switch(counter){
				case 0:
					 l = Gpio_WritePin(GPIO_B,5,HIGH);
					 l = Gpio_WritePin(GPIO_B,6,HIGH);
					 l = Gpio_WritePin(GPIO_B,7,HIGH);
					break;
				case 1:
					 l = Gpio_WritePin(GPIO_B,5,LOW);
					 l = Gpio_WritePin(GPIO_B,6,LOW);
					 l = Gpio_WritePin(GPIO_B,7,HIGH);
					break;
				case 2:
					 l = Gpio_WritePin(GPIO_B,5,LOW);
					 l = Gpio_WritePin(GPIO_B,6,HIGH);
					 l = Gpio_WritePin(GPIO_B,7,LOW);
					break;
				case 3:
					 l = Gpio_WritePin(GPIO_B,5,LOW);
					 l = Gpio_WritePin(GPIO_B,6,HIGH);
					 l = Gpio_WritePin(GPIO_B,7,HIGH);
					break;
				case 4:
					 l = Gpio_WritePin(GPIO_B,5,HIGH);
					 l = Gpio_WritePin(GPIO_B,6,LOW);
					 l = Gpio_WritePin(GPIO_B,7,LOW);
					break;
				case 5:
					 l = Gpio_WritePin(GPIO_B,5,HIGH);
					 l = Gpio_WritePin(GPIO_B,6,LOW);
					 l = Gpio_WritePin(GPIO_B,7,HIGH);

					break;
				case 6:
					 l = Gpio_WritePin(GPIO_B,5,HIGH);
					 l = Gpio_WritePin(GPIO_B,6,HIGH);
					 l = Gpio_WritePin(GPIO_B,7,LOW);

					break;
				case 7:
					 l = Gpio_WritePin(GPIO_B,5,LOW);
					 l = Gpio_WritePin(GPIO_B,6,LOW);
					 l = Gpio_WritePin(GPIO_B,7,LOW);
					break;
				}
		}

			else {
				if(flag == 1){
					counter++;
					flag = 0;
				}
			}
		}





	return 0;
}
