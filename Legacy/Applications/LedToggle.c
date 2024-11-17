
#include "stm32f407xx_gpio.h"
#include <string.h>

#define TOTAL_USER_LED 4U

const GPIO_PinConfig_St UserLedConfig[TOTAL_USER_LED] = { \
/* Port    Pin     Mode         OType     Speed      PUPDType */
  {PORT_D, PIN_12, MODE_OUTPUT, OTYPE_PP, SPEED_LOW, NO_PUPD },
  {PORT_D, PIN_13, MODE_OUTPUT, OTYPE_PP, SPEED_LOW, NO_PUPD },
  {PORT_D, PIN_14, MODE_OUTPUT, OTYPE_PP, SPEED_LOW, NO_PUPD },
  {PORT_D, PIN_15, MODE_OUTPUT, OTYPE_PP, SPEED_LOW, NO_PUPD },
};

void software_delay()
{
  for(int i = 0 ; i < 150000 ; i++);
}

void Pattern1(void)
{
  uint8_t Index = 0;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
  Index++;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
  Index++;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
  Index++;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
}

void Pattern2(void)
{
  uint8_t Index = TOTAL_USER_LED - 1;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
  Index--;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
  Index--;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
  Index--;
  TogglePin(UserLedConfig[Index].Port, UserLedConfig[Index].Pin);
  software_delay();
}

void Pattern3(void)
{
  TogglePin(UserLedConfig[0].Port, UserLedConfig[0].Pin);
  software_delay();
  TogglePin(UserLedConfig[2].Port, UserLedConfig[2].Pin);
  software_delay();
  TogglePin(UserLedConfig[1].Port, UserLedConfig[1].Pin);
  software_delay();
  TogglePin(UserLedConfig[3].Port, UserLedConfig[3].Pin);
  software_delay();
}

void LedInit(void)
{
  for(int Index = 0U ; Index < TOTAL_USER_LED ; Index++)
  {
    GPIO_Init((GPIO_PinConfig_St*)&UserLedConfig[Index]);
  }

  // while (1)
  // {
  //   Pattern1();
  //   Pattern2();
  // }
}
