// GitHub Account:     GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

#define SETBIT(ADDRESS,BIT)  (ADDRESS|=1<<BIT)
#define CLRBIT(ADDRESS,BIT)  (ADDRESS &=~(1<<BIT))
#define TOGGLEBIT(ADDRESS,BIT) (ADDRESS^=(1<<BIT))
#define EQUBIT(ADDRESS,BIT,value) {if (value) SETBIT(ADDRESS,BIT); else CLRBIT(ADDRESS,BIT);}
#define CHKBIT(ADDRESS,BIT)  ((ADDRESS &(1<<BIT))>>BIT)

char value;

void main(void){  
    SETBIT(DDRA,0); //PORTA.0 is output
    SETBIT(PORTA,0); delay_ms(500); CLRBIT(PORTA,0); delay_ms(500);
    
    SETBIT(DDRA,1);
    EQUBIT(PORTA,1,1);  delay_ms(500); EQUBIT(PORTA,1,0);  delay_ms(500);
    
    SETBIT(DDRB,0);
    value=0b00000001; EQUBIT(PORTB,0,CHKBIT(value,0)); delay_ms(500);
    value=0b00000000; EQUBIT(PORTB,0,CHKBIT(value,0)); delay_ms(500);
    
    while(1){
    };
}




