#include "millis.h"
#include "stm8s.h"

__IO uint32_t current_millis = 0; //--IO: volatile read/write 

void millis_init(void)
{
	/* Time base configuration */
	TIM4_TimeBaseInit(TIM4_PRESCALER_64, TIM4_PERIOD);
	/* Clear TIM4 update flag */
	TIM4_ClearFlag(TIM4_FLAG_UPDATE);
	/* Enable update interrupt */
	TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);

	/* enable interrupts */
	ITC_SetSoftwarePriority(ITC_IRQ_TIM4_OVF, ITC_PRIORITYLEVEL_1); 
	TIM4_Cmd(ENABLE);
	enableInterrupts();
}

uint32_t millis(void)
{
	return current_millis;
}