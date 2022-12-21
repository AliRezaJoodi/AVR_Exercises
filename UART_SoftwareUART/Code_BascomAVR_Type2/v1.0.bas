'Github Account: Github.com/AliRezaJoodi

$regfile = "M32def.dat"
$crystal = 8000000

'Config Portd.7 = Output
'Config Portd.6 = Input : Portd.7 = 1

Dim S As String * 17 : S = "Enter your text: "
Dim Txt As String * 16

Do
   Serout S , 0 , D , 7 , 9600 , 0 , 8 , 1
   Serin Txt , 0 , D , 6 , 9600 , 0 , 8 , 1
   Serout Txt , 0 , D , 7 , 9600 , 0 , 8 , 1
Loop
End