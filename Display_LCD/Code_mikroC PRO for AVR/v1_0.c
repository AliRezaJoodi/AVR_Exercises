//GitHub Account:     GitHub.com/AliRezaJoodi

// LCD module connections
sbit LCD_RS at PORTD0_bit;
sbit LCD_EN at PORTD2_bit;
sbit LCD_D4 at PORTD4_bit;
sbit LCD_D5 at PORTD5_bit;
sbit LCD_D6 at PORTD6_bit;
sbit LCD_D7 at PORTD7_bit;
sbit LCD_RS_Direction at DDD0_bit;
sbit LCD_EN_Direction at DDD2_bit;
sbit LCD_D4_Direction at DDD4_bit;
sbit LCD_D5_Direction at DDD5_bit;
sbit LCD_D6_Direction at DDD6_bit;
sbit LCD_D7_Direction at DDD7_bit;

void Config_LCD(void);
void Display_loading(void);
void Display_Advertising(void);
void Test1(void);

void main(){
     Config_LCD();
     Display_loading();
     Display_Advertising();
     Test1();

     while(1){

     }
}

//********************************************************
void Test1(void){
     char txt1[] = "ABCD";
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Out(1,1,txt1);
}

//********************************************************
void Display_loading(void){
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Out(1,1,"Testing the LCD");
     Lcd_Out(2,1,"Loading ...");
     Delay_ms(500); Lcd_Cmd(_LCD_CLEAR);
}

//********************************************************
void Display_Advertising(void){
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Out(1,1,"GitHub.com");
     Lcd_Out(2,1,"AliRezaJoodi");
     Delay_ms(500); Lcd_Cmd(_LCD_CLEAR);
}

//********************************************************
void Config_LCD(void){
     Lcd_Init();      // Initialize LCD
     Lcd_Cmd(_LCD_CURSOR_OFF);   // Cursor off
     Lcd_Cmd(_LCD_CLEAR);     // Clear display
}