// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

#ifndef CHKBIT
    #define CHKBIT(ADDRESS,BIT)         ((ADDRESS &(1<<BIT))>>BIT)
#endif

#ifndef INT_GLOBAL_ENABLE
    #define INT_GLOBAL_ENABLE          #asm("sei")
#endif

#ifndef INCLUDED_ADC
    #define INCLUDED_ADC
    
    #define GAIN_ADC                    5/1023
    
    #define CH0_ADC                     0b00000 
    #define CH1_ADC                     0b00001
    #define CH2_ADC                     0b00010
    #define CH3_ADC                     0b00011
    #define CH4_ADC                     0b00100
    #define CH5_ADC                     0b00101
    #define CH6_ADC                     0b00110 
    #define CH7_ADC                     0b00111 
    
    #define ADC_VREF_TYPE       ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))    // Voltage Reference: AVCC pin 
    //#define ADC_VREF_TYPE     ((1<<REFS1) | (1<<REFS0) | (0<<ADLAR))    // Voltage Reference: Int., cap. on AREF 
    //#define ADC_VREF_TYPE     ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))    // Voltage Reference: AREF pin
    
    #define ADC_CHANNEL_SINGLE0             ADMUX=(ADMUX & 0b11100000) | 0b00000; delay_us(10);
    #define ADC_CHANNEL_SINGLE1             ADMUX=(ADMUX & 0b11100000) | 0b00001; delay_us(10);
    #define ADC_CHANNEL_SINGLE2             ADMUX=(ADMUX & 0b11100000) | 0b00010; delay_us(10);
    #define ADC_CHANNEL_SINGLE3             ADMUX=(ADMUX & 0b11100000) | 0b00011; delay_us(10);
    #define ADC_CHANNEL_SINGLE4             ADMUX=(ADMUX & 0b11100000) | 0b00100; delay_us(10);
    #define ADC_CHANNEL_SINGLE5             ADMUX=(ADMUX & 0b11100000) | 0b00101; delay_us(10);
    #define ADC_CHANNEL_SINGLE6             ADMUX=(ADMUX & 0b11100000) | 0b00110; delay_us(10); 
    #define ADC_CHANNEL_SINGLE7             ADMUX=(ADMUX & 0b11100000) | 0b00111; delay_us(10);
    
    #define ADC_VREF_AREF                   ADMUX=(ADMUX & 0b00111111) | (0<<REFS1) | (0<<REFS0); delay_us(10);      
    #define ADC_VREF_AVCC                   ADMUX=(ADMUX & 0b00111111) | (0<<REFS1) | (1<<REFS0); delay_us(10);
    #define ADC_VREF_INTERNAL_2V56          ADMUX=(ADMUX & 0b00111111) | (1<<REFS1) | (1<<REFS0); delay_us(10);
    
    #define ADC_RESOLUTION_8BIT             SETBIT(ADMUX,ADLAR); delay_us(10);
    #define ADC_RESOLUTION_10BIT            CLRBIT(ADMUX,ADLAR); delay_us(10);
    
    #define ADC_TRIGGER_FREE            	SFIOR=(SFIOR & 0b00011111) | (0b000<<5);
    #define ADC_TRIGGER_ANALOG_COMPARATOR   SFIOR=(SFIOR & 0b00011111) | (0b001<<5);
    #define ADC_TRIGGER_INT0            	SFIOR=(SFIOR & 0b00011111) | (0b010<<5);
    #define ADC_TRIGGER_T0_COMPARE_MATCH    SFIOR=(SFIOR & 0b00011111) | (0b011<<5);
    #define ADC_TRIGGER_T0_OVERFLOW      	SFIOR=(SFIOR & 0b00011111) | (0b100<<5);
    #define ADC_TRIGGER_T_COMPARE_MATCHB    SFIOR=(SFIOR & 0b00011111) | (0b101<<5);
    #define ADC_TRIGGER_T1_OVERFLOW    	    SFIOR=(SFIOR & 0b00011111) | (0b110<<5);
    #define ADC_TRIGGER_T1_CAPTURE_EVENT    SFIOR=(SFIOR & 0b00011111) | (0b111<<5);
    
    #define ADC_AUTO_TRIGGER_ENABLE         SETBIT(ADCSRA,ADATE);
    #define ADC_AUTO_TRIGGER_DISABLE        CLRBIT(ADCSRA,ADATE);
    
    #define ADC_CLOCK_P1                    ADCSRA=(ADCSRA & 0b11111000) | 0b000;
    #define ADC_CLOCK_P2                    ADCSRA=(ADCSRA & 0b11111000) | 0b001;
    #define ADC_CLOCK_P4                    ADCSRA=(ADCSRA & 0b11111000) | 0b010;
    #define ADC_CLOCK_P8                    ADCSRA=(ADCSRA & 0b11111000) | 0b011;
    #define ADC_CLOCK_P16                   ADCSRA=(ADCSRA & 0b11111000) | 0b100;
    #define ADC_CLOCK_P32                   ADCSRA=(ADCSRA & 0b11111000) | 0b101;
    #define ADC_CLOCK_P64                   ADCSRA=(ADCSRA & 0b11111000) | 0b110;
    #define ADC_CLOCK_P128                  ADCSRA=(ADCSRA & 0b11111000) | 0b111; 
    
    #define ADC_ENABLE                      SETBIT(ADCSRA,ADEN);
    #define ADC_DISABLE                     CLRBIT(ADCSRA,ADEN);
    
    #define ADC_INTERRUPT_ENABLE            SETBIT(ADCSRA,ADIE);
    #define ADC_INTERRUPT_DISABLE           CLRBIT(ADCSRA,ADIE);
    
    #define ADC_START                       SETBIT(ADCSRA,ADSC);
    
#pragma used+

    unsigned int input_int=0;
    char task_adc=0;

//******************************************    
interrupt [ADC_INT] void adc_isr(void){
    if(CHKBIT(ADMUX,ADLAR)==0){input_int=ADCW;}    // 10Bit Resolution
            else{input_int=ADCH;}                  // 8Bit Resolution
}

//******************************************
void ConfigADC_Interrupt(void){
    INT_GLOBAL_ENABLE;
        
    ADC_CHANNEL_SINGLE7 
    ADC_VREF_AVCC;
    ADC_RESOLUTION_10BIT;
    ADC_CLOCK_P16;
    ADC_AUTO_TRIGGER_ENABLE;
    ADC_TRIGGER_T0_OVERFLOW;
    ADC_INTERRUPT_ENABLE;
    ADC_ENABLE;
    ADC_START;
}

//******************************************
void ConfigADC_Default(void){
    ADC_VREF_AVCC;
    ADC_RESOLUTION_10BIT; 
    ADC_CLOCK_P8; 
    ADC_TRIGGER_FREE;
    ADC_INTERRUPT_DISABLE;
    ADC_ENABLE;
}


//******************************************
unsigned int GetFromADC_Int(unsigned char ch){
    if(CHKBIT(ADCSRA,ADEN)){
        ADMUX=(ADMUX & 0b11100000) | ch; delay_us(10);
        ADC_START;  // Start the AD conversion
        while(CHKBIT(ADCSRA,ADIF)==0);  // Wait for the AD conversion to complete 
        SETBIT(ADCSRA,ADIF);
        
        if(CHKBIT(ADMUX,ADLAR)==0){return ADCW;}    // 10Bit Resolution
            else{return ADCH;}                      // 8Bit Resolution
    }
    else{
        return 0;
    }   
}

//******************************************
float GetFromADC_Volt(unsigned char ch){
    float volt=0;
    volt=GetFromADC_Int(ch); 
    volt=volt*GAIN_ADC; 
    return volt;
}

//******************************************
float GetFromADC_mV(unsigned char ch){
    float mv=0;
    mv=GetFromADC_Int(ch);
    mv=mv*GAIN_ADC*1000;  
    return mv;
}

#pragma used-
#endif


