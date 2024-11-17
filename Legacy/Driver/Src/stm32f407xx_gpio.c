
#include "stm32f407xx_gpio.h"
#include "stm32f407xx_error_handler.h"
#include "stm32f407xx_rcc.h"
#include <stdlib.h>

static GPIO_RegDef_t* GetGpioPort(GPIO_Port_Et Port);

void GPIO_Init(GPIO_PinConfig_St *pPinConfig)
{
  if(pPinConfig != NULL)
  {
    GPIO_RegDef_t *pGpiox = GetGpioPort(pPinConfig->Port);

    if(pGpiox != NULL)
    {
      //Enable Gpio Port clock
      RCC->AHB1ENR |= (1 << pPinConfig->Port);

      //Gpio Mode
      pGpiox->MODER |= (pPinConfig->Mode << TWO_BIT_SHIFTING(pPinConfig->Pin));

      if(pPinConfig->Mode == MODE_OUTPUT)
      {
        //OType
        pGpiox->OTYPER |= (pPinConfig->OType << pPinConfig->Pin);

        //Speed
        pGpiox->OSPEEDR |= (pPinConfig->Speed << TWO_BIT_SHIFTING(pPinConfig->Pin));

        //PUPD
        pGpiox->PUPDR |= (pPinConfig->PupdType << TWO_BIT_SHIFTING(pPinConfig->Pin));
      }
    }
    else
    {
      CatchError(NULL_ERROR);
    }
  }
  else
  {
    CatchError(NULL_ERROR);
  }
}

void WritePort(GPIO_Port_Et Port, uint16_t Data)
{
  GPIO_RegDef_t *pGpiox = GetGpioPort(Port);

  if(pGpiox != NULL)
  {
    pGpiox->ODR = Data;
  }
  else
  {
    CatchError(NULL_ERROR);
  }
}

uint16_t ReadPort(GPIO_Port_Et Port)
{
  GPIO_RegDef_t *pGpiox = GetGpioPort(Port);

  if(pGpiox != NULL)
  {
    return pGpiox->IDR;
  }
  else
  {
    CatchError(NULL_ERROR);
    return 0;
  }
}

void WritePin(GPIO_Port_Et Port, GPIO_Pin_Et Pin, Bit_State_Et State)
{
  GPIO_RegDef_t *pGpiox = GetGpioPort(Port);

  if(pGpiox != NULL)
  {
    if(State == HIGH)
    {
      pGpiox->ODR |= (1 << Pin);
    }
    else
    {
      pGpiox->ODR &= ~(1 << Pin);
    }
  }
  else
  {
    CatchError(NULL_ERROR);
  }
}

Bit_State_Et ReadPin(GPIO_Port_Et Port, GPIO_Pin_Et Pin)
{
  GPIO_RegDef_t *pGpiox = GetGpioPort(Port);

  if(pGpiox != NULL)
  {
    return (Bit_State_Et)(((pGpiox->IDR) >> Pin) & 1);
  }
  else
  {
    CatchError(NULL_ERROR);
    return LOW;
  }
}

Bit_State_Et TogglePin(GPIO_Port_Et Port, GPIO_Pin_Et Pin)
{
  GPIO_RegDef_t *pGpiox = GetGpioPort(Port);

  if(pGpiox != NULL)
  {
    pGpiox->ODR ^= (1 << Pin);
    return (Bit_State_Et)((pGpiox->ODR >> Pin) & 1);
  }
  else
  {
    CatchError(NULL_ERROR);
    return LOW;
  }
}

static GPIO_RegDef_t* GetGpioPort(GPIO_Port_Et Port)
{
  switch(Port)
  {
    case PORT_A:
      return GPIOA;

    case PORT_B:
      return GPIOB;

    case PORT_C:
      return GPIOC;

    case PORT_D:
      return GPIOD;

    case PORT_E:
      return GPIOE;

    case PORT_F:
      return GPIOF;

    case PORT_G:
      return GPIOG;

    case PORT_H:
      return GPIOH;

    case PORT_I:
      return GPIOI;

    default:
      return NULL;
  }
}

