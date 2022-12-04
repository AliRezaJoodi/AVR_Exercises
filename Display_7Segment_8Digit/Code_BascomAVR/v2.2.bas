'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "M32def.dat"
$crystal = 1000000

Active_segment Alias 1
Deactive_segment Alias 0
S1 Alias Portb.0 : Config S1 = Output : S1 = Deactive_segment
S2 Alias Portb.1 : Config S2 = Output : S2 = Deactive_segment
S3 Alias Portb.2 : Config S3 = Output : S3 = Deactive_segment
S4 Alias Portb.3 : Config S4 = Output : S4 = Deactive_segment
S5 Alias Portb.4 : Config S5 = Output : S5 = Deactive_segment
S6 Alias Portb.5 : Config S6 = Output : S6 = Deactive_segment
S7 Alias Portb.6 : Config S7 = Output : S7 = Deactive_segment
S8 Alias Portb.7 : Config S8 = Output : S8 = Deactive_segment

Active_digit Alias 0
Deactive_digit Alias 1
S_a Alias Portd.0 : Config S_a = Output : S_a = Deactive_digit
S_b Alias Portd.1 : Config S_b = Output : S_b = Deactive_digit
S_c Alias Portd.2 : Config S_c = Output : S_c = Deactive_digit
S_d Alias Portd.3 : Config S_d = Output : S_d = Deactive_digit
S_e Alias Portd.4 : Config S_e = Output : S_e = Deactive_digit
S_f Alias Portd.5 : Config S_f = Output : S_f = Deactive_digit
S_g Alias Portd.6 : Config S_g = Output : S_g = Deactive_digit
S_dp Alias Portd.7 : Config S_dp = Output : S_dp = Deactive_digit


Dim Value As Long : Value = 87654321

Declare Sub Show(byval Value As Long)

Do
   Call Show(value) : Waitus 500
Loop

End


'**********************************
Sub Show(byval Value As Long)
   Local Value_temporary As Long
   Local Digit As Long
   Local Buffer As Byte
   Dim I As Byte
   S1 = Deactive_segment
   S2 = Deactive_segment
   S3 = Deactive_segment
   S4 = Deactive_segment
   S5 = Deactive_segment
   S6 = Deactive_segment
   S7 = Deactive_segment
   S8 = Deactive_segment

   Select Case I
      Case 0:
         Value_temporary = Value / 1
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S1 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
      Case 1:
         Value_temporary = Value / 10
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S2 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
      Case 2:
         Value_temporary = Value / 100
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S3 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
      Case 3:
         Value_temporary = Value / 1000
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S4 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
      Case 4:
         Value_temporary = Value / 10000
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S5 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
      Case 5:
         Value_temporary = Value / 100000
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S6 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
      Case 6:
         Value_temporary = Value / 1000000
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S7 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
      Case 7:
         Value_temporary = Value / 10000000
         Digit = Value_temporary Mod 10
         Buffer = Lookup(digit , Data_7segment) : Buffer = Not Buffer
         S_a = Buffer.0 : S_b = Buffer.1 : S_c = Buffer.2 : S_d = Buffer.3 : S_e = Buffer.4 : S_f = Buffer.5 : S_g = Buffer.6 : S_dp = Buffer.7
         S8 = Active_segment
         Incr I : If Value_temporary < 10 Then I = 0
         I = 0
   End Select
End Sub

'0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
'A , B , C , D , E , F,
' - , Dp
Data_7segment:
Data &B00111111 , &B00000110 , &B01011011 , &B01001111 , &B01100110 , &B01101101 , &B01111101 , &B00000111 , &B01111111 , &B01101111
Data &B01110111 , &B01111100 , &B00111001 , &B01011110 , &B01111001 , &B01110001
Data &B01000000 , &B10000000