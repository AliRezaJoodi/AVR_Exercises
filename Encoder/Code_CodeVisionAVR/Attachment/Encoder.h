// GitHub Account:     GitHub.com/AliRezaJoodi

#ifndef TOGGLEBIT
    #define TOGGLEBIT(ADDRESS,BIT) (ADDRESS^=(1<<BIT)) 
#endif

#ifndef ENCODER
    #define ENCODER_DDR DDRD.2
    #define ENCODER_PORT PORTD.2
    #define ENCODER_PIN PIND.2
    #define ENCODER ENCODER_PIN
#endif

int encoder_value=0;

//******************************************
void Config_INT1(void){
    // External Interrupt(s) initialization
    // INT0: Off
    // INT1: On
    // INT2: Off
    GICR|=(1<<INT1) | (0<<INT0) | (0<<INT2);
    MCUCR=(1<<ISC11) | (1<<ISC10) | (0<<ISC01) | (0<<ISC00);    // INT1 Mode: Rising Edge 
    //MCUCR=(1<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);    // INT1 Mode: Falling Edge
    MCUCSR=(0<<ISC2);
    GIFR=(1<<INTF1) | (0<<INTF0) | (0<<INTF2);
}

//******************************************
void Config_Encoder(void){
    ENCODER_DDR=0; ENCODER_PORT=1;
    Config_INT1();
    #asm("sei") // Global enable interrupts
}

//******************************************
// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void){ 
    static bit int_status=0;
    static char encoder_status=0;

    encoder_status=encoder_status|ENCODER;

    if(int_status==0){TOGGLEBIT(MCUCR,2);} 
    else{
        if(encoder_status==0b01){encoder_value=encoder_value+1;}
            else if(encoder_status==0b10){encoder_value=encoder_value-1;} 
        encoder_status=0b00;
        TOGGLEBIT(MCUCR,2);
    } 
    
    encoder_status=encoder_status<<1;
    int_status=!int_status; 
}