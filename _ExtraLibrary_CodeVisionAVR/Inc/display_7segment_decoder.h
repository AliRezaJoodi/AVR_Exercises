// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _DISPLAY_7SEGMENT_DECODER_INCLOUDED
    #define _DISPLAY_7SEGMENT_DECODER_INCLOUDED


#include <stdint.h>

#pragma used+
uint8_t Display_DecoderDigitTo7Segment(uint8_t digit_0To9);
uint8_t Display_DecoderChrTo7Segment(uint8_t chr);
uint8_t Display_Toggle7Segment(uint8_t data);
#pragma used-


#pragma library display_7segment_decoder.lib
#endif
