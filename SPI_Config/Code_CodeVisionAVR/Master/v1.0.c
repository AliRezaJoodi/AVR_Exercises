#include <mega32a.h>
#include <delay.h>
#include <spi.h>

void Config_SPI(void);

void main(void){
    unsigned char i=0;
    Config_SPI();

    while (1){
        spi(i);
        delay_ms(1000);
        i++;
    }
}

//*******************************************
void Config_SPI(void){
    DDRB.7=1; PORTB.0=0; 
    DDRB.5=1; PORTB.5=0; 
    DDRB.4=1; PORTB.4=0;
    
    // SPI initialization
    // SPI Type: Master
    // SPI Clock Rate: 250.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);    
}
