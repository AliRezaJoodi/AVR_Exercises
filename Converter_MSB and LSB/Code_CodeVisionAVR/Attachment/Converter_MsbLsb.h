// GitHub Account:     GitHub.com/AliRezaJoodi

//***************************************
void Convert_IntToMsbLsb(unsigned int number, char *msb, char *lsb){
    *msb=number/256;
    *lsb=number%256;   
}

//***************************************
unsigned int Convert_MsbLsbToInt(char msb, char lsb){
    unsigned int number=0;
    number = (msb*256)+lsb;
    return number;   
}

//***************************************
char Get_Msb(unsigned int number){
    char msb=0; 
    msb=number/256; 
    //msb=(number>>8);
    return msb;   
}

//***************************************
char Get_Lsb(unsigned int number){
    char lsb=0; 
    lsb=number%256; 
    //lsb=number;
    return lsb;   
}
