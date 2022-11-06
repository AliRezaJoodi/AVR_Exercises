'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Portd.0 , E = Portd.2 , Db4 = Portd.4 , Db5 = Portd.5 , Db6 = Portd.6 , Db7 = Portd.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Kbd = Portc , Debounce = 50 , Delay = 100 , Rows = 6 , Row5 = Pinb.0 , Row6 = Pinb.1

Dim Numer_initial As Byte
Dim Numer_correct As Byte

Gosub Dispaly_value

Do
   Numer_initial = Getkbd()
   Numer_correct = Lookup(numer_initial , Data_keypad)
   If Numer_correct < 24 Then
      Gosub Dispaly_value
   End If
Loop

End

'*********************************
Dispaly_value:
   Cls
   Locate 1 , 1 : Lcd Numer_initial ; " "
   Locate 1 , 4 : Lcd "=>"
   Locate 1 , 7 : Lcd Numer_correct ; " "

   Locate 2 , 1 : Lcd "4x6Keypad Driver"
Return

'*********************************
Data_keypad:
'Data 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23
Data 10 , 11 , 12 , 13 , 7 , 4 , 1 , 0 , 8 , 5 , 2 , 14 , 9 , 6 , 3 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23