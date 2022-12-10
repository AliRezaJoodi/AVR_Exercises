'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

$include "Attachment\LED_Define.inc"

Dim Value As Byte
Dim I As Byte

Waitms 500

Call Flasher_led(led0_index , 500)                         
Call Set_led(led1_index , Activate_led) : Waitms 500 : Call Set_led(led1_index , Deactivate_led) : Waitms 500
Call On_leds() : Waitms 1000 : Call Off_leds() : Waitms 1000

For I = 0 To 7
   Call On_led(i) : Waitms 500 : Call Off_led(i) : Waitms 500
Next I

Do
   Incr Value
   Call Set_leds(value)
   Waitms 1000
Loop

End

$include "Attachment\LED_Functions.inc"

