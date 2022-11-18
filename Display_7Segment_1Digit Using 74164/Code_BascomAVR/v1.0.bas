'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Port_clk Alias Portb.0 : Config Port_clk = Output
Port_data Alias Portb.1 : Config Port_data = Output

Dim Value As Byte

Do
   For Value = 0 To 9
      Gosub Display_value
      Waitms 500
   Next Value
Loop

End

'**********************************************
Display_value:
   Dim Buffer As Byte
   Buffer = Lookup(value , Data_7segment) : Buffer = Not Buffer
   Shiftout Port_data , Port_clk , Buffer , 1
Return

'___________________________
'0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
'A , B , C , D , E , F,
' - , Dp
Data_7segment:
Data &B00111111 , &B00000110 , &B01011011 , &B01001111 , &B01100110 , &B01101101 , &B01111101 , &B00000111 , &B01111111 , &B01101111 _
         , &B01110111 , &B01111100 , &B00111001 , &B01011110 , &B01111001 , &B01110001 _
        , &B01000000 , &B10000000

