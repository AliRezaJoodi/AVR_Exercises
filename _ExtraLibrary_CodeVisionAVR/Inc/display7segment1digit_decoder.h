// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _DISPLAY7SEGMENT1DIGIT_DECODER_INCLOUDED
    #define _DISPLAY7SEGMENT1DIGIT_DECODER_INCLOUDED


#include <stdint.h>

#pragma used+
void Display7Segment1Digit_DecoderDigitToSegments(uint8_t digit_0To9,  uint8_t *seg);
void Display7Segment1Digit_DecoderChrToSegments(uint8_t index,  uint8_t *seg);
void Display7Segment1Digit_ToggleSegments(uint8_t *seg);

//uint8_t Display7Segment1Digit_DecoderDigitToSegments(uint8_t digit_0To9);
//uint8_t Display7Segment1Digit_DecoderChrToSegments(uint8_t chr);
//uint8_t Display7Segment1Digit_ToggleSegments(uint8_t data);
#pragma used-


#pragma library display7segment1digit_decoder.lib
#endif
