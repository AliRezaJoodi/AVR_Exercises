//GitHub Account: GitHub.com/AliRezaJoodi

#include<mega32.h>
#include<delay.h>

void main(void){
    char i;
    char flasher_data[]={
        0b00000001,
        0b00000100,
        0b00010000,
        0b01000000,
        0b10000001,
        0b01000010,
        0b00100100,
        0b00011000,
        0b00100100,
        0b01000010,
        0b10000001,
        0b10000000,
        0b00100000,
        0b00001000,
        0b00000010,
        0b00000000
    };

	DDRD = 0xFF; PORTD=0x00;
    
	while(1){
		for(i=0; i<16; ++i){
			PORTD = flasher_data[i]; delay_ms(200);
		}	
	}
}
