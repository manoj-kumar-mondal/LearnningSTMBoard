
#ifndef __STM32F407XX_ERROR_HANDLER_H__
#define __STM32F407XX_ERROR_HANDLER_H__

typedef enum
{
  NO_ERROR = 0U,
  NULL_ERROR,
  INCORRECT_VALUE,
  TOTAL_DRIVER_ERROR,
} Driver_Error_Et;


void CatchError(Driver_Error_Et ErrorType);

#endif // __STM32F407XX_ERROR_HANDLER_H__