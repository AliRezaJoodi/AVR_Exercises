'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Dim Value As Single : Value = 95

$include "Attachment\BarGraph_Define.inc"

Do
   Incr Value : If Value > 100 Then Value = 0
   Gosub Display_value
   Call Display_bar(value)
   Waitms 250
Loop

End

$include "Attachment\BarGraph_Functions.inc"


'**********************************************
Display_value:
   Locate 1 , 1 : Lcd "Value(%):" ; Fusing(value , "#.#") ; "  "
Return