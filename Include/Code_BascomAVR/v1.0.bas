'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

$include "Attachment\Hardware_v1.0_A.inc"

Config Debounce = 30

Do
   Debounce Button1 , 0 , Led_on , Sub
   Debounce Button2 , 0 , Led_off , Sub
Loop

End

'**********************************
Led_on:
   Led1 = Activate
Return

'**********************************
Led_off:
   Led1 = Deactivate
Return