// GitHub Account: GitHub.com/AliRezaJoodi

#include "_ExtraLibrary\_hardware_v1.0.h"

#include <mega32a.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

#include <utility.h>
#include <button.h>

void LCD_Config(void);
void LCD_DisplayMainPage(unsigned char);
void Button_Config(void);

void main(void){  
    uint8_t value=100;
    uint8_t value_last=0;
    
    Button_SingleClick_t button1_t ={
        &BUTTON1_PIN,
        BUTTON1_BIT,
        !BUTTON_PRESSED
    }; 
    
    Button_AutoRepeat_t button2_t ={
        &BUTTON2_PIN,
        BUTTON2_BIT,
        0
    };
    
    Button_LongPress_t button3_t ={
        &BUTTON3_PIN,
        BUTTON3_BIT,
        0,
        0
    };
//
//    Button2_t button2_t ={
//        &BUTTON2_PIN,
//        BUTTON2_BIT,
//        !BUTTON_PRESSED,
//        0
//    };
    
    LCD_Config();    
    Button_Config();

    LCD_DisplayMainPage(value);
   
    while(1){ 
        if(Button_SingleClick(&button1_t)){
            ++value;
        }
        
        if(Button_AutoRepeat_NonBlocking(&button2_t)){
            ++value;
        }
        
        if(Button_LongPress_NonBlocking(&button3_t)){
            ++value;
        }
        
//        if(Button_SingleClick_NonBlocking(&button2_t)){
//            ++value;
//        }
        
        if(value_last!=value){
            value_last=value;
            LCD_DisplayMainPage(value);
        }
    };
}

//********************************************************
void LCD_DisplayMainPage(unsigned char value){
    char txt[16];
    itoa(value,txt);
    lcd_clear();
    lcd_gotoxy(0,0); lcd_putsf("Number= "); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("Get Button");
}

//********************************************************
void LCD_Config(void){
    lcd_init(16); lcd_clear();   
}

//********************************************************
void Button_Config(void){
    ClearBit(BUTTON1_DDR, BUTTON1_BIT)  //  Input 
    SetBit(BUTTON1_PORT, BUTTON1_BIT)   // Pull_Up 

    ClearBit(BUTTON2_DDR, BUTTON2_BIT)  //  Input 
    SetBit(BUTTON2_PORT, BUTTON2_BIT)   // Pull_Up
    
    ClearBit(BUTTON3_DDR, BUTTON3_BIT)  //  Input 
    SetBit(BUTTON3_PORT, BUTTON3_BIT)   // Pull_Up
}




