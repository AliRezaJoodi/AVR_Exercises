#include <mega128a.h>
//#include <delay.h>
    
#define SETBIT(ADDRESS,BIT)  (ADDRESS|=1<<BIT)
#define CLRBIT(ADDRESS,BIT)  (ADDRESS &=~(1<<BIT))
#define CHKBIT(ADDRESS,BIT)  ((ADDRESS &(1<<BIT))>>BIT)
#define EQUBIT(ADDRESS,BIT,value) {if (value) SETBIT(ADDRESS,BIT); else CLRBIT(ADDRESS,BIT);}

void main(void){ 
    char value=0b00000000; 
    
    //DDRG.0=0; PORTG.0=1; 
    CLRBIT(DDRG,0); SETBIT(PORTG,0);    
    //DDRG.1=1; //PORTG.1=0;
    SETBIT(DDRG,1); CLRBIT(PORTG,1);
    
    CLRBIT(SFIOR,PUD);
    DDRF=0b11111111; PORTF=0b00000000; 
    value=0b00110011; PORTF=value;
    
    while(1){
        EQUBIT(PORTG,1,!CHKBIT(PING,0));
    }
}
