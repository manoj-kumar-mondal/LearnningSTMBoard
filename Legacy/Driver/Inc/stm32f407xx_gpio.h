
#ifndef __STM32F407XX_GPIO_H__
#define __STM32F407XX_GPIO_H__

#include "stm32f407xx_memory_map.h"
#include "stm32f407xx_register_defintion.h"
#include "stm32f407xx_common_defintion.h"

#define GPIOA           ((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB           ((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC           ((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD           ((GPIO_RegDef_t*)GPIOD_BASE_ADDR)
#define GPIOE           ((GPIO_RegDef_t*)GPIOE_BASE_ADDR)
#define GPIOF           ((GPIO_RegDef_t*)GPIOF_BASE_ADDR)
#define GPIOG           ((GPIO_RegDef_t*)GPIOG_BASE_ADDR)
#define GPIOH           ((GPIO_RegDef_t*)GPIOH_BASE_ADDR)
#define GPIOI           ((GPIO_RegDef_t*)GPIOI_BASE_ADDR)

typedef enum
{
  PORT_A = 0U,
  PORT_B = 1U,
  PORT_C = 2U,
  PORT_D = 3U,
  PORT_E = 4U,
  PORT_F = 5U,
  PORT_G = 6U,
  PORT_H = 7U,
  PORT_I = 8U,
  TOTAL_GPIO_PORT,
} GPIO_Port_Et;

typedef enum
{
  PIN_0 = 0U,
  PIN_1 = 1U,
  PIN_2 = 2U,
  PIN_3 = 3U,
  PIN_4 = 4U,
  PIN_5 = 5U,
  PIN_6 = 6U,
  PIN_7 = 7U,
  PIN_8 = 8U,
  PIN_9 = 9U,
  PIN_10 = 10U,
  PIN_11 = 11U,
  PIN_12 = 12U,
  PIN_13 = 13U,
  PIN_14 = 14U,
  PIN_15 = 15U,
  TOTAL_GPIO_PIN,
} GPIO_Pin_Et;

typedef enum
{
  MODE_INPUT = 0U,
  MODE_OUTPUT = 1U,
  MODE_ALTFN = 2U,
  MODE_ANALOG = 3U,
  
  MODE_INTERRUPT_START = 4U,
  MODE_INTERRUPT_FALLING_EDGE = MODE_INTERRUPT_START,
  MODE_INTERRUPT_RISING_EDGE,
  MODE_INTERRUPT_FALLING_RISING_EDGE,
  MODE_INTERRUPT_END,
  TOTAL_GPIO_MODE,
} GPIO_Mode_Et;

typedef enum
{
  OTYPE_PP = 0U,
  OTYPE_OD = 1U,
  TOTAL_GPIO_OTYPE,
} GPIO_OType_Et;

typedef enum
{
  SPEED_LOW = 0U,
  SPEED_MEDIUM = 1U,
  SPEED_HIGH = 2U,
  SPEED_VERY_HIGH = 3U,
  TOTAL_GPIO_SPEED,
} GPIO_Speed_Et;

typedef enum
{
  NO_PUPD = 0U,
  PULL_UP = 1U,
  PULL_DOWN = 2U,
  TOTAL_GPIO_PUPD,
} GPIO_Pupd_Et;

typedef struct
{
  GPIO_Port_Et Port;
  GPIO_Pin_Et Pin;
  GPIO_Mode_Et Mode;
  GPIO_OType_Et OType;
  GPIO_Speed_Et Speed;
  GPIO_Pupd_Et PupdType;
} GPIO_PinConfig_St;

void GPIO_Init(GPIO_PinConfig_St *pPinConfig);
void WritePort(GPIO_Port_Et Port, uint16_t Data);
uint16_t ReadPort(GPIO_Port_Et Port);
void WritePin(GPIO_Port_Et Port, GPIO_Pin_Et Pin, Bit_State_Et State);
Bit_State_Et ReadPin(GPIO_Port_Et Port, GPIO_Pin_Et Pin);
Bit_State_Et TogglePin(GPIO_Port_Et Port, GPIO_Pin_Et Pin);
void IRQConfig(uint8_t IRQNumber, uint8_t Mode);
void SetIRQPriority(uint8_t IRQNumber, uint8_t IRQPriority);
void IRQHandling(uint8_t Pin);

#endif // __STM32F407XX_GPIO_H__