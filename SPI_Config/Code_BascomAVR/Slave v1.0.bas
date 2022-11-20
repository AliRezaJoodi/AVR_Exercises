'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Portd = Output

Config Spi = Hard , Interrupt = On , Data Order = Msb , Master = No , Polarity = High , Phase = 0 , Clockrate = 128       ', Noss = 0
Spiinit

Dim I As Byte : I = 0

Do
   Spiin I , 1
   Portd = I
Loop

End