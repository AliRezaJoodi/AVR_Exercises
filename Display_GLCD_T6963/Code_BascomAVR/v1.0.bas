'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32DEF.DAT"
$crystal = 8000000

Config Graphlcd = 240 * 64 , Dataport = Portd , Controlport = Portc , Ce = 2 , Cd = 3 , Wr = 0 , Rd = 1 , Reset = 4 , Fs = 5 , Mode = 8
Cursor Off

Showpic 0 , 0 , Display_p1
Waitms 1000 : Cls Graph

Locate 1 , 1 : Lcd "GitHub.com/AliRezaJoodi"
Locate 3 , 1 : Lcd "T6963 240x64 Graphic LCD"
Locate 5 , 1 : Lcd "Line 3"
Locate 7 , 1 : Lcd "Line 4"
Locate 8 , 1 : Lcd "Line 5"
Waitms 1000 : Cls Text

Circle(60 , 30) , 10 , 255

End

'******************************
Display_p1:
$bgf "Attachment\P1.BGF"