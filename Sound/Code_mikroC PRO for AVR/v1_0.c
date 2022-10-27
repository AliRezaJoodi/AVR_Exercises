//GitHub Account:     GitHub.com/AliRezaJoodi

void Tone1(void);
void Tone2(void);
void Tone3(void);
void Melody(void);
void Melody2(void);
 
void main() {
  Sound_Init(&PORTB,0);          // Initialize sound pin

  Tone1(); Delay_ms(500);
  Tone2(); Delay_ms(500);
  Tone3(); Delay_ms(500);
  //Melody2(); Delay_ms(500);
  //Melody(); Delay_ms(500);
  
  while(1){
  }

}

void Tone1() {
  Sound_Play(659, 250);   // Frequency = 659Hz, duration = 250ms
}

void Tone2() {
  Sound_Play(698, 250);
}

void Tone3() {
  Sound_Play(784, 250);
}

void ToneA() {
  Sound_Play( 880, 50);
}
void ToneC() {
  Sound_Play(1046, 50);
}
void ToneE() {
  Sound_Play(1318, 50);
}

void Melody() {                              // Plays the melody "Yellow house"
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone3(); Tone3(); Tone2(); Tone2(); Tone1();
}

void Melody2() {                // Plays Melody2
   unsigned short i;
  for (i = 9; i > 0; i--) {
      ToneA();
      ToneC();
      ToneE();
    }
}