'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Portd.0 = Input : Portd.0 = 1 : Key_1 Alias Pind.0
Config Portd.0 = Input : Portd.0 = 1 : Key_2 Alias Pind.1
Config Portd.0 = Input : Portd.0 = 1 : Key_3 Alias Pind.2
Config Portb.0 = Output : Portb.0 = 0 : Buzzer Alias Portb.0

Config Debounce = 30

Do
   Debounce Key_1 , 0 , Sound_menu , Sub
   Debounce Key_2 , 0 , Sound_menu , Sub
   Debounce Key_3 , 0 , Sound_menu , Sub
Loop

End

'**********************************
Sound_menu:
   Sound Buzzer , 70 , 600
Return

