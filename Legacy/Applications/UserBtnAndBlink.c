
#include "stm32f407xx_gpio.h"

typedef void (*Function)(void);

extern void software_delay(void);
extern void LedInit(void);
extern void Pattern1(void);
extern void Pattern2(void);
extern void Pattern3(void);

const Function pFunction[3]= {
  Pattern1, Pattern2, Pattern3
};

// int main()
// {
//   GPIO_PinConfig_St Btn;
//   uint8_t Index = 0;

//   Btn.Port = PORT_A;
//   Btn.Pin = PIN_0;
//   Btn.Mode = MODE_INPUT;

//   GPIO_Init(&Btn);
//   LedInit();

//   while(1)
//   {
//     if(HIGH == ReadPin(Btn.Port, Btn.Pin))
//     {
//       Index = Index % 3;
//       Index++;
//       software_delay();
//     }
//     pFunction[Index]();
//   }
// }
