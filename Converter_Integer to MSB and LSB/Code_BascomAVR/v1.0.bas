'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Dim Value As Word : Value = 589
Dim Value_msb As Byte
Dim Value_lsb As Byte

Value_lsb = Low(value)
Value_msb = High(value)
Value = Makeint(value_lsb , Value_msb)

Gosub Display_value

Do
Loop

End

'******************************
Display_value:
   Cls
   Locate 1 , 1 : Lcd "Value  MSB   LSB"
   Locate 2 , 1 : Lcd Value
   Locate 2 , 8 : Lcd Value_msb
   Locate 2 , 14 : Lcd Value_lsb
Return

