// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>

#include <display7segment4digit_decoder_float.h>
#include <display7segment4digit2display_driver.h>

void main(void){
    float volt = 54.3456;
    uint8_t volt_segments[4];

    float amp = 2.615;
    uint8_t amp_segments[4];

    Display7Segment4Digit2Disply_Config();

    Display7Segment4Digit_DecodeFloat_2d(volt, &volt_segments[0]);
    if(ACTIVATE_SEGMENT == 0){
        Display7Segment4Digit_Toggle4Byte( &volt_segments[0] );
    }

    Display7Segment4Digit_DecodeFloat_2d(amp, &amp_segments[0]);
    if(ACTIVATE_SEGMENT == 0){
        Display7Segment4Digit_Toggle4Byte( &amp_segments[0] );
    }

    while(1){
        Display7Segment4Digit2Disply_DriveDisplay1(volt_segments); delay_ms(5);
        Display7Segment4Digit2Disply_DriveDisplay2(amp_segments); delay_ms(5);
    };
}
