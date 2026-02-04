// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _CONVERTER_TEMPERATURE_INCLUDED
#define _CONVERTER_TEMPERATURE_INCLUDED


static inline float Converter_Temp_KtoC(float value){
    return (value - 273.15f);
}

static inline float Converter_Temp_KtoF(float value){
    return (((value - 273.15f) * 1.8f) + 32.0f);
}

static inline float Converter_Temp_CtoK(float value){
    return (value + 273.15f);
}

static inline float Converter_Temp_CtoF(float value){
    return ((value * 1.8f) + 32.0f);
}

static inline float Converter_Temp_FtoC(float value){
    return ((value - 32.0f) * 0.5555556f);
}

static inline float Converter_Temp_FtoK(float value){
    return (((value - 32.0f) * 0.5555556f) + 273.15f);
}


#endif
