'Github Account: Github.com/AliRezaJoodi

$regfile = "M32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls
Gosub Display_value

Enable Interrupts

Config Timer0 = Timer , Prescale = 1024                     'PRESCALE= 1|8|64|256|1024
On Timer0 Test
Enable Timer0                                               'Enable Ovf0
Start Timer0

Dim I As Byte

Do
Loop

End

'**************************
Test:
   Stop Timer0
   Incr I : Gosub Display_value
   Start Timer0
Return

'**************************
Display_value:
   Locate 1 , 1 : Lcd "i= " ; I ; " "
   Locate 2 , 1 : Lcd "Config Timer0"
Return