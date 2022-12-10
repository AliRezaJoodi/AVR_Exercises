'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

Config Adc = Single , Prescaler = Auto , Reference = Avcc
Const Gain = 5000 / 1023
Start Adc

Config Timer0 = Timer , Prescale = 256                      'PRESCALE= 1|8|64|256|1024
On Timer0 Run_isr
Enable Ovf0
Start Timer0

Dim W As Word
Dim Input_mv As Single
Dim Input_v As Single
Dim I As Byte
Dim Input_sum As Word
Dim Input_average As Word

Do
   Idle
Loop

End

'**********************************************
Run_isr:
   Incr I
   Gosub Read_adc
   Input_sum = Input_sum + W
   If I = 10 Then
      Stop Timer0
      Input_average = Input_sum / 10
      Gosub Display_value
      Input_sum = 0 : I = 0
      Start Timer0
   End If
Return

'**********************************************
Read_adc:
   W = Getadc(7)
   Input_mv = W * Gain
   Input_v = Input_mv / 1000
Return

'**********************************************
Display_value:
   Locate 1 , 1 : Lcd "In(V):" ; Fusing(input_v , "#.###") ; "  "
   Locate 2 , 1 : Lcd "LDR Driver"
Return