//GitHub Account:     GitHub.com/AliRezaJoodi

//******************************************
float Fix_0to100(float x){
    if(x<0){x=0;} else if(x>100){x=100;};
    return x;
}

//******************************************
float Inverse_0to100(float x){
    x=Fix_0to100(x);
    return 100-x;
}

//******************************************
unsigned int Convert_0to100_0to1023(float x){
    unsigned int y=0;
    x=Fix_0to100(x);
    x=x/100*1023; y=x;
    return y;       
}

//******************************************
unsigned char Convert_0to100_0to255(float x){
    unsigned char y=0;
    x=Fix_0to100(x);
    x=x/100*255; y=x;
    return y;       
}

//******************************************
float Convert_0to100_1to5V(float x){
    float y=0; 
    x=Fix_0to100(x); 
    y=((x/100)*(5-1))+1; 
    return y;       
}

//******************************************
float Convert_0to100_0to3V3(float x){
    float y=0; 
    x=Fix_0to100(x); 
    y=(x/100)*3.3; 
    return y;       
}

//******************************************
unsigned int Convert_0to5V_0to1023(float x){
    unsigned int y=0;  
    y=(x/5)*1023;
    return y;       
}

//******************************************
unsigned char Convert_0to5V_0to255(float x){
    unsigned char y=0;  
    y=(x/5)*255;
    return y;       
}

//******************************************
unsigned int Convert_0to3V3_0to1023(float x){
    unsigned int y=0;  
    y=(x/3.3)*1023;
    return y;       
}

//******************************************
unsigned char Convert_0to3V3_0to255(float x){
    unsigned char y=0;  
    y=(x/3.3)*255;
    return y;       
}

//******************************************
float Convert_0to1023_0to5V(unsigned int x){
    float y=x;  
    y=(y/1023)*5;
    return y;       
}

//******************************************
float Convert_0to255_0to5V(unsigned char x){
    float y=x;  
    y=(y/255)*5;
    return y;       
}

//******************************************
float Convert_0to1023_0to2V56(unsigned int x){
    float y=x;  
    y=(y/1023)*2.56;
    return y;       
}

//******************************************
float Convert_0to255_0to2V56(unsigned char x){
    float y=x;  
    y=(y/255)*2.56;
    return y;       
}
