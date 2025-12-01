#include "stm8s.h"
#include "delay.h"
#include "millis.h"
#include "stdio.h"

int main() {
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
    SerialInit(9600);
    millis_init();
    while (1) {
   //do nothing
    }
}


/*Pod tento komentar vkladejte interrupt vektory*/
extern uint32_t current_millis;
/* Interrupt Vektor pro millis Nesahat!!!!*/
INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23){
	current_millis ++;
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
}