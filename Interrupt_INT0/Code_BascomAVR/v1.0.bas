'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pina.0 , E = Pina.2 , Db4 = Pina.4 , Db5 = Pina.5 , Db6 = Pina.6 , Db7 = Pina.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

Ddrd.2 = 0 : Portd.2 = 1
Config Int0 = Rising
Enable Int0
On Int0 Int0_function

Dim I As Byte

Do
   Incr I
   Gosub Display_value
   Waitms 250
Loop

End

'****************************************
Display_value:
   Locate 1 , 1 : Lcd "Value=" ; I ; "   "
   Locate 2 , 1 : Lcd "External INT0"
Return

'****************************************
Int0_function:
   I = 0
Return

