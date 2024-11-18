
#ifndef __STM32F407XX_COMMON_DEFINITION_H__
#define __STM32F407XX_COMMON_DEFINITION_H__

#define BIT_LENGTH                      1U
#define TWO_BIT_LENGTH                  2U
#define NIBBLE_LENGTH                   4U
#define BYTE_LENGTH                     8U

#define TWO_BIT_SHIFTING(value)         (value * 2U)
#define FOUR_BIT_SHIFTING(value)        (value * 4U)
#define EIGHT_BIT_SHIFTING(value)       (value * 8U)

#define ENABLE                          1U
#define DISABLE                         0U

#define MAX_IRQ_NUM_POSSIBLE            81U
#define NUM_OF_BIT_IMPLEMTED            4U

#define IRQ_NUM_EXTI0                   6U
#define IRQ_NUM_EXTI1                   7U
#define IRQ_NUM_EXTI2                   8U
#define IRQ_NUM_EXTI3                   9U
#define IRQ_NUM_EXTI4                   10U
#define IRQ_NUM_EXTI9_5                 23U
#define IRQ_NUM_EXTI15_10               40U

#define IRQ_PRIORITY0                   0U
#define IRQ_PRIORITY1                   1U
#define IRQ_PRIORITY2                   2U

#define IRQ_PRIORITY15                  15U

typedef enum
{
  LOW = 0U,
  HIGH = 1U,
} Bit_State_Et;

#endif // __STM32F407XX_COMMON_DEFINITION_H__