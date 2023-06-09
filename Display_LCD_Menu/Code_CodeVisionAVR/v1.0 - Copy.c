//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>
#include <string.h>

char i1=100;
char i2=200;

#include "Attachment\DisplayManager.h"

void SyncronDisplayValues(void);
    
void main(void){
    char txt[16]="abcd"; 
    
    struct load{
        char volt;
        char amp;  
    }device1={15,2};
      
    //struct student stdArr;
    /*MENU lcd_menu_data;
    lcd_menu_data.x1=10;
    lcd_menu_data.x2=20;
    lcd_menu_data.x3=30;
    lcd_menu_data.x4=40;
    lcd_menu_data.x5=50;
    */
        
    ConfigLCD();
    //Display_Loading(); 
    //Display_Advertising(); 
    
    device1.volt=30;
    //lcd_gotoxy(0,0); itoa(device1.volt,txt); lcd_puts(txt); lcd_putsf("  ");    
    //lcd_gotoxy(0,1); itoa(device1.amp,txt); lcd_puts(txt); lcd_putsf("  "); 
    
    strcpy(display.txt1, "Test LCD"); 
    strcpy(display.txt2, "Loding ...");
    DisplayMenu1();
    delay_ms(500);
    
    display.value1=device1.volt;
    display.value2=device1.amp;
    DisplayMenu2();
    
    while(1){
    };
}

//********************************
void SyncronDisplayValues(void){
}

