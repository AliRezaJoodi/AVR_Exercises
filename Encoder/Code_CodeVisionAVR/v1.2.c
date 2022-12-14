// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumeric LCD functions
#include <alcd.h>

#include "Attachment\Encoder.h"

void Config_LCD(void);
void Display_Value(void);

void main(void){
    int encoder_value_old=0;

    Config_LCD();
    Display_Value();
    Config_Encoder();

    while (1){ 
        if(encoder_value!=encoder_value_old){
            Display_Value();
            encoder_value_old=encoder_value;   
        }
    }
}

//*************************************
void Display_Value(void){
    char txt[16];
    itoa(encoder_value,txt); lcd_gotoxy(0,0); lcd_putsf("Value:"); lcd_puts(txt); lcd_putsf("    ");
    lcd_gotoxy(0,1); lcd_putsf("Encoder Driver");   
}

//*************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}
