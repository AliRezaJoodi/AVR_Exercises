// GitHub Account: GitHub.com/AliRezaJoodi

#ifdef _TWI_INCLUDED_
    #include <ds1307_twi.h>     
#else
    #include <ds1307.h>    
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
    struct time{ 
        unsigned char year;
        unsigned char month;
        unsigned char week;
        unsigned char day;
        unsigned char hour;
        unsigned char minute;
        unsigned char second;
    };
    struct time gregorian,jalaali;
    #pragma used-

//*********************************************
void ConfigDS1307(void){ 
    #ifdef ENABLE_DS1307
        rtc_init(_RS_1HZ,_SQWE_ENABLE,_OUT_HIGH); 
    #endif
}
        
#pragma used+

//*********************************************
void GetTimeAndDateFromRTC(void){
    #ifdef ENABLE_DS1307
        rtc_get_time(&gregorian.hour,&gregorian.minute,&gregorian.second);
        rtc_get_date(&gregorian.week,&gregorian.day,&gregorian.month,&gregorian.year); 
    #endif
}

//*********************************************
void GetTimeFromRTC(void){
    #ifdef ENABLE_DS1307
        rtc_get_time(&gregorian.hour,&gregorian.minute,&gregorian.second);
    #endif
}

//*********************************************
void GetDateFromRTC(void){
    #ifdef ENABLE_DS1307
        rtc_get_date(&gregorian.week,&gregorian.day,&gregorian.month,&gregorian.year);
    #endif
}

#pragma used-
#endif
