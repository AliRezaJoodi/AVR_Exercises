'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Gosub Display_loading
Gosub Display_advertising

Enable Interrupts

Config Adc = Single , Prescaler = Auto , Reference = Avcc
On Adc Adc_isr
Enable Adc
Start Adc
Const Gain = 5000 / 1023

Dim W As Word
Dim Input_mv As Single
Dim Input_v As Single

Do
   Idle
Loop

End

'**********************************************
Adc_isr:
   W = Getadc(7)
   Input_mv = W * Gain
   Input_v = Input_mv / 1000
   Locate 1 , 1 : Lcd "In(0-1023):" ; W ; " "
   Locate 2 , 1 : Lcd "In(0-5V):" ; Fusing(input_v , "#.###") ; " "
Return


'**********************************************
Display_loading:
   Cls
   Locate 1 , 1 : Lcd "Testing the LCD"
   Locate 2 , 1 : Lcd "Loading ..."
   Waitms 500 : Cls
Return

'**********************************************
Display_advertising:
   Cls
   Locate 1 , 1 : Lcd "GitHub.com"
   Locate 2 , 1 : Lcd "AliRezaJoodi"
   Waitms 500 : Cls
Return