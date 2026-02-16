// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _DISPLAY7SEGMENT4DIGIT_DECODER_FLOAT_INCLOUDED
    #define _DISPLAY7SEGMENT4DIGIT_DECODER_FLOAT_INCLOUDED


#include <stdint.h>

#include <utility.h>
#include <seg7_1digit_encoder.h>

#pragma used+
uint8_t Display7Segment4Digit_DecodeFloat_2d(float value, uint8_t *seg);
uint8_t Display7Segment4Digit_DecodeFloat_1d(float value, uint8_t *seg);
void Display7Segment4Digit_Toggle4Byte(uint8_t *seg);
#pragma used-


#pragma library display7segment4digit_decoder_float.lib
#endif
