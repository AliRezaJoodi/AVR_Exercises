// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef INCLUDED_AVERAGE
    #define INCLUDED_AVERAGE
    
    #ifndef TURN_OFF_AVERAGE
        #define TURN_ON_AVERAGE
    #endif  
    
    #define COUNTER     10

#pragma used+

//***********************************
float Average(float value){
    #ifdef TURN_ON_AVERAGE
        static float sum=0;
        static float average=0;
        static unsigned char i=0;
    
        sum=sum+value; ++i;
        if(i>=COUNTER){
            average=sum/COUNTER;
            sum=0; i=0;
        } 
    
        return average;
    #else 
        return value;
    #endif   
}
    
//***********************************
float Average2(float value){
    #ifdef TURN_ON_AVERAGE
        static float d[COUNTER];
        float average=0;
        unsigned char i=0; 
    
        for (i=1; i<COUNTER; ++i){
            d[i-1]=d[i];    
        }
        d[COUNTER-1]=value;
    
        for(i=0; i<COUNTER; ++i){
            average=average+d[i];
        } 
        average=average/COUNTER;
    
        return average;
    #else
        return value; 
    #endif 
}

#pragma used-
    
#endif
