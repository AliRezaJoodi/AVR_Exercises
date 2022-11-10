'Github Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

Ddrb.0 = 0 : Portb.0 = 1
Config Timer0 = Counter , Edge = Rising
'Config Timer0 = Counter , Edge = Falling
On Ovf0 Incr_value                                          'On Ovf0 Up OR On Counter0 Up
Enable Ovf0                                                 'Enable Ovf0 OR Enable Counter0
Tcnt0 = 250

Dim Tcnt0_old As Byte
Dim I As Byte

Gosub Display_value

Do
   If Tcnt0 <> Tcnt0_old Then
      Gosub Display_value
      Tcnt0_old = Tcnt0
   End If
Loop

End

'**************************
Display_value:
   Locate 1 , 1 : Lcd "Counter0=" ; Tcnt0 ; "   "
   Locate 2 , 1 : Lcd "i=" ; I ; "  "
Return

'**************************
Incr_value:
   Incr I
Return