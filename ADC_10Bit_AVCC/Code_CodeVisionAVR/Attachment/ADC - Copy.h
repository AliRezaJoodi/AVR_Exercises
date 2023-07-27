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
    
    #define ADC_GAIN                        5/1023
    
    #define SINGLE0                         0b00000
    #define SINGLE1                         0b00001
    #define SINGLE2                         0b00010
    #define SINGLE3                         0b00011
    #define SINGLE4                         0b00100
    #define SINGLE5                         0b00101
    #define SINGLE6                         0b00110
    #define SINGLE7                         0b00111
    #define DIF00_10x                       0b01000
    #define DIF10_10x                       0b01001
    #define DIF00_200x                      0b01010
    #define DIF10_200x                      0b01011
    #define DIF22_10x                       0b01100
    #define DIF32_10x                       0b01101
    #define DIF22_200x                      0b01110
    #define DIF32_200x                      0b01111
    #define DIF01_1x                        0b10000
    #define DIF11_1x                        0b10001
    #define DIF21_1x                        0b10010
    #define DIF31_1x                        0b10011
    #define DIF41_1x                        0b10100
    #define DIF51_1x                        0b10101
    #define DIF61_1x                        0b10110
    #define DIF71_1x                        0b10111
    #define DIF02_1x                        0b11000
    #define DIF12_1x                        0b11001
    #define DIF22_1x                        0b11010
    #define DIF32_1x                        0b11011
    #define DIF42_1x                        0b11100
    
    #define SET_ADC_CHANNEL(CH)             ADMUX=(ADMUX & 0b11100000) | CH; delay_us(10);
    /*
    #define ADC_CHANNEL_SINGLE0             ADMUX=(ADMUX & 0b11100000) | 0b00000; delay_us(10);
    #define ADC_CHANNEL_SINGLE1             ADMUX=(ADMUX & 0b11100000) | 0b00001; delay_us(10);
    #define ADC_CHANNEL_SINGLE2             ADMUX=(ADMUX & 0b11100000) | 0b00010; delay_us(10);
    #define ADC_CHANNEL_SINGLE3             ADMUX=(ADMUX & 0b11100000) | 0b00011; delay_us(10);
    #define ADC_CHANNEL_SINGLE4             ADMUX=(ADMUX & 0b11100000) | 0b00100; delay_us(10);
    #define ADC_CHANNEL_SINGLE5             ADMUX=(ADMUX & 0b11100000) | 0b00101; delay_us(10);
    #define ADC_CHANNEL_SINGLE6             ADMUX=(ADMUX & 0b11100000) | 0b00110; delay_us(10);
    #define ADC_CHANNEL_SINGLE7             ADMUX=(ADMUX & 0b11100000) | 0b00111; delay_us(10);
    #define ADC_CHANNEL_DIF00_10x           ADMUX=(ADMUX & 0b11100000) | 0b01000; delay_us(10);
    #define ADC_CHANNEL_DIF10_10x           ADMUX=(ADMUX & 0b11100000) | 0b01001; delay_us(10);
    #define ADC_CHANNEL_DIF00_200x          ADMUX=(ADMUX & 0b11100000) | 0b01010; delay_us(10);
    #define ADC_CHANNEL_DIF10_200x          ADMUX=(ADMUX & 0b11100000) | 0b01011; delay_us(10);
    #define ADC_CHANNEL_DIF22_10x           ADMUX=(ADMUX & 0b11100000) | 0b01100; delay_us(10);
    #define ADC_CHANNEL_DIF32_10x           ADMUX=(ADMUX & 0b11100000) | 0b01101; delay_us(10);
    #define ADC_CHANNEL_DIF22_200x          ADMUX=(ADMUX & 0b11100000) | 0b01110; delay_us(10);
    #define ADC_CHANNEL_DIF32_200x          ADMUX=(ADMUX & 0b11100000) | 0b01111; delay_us(10);
    #define ADC_CHANNEL_DIF01_1x            ADMUX=(ADMUX & 0b11100000) | 0b10000; delay_us(10);
    #define ADC_CHANNEL_DIF11_1x            ADMUX=(ADMUX & 0b11100000) | 0b10001; delay_us(10);
    #define ADC_CHANNEL_DIF21_1x            ADMUX=(ADMUX & 0b11100000) | 0b10010; delay_us(10);
    #define ADC_CHANNEL_DIF31_1x            ADMUX=(ADMUX & 0b11100000) | 0b10011; delay_us(10);
    #define ADC_CHANNEL_DIF41_1x            ADMUX=(ADMUX & 0b11100000) | 0b10100; delay_us(10);
    #define ADC_CHANNEL_DIF51_1x            ADMUX=(ADMUX & 0b11100000) | 0b10101; delay_us(10);
    #define ADC_CHANNEL_DIF61_1x            ADMUX=(ADMUX & 0b11100000) | 0b10110; delay_us(10);
    #define ADC_CHANNEL_DIF71_1x            ADMUX=(ADMUX & 0b11100000) | 0b10111; delay_us(10);
    #define ADC_CHANNEL_DIF02_1x            ADMUX=(ADMUX & 0b11100000) | 0b11000; delay_us(10);
    #define ADC_CHANNEL_DIF12_1x            ADMUX=(ADMUX & 0b11100000) | 0b11001; delay_us(10);
    #define ADC_CHANNEL_DIF22_1x            ADMUX=(ADMUX & 0b11100000) | 0b11010; delay_us(10);
    #define ADC_CHANNEL_DIF32_1x            ADMUX=(ADMUX & 0b11100000) | 0b11011; delay_us(10);
    #define ADC_CHANNEL_DIF42_1x            ADMUX=(ADMUX & 0b11100000) | 0b11100; delay_us(10);
    */
    
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

    unsigned int input_int;
    char task_adc=0;

//******************************************    
interrupt [ADC_INT] void adc_isr(void){
    if(CHKBIT(ADMUX,ADLAR)==0){input_int=ADCW;}    // 10Bit Resolution
            else{input_int=ADCH;}                  // 8Bit Resolution 
    task_adc=1;
}

//******************************************
void ConfigADC_Interrupt(unsigned char ch){
    INT_GLOBAL_ENABLE;
        
    SET_ADC_CHANNEL(ch); 
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
        //ADMUX=(ADMUX & 0b11100000) | ch; delay_us(10);
        SET_ADC_CHANNEL(ch);
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
    volt=volt*ADC_GAIN; 
    return volt;
}

//******************************************
float GetFromADC_mV(unsigned char ch){
    float mv=0;
    mv=GetFromADC_Int(ch);
    mv=mv*ADC_GAIN*1000;  
    return mv;
}

#pragma used-
#endif


