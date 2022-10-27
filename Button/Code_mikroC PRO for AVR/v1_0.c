//GitHub Account:     GitHub.com/AliRezaJoodi

void Tone1(void);
bit oldstate;

void main(){
     DDD0_bit = 0;    // Set pin as input
     
     Sound_Init(&PORTB,0);          // Initialize sound pin
     Tone1(); Delay_ms(500);

     while(1){
              if (Button(&PIND, 0, 30, 1)) {                // Detect logical one
                 oldstate = 1;                              // Update flag
              }
              if (oldstate && Button(&PIND, 0, 30, 0)) {    // Detect one-to-zero transition
                 Tone1();
                 oldstate = 0;                              // Update flag
              }
     }

}

void Tone1() {
  Sound_Play(659, 250);   // Frequency = 659Hz, duration = 250ms
}
