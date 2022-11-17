'Github Account: GitHub.com/AliRezaJoodi

$regfile = "M32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls
Gosub Display_value

Enable Interrupts

Config Timer2 = Timer , Prescale = 128 , Async = On         'Prescale = 1 | 8 | 32 | 64 | 128 | 256 | 1024
On Timer2 Test
Enable Timer2
Stop Timer2 : Start Timer2

Dim Value As Byte
Dim Status As Byte

Do
   If Value <> Status Then
      Gosub Display_value
      Status = Value
   End If
Loop

End

'**************************
Display_value:
   Locate 1 , 1 : Lcd "i= " ; Value ; " "
   Locate 2 , 1 : Lcd "Timer2 (Async)"
Return

'**************************
Test:
   Incr Value
Return


'Prescale   |  Second
'---------------------
'1          |
'8          |
'32         |  0.25
'64         |  0.5
'128        |  1
'256        |
'1024       |