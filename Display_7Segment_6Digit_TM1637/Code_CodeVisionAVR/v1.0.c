// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
//#include <stdlib.h>
#include <stdint.h>

#include <tm1637.h>

void main(void){
    uint8_t ak2=0;
    uint8_t k=0;
     
    TM1637_Config();
    delay_ms(50);
   
//    TM1637_CLK_SetOutput(1);
//    TM1637_DIO_SetOutput(1);
    while(1){ 
    
    TM1637_Start();
    ak2=TM1637_WriteByte(TM1637_I2C_COMM1);
    TM1637_Stop();

    // Write COMM2 + first digit address
	TM1637_Start();
	ak2=TM1637_WriteByte(TM1637_I2C_COMM2);

	// Write the data bytes
	for (k=0; k < 4; k++){
	  ak2=TM1637_WriteByte(0b01001111); 
    }

	TM1637_Stop();

	// Write COMM3 + brightness
	TM1637_Start();
	ak2=TM1637_WriteByte(TM1637_I2C_COMM3 + (6 & 0x0f));
	TM1637_Stop();
                 
     delay_ms(500);
                                     
    };
}
