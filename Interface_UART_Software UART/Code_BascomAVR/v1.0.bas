'Github Account: Github.com/Alirezajoodi

$regfile = "m32def.dat"
$crystal = 8000000

Enable Interrupts
Open "comd.7:9600,8,n,1" For Output As #1                   'Port TX
Open "comd.6:9600,8,n,1" For Input As #2                    'Port RX

Gosub Test

Do
Loop

End

Test:
   Dim Txt As String * 16 : Txt = "Softwar UART"
   Print #1 , Txt
   Print #1 , "Enter your text:"
   Input #2 , Txt : Print #1 , Txt
   Close #1 : Close #2
Return
