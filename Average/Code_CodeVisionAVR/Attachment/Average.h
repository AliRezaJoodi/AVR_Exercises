// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef INCLUDED_AVERAGE
    #define INCLUDED_AVERAGE
    
    #define NUMBER     10

#pragma used+

//***********************************
float Average(float value){
    static float sum=0;
    static float average=0;
    static unsigned char i=0;
    
    sum=sum+value; ++i;
    if(i>=NUMBER){
        average=sum/NUMBER;
        sum=0; i=0;
    } 
    
    return average;    
}
    
//***********************************
float Average2(float value){
    static float d[NUMBER];
    float average=0;
    unsigned char i=0; 
    
    for (i=1; i<NUMBER; ++i){
        d[i-1]=d[i];    
    }
    d[NUMBER-1]=value;
    
    for(i=0; i<NUMBER; ++i){
        average=average+d[i];
    } 
    average=average/NUMBER;
    
    return average;   
}

#pragma used-
    
#endif
