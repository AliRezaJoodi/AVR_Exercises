'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Portd.0 , E = Portd.2 , Db4 = Portd.4 , Db5 = Portd.5 , Db6 = Portd.6 , Db7 = Portd.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Kbd = Portc , Debounce = 50 , Delay = 100

Dim Numer_initial As Byte
Dim Numer_correct As Byte

Gosub Dispaly_value

Do
   Numer_initial = Getkbd()
   Numer_correct = Lookup(numer_initial , Read_key)
   If Numer_initial < 16 Then
      Gosub Dispaly_value
   End If
Loop

End

'*********************************
Dispaly_value:
   Cls
   Locate 1 , 1 : Lcd "Num(Initial):" ; Numer_initial
   Locate 2 , 1 : Lcd "Num(Correct):" ; Numer_correct
Return

'*********************************
Read_key:
Data 10 , 7 , 4 , 1 , 0 , 8 , 5 , 2 , 11 , 9 , 6 , 3 
