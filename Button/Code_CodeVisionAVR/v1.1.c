//GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#define button1 PIND.0
#define button2 PIND.1
#define button3 PIND.2

#define Buzzer PORTB.0

void Sound_Menu(void);

bit old_status_button1=1;
bit old_status_button2=1;
bit old_status_button3=1;

void main(void){        
    DDRD.0=0; PORTD.0=1;
    DDRD.1=0; PORTD.1=1;
    DDRD.2=0; PORTD.2=1;
    DDRB.0=1; PORTB.0=0; 
        
    while(1){
        if(button1==0 && old_status_button1==1){
            old_status_button1=0;
            Sound_Menu();
        }
        if(button1==1){old_status_button1=1;} 
        
        if(button2==0 && old_status_button2==1){
            old_status_button2=0;
            Sound_Menu();
        }
        if(button2==1){old_status_button2=1;} 
        
        if(button3==0 && old_status_button3==1){
            old_status_button3=0;
            Sound_Menu();
        }
        if(button3==1){old_status_button3=1;}   
    }
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


