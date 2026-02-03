// GitHub Account: GitHub.com/AliRezaJoodi

#include <button.h>

//*************************************************
void Button_Config(Button_t *btn){
    CLEAR_BIT(*btn->hw_ddr, btn->hw_bit);
//    WRITE_BIT(*btn->hw_port, btn->hw_bit, !BUTTON_PRESSED);
    btn->status  = 0;
    btn->counter = 0;
}

//*************************************************
void Button_SetPullUp(Button_t *btn, uint8_t enable){
    WRITE_BIT(*btn->hw_port, btn->hw_bit, enable);
}

//*************************************************
uint8_t Button_GetSingleClick(Button_t *btn){
    if ( GET_BIT(*btn->hw_pin, btn->hw_bit) != BUTTON_PRESSED ){
        if(btn->status == 1){
            delay_ms(BUTTON_SINGLE_CLICK_LAG);
            if (GET_BIT(*btn->hw_pin, btn->hw_bit) != BUTTON_PRESSED){
                btn->status = 0;
            } 
        }
    }
    else{
        if(btn->status == 0){
            delay_ms(BUTTON_SINGLE_CLICK_LAG);
            if (GET_BIT(*btn->hw_pin, btn->hw_bit) == BUTTON_PRESSED){
                btn->status = 1;
                return 1;
            }
        }
    }

    return 0;
}

//*************************************************
uint8_t Button_GetAutoRepeat_NonBlocking(Button_t *btn){
    if (GET_BIT(*btn->hw_pin, btn->hw_bit) == BUTTON_PRESSED){
        btn->counter++;

        if (btn->counter >= BUTTON_AUTO_REPEAT_LAG){
            btn->counter = 0;
            return 1;
        }
    }
    else{
        btn->counter = 0;
    }

    return 0;
}

//*************************************************
uint8_t Button_GetLongPress_NonBlocking(Button_t *btn){
    if (GET_BIT(*btn->hw_pin, btn->hw_bit) == BUTTON_PRESSED){
        if (btn->counter < BUTTON_LONG_PRESS_LAG)
            btn->counter++;

        if ((btn->counter >= BUTTON_LONG_PRESS_LAG) && (btn->status == 0)){
            btn->status = 1;
            return 1;
        }
    }
    else{
        btn->counter = 0;
        btn->status = 0;
    }

    return 0;
}