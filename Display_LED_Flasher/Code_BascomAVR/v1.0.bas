'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "M32def.dat"
$crystal = 1000000

Config Portd = Output : Portd = 0

Dim I As Byte
Dim D As Byte

Do
   For I = 1 To 16
      D = Lookup(i , Data_flasher) : Portd = D : Waitms 200
   Next I
Loop

End

'*********************************
Data_flasher:
Data &B00000000 ,
Data &B00000001 ,
Data &B00000100 ,
Data &B00010000 ,
Data &B01000000 ,
Data &B10000001 ,
Data &B01000010 ,
Data &B00100100 ,
Data &B00011000 ,
Data &B00100100 ,
Data &B01000010 ,
Data &B10000001 ,
Data &B00100000 ,
Data &B00001000 ,
Data &B00000010 ,
Data &B00000000