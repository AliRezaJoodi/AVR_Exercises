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
void Display_Value(void);
void Get_Button(void);

bit button_incr_status;
unsigned char value;

void main(){
     Config_LCD(); Display_Value();
     DDB0_bit = 0;    // Set pin as input

     while(1){
              Get_Button();
     }
}

//********************************************************
void Get_Button(void){
     if (button_incr_status && Button(&PINB, 0, 30, 0)) {
        Delay_ms(30);
        if (Button(&PINB, 0, 30, 0)){
           ++value;
           Display_Value();
           button_incr_status = 0;
        }
     }
     if (Button(&PINB, 0, 30, 1)) {button_incr_status = 1;}
}

//********************************************************
void Display_Value(void){
     char txt[16];
     ByteToStr(value, txt);
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Out(1,1, "Number= "); Lcd_Out(1,8, txt);
     Lcd_Out(2,1,"Get Button");
}

//********************************************************
void Config_LCD(void){
     Lcd_Init();      // Initialize LCD
     Lcd_Cmd(_LCD_CURSOR_OFF);   // Cursor off
     Lcd_Cmd(_LCD_CLEAR);     // Clear display
}