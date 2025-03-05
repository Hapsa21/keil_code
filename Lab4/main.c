#include <stm32f4xx.h>

int main(){
    
    RCC->AHB1ENR |= 0x00000002;  

    
    GPIOB->MODER |= 0x55400014; 

    
    GPIOB->ODR = 0x00000000; 

    
    SysTick->LOAD = 16000000 - 1;
    SysTick->VAL  = 0;          // Clear current value
    SysTick->CTRL = 0x5;         // Enable SysTick with processor clock

    int counter = 0, val = 0;
    while(1){
        
        if(SysTick->CTRL & 0x10000){
            if(val & 1){
                switch(counter){
                    case 0:
                        GPIOB->ODR = 0xd806;
                        break;
                    case 1:
                        GPIOB->ODR = 0x804;
                        break;
                    case 2:
                        GPIOB->ODR = 0xb802;
                        break;
                    case 3:
                        GPIOB->ODR = 0x3806;
                        break;
                    case 4:
                        GPIOB->ODR = 0x6804;
                        break;
                    case 5:
                        GPIOB->ODR = 0x7006;
                        break;
                    case 6:
                        GPIOB->ODR = 0xf006;
                        break;
                    case 7:
                        GPIOB->ODR = 0x1804;
                        break;
                    case 8:
                        GPIOB->ODR = 0xf806;
                        break;
                    case 9:
                        GPIOB->ODR = 0x7806;
                        break;
                    default:
                        GPIOB->ODR = 0x0000;
                        break;
                }
                
                counter = (counter + 1) % 10;
            }
            // Increment the tick counter
            val++;
        }
    }
    return 1;
}
