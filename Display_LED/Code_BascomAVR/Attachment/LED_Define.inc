'GitHub Account: GitHub.com/AliRezaJoodi

Activate_led Alias 1
Deactivate_led Alias 0

Led0 Alias Porta.0 : Config Led0 = Output : Led0 = Deactivate_led : Led0_index Alias 0
Led1 Alias Porta.1 : Config Led1 = Output : Led1 = Deactivate_led : Led1_index Alias 1
Led2 Alias Porta.2 : Config Led2 = Output : Led2 = Deactivate_led : Led2_index Alias 2
Led3 Alias Porta.3 : Config Led3 = Output : Led3 = Deactivate_led : Led3_index Alias 3
Led4 Alias Porta.4 : Config Led4 = Output : Led4 = Deactivate_led : Led4_index Alias 4
Led5 Alias Porta.5 : Config Led5 = Output : Led5 = Deactivate_led : Led5_index Alias 5
Led6 Alias Porta.6 : Config Led6 = Output : Led6 = Deactivate_led : Led6_index Alias 6
Led7 Alias Porta.7 : Config Led7 = Output : Led7 = Deactivate_led : Led7_index Alias 7

Declare Sub On_led(byval Index As Byte)
Declare Sub Off_led(byval Index As Byte)
Declare Sub Set_led(byval Index As Byte , Byval Status As Byte)
Declare Sub On_leds()
Declare Sub Off_leds()
Declare Sub Set_leds(byval Value As Byte)
Declare Sub flasher_led(byval Index As Byte , Byval t As word) 