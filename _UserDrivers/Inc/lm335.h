/**
 * @brief   LM335 temperature sensor conversion utilities
 *
 * @details
 * The LM335 is a precision temperature sensor that provides an output
 * voltage linearly proportional to the absolute temperature.
 *
 * Conversion rule:
 *  - Every 10 millivolts (mV) corresponds to 1 Kelvin (K)
 *  - Sensor output is referenced to absolute zero (0 K)
 *
 * Formula:
 *  - Temperature (K) = Voltage (mV) × 0.1
 *
 * @author  AliReza Joodi
 * @see https://github.com/AliRezaJoodi
 */

#ifndef _LM335_INCLUDED
#define _LM335_INCLUDED


static inline float LM335_ConvertMilliVoltToTemp(float volt_mv){
    return (volt_mv * 0.1);
}

static inline float LM335_ConvertVoltToTemp(float volt_v){
    return (volt_v * 1000 * 0.1);
}


#endif
