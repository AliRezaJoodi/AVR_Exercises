// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdlib.h>

// Alphanumeric LCD functions
#include <alcd.h>

bit int_status=0;
char encoder_status=0;
int encoder_value=0;

//******************************************
void Config_INT1_RisingEdge(void){
    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: On
    // INT1 Mode: Rising Edge
    // INT2: Off
    GICR|=(1<<INT1) | (0<<INT0) | (0<<INT2);
    MCUCR=(1<<ISC11) | (1<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR=(0<<ISC2);
    GIFR=(1<<INTF1) | (0<<INTF0) | (0<<INTF2);
}

//******************************************
void Config_INT1_FallingEdge(void){
    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: On
    // INT1 Mode: Falling Edge
    // INT2: Off
    GICR|=(1<<INT1) | (0<<INT0) | (0<<INT2);
    MCUCR=(1<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR=(0<<ISC2);
    GIFR=(1<<INTF1) | (0<<INTF0) | (0<<INTF2);
}

//******************************************
// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void){
    int_status=!int_status;
    
    encoder_status=(encoder_status|(PIND&0b00000100)) >> 1; 
    if(int_status==0){
        Config_INT1_FallingEdge();
    } 
    else{
        if(encoder_status==0b00000001){encoder_value=encoder_value+1;}
            else if(encoder_status==0b00000010){encoder_value=encoder_value-1;} 
        encoder_status=0;
        Config_INT1_RisingEdge();
    }  
}

void Config_LCD(void);
void Display_encoder_value(void);

void main(void){
    int encoder_value_old=0;
    
    #asm("sei") // Global enable interrupts

    Config_LCD();
    Display_encoder_value();
    Config_INT1_RisingEdge();

    while (1){ 
        if(encoder_value!=encoder_value_old){
            Display_encoder_value();
            encoder_value_old=encoder_value;   
        }
    }
}

//*************************************
void Display_encoder_value(void){
    char txt[16];
    itoa(encoder_value,txt); lcd_gotoxy(0,0); lcd_putsf("Value:"); lcd_puts(txt); lcd_putsf("    ");
    lcd_gotoxy(0,1); lcd_putsf("Encoder Driver");   
}

//*************************************
void Config_LCD(void){
    lcd_init(16); lcd_clear();   
}
