// GitHub Account:  GitHub.com/AliRezaJoodi

#include <mega32.h>
#include <delay.h>

void test_1(void);
void test_2(void);

void main(void){
    // Port B initialization
    // Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
    // State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
    PORTB=0x00;
    DDRB=0xFF;
    
    test_1();
    test_2();
    
    while(1){
    }; 
}

//******************************
void test_2(void){
    int t=150;
    unsigned char data;
    
    data=0B00000001;
    while(data!=0B00000000){
        PORTB= data ; delay_ms(t);
        data=data<<1;
    }; 
            
    data = 0B10000000; 
    while(data!=0B00000000){
        PORTB= data ; delay_ms(t);
        data=data>>1;
    };    
}

//******************************
void test_1(void){
    PORTB=255; delay_ms(500);
    PORTB=0; delay_ms(500); 
    PORTB=0B00001111; delay_ms(500); 
    PORTB=0XF0; delay_ms(500); 
}


