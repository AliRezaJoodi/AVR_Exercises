'GitHub Account: GitHub.com/AliRezaJoodi

'The working range is from 4MHz to 10MHz with external crystal.
'The DTMF output is available on the TIMER1 OCA1 pin.
'The DTMF output Use Timer1 In Interrupt Mode. You Must Enable Global Interrupts

$regfile = "m32def.dat"
$crystal = 8000000

Enable Interrupts

Config Portd.6 = Output : Relay Alias Portd.6 : Reset Relay

Dim Number As String * 16

Number = "09112204314"
Gosub Dial_pulse

Do
Loop

End

'***********************************
Dial_tone:
   Set Relay : Waitms 500
   Dtmfout Number , 50
Return

'***********************************
Dial_pulse:
   Dim Length As Byte
   Dim Index As Byte
   Dim Digit As Byte
   Dim S As String * 11
   Dim I As Byte

   Set Relay : Waitms 500
   Length = Len(number)
   For Index = 1 To Length
      S = Mid(number , Index , 1) : Digit = Val(s) : If Digit = 0 Then Digit = 10
      For I = 1 To Digit
         Reset Relay : Waitms 60
         Set Relay : Waitms 40
      Next I
      Waitms 200
   Next Index
   Set Relay
Return

'the DTMFOUT translates a numeric value from 0-15 into:
' numeric value    phone key
'   0                0
'   1                1
'   2                2
'   3                3
' etc.
'   9                9
'  10                *
'  11                #
'  12                A
'  13                B
'  14                C
'  15                D