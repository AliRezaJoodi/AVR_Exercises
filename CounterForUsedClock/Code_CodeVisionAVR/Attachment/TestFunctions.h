
static inline uint16_t Test1(uint16_t counts){
    return ((uint32_t)counts * 1250U) >> 8;
}

static inline float Test2(uint16_t counts){
    return (float)counts * 4.8828125f;
}

////********************************************************
//void Test2_A(void){
//    float value=12.3;
//    char txt[16];
//    ftoa(value,1,txt);
//}
//
////********************************************************
//void Test2_B(void){
//    float value=12.3;
//    char value_str[16];
//    char txt[16];
//    ftoa(value,1,value_str); sprintf(txt,"Value:%02s",value_str,);
//}
//
////********************************************************
//void Test1_A(void){
//    unsigned char data=3;
//    DDRA=0b11111111;
//    PORTA.0 = data & 0b00000000;
//    PORTA.1 = data & 0b00000010;
//    PORTA.2 = data & 0b00000100;
//    PORTA.3 = data & 0b00001000;
//    PORTA.4 = data & 0b00010000;
//    PORTA.5 = data & 0b00100000;
//    PORTA.6 = data & 0b01000000;
//    PORTA.7 = data & 0b10000000;
//}
//
////********************************************************
//void Test1_B(void){
//    unsigned char data=3;
//    DDRA=0b11111111;
//    PORTA.0 = CHKBIT(data,0);
//    PORTA.1 = CHKBIT(data,1);
//    PORTA.2 = CHKBIT(data,2);
//    PORTA.3 = CHKBIT(data,3);
//    PORTA.4 = CHKBIT(data,4);
//    PORTA.5 = CHKBIT(data,5);
//    PORTA.6 = CHKBIT(data,6);
//    PORTA.7 = CHKBIT(data,7);
//}
//
