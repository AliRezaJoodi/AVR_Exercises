'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Portd = Output

Enable Interrupts

Config Spi = Hard , Interrupt = On , Data Order = Msb , Master = No , Polarity = Low , Phase = 0       ', Clockrate = 128       ', Noss = 0
Enable Spi
On Spi Spi_isr
Spiinit

Do
Loop

End

'*********************************
Spi_isr:
   Portd = Spdr
Return