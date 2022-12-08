'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m16def.dat"
$crystal = 1000000

Activate_led Alias 1
Deactivate_led Alias 0
Led0 Alias Porta.0
Led1 Alias Porta.1
Led2 Alias Porta.2
Led3 Alias Porta.3
Led4 Alias Porta.4
Led5 Alias Porta.5
Led6 Alias Porta.6
Led7 Alias Porta.7

Gosub Config_led

Dim Value As Byte

Do
   Incr Value
   Gosub Set_leds
   Waitms 1000
Loop

End

'***********************
Set_leds:
   Led0 = Value.0
   Led1 = Value.1
   Led2 = Value.2
   Led3 = Value.3
   Led4 = Value.4
   Led5 = Value.5
   Led6 = Value.6
   Led7 = Value.7
Return

'***********************
Config_led:
   Config Led0 = Output : Led0 = Deactivate_led
   Config Led1 = Output : Led1 = Deactivate_led
   Config Led2 = Output : Led2 = Deactivate_led
   Config Led3 = Output : Led3 = Deactivate_led
   Config Led4 = Output : Led4 = Deactivate_led
   Config Led5 = Output : Led5 = Deactivate_led
   Config Led6 = Output : Led6 = Deactivate_led
   Config Led7 = Output : Led7 = Deactivate_led
Return