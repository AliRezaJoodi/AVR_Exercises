'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Portd.0 , E = Portd.2 , Db4 = Portd.4 , Db5 = Portd.5 , Db6 = Portd.6 , Db7 = Portd.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Kbd = Portc , Debounce = 50 , Delay = 100

Dim A As Byte

Cls
Locate 1 , 1 : Lcd "Number:" ;
Locate 2 , 1 : Lcd "Test 4x4 Keypad"

Do
   A = Getkbd()
   If A < 16 Then
      Locate 1 , 8 : Lcd A ; "   "
   End If
Loop

End