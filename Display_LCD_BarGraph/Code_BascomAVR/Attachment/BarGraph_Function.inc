'GitHub Account: GitHub.com/AliRezaJoodi

'**********************************************
Sub Display_bargraph(byval Percent As Single)
   Local Bar_single As Single
   Local N5 As Byte
   Local N_ As Byte
   Local Bars As Byte
   Local I As Byte
   Local Null As Byte

   Locate Display_row , 1

   If Percent < 0 Then Percent = 0
   If Percent > 100 Then Percent = 100

   Bar_single = Percent / 100 : Bar_single = Bar_single * Maximum_bars : Bars = Bar_single
   N5 = Bars / 5
   For I = 1 To N5
      Lcd Chr(5)
   Next I

   N_ = Bars Mod 5
   If N_ = 4 Then Lcd Chr(4)
   If N_ = 3 Then Lcd Chr(3)
   If N_ = 2 Then Lcd Chr(2)
   If N_ = 1 Then Lcd Chr(1)

   Null = Lcd_column - N5 : If N_ <> 0 Then Null = Null - 1
   Lcd Space(null)
End Sub

'**********************************************
Sub Test_bargraph()
   Dim I_ As Byte
   'Dim Value_ As Single

   For I_ = 0 To 100 Step 1
      'Value_ = I_
      Call Display_bargraph(i_)
      Waitms 5
   Next I_

   For I_ = 100 To 0 Step -1
      'Value_ = I_
      Call Display_bargraph(i_)
      Waitms 5
   Next I_

End Sub
