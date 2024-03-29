// GitHub Account: GitHub.com/AliRezaJoodi
// A local library

#ifndef _INCLUDED_EEPROM
    #define _INCLUDED_EEPROM
    
    //define DISABLE_EEPROM
    #ifndef DISABLE_EEPROM
        #define ENABLE_EEPROM
    #endif

#pragma used+

eeprom char validator_eeprom=0;
eeprom char i_eeprom; 

//******************************
void SaveDefaultValuesInEEPROM(void){
    #ifdef ENABLE_EEPROM 
        validator_eeprom=1; delay_ms(10);
        i_eeprom=100; delay_ms(10);
    #endif
}

//******************************
void LoadValuesFromEEPROM(void){
    #ifdef ENABLE_EEPROM
        i=i_eeprom; 
    #endif
}

//******************************
void SaveNewChangesInEEPROM(void){
    #ifdef ENABLE_EEPROM
        if(i!=i_eeprom){i_eeprom=i; delay_ms(10);}
    #endif    
}

//******************************
void ValidateEEPROM(void){
    #ifdef ENABLE_EEPROM
        if(validator_eeprom!=1){SaveDefaultValuesInEEPROM();}
    #endif  
} 

#pragma used-
#endif                                