#include <mega32a.h>
#include <spi.h>

void Config_IO(void);
void Config_SPI(void);

void main(void){
    Config_IO();
    Config_SPI();

    while(1){ 
        PORTD=spi(0);
    }
}

//*******************************************
void Config_IO(void){
    DDRD=0b11111111; PORTD=0b00000000;
}

//*******************************************
void Config_SPI(void){
    DDRB.6=1; PORTB.6=0; 
    
    // SPI initialization
    // SPI Type: Slave
    // SPI Clock Rate: 250.000 kHz
    // SPI Clock Phase: Cycle Start
    // SPI Clock Polarity: Low
    // SPI Data Order: MSB First
    SPCR=(1<<SPIE) | (1<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
    SPSR=(0<<SPI2X);
}
