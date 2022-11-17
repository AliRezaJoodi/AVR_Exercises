'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

$baud = 9600
Config Porta.0 = Output

Dim I As Integer

Print "RC Servo Motor Controller"

Do
   Input "Enter a Number (1999~4000): " , I
   Pulseout Porta , 0 , I
Loop

End