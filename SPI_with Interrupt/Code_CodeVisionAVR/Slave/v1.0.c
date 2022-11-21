#include <mega32a.h>
#include <spi.h>
#include <stdio.h>

// SPI interrupt service routine
interrupt [SPI_STC] void spi_isr(void){
    PORTD=SPDR;
}

void Config_IO(void);
void Config_SPI(void);

void main(void){
    Config_IO();
    Config_SPI();
    #asm("sei") // Global enable interrupts

    while(1){
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

    // Clear the SPI interrupt flag
    #asm
        in   r30,spsr
        in   r30,spdr
    #endasm
}
