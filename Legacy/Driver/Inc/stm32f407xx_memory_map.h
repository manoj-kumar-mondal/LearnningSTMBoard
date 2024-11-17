
#ifndef __STM32F40XX_MEMORY_MAP_H__
#define __STM32F40XX_MEMORY_MAP_H__

/**
 * @brief Device's base addresses
 */
#define FLASH_BASE_ADDR                     (0x08000000UL)
#define SRAM1_BASE_ADDR                     (0x20000000UL) /*!< size of SRAM1 = 112KB >*/
#define SRAM2_BASE_ADDR                     (0x20001C00UL) /*!< size of SRAM2 = 16KB >*/
#define ROM_BASE_ADDR                       (0x1FFF0000UL)
#define OTP_BASE_ADDR                       (0x1FFFC000UL)
#define SRAM_START_ADDR                     (SRAM1_BASE_ADDR)

/**
 * @brief Device's buses addresses
 */
#define PERIPHERAL_BASE_ADDR                (0x40000000UL)
#define APB1_PERIPHERAL_BASE_ADDR           (PERIPHERAL_BASE_ADDR)
#define APB2_PERIPHERAL_BASE_ADDR           (0x40010000UL)
#define AHB1_PERIPHERAL_BASE_ADDR           (0x40020000UL)
#define AHB2_PERIPHERAL_BASE_ADDR           (0x50000000UL)

/**
 * @brief AHB1 peripherals
 */
#define GPIOA_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR)
#define GPIOB_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x0400UL)
#define GPIOC_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x0800UL)
#define GPIOD_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x0C00UL)
#define GPIOE_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x1000UL)
#define GPIOF_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x1400UL)
#define GPIOG_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x1800UL)
#define GPIOH_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x1C00UL)
#define GPIOI_BASE_ADDR                     (AHB1_PERIPHERAL_BASE_ADDR + 0x2000UL)
#define RCC_BASE_ADDR                       (AHB1_PERIPHERAL_BASE_ADDR + 0x3800UL)

/**
 * @brief APB1 peripherals
 */
#define USART2_BASE_ADDR                    (APB1_PERIPHERAL_BASE_ADDR + 0x4400UL)
#define USART3_BASE_ADDR                    (APB1_PERIPHERAL_BASE_ADDR + 0x4800UL)
#define UART4_BASE_ADDR                     (APB1_PERIPHERAL_BASE_ADDR + 0x4C00UL)
#define UART5_BASE_ADDR                     (APB1_PERIPHERAL_BASE_ADDR + 0x5000UL)
#define I2C1_BASE_ADDR                      (APB1_PERIPHERAL_BASE_ADDR + 0x5400UL)
#define I2C1_BASE_ADDR                      (APB1_PERIPHERAL_BASE_ADDR + 0x5400UL)
#define I2C2_BASE_ADDR                      (APB1_PERIPHERAL_BASE_ADDR + 0x5800UL)
#define I2C3_BASE_ADDR                      (APB1_PERIPHERAL_BASE_ADDR + 0x5C00UL)

/**
 * @brief APB2 peripherals
 */
#define USART1_BASE_ADDR                    (APB2_PERIPHERAL_BASE_ADDR + 0x1000UL)
#define USART6_BASE_ADDR                    (APB2_PERIPHERAL_BASE_ADDR + 0x1400UL)
#define SPI1_BASE_ADDR                      (APB2_PERIPHERAL_BASE_ADDR + 0x3000UL)
#define SPI4_BASE_ADDR                      (APB2_PERIPHERAL_BASE_ADDR + 0x3400UL)
#define SYSCFG_BASE_ADDR                    (APB2_PERIPHERAL_BASE_ADDR + 0x3800UL)
#define EXTI_BASE_ADDR                      (APB2_PERIPHERAL_BASE_ADDR + 0x3C00UL)

#endif // __STM32F40XX_MEMORY_MAP_H__