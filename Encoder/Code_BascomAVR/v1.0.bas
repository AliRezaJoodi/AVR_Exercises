'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Portc.0 , E = Portc.2 , Db4 = Portc.4 , Db5 = Portc.5 , Db6 = Portc.6 , Db7 = Portc.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Portd.2 = Input : Portd.2 = 1
Config Portd.3 = Input : Portd.3 = 1

Dim Value As Integer : Value = 0
Dim Value_old As Integer
Dim B As Byte

Do
   B = Encoder(pind.2 , Pind.3 , Leftlabel , Rightlabel , 0)

   '                                               ^--- 1 means wait for change which blocks programflow
   '                               ^--------^---------- labels which are called
   '              ^-------^---------------------------- port PINs

   If Value <> Value_old Then
      Cls : Lcd "Value:" ; Value
      Value_old = Value
   End If

Loop

End

'**********************************
Leftlabel:
   Incr Value
Return

'**********************************
Rightlabel:
   Decr Value
Return


