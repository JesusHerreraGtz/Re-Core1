#pragma once

#include <stdint.h>
#include "main.h"

/// @brief Realiza una lectura del ADC y la convierte a milivoltios.
/// @return El voltaje de la batería en milivoltios (0 a 3300 mV).
uint16_t BSP_GetBatteryVoltage(void);