$regfile = "M8def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Db4 = Pinb.3 , Db5 = Pinb.2 , Db6 = Pinb.1 , Db7 = Pinb.0 , E = Pinb.4 , Rs = Pinb.5
Config Lcd = 16 * 2
Cursor Off
Cls
Gosub Display_value

Enable Interrupts

Config Timer0 = Timer , Prescale = 1024                     'PRESCALE= 1|8|64|256|1024
On Timer0 Lable
Enable Timer0                                               'Enable Ovf0
Start Timer0

Dim I As Byte

Do
Loop

End

'**************************
Lable:
   Stop Timer0
   Incr I : Gosub Display_value
   Start Timer0
Return

'**************************
Display_value:
   Locate 1 , 1 : Lcd "i= " ; I ; " "
   Locate 2 , 1 : Lcd "Config Timer0"
Return