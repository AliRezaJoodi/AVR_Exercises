'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Portb = Output

'Gosub Test_1
'Gosub Test_2
Gosub Test_3

Do
Loop

End

'**********************************
Test_3:
   Dim I As Byte

   I = &B00000001
   Do
      Portb = I : Waitms 150
      Shift I , Left
   Loop Until I = &B00000000

   I = &B10000000
   Do
      Portb = I : Waitms 150
      Shift I , Right
   Loop Until I = &B00000000
Return

'**********************************
Test_2:
   Dim A As Byte : A = &B00000011
   Portb = A : Waitms 500
Return

'**********************************
Test_1:
   Portb = 255 : Waitms 500
   Portb = 0 : Waitms 500
   Portb = &B00001111 : Waitms 500
   Portb = &HF0 : Waitms 500
Return