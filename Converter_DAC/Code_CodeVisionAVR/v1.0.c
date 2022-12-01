// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <alcd.h>
flash char LCD_COLUMN=16;

void Config_LCD(void);
void Display_LCD_Loding(unsigned int);
void Display_LCD(float);
void Config_Timer1(void);
void DAC_Voltage(float);

void main(void){
    float out_persent=0;
    unsigned int out_pwm=0;
    
    Config_Timer1();
    Config_LCD();
    Display_LCD_Loding(500); 
    
    out_persent=50; DAC_Voltage(out_persent);
    Display_LCD(out_persent);
    
    while (1){
    }
}

//******************************************
void DAC_Voltage(float x){
    char buffer_lcd[LCD_COLUMN];
    float y=0;     
    if(x>100){x=100;};     //x=0~100%
    //x=100-x;   //inverse 
    y=((x*(5-1))/100)+1;   //y=1~5V
    y=(y*1000)/4.8875855;    //y=204~1023
    OCR1A=y;    
    //sprintf(buffer_lcd,"PWM=%5.1f",y); lcd_gotoxy(0,1); lcd_puts(buffer_lcd); lcd_putsf("    "); 
}

//********************************************************
void Config_Timer1(void){
// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Fast PWM top=0x03FF
// OC1A output: Non-Inverted PWM
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 0.128 ms
// Output Pulse(s):
// OC1A Period: 0.128 ms Width: 0 us
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (1<<WGM11) | (1<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

DDRD.4=1; PORTD.4=0;
DDRD.5=1; PORTD.5=0;
}

//******************************************
void Display_LCD(float x){
    char txt[LCD_COLUMN]; 
    sprintf(txt,"Out(1-5V):%2.1f%%",x); lcd_gotoxy(0,0); lcd_puts(txt); lcd_putsf("  ");
    lcd_gotoxy(0,1); lcd_putsf("DAC with PWM");
}

//******************************************
void Display_LCD_Loding(unsigned int x){
    lcd_gotoxy(0,0); lcd_putsf("Please Wait ...");
    delay_ms(x); lcd_clear();
} 

//********************************************************
void Config_LCD(void){
    lcd_init(LCD_COLUMN);
    lcd_clear();
}


