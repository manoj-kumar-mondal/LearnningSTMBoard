
#ifndef __STM32F407XX_REGISTER_DEFINITION_H__
#define __STM32F407XX_REGISTER_DEFINITION_H__

#include <stdint.h>

/**
 * @brief GPIO port
 */
typedef struct
{
  volatile uint32_t MODER;                  /*!< Mode                   Address Offset: 0x00 >*/
  volatile uint32_t OTYPER;                 /*!< Ouput Type             Address Offset: 0x04 >*/
  volatile uint32_t OSPEEDR;                /*!< Output Speed           Address Offset: 0x08 >*/
  volatile uint32_t PUPDR;                  /*!< Pull-up/Pull-down      Address Offset: 0x0C >*/
  volatile uint32_t IDR;                    /*!< Input Data             Address Offset: 0x10 >*/
  volatile uint32_t ODR;                    /*!< Output Data            Address Offset: 0x14 >*/
  volatile uint32_t BSRR;                   /*!< Bit Set/Reset          Address Offset: 0x18 >*/
  volatile uint32_t LCKR;                   /*!< Configuration Lock     Address Offset: 0x1C >*/
  volatile uint32_t AFR[2];                 /*!< Alternate Function     Address Offset: 0x1C >*/ //contains array of low & high registers
} GPIO_RegDef_t;

/**
 * @brief RCC
 */
typedef struct
{
  volatile uint32_t CR;                     /*!< Control                    Address Offset: 0x00 >*/
  volatile uint32_t PLLCFGR;                /*!< PLL Configuration          Address Offset: 0x04 >*/
  volatile uint32_t CFGR;                   /*!< Clock Configuration        Address Offset: 0x08 >*/
  volatile uint32_t CIR;                    /*!< Clock Interrupt            Address Offset: 0x0C >*/
  volatile uint32_t AHB1RSTR;               /*!< AHB1 Reset                 Address Offset: 0x10 >*/
  volatile uint32_t AHB2RSTR;               /*!< AHB2 Reset                 Address Offset: 0x14 >*/
  volatile uint32_t AHB3RSTR;               /*!< AHB3 Reset                 Address Offset: 0x18 >*/
  uint32_t Reserved0;
  volatile uint32_t APB1RSTR;               /*!< APB1 Reset                 Address Offset: 0x20 >*/
  volatile uint32_t APB2RSTR;               /*!< APB2 Reset                 Address Offset: 0x24 >*/
  uint32_t  Reserved1[2];
  volatile uint32_t AHB1ENR;                /*!< AHB1 Clock                 Address Offset: 0x30 >*/
  volatile uint32_t AHB2ENR;                /*!< AHB2 Clock                 Address Offset: 0x34 >*/
  volatile uint32_t AHB3ENR;                /*!< AHB3 Clock                 Address Offset: 0x38 >*/
  uint32_t Reserved2;
  volatile uint32_t APB1ENR;                /*!< APB1 Clock                 Address Offset: 0x40 >*/
  volatile uint32_t APB2ENR;                /*!< APB2 Clock                 Address Offset: 0x44 >*/
  uint32_t Reserved3[2];
  volatile uint32_t AHB1LPENR;              /*!< AHB1 Clock (LP Mode)       Address Offset: 0x50 >*/ //LP: Low Power
  volatile uint32_t AHB2LPENR;              /*!< AHB2 Clock (LP Mode)       Address Offset: 0x54 >*/
  volatile uint32_t AHB3LPENR;              /*!< AHB3 Clock (LP Mode)       Address Offset: 0x58 >*/
  uint32_t Reserved4;
  volatile uint32_t APB1LPENR;              /*!< APB1 Clock (LP Mode)       Address Offset: 0x60 >*/
  volatile uint32_t APB2LPENR;              /*!< APB2 Clock (LP Mode)       Address Offset: 0x64 >*/
  uint32_t Reserved5[2];
  volatile uint32_t BDCR;                   /*!< Backup Domain Control      Address Offset: 0x70 >*/
  volatile uint32_t CSR;                    /*!< Clock Control & Status     Address Offset: 0x74 >*/
  uint32_t Reserved6[2];
  volatile uint32_t SSCGR;                  /*!< Spread Spectrum Clock Gen  Address Offset: 0x80 >*/
  volatile uint32_t PLLI2SCFGR;             /*!< PLLI2S configuration       Address Offset: 0x84 >*/
  volatile uint32_t PLLSAICFGR;             /*!< PLL configuration          Address Offset: 0x88 >*/
  volatile uint32_t DCKCFGR;                /*!< Dedicated Clock config     Address Offset: 0x8C >*/
} RCC_RegDef_t;

/**
 * @brief EXTI
 */
typedef struct
{
  volatile uint32_t IMR;                    /*!< Interrupt Mask             Address Offset: 0x00 >*/
  volatile uint32_t EMR;                    /*!< Event  Mask                Address Offset: 0x04 >*/
  volatile uint32_t RTSR;                   /*!< Rising Trigger             Address Offset: 0x08 >*/
  volatile uint32_t FTSR;                   /*!< Falling Trigger            Address Offset: 0x0C >*/
  volatile uint32_t SWIER;                  /*!< Software Interrupt Event   Address Offset: 0x10 >*/
  volatile uint32_t PR;                     /*!< Pending                    Address Offset: 0x14 >*/
} EXTI_RegDef_t;

/**
 * @brief SYSCFG
 */
typedef struct
{
  volatile uint32_t MEMRMP;                 /*!< Memory Remap               Address Offset: 0x00 >*/
  volatile uint32_t PMC;                    /*!< Peripheral Mode Config     Address Offset: 0x04 >*/
  volatile uint32_t EXTICR[4];                /*!< External Interrupt Config  Address Offset: 0x08 - 0x14 >*/
  uint32_t Reserved[2];
  volatile uint32_t CMPCR;                  /*!< Compensation Cell Control  Address Offset: 0x20 >*/
} SYSCFG_RegDef_t;

#endif // __STM32F407XX_REGISTER_DEFINITION_H__