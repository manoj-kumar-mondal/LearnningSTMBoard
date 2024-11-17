
#ifndef __STM32F407XX_COMMON_DEFINITION_H__
#define __STM32F407XX_COMMON_DEFINITION_H__

#define TWO_BIT_SHIFTING(value)         (value * 2U)
#define FOUR_BIT_SHIFTING(value)        (value * 4U)

typedef enum
{
  LOW = 0U,
  HIGH = 1U,
} Bit_State_Et;

#endif // __STM32F407XX_COMMON_DEFINITION_H__