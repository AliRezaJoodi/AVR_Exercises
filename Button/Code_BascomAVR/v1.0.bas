'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Portb.0 = Input : Portb.0 = 1 : Key_incr Alias Pinb.0
Config Debounce = 30
Dim I As Word : I = 0
Dim R As Word : R = 3000
Dim I2 As Word : I2 = 0
Dim Status_old As Byte

Dim Value As Byte : Value = 100
Gosub Display_value

Do
   'Gosub Get_button_1
   'Gosub Get_button_2
   'Gosub Get_button_3
   'Gosub Get_button_4
   Gosub Get_button_5
Loop

End

'***********************************
Get_button_5:
   If Key_incr = 0 Then
      Incr I
      If I >= R Then
         Incr Value : Gosub Display_value
         I = 0 : Incr I2
         If I2 >= 10 Then
            R = R / 2
            I2 = 0
         End If
      End If
   End If
   If Key_incr = 1 Then
      I = 0 : I2 = 0 : R = 3000
   End If
Return

'***********************************
Get_button_4:
   If Key_incr = 0 Then
      Incr I
      If I >= R Then
         Incr Value : Gosub Display_value
         I = 0
      End If
   End If
   If Key_incr = 1 Then
      I = 0
   End If
Return

'***********************************
Get_button_3:
   If Key_incr = 0 Then
      Waitms 30
      If Key_incr = 0 Then
         Incr Value : Gosub Display_value
         Waitms 150
      End If
   End If
Return

'***********************************
Get_button_2:
   If Key_incr = 0 And Status_old = 1 Then
      Waitms 30
      If Key_incr = 0 Then
         Incr Value : Gosub Display_value
         Status_old = 0
      End If
   End If
   If Key_incr = 1 Then Status_old = 1
Return

'***********************************
Get_button_1:
   Debounce Key_incr , 0 , Value_incr , Sub
Return
'----------------------------------
Value_incr:
   Incr Value : Gosub Display_value
Return

'***********************************
Display_value:
   Cls : Lcd "Number= " ; Value
   Locate 2 , 1 : Lcd "Get Button"
Return

