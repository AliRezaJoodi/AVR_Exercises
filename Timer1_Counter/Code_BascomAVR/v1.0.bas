'Github Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

Ddrb.1 = 0 : Portb.1 = 1
Config Timer1 = Counter , Edge = Rising
'Config Timer1 = Counter , Edge = Falling
Enable Ovf1                                                 'Enable Ovf1 OR Enable Counter1
On Ovf1 Incr_value                                          'On Ovf1 Up OR On Counter1 Up
Counter1 = 65530

Dim Counter1_old As Byte
Dim I As Byte
Gosub Display_value

Do
   If Counter1 <> Counter1_old Then
      Gosub Display_value
      Counter1_old = Counter1
   End If
Loop

End

'**************************
Display_value:
   Locate 1 , 1 : Lcd "Counter1=" ; Counter1 ; "      "
   Locate 2 , 1 : Lcd "i=" ; I ; " "
Return

'**************************
Incr_value:
   Incr I
Return