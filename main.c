
#define GPIOB_BASE_ADDR 0x40020400
#define GPIOB_MODER (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_OTYPER (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))
#define GPIOB_ODR (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))

#define RCC_AHB1ENR      (*(unsigned long *) (0x40023800 + 0x30))
#define RCC_CR           (*(unsigned long *) (0x40023800 + 0x00))

#define GPIOB_IDR        (*(unsigned long *)(GPIOB_BASE_ADDR + 0x10))
#define GPIOB_PUPDR 	(*(unsigned long *)(GPIOB_BASE_ADDR + 0x0C))
#define RCC_CFGR (*(unsigned long *)((0x40023800) + (0x08)))



int main(){
	RCC_CR |= (1 << 0);
	RCC_AHB1ENR  |= (1 << 1);  // enable clock on portb
	RCC_CFGR |= (0x0A << 4);
	unsigned char pinReadPrevious,pinReadCurrent;
	GPIOB_MODER &= ~ (0x03 << 3*2); // pin3 input mode
	GPIOB_PUPDR &= ~(0x03 << 3*2); //clear pin3
	GPIOB_PUPDR |= (0x01 << 3*2); // pin3 pull up enable

	for(unsigned long k = 5 ; k<=7; k++){
	GPIOB_MODER &= ~(0x03 << k * 2); /* clear pin k */
	GPIOB_MODER |= 0x01 << ( k * 2); // pin k output mode
	GPIOB_OTYPER &= ~(1 << k); // pin k push pull
	}

	unsigned char counter = 0 ;
	unsigned char flag = 0;
	unsigned long i = 0;
	while(1){
		if(counter> 7){
			counter = 0;
		}
		pinReadPrevious = (GPIOB_IDR & (1 << 3) ) >> 3;
		for(i = 0; i < 5000; i++); //debounce feature
		pinReadCurrent = (GPIOB_IDR & (1 << 3) ) >> 3;

		if(pinReadPrevious == pinReadCurrent){
			if(pinReadCurrent == 0){
				flag = 1;
				switch(counter){
				case 0:
					GPIOB_ODR |= (1 << 5);
					GPIOB_ODR |= (1 << 6);
					GPIOB_ODR |= (1 << 7);
					break;
				case 1:
					GPIOB_ODR &=~ (1 << 5);
					GPIOB_ODR &=~ (1 << 6);
					GPIOB_ODR |= (1 << 7);

					break;
				case 2:
					GPIOB_ODR &= ~ (1 << 5);
					GPIOB_ODR |= (1 << 6);
					GPIOB_ODR &= ~ (1 << 7);
					break;
				case 3:
					GPIOB_ODR |= (1 << 5);
					GPIOB_ODR |= (1 << 6);
					GPIOB_ODR &=~ (1 << 7);
					break;
				case 4:
					GPIOB_ODR |=  (1 << 5);
					GPIOB_ODR &= ~ (1 << 6);
					GPIOB_ODR &= ~ (1 << 7);
					break;
				case 5:
					GPIOB_ODR |= (1 << 5);
					GPIOB_ODR &=~ (1 << 6);
					GPIOB_ODR |= (1 << 7);

					break;
				case 6:
					GPIOB_ODR &= ~ (1 << 5);
					GPIOB_ODR |= (1 << 6);
					GPIOB_ODR |= (1 << 7);

					break;
				case 7:
					GPIOB_ODR &= ~ (1 << 5);
					GPIOB_ODR &= ~ (1 << 6);
					GPIOB_ODR &=~ (1 << 7);
					break;
				}
		}else {
				if(flag == 1){
					counter++;
					flag = 0;
				}
			}
		}
	}


	return 0;
}

