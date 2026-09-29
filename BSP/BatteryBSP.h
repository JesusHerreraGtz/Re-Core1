#pragma once

#include <stdint.h>
#include "main.h"

/// @brief Performs an ADC reading of the battery voltage and converts it to millivolts.
/// @return The battery voltage in millivolts (0 to 3300 mV).
uint16_t BSP_GetBatteryVoltage(void);