'Github Account: Github.com/Alirezajoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Adc = Single , Prescaler = Auto , Reference = Avcc
Start Adc
Const Gain = 5000 / 1023

Dim W As Word
Dim Input_mv As Single
Dim Input_v As Single

Gosub Display_lcd_start_text

Do
   Gosub Read_the_adc
   Gosub Display_in
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
   Input_mv = W * Gain
   Input_v= Input_mv/1000
Return

'**********************************************
Display_in:
   Locate 1 , 1 : Lcd "In(0-1023):" ; W ; " "
   Locate 2 , 1 : Lcd "In(V):" ; Fusing(input_v , "#.###") ; " "
Return