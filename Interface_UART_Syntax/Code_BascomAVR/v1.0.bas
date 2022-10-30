'Github Account: Github.com/Alirezajoodi

$regfile = "m32def.dat"
$crystal = 8000000

$baud = 9600
Config Com1 = Dummy , Synchrone = 0 , Parity = None , Stopbits = 1 , Databits = 8 , Clockpol = 0
Config Serialin = Buffered , Size = 20

Enable Interrupts

Dim S As String * 16

'Gosub Test1
'Gosub Test2
Gosub Test3

Do

Loop

End

'**********************************************
Test3:
   Dim A2 As Byte
   Print "*** Function ***"
   Do
      A2 = Waitkey()
      Print "ASCII Decimal: " ; A2
      Print "ASCII Char:    " ; Chr(a2)
   Loop
Return


'**********************************************
Test2:
   Dim A As Byte
   Print "*** Function ***"
   Do
      A = Inkey()
      If A <> 0 Then
         Print "ASCII Decimal: " ; A
         Print "ASCII Char:    " ; Chr(a)
      End If
   Loop
Return

'**********************************************
Test1:
   Print "*** Function ***"
   Input "Enter your Text: " , S
   Print "Your text was:   " ; S
Return