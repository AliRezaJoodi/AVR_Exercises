#ifndef _LCD_INCLUDED_
#define _LCD_INCLUDED_

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

#pragma library Display_LCD.lib

#endif

