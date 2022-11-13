'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "M32def.dat"
$crystal = 1000000

Config Portd = Output : Portd = 0

Active Alias 1
Inactive Alias 0

S1 Alias Portb.0 : Config S1 = Output : S1 = Inactive
S2 Alias Portb.1 : Config S2 = Output : S2 = Inactive
S3 Alias Portb.2 : Config S3 = Output : S3 = Inactive
S4 Alias Portb.3 : Config S4 = Output : S4 = Inactive
S5 Alias Portb.4 : Config S5 = Output : S5 = Inactive
S6 Alias Portb.5 : Config S6 = Output : S6 = Inactive
S7 Alias Portb.6 : Config S7 = Output : S7 = Inactive
S8 Alias Portb.7 : Config S8 = Output : S8 = Inactive

Const Display_delay = 350

Dim Value_long As Long : Value_long = 12345678
Dim I As Byte

Declare Sub Show(byval X As Long)

Do
   Call Show(value_long)
Loop

End

'**********************************
Sub Show(x As Long)
   Dim Digit As Long
   Dim Buffer As Byte
   Do
      Incr I
      Digit = X Mod 10
      Buffer = Lookup(digit , Data_7segment)
      Portd = Not Buffer
      Select Case I
         Case 1:
            S1 = Active : Waitus Display_delay : S1 = Inactive
         Case 2:
            S2 = Active : Waitus Display_delay : S2 = Inactive
         Case 3:
            S3 = Active : Waitus Display_delay : S3 = Inactive
         Case 4:
            S4 = Active : Waitus Display_delay : S4 = Inactive
         Case 5:
            S5 = Active : Waitus Display_delay : S5 = Inactive
         Case 6:
            S6 = Active : Waitus Display_delay : S6 = Inactive
         Case 7:
            S7 = Active : Waitus Display_delay : S7 = Inactive
         Case 8:
            S8 = Active : Waitus Display_delay : S8 = Inactive
      End Select
      X = X \ 10
      If X = 0 Then
         I = 0
         Exit Sub
      End If
   Loop
End Sub

'___________________________
'0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
'A , B , C , D , E , F,
' - , Dp
Data_7segment:
Data &B00111111 , &B00000110 , &B01011011 , &B01001111 , &B01100110 , &B01101101 , &B01111101 , &B00000111 , &B01111111 , &B01101111 _
        , &B01110111 , &B01111100 , &B00111001 , &B01011110 , &B01111001 , &B01110001 _
        , &B01000000 , &B10000000