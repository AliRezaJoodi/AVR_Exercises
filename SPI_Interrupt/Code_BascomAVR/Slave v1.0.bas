'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Portd = Output

Enable Interrupts

Config Spi = Hard , Interrupt = On , Data Order = Msb , Master = No , Polarity = low , Phase = 0 , Clockrate = 128       ', Noss = 0
Enable Spi
On Spi Int_sub
Spiinit

Do
Loop

End

'*********************************
Int_sub:
   Portd = Spdr
Return