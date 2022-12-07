// GitHub Account:     GitHub.com/AliRezaJoodi

//***************************************
unsigned int Get_Int(char msb, char lsb){
    unsigned int number=0;
    number = (msb*256)+lsb;
    return number;   
}

//***************************************
char Get_Msb(unsigned int number){
    char msb=0; 
    msb=number/256; 
    return msb;   
}

//***************************************
char Get_Lsb(unsigned int number){
    char lsb=0; 
    lsb=number%256; 
    return lsb;   
}