'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Adc = Single , Prescaler = Auto , Reference = Aref
Start Adc
Const Gain = 3300 / 1023

Dim Input_int As Word
Dim Input_mv As Single
Dim Input_v As Single

Do
   Gosub Get_adc
   Gosub Display_in
   Waitms 200
Loop

End

'**********************************************
Get_adc:
   Input_int = Getadc(7)
   Input_mv = Input_int * Gain
   Input_v = Input_mv / 1000
Return

'**********************************************
Display_in:
   Locate 1 , 1 : Lcd "In(0-1023):" ; Input_int ; " "
   Locate 2 , 1 : Lcd "In(0-3V3):" ; Fusing(input_v , "#.###") ; " "
Return
