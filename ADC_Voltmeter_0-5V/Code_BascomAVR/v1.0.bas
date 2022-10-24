'(
   Title:               0~5V Voltmeter
   MCU:                 ATmega32
   Clock Frequency:     1.000000 MHz
   Voltage References:  AVCC
   GitHub Account:     GitHub.com/AliRezaJoodi
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
Dim Input_v As Single

Gosub Display_lcd_start_text

Do
   Gosub Read_the_adc
   Gosub Display_lcd
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
   Input_v = Input_mv / 1000
Return


'**********************************************
Display_lcd:
   Locate 2 , 1 : Lcd "Input(mV): " ; Fusing(input_mv , "#.#") ; " " 
   Locate 1 , 1 : Lcd "Input(V): " ; Fusing(input_v , "#.#") ; " "
Return