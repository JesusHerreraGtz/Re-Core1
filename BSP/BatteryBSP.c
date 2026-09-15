#include "BatteryBSP.h"

// Importamos la variable del ADC generada por STM32CubeMX en main.c
extern ADC_HandleTypeDef hadc1; 

uint16_t BSP_GetBatteryVoltage(void)
{
    uint32_t adc_value = 0;
    uint16_t voltage_mv = 0;

    // 1. Iniciamos la lectura del ADC
    HAL_ADC_Start(&hadc1);
    
    // 2. Esperamos a que la lectura termine (con un tiempo límite de 10 milisegundos)
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
        // 3. Obtenemos el valor crudo del ADC (un número entre 0 y 4095)
        adc_value = HAL_ADC_GetValue(&hadc1);
        
        // 4. Convertimos el valor crudo a milivoltios.
        // Multiplicamos por 3300mV (max de la tarjeta) y dividimos entre 4095
        voltage_mv = (uint16_t)((adc_value * 3300) / 4095);
    }
    
    // 5. Apagamos el ADC para ahorrar energía
    HAL_ADC_Stop(&hadc1);

    // 6. Retornamos el voltaje ya convertido
    return voltage_mv;
}