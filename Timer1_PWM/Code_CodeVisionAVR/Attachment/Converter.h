//GitHub Account:     GitHub.com/AliRezaJoodi

// Input(float):    0~100%
// Output(int):    0~1023
unsigned int Get_0to1023(float x){
    unsigned int y=0;
    if(x<0){x=0;} else if(x>100){x=100;}
    x=x*1023/100; y=x;
    return y;       
}

// Input(float):    0~100%
// Output(char):    0~255
unsigned char Get_0to255(float x){
    unsigned char y=0;
    if(x<0){x=0;} else if(x>100){x=100;}
    x=x*255/100; y=x;
    return y;       
}