#include "stm32f412zx.h"

void UART_config(void);
void USART3_sendchar(uint8_t c);
uint8_t USART3_getchar(void);
void sendstring(char* str);

void UART_config(void ){
	RCC->APB1ENR |= (1 << 18);
	RCC->AHB1ENR |= (1 << 3);
	
	GPIOD->MODER |= (1 <<17);
	GPIOD->MODER |= (1 << 19);
	
	//alternate function
	GPIOD->AFR[1]=0x77;
	
	
	//UE
	USART3->CR1&=~(1<<13);
	
	//ctrl register 
	USART3->CR1&=~(1<<12);
	
	//baud rate 
	USART3->BRR&=0X683;
	
	//te and re 
	USART3->CR1&=~(1<<2);
	USART3->CR1&=~(1<<3);
	
}

void USART3_sendchar(uint8_t c){
	USART3->DR=c;
	while(!(USART3->SR & (1<< 7)));
	
}

uint8_t USART3_getchar(void){
	uint8_t temp;
	while(!(USART3->SR & (1<<5)));
	temp = USART3->DR;
	return temp;
}


void sendstring(char* str){
	while(*str){
		USART3_sendchar(*str);
	}
}




