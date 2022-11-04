' GitHub Account:      GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Portb = Input

Dim Value As Byte
Dim Value_old As Byte

Do
   Value = Pinb
   If Value <> Value_old Then
      Cls
      Locate 1 , 1 : Lcd "Value= " ; Value
      Locate 2 , 1 : Lcd "Input Test"
      Value_old = Value
   End If
Loop

End