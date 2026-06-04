// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <mega32a.h>
#include <delay.h>

#include "hardware.h"
#include "aj_gpio.h"

void main(void){
    uint8_t value = 0;

    typedef struct{
        const AJ_GPIO_PortReg_t *gpio;
        const AJ_GPIO_PinPos_t index;
    } LED_t;

    static const LED_t LED2 = {
        .gpio   = &GPIOB,
        .index  = AJ_GPIO_PIN_1_POS,
    };

//    AJ_GPIO_ConfigPinsAsInput_Mask(&GPIOC, AJ_GPIO_PIN_0_MASK | AJ_GPIO_PIN_1_MASK | AJ_GPIO_PIN_7_MASK);
//    AJ_GPIO_EnablePullUp_Mask(&GPIOC, AJ_GPIO_PIN_0_MASK | AJ_GPIO_PIN_1_MASK | AJ_GPIO_PIN_7_MASK);
//    AJ_GPIO_DisablePullUp_Mask(&GPIOC, AJ_GPIO_PIN_0_MASK | AJ_GPIO_PIN_1_MASK);
//    AJ_GPIO_EnablePullUp_Position(&GPIOC, AJ_GPIO_PIN_0_POS);
//    AJ_GPIO_DisablePullUp_Position(&GPIOC, AJ_GPIO_PIN_0_POS);
//    while(1){}

    //Init Pins for LED2
    AJ_GPIO_ConfigDirection(LED2.gpio, LED2.index, AJ_GPIO_DIR_OUTPUT);
    AJ_GPIO_WritePin_Position(LED2.gpio, LED2.index, 1);

    //Init Pins for LED
    AJ_GPIO_ConfigDirection(&GPIOB, AJ_GPIO_PIN_0_POS, AJ_GPIO_DIR_OUTPUT);
    AJ_GPIO_WritePin_Position(&GPIOB, AJ_GPIO_PIN_0_POS, 0);
//    AJ_GPIO_SetPin_Position(&GPIOB, AJ_GPIO_PIN_0); delay_ms(1000);
//    AJ_GPIO_ClearPin_Position(&GPIOB, AJ_GPIO_PIN_0); delay_ms(1000);
//    AJ_AJ_GPIO_SetPin_Positions_Mask(&GPIOB, AJ_GPIO_PINMASK_0); delay_ms(1000);
//    AJ_GPIO_ClearPins_Mask(&GPIOB, AJ_GPIO_PINMASK_0); delay_ms(1000);
//    AJ_GPIO_TogglePins_Mask(&GPIOB, AJ_GPIO_PINMASK_0); delay_ms(1000);
//    AJ_GPIO_TogglePins_Mask(&GPIOB, AJ_GPIO_PINMASK_0); delay_ms(1000);
//    AJ_GPIO_TogglePin_Position(&GPIOB, AJ_GPIO_PIN_0); delay_ms(1000);
//    AJ_GPIO_TogglePin_Position(&GPIOB, AJ_GPIO_PIN_0); delay_ms(1000);

    //Init Pins for Button_On
    AJ_GPIO_ConfigDirection(&GPIOA, AJ_GPIO_PIN_0_POS, AJ_GPIO_DIR_INPUT);
    AJ_GPIO_ConfigPull(&GPIOA, AJ_GPIO_PIN_0_POS, AJ_GPIO_PULL_UP);

    //Init Pins for Button_Off
    AJ_GPIO_ConfigDirection(&GPIOA, AJ_GPIO_PIN_1_POS, AJ_GPIO_DIR_INPUT);
    AJ_GPIO_ConfigPull(&GPIOA, AJ_GPIO_PIN_1_POS, AJ_GPIO_PULL_NONE);

    //Init Pins for 4-channel input
    AJ_GPIO_ConfigDirection(&GPIOB, AJ_GPIO_PIN_3_POS, AJ_GPIO_DIR_INPUT);
    AJ_GPIO_ConfigPull(&GPIOA, AJ_GPIO_PIN_3_POS, AJ_GPIO_PULL_NONE);

    AJ_GPIO_ConfigDirection(&GPIOB, AJ_GPIO_PIN_4_POS, AJ_GPIO_DIR_INPUT);
    AJ_GPIO_ConfigPull(&GPIOA, AJ_GPIO_PIN_4_POS, AJ_GPIO_PULL_NONE);

    AJ_GPIO_ConfigDirection(&GPIOB, AJ_GPIO_PIN_5_POS, AJ_GPIO_DIR_INPUT);
    AJ_GPIO_ConfigPull(&GPIOA, AJ_GPIO_PIN_5_POS, AJ_GPIO_PULL_NONE);

    AJ_GPIO_ConfigDirection(&GPIOB, AJ_GPIO_PIN_6_POS, AJ_GPIO_DIR_INPUT);
    AJ_GPIO_ConfigPull(&GPIOA, AJ_GPIO_PIN_6_POS, AJ_GPIO_PULL_NONE);

    //Init Pins for 4-pin 7-Segment
    AJ_GPIO_ConfigDirection(&GPIOC, AJ_GPIO_PIN_2_POS, AJ_GPIO_DIR_OUTPUT);
    AJ_GPIO_WritePin_Position(&GPIOC, AJ_GPIO_PIN_2_POS, 0);

    AJ_GPIO_ConfigDirection(&GPIOC, AJ_GPIO_PIN_3_POS, AJ_GPIO_DIR_OUTPUT);
    AJ_GPIO_WritePin_Position(&GPIOC, AJ_GPIO_PIN_3_POS, 0);

    AJ_GPIO_ConfigDirection(&GPIOC, AJ_GPIO_PIN_4_POS, AJ_GPIO_DIR_OUTPUT);
    AJ_GPIO_WritePin_Position(&GPIOC, AJ_GPIO_PIN_4_POS, 0);

    AJ_GPIO_ConfigDirection(&GPIOC, AJ_GPIO_PIN_5_POS, AJ_GPIO_DIR_OUTPUT);
    AJ_GPIO_WritePin_Position(&GPIOC, AJ_GPIO_PIN_5_POS, 0);

    while(1){
        if(AJ_GPIO_ReadPin_Position(&GPIOA, AJ_GPIO_PIN_0_POS) == 0){
			AJ_GPIO_SetPin_Position(&GPIOB, AJ_GPIO_PIN_0_POS);
		}

		if(AJ_GPIO_ReadPin_Position(&GPIOA, AJ_GPIO_PIN_1_POS) == 0){
			AJ_GPIO_ClearPin_Position(&GPIOB, AJ_GPIO_PIN_0_POS);
		}

	    value = AJ_GPIO_Read4Pins_Position(&GPIOB, AJ_GPIO_PIN_3_POS);
		AJ_GPIO_Write4Pins_Position(&GPIOC, AJ_GPIO_PIN_2_POS, value);
    }
}



