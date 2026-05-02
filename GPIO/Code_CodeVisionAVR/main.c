// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include "gpio.h"

void main(void){
    static const GPIO_t led = {
        .ddr   = &LED_DDR,
        .port  = &LED_PORT,
        .pin   = &LED_PIN,
        .index = LED_BIT,
        .mask  = LED_MASK
    };

    static const GPIO_t key = {
        .ddr   = &KEY_DDR,
        .port  = &KEY_PORT,
        .pin   = &KEY_PIN,
        .index = KEY_BIT,
        .mask  = KEY_MASK
    };

    static const GPIO_t out_x4 = {
        .ddr   = &OUT_DDR,
        .port  = &OUT_PORT,
        .pin   = &OUT_PIN,
        .index = OUT_BIT,
        .mask  = OUT_MASK
    };

    static const GPIO_t in_x4 = {
        .ddr   = &IN_DDR,
        .port  = &IN_PORT,
        .pin   = &IN_PIN,
        .index = IN_BIT,
        .mask  = IN_MASK
    };

    GPIO_SetOutputPinMask(&led); delay_ms(1000);

    GPIO_WriteHighPin(&led); delay_ms(500);
    GPIO_WriteLowPin(&led); delay_ms(1000);

    GPIO_WriteHighPinMask(&led); delay_ms(500);
    GPIO_WriteLowPinMask(&led); delay_ms(1000);

    GPIO_WritePin(&led, 1); delay_ms(500);
    GPIO_WritePin(&led, 0); delay_ms(1000);

    GPIO_TogglePin(&led); delay_ms(500);
    GPIO_TogglePin(&led); delay_ms(1000);

    GPIO_TogglePinMask(&led); delay_ms(500);
    GPIO_TogglePinMask(&led); delay_ms(1000);

    GPIO_SetInputPinMask(&key);
    GPIO_SetPullUpPinMask(&key); delay_ms(1000);
    GPIO_SetPullNonePinMask(&key); delay_ms(1000);
    GPIO_SetPullUpPinMask(&key);

    GPIO_SetOutputPinMask(&out_x4); delay_ms(1000);
    GPIO_SetInputPinMask(&in_x4);
    GPIO_SetPullUpPinMask(&in_x4); delay_ms(1000);

    while(1){
        PORTB.0 = GPIO_ReadPin(&key);
        GPIO_WritePinMask(&out_x4, GPIO_ReadPinMask_Shifted(&in_x4));
    }
}



