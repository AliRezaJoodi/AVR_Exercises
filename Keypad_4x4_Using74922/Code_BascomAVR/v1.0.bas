'Github Account: Github.com/AliRezaJoodi

$regfile = "M32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pina.0 , E = Pina.2 , Db4 = Pina.4 , Db5 = Pina.5 , Db6 = Pina.6 , Db7 = Pina.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

Ddrd.2 = 0 : Portd.2 = 1
Config Int0 = Rising
On Int0 Get_keypad
Enable Int0

Config Clock = Soft

Dim Numer_initial As Byte
Dim Numer_correct As Byte

Gosub Dispaly2_value

Do

Loop

End

'*********************************
Get_keypad:
   Numer_initial = Pinb And &H0F
   Numer_correct = Lookup(numer_initial , Data_keypad)
   Gosub Dispaly2_value
Return

'*********************************
Dispaly2_value:
   Cls
   Locate 1 , 1 : Lcd Numer_initial ; " "
   Locate 1 , 4 : Lcd "=>"
   Locate 1 , 7 : Lcd Numer_correct ; " "

   Locate 2 , 1 : Lcd "Keypad & 74922"
Return

'*********************************
Dispaly_value:
   Cls
   Locate 1 , 1 : Lcd "Num(Initial):" ; Numer_initial
   Locate 2 , 1 : Lcd "Num(Correct):" ; Numer_correct
Return

'*********************************
Data_keypad:
'Data 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 
Data 7 , 4 , 1 , 10 , 8 , 5 , 2 , 0 , 9 , 6 , 3 , 11 , 12 , 13 , 14 , 15

