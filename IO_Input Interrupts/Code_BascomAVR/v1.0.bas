'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pina.0 , E = Pina.2 , Db4 = Pina.4 , Db5 = Pina.5 , Db6 = Pina.6 , Db7 = Pina.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

Ddrd.2 = 0 : Portd.2 = 1
Config Int0 = Falling
Enable Int0
On Int0 Up

Ddrd.3 = 0 : Portd.3 = 1
Config Int1 = Rising
Enable Int1
On Int1 Downe

Dim I1 As Byte
Dim I2 As Integer

Do
   Incr I1
   Gosub Display_value
   Waitms 250
Loop

End

'****************************************
Display_value:
   Locate 1 , 1 : Lcd "Num(Int)=" ; I2 ; "   "
   Locate 1 , 14 : Lcd I1 ; " "
   Locate 2 , 1 : Lcd "Input Interrupts"
Return

'****************************************
Up:
   Incr I2
Return

'****************************************
Downe:
   Decr I2
Return