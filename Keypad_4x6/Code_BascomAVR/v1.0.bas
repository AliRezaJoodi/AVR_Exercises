'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Portd.0 , E = Portd.2 , Db4 = Portd.4 , Db5 = Portd.5 , Db6 = Portd.6 , Db7 = Portd.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Kbd = Portc , Debounce = 50 , Delay = 100 , Rows = 6 , Row5 = Pinb.0 , Row6 = Pinb.1

Dim Numer_initial As Byte

Gosub Dispaly_value

Do
   Numer_initial = Getkbd()
   If Numer_initial < 24 Then
      Gosub Dispaly_value
   End If
Loop

End

'*********************************
Dispaly_value:
   Cls
   Locate 1 , 1 : Lcd "Num(Initial):" ; Numer_initial
   Locate 2 , 1 : Lcd "4x6Keypad Driver"
Return