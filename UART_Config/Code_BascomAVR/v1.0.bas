'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 11059200

$baud = 9600
Config Com1 = Dummy , Synchrone = 0 , Parity = None , Stopbits = 1 , Databits = 8 , Clockpol = 0
Config Serialin = Buffered , Size = 20

Enable Interrupts

Dim S As String * 16

'Gosub Test1
Gosub Test2
'Gosub Test3

Do
 'Print "*** Function ***"
 'wait 1
Loop

End

'**********************************************
Test3:
   Dim A2 As Byte
   Print "Enter your chr:"
   Do
      A2 = Waitkey()
      Print "ASCII Decimal: " ; A2
      Print "ASCII Char:    " ; Chr(a2)
   Loop
Return


'**********************************************
Test2:
   Dim A As Byte
   Print "Enter your chr: "
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