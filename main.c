#include "USART.c"

void delay(int delay);

void delay(int delay){
	SysTick ->LOAD = delay; //
	SysTick ->VAL = 0; // Reset the current VAL
	SysTick ->CTRL = 0x5;
	
	while(1){
		// (Check COUNTFLAG = 1) ?
		if(SysTick->CTRL & 0x10000){
		//GPIOB->ODR = GPIOB->ODR ˆ 0x00004080; // Toggle
			return ;
		}
	}
}

int main(){
	UART_config();
	char* str = 
	RCC->AHB1ENR |= 0x00000002; // (PORT B -> ENABLE)
	GPIOB->MODER |= 0x4; // (PB1 )-> Output Mode && & PB2 ->INPUT MODE 
	
	
	GPIOB->ODR = 0x00000002; 
	
	delay(10*16); //geneartes a 10us delay
	
	GPIOB->ODR = 0x00000000;
	
	int counter = 0;
	while(GPIOB->IDR & (1<<2)){
		counter++;
	}
	int distance = (counter /16000000)*(343/2);
	
	return distance;
	
	//return 1;
}