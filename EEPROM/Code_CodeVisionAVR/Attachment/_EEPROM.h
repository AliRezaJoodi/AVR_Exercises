// GitHub Account: GitHub.com/AliRezaJoodi
// A local library

//define DISABLE_EEPROM
#ifndef DISABLE_EEPROM
    #define ENABLE_EEPROM
#endif

#pragma used+

eeprom char i_eeprom; 
eeprom char empty_eeprom;

//******************************
void SetDefaultValuesInEEPROM(void){
    #ifdef ENABLE_EEPROM
        i_eeprom=100; delay_ms(10);
        empty_eeprom=1; delay_ms(10);
    #endif
}

//******************************
void LoadValuesOfEEPROM(void){
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
        if(empty_eeprom!=1){SetDefaultValuesInEEPROM();} 
    #endif 
}

#pragma used-

