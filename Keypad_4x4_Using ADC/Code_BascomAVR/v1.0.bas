'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Adc = Single , Prescaler = Auto , Reference = Avcc
Start Adc

Dim W0 As Word
Dim Status_w0 As Word : Status_w0 = 0

Dim W1 As Word
Dim Status_w1 As Word : Status_w1 = 0

Do
   W0 = Getadc(0)
   If W0 <> Status_w0 Then
      Gosub Display_in
      Status_w0 = W0
   End If

   W1 = Getadc(1)
   If W1 <> Status_w1 Then
      Gosub Display_in
      Status_w1 = W1
   End If
Loop

End

'**********************************************
Display_in:
   Locate 1 , 1 : Lcd "In1(0-1023):" ; W0 ; "   "
   Locate 2 , 1 : Lcd "In2(0-1023):" ; W1 ; "   "
Return