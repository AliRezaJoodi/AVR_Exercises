// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _DISPLAY7SEGMENT4DIGIT_DECODER_TIME_INCLOUDED
#define _DISPLAY7SEGMENT4DIGIT_DECODER_TIME_INCLOUDED

#include <stdint.h>

#include <utility.h> 
#include <seg7_1digit_encoder.h>

typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t colon;
} Time_t;

// Define in Main:
//Time_t time_t = {
//    .hour  = 23,
//    .minute  = 59,
//    .second = 50,
//    .colon  = 1
//};

uint8_t Display7Segment4Digit_DecodeTime_HourMin(Time_t time, uint8_t *seg);
uint8_t Display7Segment4Digit_DecodeTime_MinSec(Time_t time, uint8_t *seg);

#pragma library display7segment4digit_decoder_time.lib
#endif
