'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Spi = Hard , Interrupt = Off , Data Order = Msb , Master = Yes , Polarity = High , Phase = 1 , Clockrate = 128       ', Noss = 1
Spiinit

Dim I As Byte

Do
   Spiout I , 1
   Waitms 500
   Incr I
Loop

End