'Github Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Pind.4 = Output
Config Pind.5 = Output
Config Timer1 = Pwm , Pwm = 10 , Compare A Pwm = Clear Up , Compare B Pwm = Clear Down , Prescale = 8
Pwm1a = 0                                                   '0~1023
Pwm1b = 0                                                   '0~1023

Dim Value1 As Word : Value1 = 250
Dim Value2 As Word : Value2 = 250

Pwm1a = Value1
Pwm1b = Value2

Do
Loop

End
