// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef INCLUDED_ADC
    #define INCLUDED_ADC

#ifndef PORTS_ADC
    #define PORTS_ADC

    #define CH0_ADC             0 
    #define CH1_ADC             1
    #define CH2_ADC             2
    #define CH3_ADC             3
    #define CH4_ADC             4
    #define CH5_ADC             5
    #define CH6_ADC             6 
    #define CH7_ADC             7 
    
    #define ADC_VREF_TYPE       ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))    // Voltage Reference: AVCC pin 
    //#define ADC_VREF_TYPE     ((1<<REFS1) | (1<<REFS0) | (0<<ADLAR))    // Voltage Reference: Int., cap. on AREF 
    //#define ADC_VREF_TYPE     ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))    // Voltage Reference: AREF pin
    
    #define GAIN_ADC            5/1023   
#endif

//******************************************
// ADC initialization
// ADC Clock frequency: 125.000 kHz
// ADC Auto Trigger Source: ADC Stopped
void Config_ADC(void){
    ADMUX=ADC_VREF_TYPE;
    ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
}

#pragma used+

//******************************************
// Read the AD conversion result
unsigned int Get_ADC(unsigned char ch){
    ADMUX=ch | ADC_VREF_TYPE;
    // Delay needed for the stabilization of the ADC input voltage
    delay_us(10);
    // Start the AD conversion
    ADCSRA|=(1<<ADSC);
    // Wait for the AD conversion to complete
    while ((ADCSRA & (1<<ADIF))==0);
    ADCSRA|=(1<<ADIF);
    return ADCW;
}

//******************************************
float Convert_IntToVolt(unsigned int value){
    float y=value;  
    y=y*GAIN_ADC;
    return y;       
}

//******************************************
float GetVolt_ADC(unsigned char ch){
    float out=0;
    unsigned int x=0;  
    x=Get_ADC(ch); 
    out=Convert_IntToVolt(x); 
    return out;
}

//******************************************
float GetMilliVolt_ADC(unsigned char ch){
    float out=0;
    out=GetVolt_ADC(ch)*1000; 
    return out;
}

#pragma used-

#endif


