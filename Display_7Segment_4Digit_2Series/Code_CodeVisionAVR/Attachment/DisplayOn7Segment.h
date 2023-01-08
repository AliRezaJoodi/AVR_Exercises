// GitHub Account:     GitHub.com/AliRezaJoodi

#ifndef D1_0_DDR
    #define D1_0_DDR DDRB.3
    #define D1_0_PORT PORTB.3
    #define D1_0_PIN PINB.3
#endif
#define D1_0 D1_0_PORT

#ifndef D1_1_DDR
    #define D1_1_DDR DDRB.2
    #define D1_1_PORT PORTB.2
    #define D1_1_PIN PINB.2
#endif
#define D1_1 D1_1_PORT

#ifndef D1_2_DDR
    #define D1_2_DDR DDRB.1
    #define D1_2_PORT PORTB.1
    #define D1_2_PIN PINB.1
#endif
#define D1_2 D1_2_PORT

#ifndef D1_3_DDR
    #define D1_3_DDR DDRB.0
    #define D1_3_PORT PORTB.0
    #define D1_3_PIN PINB.0
#endif
#define D1_3 D1_3_PORT

#ifndef D2_0_DDR
    #define D2_0_DDR DDRB.7
    #define D2_0_PORT PORTB.7
    #define D2_0_PIN PINB.7
#endif
#define D2_0 D2_0_PORT

#ifndef D2_1_DDR
    #define D2_1_DDR DDRB.6
    #define D2_1_PORT PORTB.6
    #define D2_1_PIN PINB.6
#endif
#define D2_1 D2_1_PORT

#ifndef D2_2_DDR
    #define D2_2_DDR DDRB.5
    #define D2_2_PORT PORTB.5
    #define D2_2_PIN PINB.5
#endif
#define D2_2 D2_2_PORT

#ifndef D2_3_DDR
    #define D2_3_DDR DDRB.4
    #define D2_3_PORT PORTB.4
    #define D2_3_PIN PINB.4
#endif
#define D2_3 D2_3_PORT

#ifndef ACTIVATE_SEGMENT
    #define ACTIVATE_SEGMENT 1 
#endif 
#define DEACTIVATE_SEGMENT !ACTIVATE_SEGMENT
#define DEFAULT_SEGMENT DEACTIVATE_SEGMENT

#ifndef A_DDR
    #define A_DDR DDRD.0
    #define A_PORT PORTD.0
    #define A_PIN PIND.0
#endif 
#define S_A A_PORT

#ifndef B_DDR
    #define B_DDR DDRD.1
    #define B_PORT PORTD.1
    #define B_PIN PIND.1
#endif 
#define S_B B_PORT

#ifndef C_DDR
    #define C_DDR DDRD.2
    #define C_PORT PORTD.2
    #define C_PIN PIND.2
#endif 
#define S_C C_PORT

#ifndef D_DDR
    #define D_DDR DDRD.3
    #define D_PORT PORTD.3
    #define D_PIN PIND.3
#endif 
#define S_D D_PORT

#ifndef E_DDR
    #define E_DDR DDRD.4
    #define E_PORT PORTD.4
    #define E_PIN PIND.4
#endif 
#define S_E E_PORT

#ifndef F_DDR
    #define F_DDR DDRD.5
    #define F_PORT PORTD.5
    #define F_PIN PIND.5
#endif 
#define S_F F_PORT

#ifndef G_DDR
    #define G_DDR DDRD.6
    #define G_PORT PORTD.6
    #define G_PIN PIND.6
#endif 
#define S_G G_PORT

#ifndef DP_DDR
    #define DP_DDR DDRD.7
    #define DP_PORT PORTD.7
    #define DP_PIN PIND.7
#endif 
#define S_DP DP_PORT

#ifndef ACTIVATE_DIGIT
    #define ACTIVATE_DIGIT 0 
#endif 
#define DEACTIVATE_DIGIT !ACTIVATE_DIGIT
#define DEFAULT_DIGIT DEACTIVATE_DIGIT

//**************************************
void _Config_7Segment(void){
    #define OUTPUT 1
    static char status = 0;  
    
    if(status==0){
        D1_0_DDR=OUTPUT; D1_0_PORT=DEACTIVATE_SEGMENT;
        D1_1_DDR=OUTPUT; D1_1_PORT=DEACTIVATE_SEGMENT;
        D1_2_DDR=OUTPUT; D1_2_PORT=DEACTIVATE_SEGMENT;
        D1_3_DDR=OUTPUT; D1_3_PORT=DEACTIVATE_SEGMENT; 
        D2_0_DDR=OUTPUT; D2_0_PORT=DEACTIVATE_SEGMENT;
        D2_1_DDR=OUTPUT; D2_1_PORT=DEACTIVATE_SEGMENT;
        D2_2_DDR=OUTPUT; D2_2_PORT=DEACTIVATE_SEGMENT;
        D2_3_DDR=OUTPUT; D2_3_PORT=DEACTIVATE_SEGMENT;
    
        A_DDR=OUTPUT; A_PORT=DEACTIVATE_SEGMENT;
        B_DDR=OUTPUT; B_PORT=DEACTIVATE_SEGMENT;
        C_DDR=OUTPUT; C_PORT=DEACTIVATE_SEGMENT;
        D_DDR=OUTPUT; D_PORT=DEACTIVATE_SEGMENT; 
        E_DDR=OUTPUT; E_PORT=DEACTIVATE_SEGMENT;
        F_DDR=OUTPUT; F_PORT=DEACTIVATE_SEGMENT;
        G_DDR=OUTPUT; G_PORT=DEACTIVATE_SEGMENT;
        DP_DDR=OUTPUT; DP_PORT=DEACTIVATE_SEGMENT;
    }
    status=1;
}

//**************************************
void _Deactivate_7Segments(void){
    D1_0=DEACTIVATE_SEGMENT; 
    D1_1=DEACTIVATE_SEGMENT; 
    D1_2=DEACTIVATE_SEGMENT; 
    D1_3=DEACTIVATE_SEGMENT; 
    D2_0=DEACTIVATE_SEGMENT; 
    D2_1=DEACTIVATE_SEGMENT; 
    D2_2=DEACTIVATE_SEGMENT; 
    D2_3=DEACTIVATE_SEGMENT;
    
    S_A=DEACTIVATE_DIGIT; 
    S_B=DEACTIVATE_DIGIT; 
    S_C=DEACTIVATE_DIGIT; 
    S_D=DEACTIVATE_DIGIT; 
    S_E=DEACTIVATE_DIGIT; 
    S_F=DEACTIVATE_DIGIT; 
    S_G=DEACTIVATE_DIGIT; 
    S_DP=DEACTIVATE_DIGIT;  
}

//**************************************
unsigned char _Convert_Data(unsigned char digit){
    unsigned char out=0;
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    //A , B , C , D , E , F,
    // - , Dp
    unsigned char data_7segment[18]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000 , 0b10000000}; 
    
    out=data_7segment[digit]; 
    return out; 
}

//**************************************
unsigned char _Reverse_Data(unsigned char x){
    return x ^ 0b11111111; 
}

//**************************************
void _Drive_Data(unsigned char digit){
    #ifndef CHKBIT(ADDRESS,BIT)
        #define CHKBIT(ADDRESS,BIT)  ((ADDRESS &(1<<BIT))>>BIT) 
    #endif 
    
    S_A = CHKBIT(digit,0);
    S_B = CHKBIT(digit,1);
    S_C = CHKBIT(digit,2);
    S_D = CHKBIT(digit,3);
    S_E = CHKBIT(digit,4);
    S_F = CHKBIT(digit,5);
    S_G = CHKBIT(digit,6);
    S_DP = CHKBIT(digit,7);       
}

//**************************************
void DisplayOn7Segment_D1_Int(unsigned int value){
    unsigned int value_temporary=0;
    unsigned char digit=0;
    static unsigned char i = 0; 
    
    _Config_7Segment();
    _Deactivate_7Segments();
    
    switch(i){ 
        case 0:
            value_temporary=value/1;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_0=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 1:
            value_temporary=value/10;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_1=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 2:
            value_temporary=value/100;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_2=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 3:
            value_temporary=value/1000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_3=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
    }
}

//**************************************
void DisplayOn7Segment_D2_Int(unsigned int value){
    unsigned int value_temporary=0;
    unsigned char digit=0;
    static unsigned char i = 0; 
    
    _Config_7Segment();
    _Deactivate_7Segments();
    
    switch(i){ 
        case 0:
            value_temporary=value/1;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_0=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 1:
            value_temporary=value/10;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_1=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 2:
            value_temporary=value/100;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_2=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 3:
            value_temporary=value/1000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_3=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
    }
}

//**************************************
void DisplayOn7Segment_D1_Float(float value){
    unsigned int value_temporary=0;
    unsigned char digit=0;
    static unsigned char i = 0; 
    unsigned char dp=2;
    
    _Config_7Segment();
    _Deactivate_7Segments();
    
    if (value<100){value=value*100; dp=2;}
        else if (value<1000) {value=value*10; dp=1;}
            else if (value<10000) {value=value*1; dp=0;}
    
    switch(i){ 
        case 0:
            value_temporary=value/1;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_0=ACTIVATE_SEGMENT; 
            i++; //if(value_temporary<10){i=0;}
            break;
        case 1:
            value_temporary=value/10;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if (dp==1){digit=digit | 0b10000000;}
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_1=ACTIVATE_SEGMENT; 
            i++; //if(value_temporary<10){i=0;}
            break;
        case 2:
            value_temporary=value/100;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if (dp==2){digit=digit | 0b10000000;} 
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_2=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 3:
            value_temporary=value/1000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D1_3=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
    }
}

//**************************************
void DisplayOn7Segment_D2_Float(float value){
    unsigned int value_temporary=0;
    unsigned char digit=0;
    static unsigned char i = 0; 
    unsigned char dp=2;
    
    _Config_7Segment();
    _Deactivate_7Segments();
    
    if (value<100){value=value*100; dp=2;}
        else if (value<1000) {value=value*10; dp=1;}
            else if (value<10000) {value=value*1; dp=0;}
    
    switch(i){ 
        case 0:
            value_temporary=value/1;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_0=ACTIVATE_SEGMENT; 
            i++; //if(value_temporary<10){i=0;}
            break;
        case 1:
            value_temporary=value/10;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if (dp==1){digit=digit | 0b10000000;}
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_1=ACTIVATE_SEGMENT; 
            i++; //if(value_temporary<10){i=0;}
            break;
        case 2:
            value_temporary=value/100;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if (dp==2){digit=digit | 0b10000000;} 
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_2=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 3:
            value_temporary=value/1000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            D2_3=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
    }
}





