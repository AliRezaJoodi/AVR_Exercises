'Github Account: Github.com/Alirezajoodi

$regfile = "m32def.dat"
$crystal = 8000000

Enable Interrupts

$baud = 9600
Config Com1 = Dummy , Synchrone = 0 , Parity = None , Stopbits = 1 , Databits = 8 , Clockpol = 0
Enable Urxc
On Urxc Test

Print "Press any key"

Do

Loop

End

'**********************************************
Test:
   Dim A As Byte
   A = Udr
   Print "ASCII Decimal: " ; A
   Print "ASCII Char:    " ; Chr(a)
Return
