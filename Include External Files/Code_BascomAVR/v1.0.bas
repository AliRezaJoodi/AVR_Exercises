'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

$include "Attachment\Config_Hardware_v1.0.txt"

Config Debounce = 30

Do
   Debounce Key_1 , 0 , Led_on , Sub
   Debounce Key_2 , 0 , Led_off , Sub
Loop

End

'**********************************
Led_on:
   Set Led
Return

'**********************************
Led_off:
   Reset Led
Return
