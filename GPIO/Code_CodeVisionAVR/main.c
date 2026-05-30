// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include "gpio.h"

void main(void){
    uint8_t value = 0;

    typedef struct{
        const GPIO_PortReg_t *gpio;
        const GPIO_PinPos_t index;
    } LED_t;

    static const LED_t LED2 = {
        .gpio   = &GPIOB,
        .index  = GPIO_PIN_1_POS,
    };

    //Init Pins for LED2
    GPIO_ConfigDirection(LED2.gpio, LED2.index, GPIO_DIR_OUTPUT);
    GPIO_WritePin(LED2.gpio, LED2.index, 1);

    //Init Pins for LED
    GPIO_ConfigDirection(&GPIOB, GPIO_PIN_0_POS, GPIO_DIR_OUTPUT);
    GPIO_WritePin(&GPIOB, GPIO_PIN_0_POS, 0);
//    GPIO_SetPin(&GPIOB, GPIO_PIN_0); delay_ms(1000);
//    GPIO_ClearPin(&GPIOB, GPIO_PIN_0); delay_ms(1000);
//    GPIO_SetPinMask(&GPIOB, GPIO_PINMASK_0); delay_ms(1000);
//    GPIO_ClearPinMask(&GPIOB, GPIO_PINMASK_0); delay_ms(1000);
//    GPIO_TogglePinMask(&GPIOB, GPIO_PINMASK_0); delay_ms(1000);
//    GPIO_TogglePinMask(&GPIOB, GPIO_PINMASK_0); delay_ms(1000);
//    GPIO_TogglePin(&GPIOB, GPIO_PIN_0); delay_ms(1000);
//    GPIO_TogglePin(&GPIOB, GPIO_PIN_0); delay_ms(1000);

    //Init Pins for Button_On
    GPIO_ConfigDirection(&GPIOA, GPIO_PIN_0_POS, GPIO_DIR_INPUT);
    GPIO_ConfigPull(&GPIOA, GPIO_PIN_0_POS, GPIO_PULL_UP);

    //Init Pins for Button_Off
    GPIO_ConfigDirection(&GPIOA, GPIO_PIN_1_POS, GPIO_DIR_INPUT);
    GPIO_ConfigPull(&GPIOA, GPIO_PIN_1_POS, GPIO_PULL_NONE);

    //Init Pins for 4-channel input
    GPIO_ConfigDirection(&GPIOB, GPIO_PIN_3_POS, GPIO_DIR_INPUT);
    GPIO_ConfigPull(&GPIOA, GPIO_PIN_3_POS, GPIO_PULL_NONE);

    GPIO_ConfigDirection(&GPIOB, GPIO_PIN_4_POS, GPIO_DIR_INPUT);
    GPIO_ConfigPull(&GPIOA, GPIO_PIN_4_POS, GPIO_PULL_NONE);

    GPIO_ConfigDirection(&GPIOB, GPIO_PIN_5_POS, GPIO_DIR_INPUT);
    GPIO_ConfigPull(&GPIOA, GPIO_PIN_5_POS, GPIO_PULL_NONE);

    GPIO_ConfigDirection(&GPIOB, GPIO_PIN_6_POS, GPIO_DIR_INPUT);
    GPIO_ConfigPull(&GPIOA, GPIO_PIN_6_POS, GPIO_PULL_NONE);

    //Init Pins for 4-pin 7-Segment
    GPIO_ConfigDirection(&GPIOC, GPIO_PIN_2_POS, GPIO_DIR_OUTPUT);
    GPIO_WritePin(&GPIOC, GPIO_PIN_2_POS, 0);

    GPIO_ConfigDirection(&GPIOC, GPIO_PIN_3_POS, GPIO_DIR_OUTPUT);
    GPIO_WritePin(&GPIOC, GPIO_PIN_3_POS, 0);

    GPIO_ConfigDirection(&GPIOC, GPIO_PIN_4_POS, GPIO_DIR_OUTPUT);
    GPIO_WritePin(&GPIOC, GPIO_PIN_4_POS, 0);

    GPIO_ConfigDirection(&GPIOC, GPIO_PIN_5_POS, GPIO_DIR_OUTPUT);
    GPIO_WritePin(&GPIOC, GPIO_PIN_5_POS, 0);

    while(1){
        if(GPIO_ReadPin(&GPIOA, GPIO_PIN_0_POS) == 0){
			GPIO_SetPin(&GPIOB, GPIO_PIN_0_POS);
		}

		if(GPIO_ReadPin(&GPIOA, GPIO_PIN_1_POS) == 0){
			GPIO_ClearPin(&GPIOB, GPIO_PIN_0_POS);
		}

	    value = GPIO_Read4Pin(&GPIOB, GPIO_PIN_3_POS);
		GPIO_Write4Pin(&GPIOC, GPIO_PIN_2_POS, value);
    }
}



