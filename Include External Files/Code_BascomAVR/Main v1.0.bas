'Github Account: Github.com/Alirezajoodi

$regfile = "m32def.dat"
$crystal = 1000000

$include "Config_Hardware.txt"

Dim A As Byte

Cls
Locate 1 , 1 : Lcd "Number:" ;
Locate 2 , 1 : Lcd "Test Keypad"

Do
   A = Getkbd()
   If A < 16 Then
      Locate 1 , 8 : Lcd A ; "   "
   End If
Loop

End