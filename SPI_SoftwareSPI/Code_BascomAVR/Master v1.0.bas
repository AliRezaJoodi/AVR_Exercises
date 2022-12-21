'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Spi = Soft , Din = Pinb.6 , Dout = Portb.5 , Ss = None , Clock = Portb.7 , Setup = 40 , Mode = 1

Deactivate_ss Alias 1
Activate_ss Alias 0
Ss Alias Portb.4 : Config Ss = Output : Ss = Deactivate_ss
Spiinit

Dim I As Byte

Do
   Ss = Activate_ss
   Spiout I , 1
   Ss = Deactivate_ss

   Waitms 500
   Incr I
Loop

End

