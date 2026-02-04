/**
 * @brief   LM335 temperature sensor conversion utilities
 *
 * @details
 * LM335 outputs a voltage linearly proportional to absolute temperature
 * in Kelvin (10 mV per 1 K).
 *
 * Formula:
 *  - Temperature (K) = Voltage (mV) × 0.1
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef _LM335_INCLUDED
#define _LM335_INCLUDED


static inline float LM335_ConvertMilliVoltToTemp(float volt_mv){
    return (volt_mv * 0.1f);
}

static inline float LM335_ConvertVoltToTemp(float volt_v){
    return (volt_v * 1000 * 0.1f);
}


#endif
