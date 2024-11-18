
#include "stm32f407xx_gpio.h"
#include "stm32f407xx_error_handler.h"
#include "stm32f407xx_rcc.h"
#include "stm32f407xx_exti.h"
#include "stm32f407xx_syscfg.h"
#include "stm32f407xx_nvic.h"

#include <stdlib.h>

static GPIO_RegDef_t* GetGpioPort(GPIO_Port_Et Port);
static void ConfigInterruptMode(GPIO_Mode_Et Mode, GPIO_Port_Et Port, GPIO_Pin_Et Pin);

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
      pGpiox->MODER &= ~(0x3 << TWO_BIT_SHIFTING(pPinConfig->Pin)); // clear the previous value.
      if(MODE_INTERRUPT_START <= pPinConfig->Mode && MODE_INTERRUPT_END >= pPinConfig->Mode)
      {
        //configure gpio to input mode
        ConfigInterruptMode(pPinConfig->Mode, pPinConfig->Port, pPinConfig->Pin);
      }
      else
      {
        pGpiox->MODER |= (pPinConfig->Mode << TWO_BIT_SHIFTING(pPinConfig->Pin));
      }

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

void IRQConfig(uint8_t IRQNumber, uint8_t Mode)
{
  if(IRQNumber <= MAX_IRQ_NUM_POSSIBLE)
  {
    uint8_t IRQIndex = IRQNumber / 32; //each register having 32 IRQ number
    uint8_t ShiftIndex = IRQNumber % 32;

    if(Mode == ENABLE)
    {
      uint32_t *pISER = (uint32_t*)(NVIC_ISER_BASE_ADDR);

      pISER += IRQIndex;
      *pISER |= (1 << ShiftIndex);

    }
    else if(Mode == DISABLE)
    {
      uint32_t *pICER = (uint32_t*)(NVIC_ICER_BASE_ADDR);

      pICER += IRQIndex;
      *pICER |= (1 << ShiftIndex);
    }
  }
  else
  {
    CatchError(INCORRECT_VALUE);
  }
}

void SetIRQPriority(uint8_t IRQNumber, uint8_t IRQPriority)
{
  if(IRQNumber <= MAX_IRQ_NUM_POSSIBLE)
  {
    uint8_t IRQIndex = IRQNumber / NIBBLE_LENGTH;
    uint8_t ShiftIndex = IRQNumber % NIBBLE_LENGTH;
    uint32_t *pIPR = (uint32_t*)(NVIC_IPR_BASE_ADDR);

    pIPR += IRQIndex;
    // In IPR registers, each IRQPriority having 8 bits, but the lower 4 bits are not implemented.
    ShiftIndex = (ShiftIndex * BYTE_LENGTH) + (BYTE_LENGTH - NUM_OF_BIT_IMPLEMTED);
    *pIPR |= (IRQPriority << ShiftIndex);
  }
  else
  {
    CatchError(INCORRECT_VALUE);
  }
}

void IRQHandling(uint8_t Pin)
{
  if((EXTI->PR) & (1 << Pin))
  {
    EXTI->PR |= (1 << Pin);
  }
}

static void ConfigInterruptMode(GPIO_Mode_Et Mode, GPIO_Port_Et Port, GPIO_Pin_Et Pin)
{
  if(MODE_INTERRUPT_RISING_EDGE == Mode)
  {
    EXTI->RTSR |= (1 << Pin);
    EXTI->FTSR &= ~(1 << Pin);
  }
  else if(MODE_INTERRUPT_FALLING_EDGE == Mode)
  {
    EXTI->FTSR |= (1 << Pin);
    EXTI->RTSR &= ~(1 << Pin);
  }
  else if(MODE_INTERRUPT_FALLING_RISING_EDGE == Mode)
  {
    EXTI->RTSR |= (1 << Pin);
    EXTI->FTSR |= (1 << Pin);
  }

  // Enable clock for syscfg
  RCC->APB2ENR |= (1 << 14);
  
  //configure exti control register
  uint8_t CRIndex = Pin / NIBBLE_LENGTH;
  uint8_t ShiftIndex = Pin % NIBBLE_LENGTH;
  SYSCFG->EXTICR[CRIndex] |= (Port << FOUR_BIT_SHIFTING(ShiftIndex));

  // Enable Interrupt Delivery usinf IMR
  EXTI->IMR |= (1 << Pin);
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

