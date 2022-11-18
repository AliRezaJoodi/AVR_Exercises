'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Portb = Output

Dim Value As Byte

Do
   For Value = 0 To 9
      Gosub Display_value
      Waitms 500
   Next Value
Loop

End

'**********************************************
Display_value:
   Portb = Value
Return
