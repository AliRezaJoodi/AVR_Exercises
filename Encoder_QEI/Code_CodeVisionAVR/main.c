// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumeric LCD functions
#include <alcd.h>

#include "hardware.h"
#include "qei.h"

uint8_t lcd_task = 0;

QEI_t qei = {
    .chA = {
        .ddr   = &QEI_A_DDR,
        .port  = &QEI_A_PORT,
        .pin   = &QEI_A_PIN,
        .index = QEI_A_BIT,
        .mask  = QEI_A_MASK
    },
    .chB = {
        .ddr   = &QEI_B_DDR,
        .port  = &QEI_B_PORT,
        .pin   = &QEI_B_PIN,
        .index = QEI_B_BIT,
        .mask  = QEI_B_MASK
    },
    .count = 0U,
    .last  = 0U
};

void LCD_Config(void);
void LCD_Display(void);

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void){
    QEI_Update(&qei);
    lcd_task = 1;
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void){
    QEI_Update(&qei);
//    lcd_task = 1;
}

void main(void){
    // External Interrupt(s) initialization
    // INT0: On
    // INT0 Mode: Any change
    // INT1: On
    // INT1 Mode: Any change
    // INT2: Off
    GICR|=(1<<INT1) | (1<<INT0) | (0<<INT2);
    MCUCR=(0<<ISC11) | (1<<ISC10) | (0<<ISC01) | (1<<ISC00);
    MCUCSR=(0<<ISC2);
    GIFR=(1<<INTF1) | (1<<INTF0) | (0<<INTF2);

    LCD_Config();
    LCD_Display();

    QEI_Init(&qei);
    #asm("sei")     // Globally enable interrupts

    while (1){
        if (lcd_task == 1){
            lcd_task = 0;
            LCD_Display();
        }
    }
}

//*************************************
void LCD_Display(void){
    char txt[16];
    itoa(qei.count, txt);
    lcd_gotoxy(0,0); lcd_putsf("Value:"); lcd_puts(txt); lcd_putsf("    ");
    lcd_gotoxy(0,1); lcd_putsf("Encoder Driver");
}

//*************************************
void LCD_Config(void){
    lcd_init(16);
    lcd_clear();
}
