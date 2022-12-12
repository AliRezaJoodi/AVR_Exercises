'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "ATtiny13A.DAT"
$crystal = 4800000

$hwstack = 6
$swstack = 12
$framesize = 28

 Led_red Alias Portb.0 : Config Led_red = Output : Led_red = 0
 Led_yellow Alias Portb.1 : Config Led_yellow = Output : Led_yellow = 0
 Led_green Alias Portb.2 : Config Led_green = Output : Led_green = 0

Do
   Set Led_red : Wait 500 : Reset Led_red
   Set Led_yellow : Wait 500 : Reset Led_yellow
   Set Led_green : Wait 500 : Reset Led_green
Loop

End