
#include "stm32f407xx_gpio.h"
#include <string.h>

int main()
{
	GPIO_PinConfig_St Btn, Led;

	memset(&Led, 0, sizeof(GPIO_PinConfig_St));
	memset(&Btn, 0, sizeof(GPIO_PinConfig_St));

	Btn.Port = PORT_A;
	Btn.Pin = PIN_0;
	Btn.Mode = MODE_INTERRUPT_RISING_EDGE;

	Led.Port = PORT_D;
	Led.Pin = PIN_15;
	Led.Mode = MODE_OUTPUT;

	GPIO_Init(&Led);
	GPIO_Init(&Btn);

	IRQConfig(IRQ_NUM_EXTI0, ENABLE);
	SetIRQPriority(IRQ_NUM_EXTI0, IRQ_PRIORITY15);
	
	while(1);
	return 0;
}

void EXTI0_IRQHandler(void)
{
	IRQHandling(PIN_0);
	TogglePin(PORT_D, PIN_15);
}