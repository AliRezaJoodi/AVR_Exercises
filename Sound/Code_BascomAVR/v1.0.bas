'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Portb.0 = Output : Portb.0 = 0 : Buzzer Alias Portb.0

Gosub Sound_number: Waitms 500
Gosub Sound_menu : Waitms 500
Gosub Sound_error : Waitms 500

Do
Loop

End

'**********************************
Sound_number:
   Sound Buzzer , 400 , 200
Return

'**********************************
Sound_menu:
   Sound Buzzer , 70 , 600
Return

'**********************************
Sound_error:
   Sound Buzzer , 10 , 2500
Return