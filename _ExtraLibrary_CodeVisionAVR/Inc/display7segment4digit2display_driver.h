// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _DISPLAY7SEGMENT4DIGIT2DISPLAY_DRIVER_INCLOUDED
    #define _DISPLAY7SEGMENT4DIGIT2DISPLAY_DRIVER_INCLOUDED


#include <stdint.h>

#include <display7segment4digit2display_driver_hw.h>

void Display7Segment4Digit2Disply_Config(void);

#pragma used+
char Display7Segment4Digit2Disply_DriveDisplay1(uint8_t segments[]);
char Display7Segment4Digit2Disply_DriveDisplay2(uint8_t segments[]);
#pragma used-


#pragma library display7segment4digit2display_driver.lib
#endif






