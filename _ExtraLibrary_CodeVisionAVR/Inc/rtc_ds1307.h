// GitHub Account: GitHub.com/AliRezaJoodi

#ifdef _TWI_INCLUDED_
    #include <ds1307_twi.h>     
#else
    #include <ds1307.h>    
#endif

#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif
    
#ifndef _INCLUDED_DS1307
    #define _INCLUDED_DS1307
    
    //#define DISABLE_DS1307
    #ifndef DISABLE_DS1307
        #define ENABLE_DS1307
    #endif

    #define _RS_1HZ             0b00
    #define _RS_4096HZ          0b01
    #define _RS_8192HZ          0b10
    #define _RS_32768HZ         0b11
    #define _SQWE_ENABLE        1
    #define _OUT_HIGH           1 

    #pragma used+
    struct ds1307{
        unsigned char year;  
        unsigned char month;
        unsigned char week;
        unsigned char day;
        unsigned char hour;
        unsigned char minute;
        unsigned char second;
    };
    struct ds1307 gregorian; 

//*********************************************
void ConfigDS1307(void){ 
    #ifdef ENABLE_DS1307
        rtc_init(_RS_1HZ,_SQWE_ENABLE,_OUT_HIGH);
    #endif
}

//*********************************************
void GetClockFromDS1307(void){
    #ifdef ENABLE_DS1307
        rtc_get_time(&gregorian.hour,&gregorian.minute,&gregorian.second); 
        gregorian.second=gregorian.second&0b01111111; 
        gregorian.hour=gregorian.hour&0b00111111;
    #endif
}

//*********************************************
void GetCalendarFromDS1307(void){
    #ifdef ENABLE_DS1307
        rtc_get_date(&gregorian.week,&gregorian.day,&gregorian.month,&gregorian.year);
    #endif
}

//*********************************************
void DisableSquareWaveOfDS1307(void){
    unsigned char buffer=0;
    buffer=rtc_read(7);
    rtc_write(7,CLRBIT(buffer,4));
}

//*********************************************
void EnableSquareWaveOfDS1307(void){
    unsigned char buffer=0;
    buffer=rtc_read(7);
    rtc_write(7,SETBIT(buffer,4));
}
    
//*********************************************
void DisableOscillatorOfDS1307(void){
    unsigned char buffer=0;
    buffer=rtc_read(0);
    //rtc_write(0,0b10000000|gregorian.second);  
    rtc_write(0,SETBIT(buffer,7));
}

//*********************************************
void EnableOscillatorOfDS1307(void){
    unsigned char buffer=0;
    buffer=rtc_read(0);  
    //rtc_write(0,0b01111111&gregorian.second); 
    rtc_write(0,CLRBIT(buffer,7));
}

//*********************************************
void SetHourFormatTo24(void){
    unsigned char buffer=0;
    buffer=rtc_read(2);  
    rtc_write(2,CLRBIT(buffer,6));
}

#pragma used-
#endif
