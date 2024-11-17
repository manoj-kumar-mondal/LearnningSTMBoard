
#include "stm32f407xx_error_handler.h"
#include <stdint.h>

typedef struct
{
  Driver_Error_Et LastErrorType;
  Driver_Error_Et ErrorType;
  uint8_t IsErrorHandled;
} DriverErrorHandler_St;

DriverErrorHandler_St g_DriverErrorHandle;

void CatchError(Driver_Error_Et ErrorType)
{
  g_DriverErrorHandle.LastErrorType = g_DriverErrorHandle.ErrorType;
  g_DriverErrorHandle.ErrorType = ErrorType;
}
