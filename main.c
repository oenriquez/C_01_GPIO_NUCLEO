#include "stm32f4xx.h"                  // Device header
void LED_INIT(void);
void LED_OUTPUT(int val);
void delay_ms(int delay_time);

int main(){
	LED_INIT(); 
	
	while(1){
			LED_OUTPUT(0);
			delay_ms(500);
		
			LED_OUTPUT(1);
			delay_ms(500);
	}
}
void LED_INIT(void){
	RCC->AHB1ENR|=(1<<0);//habilitando el puerto GPIOA 
	GPIOA->MODER&=~(0x3<<10);//asi limpiamos el registro
	GPIOA->MODER|=(1<<10);//ponemos 1 en ese registro 
}
void LED_OUTPUT(int val){
	if (val==0){
				GPIOA->BSRRH=(1<<5);// bsrrh pone en bajo el pin 5
	}
	else{
				GPIOA->BSRRL=(1<<5);// bsrrl pone en alto el pin 5
	}
		
}
void delay_ms(int delay_time){
	int i;
	int j;
	j=delay_time*0xFFF;
	for(i=0;i<j;i++){
		
	}
  
}
