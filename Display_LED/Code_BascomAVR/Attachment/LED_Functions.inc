'GitHub Account: GitHub.com/AliRezaJoodi

'***********************
Sub On_led(byval Index As Byte)
   Select Case Index
      Case 0 : Led0 = Activate_led
      Case 1 : Led1 = Activate_led
      Case 2 : Led2 = Activate_led
      Case 3 : Led3 = Activate_led
      Case 4 : Led4 = Activate_led
      Case 5 : Led5 = Activate_led
      Case 6 : Led6 = Activate_led
      Case 7 : Led7 = Activate_led
   End Select
End Sub

'***********************
Sub Off_led(byval Index As Byte)
   Select Case Index
      Case 0 : Led0 = Deactivate_led
      Case 1 : Led1 = Deactivate_led
      Case 2 : Led2 = Deactivate_led
      Case 3 : Led3 = Deactivate_led
      Case 4 : Led4 = Deactivate_led
      Case 5 : Led5 = Deactivate_led
      Case 6 : Led6 = Deactivate_led
      Case 7 : Led7 = Deactivate_led
   End Select
End Sub

'***********************
Sub Set_led(byval Index As Byte , Byval Status As Byte)
   Select Case Index
      Case 0 : Led0 = Status
      Case 1 : Led1 = Status
      Case 2 : Led2 = Status
      Case 3 : Led3 = Status
      Case 4 : Led4 = Status
      Case 5 : Led5 = Status
      Case 6 : Led6 = Status
      Case 7 : Led7 = Status
   End Select
End Sub

'***********************
Sub On_leds()
   Local Index As Byte
   For Index = 0 To 7
      Call On_led(index)
   Next Index
End Sub

'***********************
Sub Off_leds()
   Local Index As Byte
   For Index = 0 To 7
      Call Off_led(index)
   Next Index
End Sub

'***********************
Sub Set_leds(byval Value As Byte)
   Led0 = Value.0
   Led1 = Value.1
   Led2 = Value.2
   Led3 = Value.3
   Led4 = Value.4
   Led5 = Value.5
   Led6 = Value.6
   Led7 = Value.7
End Sub

'***********************
Sub Flasher_led(byval Index As Byte , Byval T As word)
   Select Case Index
      Case 0 : Led0 = Activate_led : Waitms T : Led0 = Deactivate_led
      Case 1 : Led1 = Activate_led : Waitms T : Led1 = Deactivate_led
      Case 2 : Led2 = Activate_led : Waitms T : Led2 = Deactivate_led
      Case 3 : Led3 = Activate_led : Waitms T : Led3 = Deactivate_led
      Case 4 : Led4 = Activate_led : Waitms T : Led4 = Deactivate_led
      Case 5 : Led5 = Activate_led : Waitms T : Led5 = Deactivate_led
      Case 6 : Led6 = Activate_led : Waitms T : Led6 = Deactivate_led
      Case 7 : Led7 = Activate_led : Waitms T : Led7 = Deactivate_led
   End Select
End Sub