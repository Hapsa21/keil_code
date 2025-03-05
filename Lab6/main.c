#include "stm32f412zx.h"
float voltage ;



int main() {
		RCC->APB2ENR |= 0x100; // Enable clock for ADC1
		RCC->AHB1ENR |= 0x1;
		RCC->AHB1ENR |= 0x2;
	
		ADC1->CR2 |= 0x2; // Enable continuous conversion mode
		ADC1->CR2 |= 0x400; // EOC after each conversion
		ADC1->CR2 |= 0x1; // ADON =1 enable ADC1
		ADC1->SQR3 |= 0; // Conversion in regular sequence
		GPIOA->MODER |= 0x3; // Analog mode for PA0
		GPIOB->MODER |= 0x4000; 
		
		while(1) {
			ADC1->SR = 0; // Clear the status register
			ADC1->CR2 |= (0x40000000); // SWSTART
			while (ADC1->SR & (0x2)) { // Check conversion completes
				//adc_value = ADC1->DR; // get ADC values
				uint32_t adc_val = ADC1->DR;
				voltage = adc_val*(3.3/(1<<12));
				
				if(voltage <1.78){
					GPIOB->ODR = 0x80;
				}else{
					GPIOB->ODR = 0x0;
				}
				
				
		}
	}
}