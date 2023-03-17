// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef PORTS_7SEGMENTS
    #define PORTS_7SEGMENTS

    #define ACTIVATE_DIGIT      1 
    #define ACTIVATE_SEGMENT    0 
     
    #define D1_0_DDR            DDRB.3
    #define D1_0_PORT           PORTB.3
    #define D1_0_PIN            PINB.3
    #define D1_0                D1_0_PORT

    #define D1_1_DDR            DDRB.2
    #define D1_1_PORT           PORTB.2
    #define D1_1_PIN            PINB.2
    #define D1_1                D1_1_PORT

    #define D1_2_DDR            DDRB.1
    #define D1_2_PORT           PORTB.1
    #define D1_2_PIN            PINB.1
    #define D1_2                D1_2_PORT

    #define D1_3_DDR            DDRB.0
    #define D1_3_PORT           PORTB.0
    #define D1_3_PIN            PINB.0
    #define D1_3                D1_3_PORT

    #define D2_0_DDR            DDRB.7
    #define D2_0_PORT           PORTB.7
    #define D2_0_PIN            PINB.7
    #define D2_0                D2_0_PORT

    #define D2_1_DDR            DDRB.6
    #define D2_1_PORT           PORTB.6
    #define D2_1_PIN            PINB.6
    #define D2_1                D2_1_PORT

    #define D2_2_DDR            DDRB.5
    #define D2_2_PORT           PORTB.5
    #define D2_2_PIN            PINB.5
    #define D2_2                D2_2_PORT

    #define D2_3_DDR            DDRB.4
    #define D2_3_PORT           PORTB.4
    #define D2_3_PIN            PINB.4
    #define D2_3                D2_3_PORT

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

//**************************************
void Config_7Segment(void){
    #ifndef OUTPUT
        #define OUTPUT  1 
    #endif
        
    D1_0_DDR=OUTPUT; D1_0_PORT=!ACTIVATE_DIGIT;
    D1_1_DDR=OUTPUT; D1_1_PORT=!ACTIVATE_DIGIT;
    D1_2_DDR=OUTPUT; D1_2_PORT=!ACTIVATE_DIGIT;
    D1_3_DDR=OUTPUT; D1_3_PORT=!ACTIVATE_DIGIT; 
    D2_0_DDR=OUTPUT; D2_0_PORT=!ACTIVATE_DIGIT;
    D2_1_DDR=OUTPUT; D2_1_PORT=!ACTIVATE_DIGIT;
    D2_2_DDR=OUTPUT; D2_2_PORT=!ACTIVATE_DIGIT;
    D2_3_DDR=OUTPUT; D2_3_PORT=!ACTIVATE_DIGIT;
    
    A_DDR=OUTPUT; A_PORT=!ACTIVATE_SEGMENT;
    B_DDR=OUTPUT; B_PORT=!ACTIVATE_SEGMENT;
    C_DDR=OUTPUT; C_PORT=!ACTIVATE_SEGMENT;
    D_DDR=OUTPUT; D_PORT=!ACTIVATE_SEGMENT; 
    E_DDR=OUTPUT; E_PORT=!ACTIVATE_SEGMENT;
    F_DDR=OUTPUT; F_PORT=!ACTIVATE_SEGMENT;
    G_DDR=OUTPUT; G_PORT=!ACTIVATE_SEGMENT;
    DP_DDR=OUTPUT; DP_PORT=!ACTIVATE_SEGMENT;
}

#pragma used+

//**************************************
void _Off_7Segment(void){
    D1_0=!ACTIVATE_DIGIT; 
    D1_1=!ACTIVATE_DIGIT; 
    D1_2=!ACTIVATE_DIGIT; 
    D1_3=!ACTIVATE_DIGIT; 
    D2_0=!ACTIVATE_DIGIT; 
    D2_1=!ACTIVATE_DIGIT; 
    D2_2=!ACTIVATE_DIGIT; 
    D2_3=!ACTIVATE_DIGIT;
    
    A_SEGMENT=!ACTIVATE_SEGMENT; 
    B_SEGMENT=!ACTIVATE_SEGMENT; 
    C_SEGMENT=!ACTIVATE_SEGMENT; 
    D_SEGMENT=!ACTIVATE_SEGMENT; 
    E_SEGMENT=!ACTIVATE_SEGMENT; 
    F_SEGMENT=!ACTIVATE_SEGMENT; 
    G_SEGMENT=!ACTIVATE_SEGMENT; 
    DP_SEGMENT=!ACTIVATE_SEGMENT;  
}

//**************************************
unsigned char _DataReverser(unsigned char x){
    return x ^ 0b11111111; 
}

//**************************************
unsigned char _DataConverter(unsigned char digit){
    //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    //A , B , C , D , E , F,
    // - 
    unsigned char data_7segment[17]={
    0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111,
    0b01110111 , 0b01111100 , 0b00111001 , 0b01011110 , 0b01111001 , 0b01110001 ,
    0b01000000}; 
    
    digit=data_7segment[digit];
    
    return digit; 
}

//**************************************
void _DataDriver(unsigned char digit){
    #ifndef CHKBIT(ADDRESS,BIT)
        #define CHKBIT(ADDRESS,BIT)  ((ADDRESS &(1<<BIT))>>BIT) 
    #endif 
    
    A_SEGMENT = CHKBIT(digit,0);
    B_SEGMENT = CHKBIT(digit,1);
    C_SEGMENT = CHKBIT(digit,2);
    D_SEGMENT = CHKBIT(digit,3);
    E_SEGMENT = CHKBIT(digit,4);
    F_SEGMENT = CHKBIT(digit,5);
    G_SEGMENT = CHKBIT(digit,6);
    DP_SEGMENT = CHKBIT(digit,7);       
}

//**************************************
void Int_RightToLeft_Display1(unsigned int value){
    unsigned int value_int=0;
    unsigned char digit=0;
    static unsigned char i = 0; 
    
    _Off_7Segment();
    
    switch(i){ 
        case 0:
            value_int=value/1;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D1_0=ACTIVATE_DIGIT; 
            i++; if(value_int<10){i=0;}
            break;
        case 1:
            value_int=value/10;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D1_1=ACTIVATE_DIGIT; 
            i++; if(value_int<10){i=0;}
            break;
        case 2:
            value_int=value/100;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D1_2=ACTIVATE_DIGIT; 
            i++; if(value_int<10){i=0;}
            break;
        case 3:
            value_int=value/1000;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D1_3=ACTIVATE_DIGIT; 
            i++; if(value_int<10){i=0;} 
            break;
    }
}

//**************************************
void Int_LefToRight_Display1(unsigned int value){
    unsigned int value_int=0;
    unsigned char digit=0;
    static char i = 3;     
    static char status=0;
    
    _Off_7Segment();
    
    switch(i){
        case 3:
            value_int=value/1000;
            digit=value_int%10; 
            if(digit>0){status=1;}
            if(status){
                digit=_DataConverter(digit);
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
                _DataDriver(digit);
                D1_3=ACTIVATE_DIGIT;
                i--; break; 
            }
            i--; 
        case 2:
            value_int=value/100;
            digit=value_int%10;
            if(digit>0){status=1;} 
            if(status){
                digit=_DataConverter(digit);
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
                _DataDriver(digit);
                D1_2=ACTIVATE_DIGIT;
                i--; break;   
            }
            i--; 
        case 1:
            value_int=value/10;
            digit=value_int%10;
            if(digit>0){status=1;}  
            if(status){
                digit=_DataConverter(digit);
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
                _DataDriver(digit);
                D1_1=ACTIVATE_DIGIT;  
                i--; break;
            } 
            i--;
        case 0:
            value_int=value/1;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D1_0=ACTIVATE_DIGIT; 
            i--; if(value_int<10000){i=3; status=0;}   
            break;
    }
}

//**************************************
void Float_RightToLeft_Display2(float value){
    unsigned int value_int=0;
    unsigned char digit=0;
    unsigned char dp=0;
    static char i = 0; 
    
    _Off_7Segment();
    if(value<10){value=value*1000; dp=3;}
        else if(value<100){value=value*100; dp=2;}
            else if(value<1000){value=value*10; dp=1;}
                else if(value<10000){value=value*1; dp=0;}
    
    switch(i){ 
        case 0:
            value_int=value/1;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_0=ACTIVATE_DIGIT; 
            i++; 
            break;
        case 1:
            value_int=value/10;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(dp==1){digit=digit | 0b10000000;}
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_1=ACTIVATE_DIGIT; 
            i++; 
            break;
        case 2:
            value_int=value/100;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(dp==2){digit=digit | 0b10000000;} 
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_2=ACTIVATE_DIGIT; 
            i++;
            break;
        case 3:
            value_int=value/1000;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(dp==3){digit=digit | 0b10000000;}
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_3=ACTIVATE_DIGIT; 
            i++; if(value_int<10){i=0;} 
            break;
    }
}

//**************************************
void Float_LefToRight_Display2(float value){
    unsigned int value_int=0;
    unsigned char digit=0;
    unsigned char dp=0;
    static char i=3;     
    static char status=0;

    _Off_7Segment();
    if(value<10){value=value*1000; dp=3;}
        else if(value<100){value=value*100; dp=2;}
            else if(value<1000){value=value*10; dp=1;}
                else if(value<10000){value=value*1; dp=0;}
    
    switch(i){
        case 3:
            value_int=value/1000;
            digit=value_int%10; 
            digit=_DataConverter(digit);
            if(dp==3){digit=digit | 0b10000000;}
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_3=ACTIVATE_DIGIT;
            i--; 
            break; 
        case 2:
            value_int=value/100;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(dp==2){digit=digit | 0b10000000;} 
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_2=ACTIVATE_DIGIT;
            i--; 
            break;   
        case 1:
            value_int=value/10;
            digit=value_int%10; 
            digit=_DataConverter(digit);
            if(dp==1){digit=digit | 0b10000000;}
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_1=ACTIVATE_DIGIT;  
            i--; 
            break; 
        case 0:
            value_int=value/1;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}
            _DataDriver(digit);
            D2_0=ACTIVATE_DIGIT; 
            i--; if(value_int<10000){i=3; status=0;}   
            break;
    }
}

//**************************************
char Display1(float value, char decimal){
    unsigned int value_int=0;
    unsigned char digit=0;
    static char i=3;     
    static char status=0;
    
    if(value>=10000){i=3; return i;}
    
    if(value<10){if(decimal>3){decimal=3;}}
        else if(10<=value && value<100){if(decimal>2){decimal=2;}}
            else if(100<=value && value<1000){if(decimal>1){decimal=1;}}
                else if(1000<=value && value<10000){if(decimal>0){decimal=0;}}
        
    if(decimal==3){value=value*1000;}
        else if(decimal==2){value=value*100;}
            else if(decimal==1){value=value*10;}
                else if(decimal==0){value=value*1;} 

    value_int=value;  
    
    switch(i){
        case 3:
            value_int=value/1000;
            digit=value_int%10; 
            if(digit>0 || decimal==3){status=1;}
            if(status){
                digit=_DataConverter(digit); 
                if(decimal==3){digit=digit | 0b10000000;}
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);} 
                _Off_7Segment();
                _DataDriver(digit);
                D1_3=ACTIVATE_DIGIT;
                i--; break; 
            }
            i--; 
        case 2:
            value_int=value/100;
            digit=value_int%10;
            if(digit>0 || decimal==2){status=1;} 
            if(status){
                digit=_DataConverter(digit);
                if(decimal==2){digit=digit | 0b10000000;}
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);} 
                _Off_7Segment();
                _DataDriver(digit);
                D1_2=ACTIVATE_DIGIT;
                i--; break;   
            }
            i--; 
        case 1:
            value_int=value/10;
            digit=value_int%10;
            if(digit>0 || decimal==1){status=1;}  
            if(status){
                digit=_DataConverter(digit);  
                if(decimal==1){digit=digit | 0b10000000;}
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);} 
                _Off_7Segment();
                _DataDriver(digit);
                D1_1=ACTIVATE_DIGIT;  
                i--; break;
            } 
            i--;
        case 0:
            value_int=value/1;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}  
            _Off_7Segment();
            _DataDriver(digit);
            D1_0=ACTIVATE_DIGIT; 
            //i--; if(value_int<10000){i=3; status=0;}
            i=3; status=0;   
            break;
    } 
    
    return i;
}

//**************************************
char Display2(float value, char decimal){
    unsigned int value_int=0;
    unsigned char digit=0;
    static char i=3;     
    static char status=0;
    
    if(value>=10000){i=3; return i;}
    
    if(value<10){if(decimal>3){decimal=3;}}
        else if(10<=value && value<100){if(decimal>2){decimal=2;}}
            else if(100<=value && value<1000){if(decimal>1){decimal=1;}}
                else if(1000<=value && value<10000){if(decimal>0){decimal=0;}}
        
    if(decimal==3){value=value*1000;}
        else if(decimal==2){value=value*100;}
            else if(decimal==1){value=value*10;}
                else if(decimal==0){value=value*1;} 

    value_int=value;  
    
    switch(i){
        case 3:
            value_int=value/1000;
            digit=value_int%10; 
            if(digit>0 || decimal==3){status=1;}
            if(status){
                digit=_DataConverter(digit); 
                if(decimal==3){digit=digit | 0b10000000;}
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);} 
                _Off_7Segment();
                _DataDriver(digit);
                D2_3=ACTIVATE_DIGIT;
                i--; break; 
            }
            i--; 
        case 2:
            value_int=value/100;
            digit=value_int%10;
            if(digit>0 || decimal==2){status=1;} 
            if(status){
                digit=_DataConverter(digit);
                if(decimal==2){digit=digit | 0b10000000;}
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);} 
                _Off_7Segment();
                _DataDriver(digit);
                D2_2=ACTIVATE_DIGIT;
                i--; break;   
            }
            i--; 
        case 1:
            value_int=value/10;
            digit=value_int%10;
            if(digit>0 || decimal==1){status=1;}  
            if(status){
                digit=_DataConverter(digit);  
                if(decimal==1){digit=digit | 0b10000000;}
                if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);} 
                _Off_7Segment();
                _DataDriver(digit);
                D2_1=ACTIVATE_DIGIT;  
                i--; break;
            } 
            i--;
        case 0:
            value_int=value/1;
            digit=value_int%10;
            digit=_DataConverter(digit);
            if(ACTIVATE_SEGMENT==0){digit=_DataReverser(digit);}  
            _Off_7Segment();
            _DataDriver(digit);
            D2_0=ACTIVATE_DIGIT; 
            //i--; if(value_int<10000){i=3; status=0;}
            i=3; status=0;   
            break;
    } 
    
    return i;
}

//**********************************************
void DisplayAll(float value1, float value2){
    char refresh_display=0;
    static char i_display = 0;
    
    switch(i_display){ 
        case 0:
            refresh_display = Display1(value1, 3); if(refresh_display==3){++i_display;}  
            break;
        case 1: 
            refresh_display = Display2(value2, 3); if(refresh_display==3){i_display=0;} 
            break;
    }
}

#pragma used+





