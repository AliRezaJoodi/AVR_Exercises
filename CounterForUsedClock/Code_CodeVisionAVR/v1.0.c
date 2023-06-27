// GitHub Account: GitHub.com/AliRezaJoodi

#include <mega32a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

#define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#define TOGGLEBIT(ADDRESS,BIT)      (ADDRESS^=(1<<BIT))
#define EQUBIT(ADDRESS,BIT,value)   {if (value) SETBIT(ADDRESS,BIT); else CLRBIT(ADDRESS,BIT);}
#define CHKBIT(ADDRESS,BIT)         ((ADDRESS &(1<<BIT))>>BIT)

#define INTERRUPTS_ENABLE           #asm("sei")
#define INTERRUPTS_DISABLE          #asm("cli")
#define TIMER1_CLOCK_STOP           TCCR1B&=~0b00000111;
#define TIMER1_CLOCK_P1             TIMER1_CLOCK_STOP; TCCR1B|=0b00000001;
#define TIMER1_CLOCK_P8             TIMER1_CLOCK_STOP; TCCR1B|=0b00000010;
#define TIMER1_CLOCK_P64            TIMER1_CLOCK_STOP; TCCR1B|=0b00000011;
#define TIMER1_CLOCK_P256           TIMER1_CLOCK_STOP; TCCR1B|=0b00000100;
#define TIMER1_INTERRUPT_ENABLE     TIMSK|=0b00000100;
#define TIMER1_INTERRUPT_DISABLE    TIMSK&=~0b00000100;
#define TIMER1_RESET                TCNT1H=0x00; TCNT1L=0x00;  

unsigned int i2=0; 
#define VALUES_RESET                i2=0;

void ConfigUSART(void);
void DisplayValues(unsigned int);
void ConfigTimer1(void);
void EnableTimer1(void);
void DisableTimer1(void);
void TestFunction1(void);
void TestFunction2(void);

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void){
    ++i2;
}
    
void main(void){    	
    ConfigUSART(); putsf("Clock Used In The Functions\r");  

    INTERRUPTS_ENABLE;    
    ConfigTimer1();
    
    TIMER1_RESET; TIMER1_CLOCK_P1; TIMER1_INTERRUPT_ENABLE;
    TestFunction1();
    TIMER1_CLOCK_STOP; TIMER1_INTERRUPT_DISABLE;
    putsf("\rFunction1="); DisplayValues(TCNT1); 
    
    TIMER1_RESET; TIMER1_CLOCK_P1; TIMER1_INTERRUPT_ENABLE;
    TestFunction2();
    TIMER1_CLOCK_STOP; TIMER1_INTERRUPT_DISABLE;
    putsf("\rFunction2="); DisplayValues(TCNT1);
    	
    while(1){ 
    }
}

//********************************************************
void TestFunction2(void){
    unsigned char data=3;
    DDRA=0b11111111;
    PORTA.0 = data & 0b00000000;
    PORTA.1 = data & 0b00000010;
    PORTA.2 = data & 0b00000100;
    PORTA.3 = data & 0b00001000;
    PORTA.4 = data & 0b00010000;
    PORTA.5 = data & 0b00100000;
    PORTA.6 = data & 0b01000000;
    PORTA.7 = data & 0b10000000;   
}

//********************************************************
void TestFunction1(void){
    unsigned char data=3;
    DDRA=0b11111111;
    PORTA.0 = CHKBIT(data,0);
    PORTA.1 = CHKBIT(data,1);
    PORTA.2 = CHKBIT(data,2);
    PORTA.3 = CHKBIT(data,3);
    PORTA.4 = CHKBIT(data,4);
    PORTA.5 = CHKBIT(data,5);
    PORTA.6 = CHKBIT(data,6);
    PORTA.7 = CHKBIT(data,7);   
}

//********************************************************
void ConfigTimer1(void){
// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 8.192 ms
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00; TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
}

//********************************************************
void EnableTimer1(void){
    TIMER1_CLOCK_P1;
    TIMER1_INTERRUPT_ENABLE;
}

//********************************************************
void DisableTimer1(void){
    TIMER1_CLOCK_STOP;
    TIMER1_INTERRUPT_DISABLE;
}

//********************************************************
void DisplayValues(unsigned int x){ 
    char txt[16];     
    //putsf("\rCount="); 
    itoa(x,txt); puts(txt);
    //putsf("\ri2="); itoa(i2,txt); puts(txt); 
    //putsf("\r");
}

//********************************************************
void ConfigUSART(void){
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600
    UCSRA=0x00;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRH=0x00;
    UBRRL=0x33;
}