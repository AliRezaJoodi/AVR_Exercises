//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#define Buzzer PORTB.0

void Sound_Number(void);
void Sound_Menu(void);
void Sound_Error(void);



void main(void){        
    DDRB.0=1; PORTB.0=0; 
    
    Sound_Number(); delay_ms(500);
    Sound_Menu(); delay_ms(500);
    Sound_Error(); delay_ms(500);
        
    while(1){ 
    }
}

//*******************************************************
void Sound_Number(void){
    unsigned int i_sound;
    for (i_sound=1;i_sound<=400;++i_sound) {
        Buzzer=1; delay_us(200);
        Buzzer=0; delay_us(200);
    }; 
    Buzzer=0;   
}

//*******************************************************
void Sound_Menu(void){
    unsigned int i_sound;
    for (i_sound=1;i_sound<=70;++i_sound) {
        Buzzer=1; delay_us(600);
        Buzzer=0; delay_us(600);
    };
    Buzzer=0;    
}

//*******************************************************
void Sound_Error(void){
    unsigned int i_sound;
    for (i_sound=1;i_sound<=10;++i_sound) {
        Buzzer=1; delay_us(2500);
        Buzzer=0; delay_us(2500);
    };
    Buzzer=0;    
}


