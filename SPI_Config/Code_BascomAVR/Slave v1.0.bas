'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Portd = Output

'Config Portb.4 = Input : Portb.4 = 0
'Config Portb.5 = Input : Portb.5 = 0
'Config Portb.6 = Output : Portb.6 = 0
'Config Portb.7 = Input : Portb.7 = 0
Config Spi = Hard , Interrupt = On , Data Order = Msb , Master = No , Polarity = High , Phase = 0 , Clockrate = 128       ', Noss = 0
Spiinit

Dim I As Byte : I = 0

Do
   Spiin I , 1
   Portd = I
Loop

End