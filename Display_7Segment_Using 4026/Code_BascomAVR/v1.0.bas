'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Decoder_reset Alias Portb.0 : Config Decoder_reset = Output
Decoder_clock Alias Portb.1 : Config Decoder_reset = Output

Dim Value As Byte

Do
   For Value = 0 To 9
      Gosub Display_value : Wait 1
   Next Value
Loop

End

'**********************************************
Display_value:
   Decoder_reset = 1 : Waitus 10 : Decoder_reset = 0
   If Value <> 0 Then Sound Decoder_clock , Value , 30
Return