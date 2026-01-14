// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _DISPLAY_7SEGMENT_1DIGIT_INCLOUDED
    #define _DISPLAY_7SEGMENT_1DIGIT_INCLOUDED


#include <stdint.h>

#pragma used+
void Display7Segment1Digit_DecoderDigitToSegments(uint8_t digit_0To9,  uint8_t *seg);
void Display7Segment1Digit_DecoderChrToSegments(uint8_t index,  uint8_t *seg);
void Display7Segment1Digit_ToggleSegments(uint8_t *seg);

//uint8_t Display7Segment1Digit_DecoderDigitToSegments(uint8_t digit_0To9);
//uint8_t Display7Segment1Digit_DecoderChrToSegments(uint8_t chr);
//uint8_t Display7Segment1Digit_ToggleSegments(uint8_t data);
#pragma used-


#pragma library display_7segment_1digit.lib
#endif
