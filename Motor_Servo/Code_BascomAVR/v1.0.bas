'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

$baud = 9600
Config Serialin = Buffered , Size = 20
Enable Interrupts

Config Porta.0 = Output
Config Servos = 1 , Servo1 = Porta.0 , Reload = 3
Const In_min = 112
Const In_max = 224

Dim Degree As Integer
Dim G As Single
Dim Puls_single As Single
Dim Puls_byte As Byte

Print "Servo Motor Controller"
Print "Rotatable From -90 to 90"

Do
   Input "Enter a Degree: " , Degree
   Gosub Servo_drive
Loop

End

'****************************************
Servo_drive:
   G = In_max - In_min : G = 180 / G
   Puls_single = Degree + 90 : Puls_single = Puls_single / G : Puls_single = Puls_single + In_min
   Puls_byte = Puls_single
   Servo(1) = Puls_byte
Return