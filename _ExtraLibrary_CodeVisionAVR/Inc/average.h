// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _AVERAGE_INCLUDED
#define _AVERAGE_INCLUDED
    
#ifndef _AVERAGE_HARDWARE
#define _AVERAGE_HARDWARE 
    #define AVERAGE_COUNT     10
#endif  

#pragma used+

//***********************************
float Average(float value){
    static float sum=0;
    static float average=0;
    static unsigned char i=0;
    
    sum=sum+value; ++i;
    if(i>=AVERAGE_COUNT){
        average=sum/AVERAGE_COUNT;
        sum=0; i=0;
    } 
    
    return average;  
}
    
//***********************************
float Average2(float value){
    static float d[AVERAGE_COUNT];
    float average=0;
    unsigned char i=0; 
    
    for (i=1; i<AVERAGE_COUNT; ++i){
        d[i-1]=d[i];    
    }
    d[AVERAGE_COUNT-1]=value;
    
    for(i=0; i<AVERAGE_COUNT; ++i){
        average=average+d[i];
    } 
    average=average/AVERAGE_COUNT;
    
    return average;
}

#pragma used-
    
#endif
