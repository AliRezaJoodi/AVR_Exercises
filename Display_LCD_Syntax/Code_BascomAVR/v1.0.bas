'Github Account: Github.com/Alirezajoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Deflcdchar 0 , 4 , 14 , 31 , 4 , 4 , 4 , 4 , 4
Deflcdchar 1 , 32 , 32 , 2 , 2 , 30 , 32 , 8 , 32
Deflcdchar 2 , 32 , 32 , 2 , 2 , 31 , 32 , 8 , 32
Deflcdchar 3 , 32 , 32 , 32 , 1 , 1 , 2 , 4 , 24

Gosub Display_loading
Gosub Display_advertising
Gosub Syntax_format

Do

Loop

End

'**********************************************
Syntax_format:
   Dim S1 As String * 3 : S1 = "123"
   Dim S2 As String * 16
   Cls

   S2 = Format(s1 , "+")
   Locate 1 , 1 : Lcd S2

   S2 = Format(s1 , "00000")
   Locate 1 , 8 : Lcd S2

   S2 = Format(s1 , "000.00")
   Locate 2 , 1 : Lcd S2

   S2 = Format(s1 , " +000.00")
   Locate 2 , 8 : Lcd S2
Return

'**********************************************
Display_loading:
   Cls
   Locate 1 , 1 : Lcd "Testing the LCD"
   Locate 2 , 1 : Lcd "Loading ..."
   Waitms 500 : Cls
Return

'**********************************************
Display_advertising:
   Home Upper : Lcd "GitHub.com"
   Home Lower : Lcd "AliRezaJoodi"
   Waitms 500 : Cls
Return

'**********************************************
Display_Persian:
   Cls
   Lcd Chr(3)
   Lcd Chr(2)
   Lcd Chr(1)
Return

'**********************************************
Test1:
   Deflcdchar 0 , 28 , 20 , 28 , 32 , 32 , 32 , 32 , 32
   Cls
   Locate 1 , 1
   Lcd "Temp: " ; 27 ; Chr(0) ; "C   "
   Locate 2 , 1
   Lcd "Setpoint: " ; 30 ; "   "
Return