'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Porta.0 = Output : Out0 Alias Porta.0
Config Porta.1 = Output : Out1 Alias Porta.1
Config Portb.0 = Output : Out2 Alias Portb.0
Config Portb.1 = Output : Out3 Alias Portb.1
Config Portc.0 = Output : Out4 Alias Portc.0
Config Portc.1 = Output : Out5 Alias Portc.1
Config Portd.0 = Output : Out6 Alias Portd.0
Config Portd.1 = Output : Out7 Alias Portd.1

Dim Status As Byte : Status = &B01001110

Gosub Driver_output

Do

Loop

End

'*****************************************
Driver_output:
   Out0 = Status.0
   Out1 = Status.1
   Out2 = Status.2
   Out3 = Status.3
   Out4 = Status.4
   Out5 = Status.5
   Out6 = Status.6
   Out7 = Status.7
Return