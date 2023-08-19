// GitHub Account: GitHub.com/AliRezaJoodi

#include <delay.h>

#ifndef SETBIT
    #define SETBIT(ADDRESS,BIT)         (ADDRESS|=1<<BIT)
#endif 
    
#ifndef CLRBIT
    #define CLRBIT(ADDRESS,BIT)         (ADDRESS &=~(1<<BIT))
#endif

#ifndef CHKBIT
    #define CHKBIT(ADDRESS,BIT)         ((ADDRESS &(1<<BIT))>>BIT)
#endif

#ifndef EnableGlobalInterrupt
    #define EnableGlobalInterrupt(STATUS)     if(STATUS){#asm("sei")} else{#asm("cli")}
#endif

#ifndef _ADC_INCLUDED
    #define _ADC_INCLUDED
    
    #define ADC_GAIN                        0.0048875855    // 5/1023
    
    // Analog Channel and Gain Selections
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
    
    // Voltage Reference Selections
    #define AREF_PIN                        (0<<REFS1) | (0<<REFS0)
    #define AVCC_PIN                        (0<<REFS1) | (1<<REFS0) 
    #define INTERNAL_2V56                   (1<<REFS1) | (1<<REFS0)
    
    // Resolution Selections
    #define R1024                           (0<<ADLAR)
    #define R256                            (1<<ADLAR)
    
    // ADC Trigger Source Selections
    #define FREE_RUNNING                    (0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0) 
    #define ANALOG_COMPARATOR               (0<<ADTS2) | (0<<ADTS1) | (1<<ADTS0)
    #define EXTERNAL_NTERRUPT_REQUEST_0     (0<<ADTS2) | (1<<ADTS1) | (0<<ADTS0)
    #define TIMER0_COMPARE_MATCH            (0<<ADTS2) | (1<<ADTS1) | (1<<ADTS0)
    #define TIMER0_OVERFLOW               	(1<<ADTS2) | (0<<ADTS1) | (0<<ADTS0)
    #define TIMER_COMPARE_MATCH_B           (1<<ADTS2) | (0<<ADTS1) | (1<<ADTS0)
    #define TIMER1_OVERFLOW               	(1<<ADTS2) | (1<<ADTS1) | (0<<ADTS0)
    #define TIMER1_CAPTURE_EVENT            (1<<ADTS2) | (1<<ADTS1) | (1<<ADTS0) 
      
    // ADC Clock Prescaler Selections
    #define P2               	            (0<<ADPS2) | (0<<ADPS1) | (1<<ADPS0)
    #define P4               	            (0<<ADPS2) | (1<<ADPS1) | (0<<ADPS0)
    #define P8               	            (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)
    #define P16               	            (1<<ADPS2) | (0<<ADPS1) | (0<<ADPS0)
    #define P32               	            (1<<ADPS2) | (0<<ADPS1) | (1<<ADPS0)
    #define P64               	            (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0)
    #define P128               	            (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)

    // Configuration Commands
    #define SetClockSourceFromADC(MODE)                 ADCSRA=(ADCSRA & 0b11111000) | MODE; 
    #define SetVoltageReferenceFromADC(MODE)            ADMUX=(ADMUX & 0b00111111) | MODE; 
    #define SetResolutionFromADC(MODE)                  ADMUX=(ADMUX & 0b11011111) | MODE; 
    #define EnableInterruptFromADC(STATUS)              if(STATUS){SETBIT(ADCSRA,ADIE);} else{CLRBIT(ADCSRA,ADIE);}
    #define SetAutoTriggerSourceFromADC(MODE)           SFIOR=(SFIOR & 0b00011111) | MODE;
    #define EnableAutoTriggerFromADC(STATUS)            if(STATUS){SETBIT(ADCSRA,ADATE);} else{CLRBIT(ADCSRA,ADATE);}
    #define SetInputChannelAndGainSelectionsFromADC(CH) ADMUX=(ADMUX & 0b11100000) | CH; 
    #define EnableADC(STATUS)                           if(STATUS){SETBIT(ADCSRA,ADEN);} else{CLRBIT(ADCSRA,ADEN);}        
    #define StartConversionFromADC(STATUS)              if(STATUS){SETBIT(ADCSRA,ADSC);} else{CLRBIT(ADCSRA,ADSC);}
    
    // Check Commands
    #define CHECK_ADC_ENABLE                CHKBIT(ADCSRA,ADEN)
    #define CHECK_ADC_RESOLUTION_256        CHKBIT(ADMUX,ADLAR) 
    #define CHECK_ADC_RESOLUTION_1024       (CHKBIT(ADMUX,ADLAR) ^ 0b00000001) 
    #define END_ADC_CONVERSION              (CHKBIT(ADCSRA,ADIF) ^ 0b00000001) 
    
#pragma used+

    unsigned int input_int;
    char task_adc=0;

//******************************************    
interrupt [ADC_INT] void adc_isr(void){
    if(CHECK_ADC_RESOLUTION_1024){input_int=ADCW;}      // 10Bit Resolution
            else{input_int=ADCH;}                       // 8Bit Resolution 
    task_adc=1;
}

//******************************************
void ConfigADCwithInterrupt(unsigned char ch){    
    SetClockSourceFromADC(P16);
    SetVoltageReferenceFromADC(AVCC_PIN);
    SetResolutionFromADC(R1024);
    EnableInterruptFromADC(1);
    SetAutoTriggerSourceFromADC(TIMER0_OVERFLOW);
    EnableAutoTriggerFromADC(1);    
    SetInputChannelAndGainSelectionsFromADC(ch); 
    EnableADC(1);
    delay_us(10);
    StartConversionFromADC(1);
    
    EnableGlobalInterrupt(1);
}

//******************************************
void ConfigADC(void){
    SetClockSourceFromADC(P16);
    SetVoltageReferenceFromADC(AVCC_PIN);
    SetResolutionFromADC(R1024);
    EnableInterruptFromADC(0);
    SetAutoTriggerSourceFromADC(FREE_RUNNING);
    EnableAutoTriggerFromADC(0);    
    SetInputChannelAndGainSelectionsFromADC(0); 
    EnableADC(1);
    delay_us(10);
    StartConversionFromADC(0); 
    
    EnableGlobalInterrupt(0);
}

//******************************************
unsigned int GetIntValueFromADC(unsigned char ch){
    if(CHECK_ADC_ENABLE){
        SetInputChannelAndGainSelectionsFromADC(ch);
        delay_us(10);
        StartConversionFromADC(1);
        while(END_ADC_CONVERSION);
        SETBIT(ADCSRA,ADIF);
        
        if(CHECK_ADC_RESOLUTION_1024){return ADCW;}     // 10Bit Resolution
            else{return ADCH;}                          // 8Bit Resolution
    }
    else{
        return 0;
    }   
}

#define GetVoltFromADC(CH)                  (GetIntValueFromADC(CH)*ADC_GAIN)
#define GetMilliVoltFromADC(CH)             (GetVoltFromADC(CH)*1000)

#pragma used-
#endif


