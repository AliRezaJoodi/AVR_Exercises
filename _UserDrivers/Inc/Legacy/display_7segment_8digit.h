// GitHub Account: GitHub.com/AliRezaJoodi

#include <utility.h>
    
#ifndef _7SEGMENT_INCLOUDED
    #define _7SEGMENT_INCLOUDED

#ifndef SEGMENT_HARDWARE
    #define SEGMENT_HARDWARE 
    
    #define DISPLAYLAG          5 //Display Lag
    #define ACTIVATE_DIGIT      1
    #define ACTIVATE_SEGMENT    0
      
    #define DIGIT0_DDR          DDRB.0
    #define DIGIT0_PORT         PORTB.0
    #define DIGIT0_PIN          PINB.0
    #define DIGIT0              DIGIT0_PORT
    
    #define DIGIT1_DDR          DDRB.1
    #define DIGIT1_PORT         PORTB.1
    #define DIGIT1_PIN          PINB.1
    #define DIGIT1              DIGIT1_PORT
    
    #define DIGIT2_DDR          DDRB.2
    #define DIGIT2_PORT         PORTB.2
    #define DIGIT2_PIN          PINB.2
    #define DIGIT2              DIGIT2_PORT
    
    #define DIGIT3_DDR          DDRB.3
    #define DIGIT3_PORT         PORTB.3
    #define DIGIT3_PIN          PINB.3
    #define DIGIT3              DIGIT3_PORT
    
    #define DIGIT4_DDR          DDRB.4
    #define DIGIT4_PORT         PORTB.4
    #define DIGIT4_PIN          PINB.4
    #define DIGIT4              DIGIT4_PORT
    
    #define DIGIT5_DDR          DDRB.5
    #define DIGIT5_PORT         PORTB.5
    #define DIGIT5_PIN          PINB.5
    #define DIGIT5              DIGIT5_PORT
    
    #define DIGIT6_DDR          DDRB.6
    #define DIGIT6_PORT         PORTB.6
    #define DIGIT6_PIN          PINB.6
    #define DIGIT6              DIGIT6_PORT
    
    #define DIGIT7_DDR          DDRB.7
    #define DIGIT7_PORT         PORTB.7
    #define DIGIT7_PIN          PINB.7
    #define DIGIT7              DIGIT7_PORT
    
    #define A_DDR               DDRD.0
    #define A_PORT              PORTD.0
    #define A_PIN               PIND.0
    #define A_SEGMENT           A_PORT
    
    #define B_DDR               DDRD.1
    #define B_PORT              PORTD.1
    #define B_PIN               PIND.1
    #define B_SEGMENT           B_PORT
    
    #define C_DDR               DDRD.2
    #define C_PORT              PORTD.2
    #define C_PIN               PIND.2
    #define C_SEGMENT           C_PORT
    
    #define D_DDR               DDRD.3
    #define D_PORT              PORTD.3
    #define D_PIN               PIND.3
    #define D_SEGMENT           D_PORT
    
    #define E_DDR               DDRD.4
    #define E_PORT              PORTD.4
    #define E_PIN               PIND.4
    #define E_SEGMENT           E_PORT
    
    #define F_DDR               DDRD.5
    #define F_PORT              PORTD.5
    #define F_PIN               PIND.5
    #define F_SEGMENT           F_PORT
    
    #define G_DDR               DDRD.6
    #define G_PORT              PORTD.6
    #define G_PIN               PIND.6
    #define G_SEGMENT           G_PORT
    
    #define DP_DDR              DDRD.7
    #define DP_PORT             PORTD.7
    #define DP_PIN              PIND.7
    #define DP_SEGMENT          DP_PORT
#endif

//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//A , B , C , D , E , F,
// - , Dp
 unsigned char table_7segment[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000,
 }; 
    
#define _Convert_Data(VALUE)                (table_7segment[VALUE])

#define _TurnOffDigits \
    DIGIT0=!ACTIVATE_DIGIT;\
    DIGIT1=!ACTIVATE_DIGIT;\
    DIGIT2=!ACTIVATE_DIGIT;\
    DIGIT3=!ACTIVATE_DIGIT;\
    DIGIT4=!ACTIVATE_DIGIT;\
    DIGIT5=!ACTIVATE_DIGIT;\
    DIGIT6=!ACTIVATE_DIGIT;\
    DIGIT7=!ACTIVATE_DIGIT; 
 
#define _DriveDataOn7Segment(data) \
    A_SEGMENT = GetBit(data,0);\
    B_SEGMENT = GetBit(data,1);\
    C_SEGMENT = GetBit(data,2);\
    D_SEGMENT = GetBit(data,3);\
    E_SEGMENT = GetBit(data,4);\
    F_SEGMENT = GetBit(data,5);\
    G_SEGMENT = GetBit(data,6);\
    DP_SEGMENT = GetBit(data,7);

//**************************************
void Configure7Segment(void){    
    DIGIT0_DDR=1; DIGIT0_PORT=!ACTIVATE_DIGIT;
    DIGIT1_DDR=1; DIGIT1_PORT=!ACTIVATE_DIGIT;
    DIGIT2_DDR=1; DIGIT2_PORT=!ACTIVATE_DIGIT;
    DIGIT3_DDR=1; DIGIT3_PORT=!ACTIVATE_DIGIT; 
    DIGIT4_DDR=1; DIGIT4_PORT=!ACTIVATE_DIGIT;
    DIGIT5_DDR=1; DIGIT5_PORT=!ACTIVATE_DIGIT;
    DIGIT6_DDR=1; DIGIT6_PORT=!ACTIVATE_DIGIT;
    DIGIT7_DDR=1; DIGIT7_PORT=!ACTIVATE_DIGIT;
    
    A_DDR=1; A_PORT=!ACTIVATE_SEGMENT;
    B_DDR=1; B_PORT=!ACTIVATE_SEGMENT;
    C_DDR=1; C_PORT=!ACTIVATE_SEGMENT;
    D_DDR=1; D_PORT=!ACTIVATE_SEGMENT; 
    E_DDR=1; E_PORT=!ACTIVATE_SEGMENT;
    F_DDR=1; F_PORT=!ACTIVATE_SEGMENT;
    G_DDR=1; G_PORT=!ACTIVATE_SEGMENT;
    DP_DDR=1; DP_PORT=!ACTIVATE_SEGMENT; 
}
    
//**************************************
void Display_7Segment(unsigned long int value){
    unsigned long int value_temporary=0;
    unsigned char digit=0;
    static unsigned char i = 0; 

    _TurnOffDigits; 
    
    switch(i){ 
        case 0:
            value_temporary=value/1;
            digit=value_temporary%10;
            digit=_Convert_Data(digit); 
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);} 
            _DriveDataOn7Segment(digit);
            DIGIT0=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 1:
            value_temporary=value/10;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);}
            _DriveDataOn7Segment(digit);
            DIGIT1=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 2:
            value_temporary=value/100;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);}
            _DriveDataOn7Segment(digit);
            DIGIT2=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 3:
            value_temporary=value/1000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);}
            _DriveDataOn7Segment(digit);
            DIGIT3=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 4:
            value_temporary=value/10000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);}
            _DriveDataOn7Segment(digit);
            DIGIT4=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 5:
            value_temporary=value/100000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);}
            _DriveDataOn7Segment(digit);
            DIGIT5=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 6:
            value_temporary=value/1000000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);}
            _DriveDataOn7Segment(digit);
            DIGIT6=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 7:
            value_temporary=value/10000000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_SEGMENT==0){digit=ToggleByte(digit);}
            _DriveDataOn7Segment(digit);
            DIGIT7=ACTIVATE_DIGIT; 
            i++; if(value_temporary<10){i=0;}
            i=0; 
            break;
    }
}

#endif



