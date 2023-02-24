// GitHub Account:  GitHub.com/AliRezaJoodi
// A local library

eeprom char i_eeprom; 
eeprom char empty_eeprom;

#pragma used+

//******************************
void Default_EEPROM(void){
    i_eeprom=100; delay_ms(10);
    empty_eeprom=1; delay_ms(10);
}

//******************************
void Load_EEPROM(void){
    i=i_eeprom;
}

//******************************
void Save_EEPROM(void){
    i_eeprom=i; delay_ms(10);    
}

//******************************
void SaveChanges_EEPROM(void){
    if(i!=i_eeprom){i_eeprom=i; delay_ms(10);}    
}

//******************************
char CheckNewChange_EEPROM(char value){
    static char value_old=0;
    if(value!=value_old){value_old=value; return 1;}
    return 0;
}

//******************************
void CheckValidity_EEPROM(void){
    if(empty_eeprom!=1){Default_EEPROM();}
}

#pragma used-

