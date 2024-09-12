
#include <io.h>
#include <delay.h>

#ifndef _LCD_INCLUDED
#define _LCD_INCLUDED

#ifndef LCD_HARDWARE
#define LCD_HARDWARE
    #define rs  PORTD.0
    #define e   PORTD.2
    #define d4  PORTD.4
    #define d5  PORTD.5
    #define d6  PORTD.6
    #define d7  PORTD.7
#endif

#pragma used+
void lcd_write (unsigned char data);
// write a byte to the LCD character generator or display RAM
void lcd_gotoxy(unsigned char x, unsigned char y);
// clear the LCD
void lcd_clear(void);
void lcd_putchar(char c);
// write the string str located in SRAM to the LCD
void lcd_puts(char *str);
// write the string str located in FLASH to the LCD
void lcd_putsf(char flash *str);
// initialize the LCD controller
void lcd_init(unsigned char lcd_columns);
#pragma used-

#pragma library display_lcd.lib

#endif

