// GitHub Account:     GitHub.com/AliRezaJoodi

//#ifndef S1_DDR
//#endif

#define S1_DDR DDRB.0
#define S1_PORT PORTB.0
#define S1_PIN PINB.0
#define S1 S1_PORT

#define S2_DDR DDRB.1
#define S2_PORT PORTB.1
#define S2_PIN PINB.1
#define S2 S2_PORT

#define S3_DDR DDRB.2
#define S3_PORT PORTB.2
#define S3_PIN PINB.2
#define S3 S3_PORT

#define S4_DDR DDRB.3
#define S4_PORT PORTB.3
#define S4_PIN PINB.3
#define S4 S4_PORT

#define S5_DDR DDRB.4
#define S5_PORT PORTB.4
#define S5_PIN PINB.4
#define S5 S5_PORT

#define S6_DDR DDRB.5
#define S6_PORT PORTB.5
#define S6_PIN PINB.5
#define S6 S6_PORT

#define S7_DDR DDRB.6
#define S7_PORT PORTB.6
#define S7_PIN PINB.6
#define S7 S7_PORT

#define S8_DDR DDRB.7
#define S8_PORT PORTB.7
#define S8_PIN PINB.7
#define S8 S8_PORT

#define ACTIVATE_SEGMENT 1  
#define DEACTIVATE_SEGMENT !ACTIVATE_SEGMENT
#define DEFAULT_SEGMENT DEACTIVATE_SEGMENT

#define A_DDR DDRD.0
#define A_PORT PORTD.0
#define A_PIN PIND.0
#define S_A A_PORT

#define B_DDR DDRD.1
#define B_PORT PORTD.1
#define B_PIN PIND.1
#define S_B B_PORT

#define C_DDR DDRD.2
#define C_PORT PORTD.2
#define C_PIN PIND.2
#define S_C C_PORT

#define D_DDR DDRD.3
#define D_PORT PORTD.3
#define D_PIN PIND.3
#define S_D D_PORT

#define E_DDR DDRD.4
#define E_PORT PORTD.4
#define E_PIN PIND.4
#define S_E E_PORT

#define F_DDR DDRD.5
#define F_PORT PORTD.5
#define F_PIN PIND.5
#define S_F F_PORT

#define G_DDR DDRD.6
#define G_PORT PORTD.6
#define G_PIN PIND.6
#define S_G G_PORT

#define DP_DDR DDRD.7
#define DP_PORT PORTD.7
#define DP_PIN PIND.7
#define S_DP DP_PORT

#define ACTIVATE_DIGIT 0 
#define DEACTIVATE_DIGIT !ACTIVATE_DIGIT
#define DEFAULT_DIGIT DEACTIVATE_DIGIT

//**************************************
void Config_7Segment(void){
    #define OUTPUT 1
    
    S1_DDR=OUTPUT; S1_PORT=DEACTIVATE_SEGMENT;
    S2_DDR=OUTPUT; S2_PORT=DEACTIVATE_SEGMENT;
    S3_DDR=OUTPUT; S3_PORT=DEACTIVATE_SEGMENT;
    S4_DDR=OUTPUT; S4_PORT=DEACTIVATE_SEGMENT; 
    S5_DDR=OUTPUT; S5_PORT=DEACTIVATE_SEGMENT;
    S6_DDR=OUTPUT; S6_PORT=DEACTIVATE_SEGMENT;
    S7_DDR=OUTPUT; S7_PORT=DEACTIVATE_SEGMENT;
    S8_DDR=OUTPUT; S8_PORT=DEACTIVATE_SEGMENT;
    
    A_DDR=OUTPUT; A_PORT=DEACTIVATE_SEGMENT;
    B_DDR=OUTPUT; B_PORT=DEACTIVATE_SEGMENT;
    C_DDR=OUTPUT; C_PORT=DEACTIVATE_SEGMENT;
    D_DDR=OUTPUT; D_PORT=DEACTIVATE_SEGMENT; 
    E_DDR=OUTPUT; E_PORT=DEACTIVATE_SEGMENT;
    F_DDR=OUTPUT; F_PORT=DEACTIVATE_SEGMENT;
    G_DDR=OUTPUT; G_PORT=DEACTIVATE_SEGMENT;
    DP_DDR=OUTPUT; DP_PORT=DEACTIVATE_SEGMENT;
}

//**************************************
void _Deactivate_7Segments(void){
    S1=DEACTIVATE_SEGMENT; 
    S2=DEACTIVATE_SEGMENT; 
    S3=DEACTIVATE_SEGMENT; 
    S4=DEACTIVATE_SEGMENT; 
    S5=DEACTIVATE_SEGMENT; 
    S6=DEACTIVATE_SEGMENT; 
    S7=DEACTIVATE_SEGMENT; 
    S8=DEACTIVATE_SEGMENT;
    
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
void Display_7Segment(unsigned long int value){
    unsigned long int value_temporary=0;
    unsigned char digit=0;
    static unsigned char i = 0; 
    
    static char status = 0;
    if (status==0){Config_7Segment(); status=1;}
    
    _Deactivate_7Segments();
    switch(i){ 
        case 0:
            value_temporary=value/1;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S1=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 1:
            value_temporary=value/10;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S2=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 2:
            value_temporary=value/100;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S3=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            break;
        case 3:
            value_temporary=value/1000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S4=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 4:
            value_temporary=value/10000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S5=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 5:
            value_temporary=value/100000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S6=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 6:
            value_temporary=value/1000000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S7=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;} 
            break;
        case 7:
            value_temporary=value/10000000;
            digit=value_temporary%10;
            digit=_Convert_Data(digit);
            if(ACTIVATE_DIGIT==0){digit=_Reverse_Data(digit);}
            _Drive_Data(digit);
            S8=ACTIVATE_SEGMENT; 
            i++; if(value_temporary<10){i=0;}
            i=0; 
            break;
    }
}


