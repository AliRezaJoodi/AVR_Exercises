'(
   Title:               Thermometer with LM35
   MCU:                 ATMEGA32
   Clock Frequency:     1.000000 MHz
   VREF:                AVCC
   IDE:                 Bascom AVR v2.0.7.5
   GitHub Account:      GitHub.com/AliRezaJoodi
')

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Adc = Single , Prescaler = Auto , Reference = Avcc
Start Adc

Dim W As Word
Dim Input_mv As Single
'Dim Input_v As Single
Dim Temp As Single

Gosub Display_lcd_start_text

Do
   Gosub Read_the_adc
   Gosub Convert
   Gosub Display_
   Waitms 200
Loop

End

'**********************************************
Display_lcd_start_text:
   Locate 1 , 1 : Lcd "GitHub.com"
   Locate 2 , 1 : Lcd "AliRezaJoodi"
   Wait 1 : Cls
Return

'**********************************************
Read_the_adc:
   W = Getadc(7)
   Input_mv = W * 4.8828125
   'Input_v = Input_mv / 1000
Return

'**********************************************
Convert:
   Temp = Input_mv / 10    'Lm35 outputs 10mv for each C degree
Return

'**********************************************
Display_:
   Deflcdchar 0 , 7 , 5 , 7 , 32 , 32 , 32 , 32 , 32
   Locate 1 , 1 : Lcd "Temp: " ; Fusing(temp , "#.#") ; Chr(0) ; "C  "
   Locate 2 , 1 : Lcd "Input: " ; Fusing(input_mv , "#.#") ; "mV"
Return