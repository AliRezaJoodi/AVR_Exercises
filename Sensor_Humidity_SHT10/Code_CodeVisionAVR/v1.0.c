// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32.h>               
#include <delay.h>                                      
#include <stdio.h>  

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x1b ;PORTA
#endasm
#include <lcd.h>

#include "Attachment\hardware_v1.0.h"
#include <sensor_shtxx.h>  

float temperature=0; 
float humidity=0;
void Display_Values(void);
                                
void main(void){                                
    lcd_init(16); lcd_clear();
                                       
    while(1){
        humidity=Get_Humidity(); 
        temperature= Get_Temp();
        Display_Values();
        delay_ms(250);                                  
    }
}

//***********************
void Display_Values(void){
    char txt[16]; 
    lcd_clear();
    sprintf(txt,"Humidity(%%)=%3.1f",humidity); lcd_gotoxy(0,0); lcd_puts(txt);  
    sprintf(txt,"Temp(C)=%3.1f",temperature); lcd_gotoxy(0,1); lcd_puts(txt); 
}

