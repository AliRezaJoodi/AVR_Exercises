'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 11059200

'Config Lcdpin = Pin , Rs = Porta.3 , E = Porta.5 , Db4 = Porta.6 , Db5 = Porta.7 , Db6 = Portc.7 , Db7 = Portc.6
Config Lcdpin = Pin , Rs = Portc.0 , E = Portc.2 , Db4 = Portc.4 , Db5 = Portc.5 , Db6 = Portc.6 , Db7 = Portc.7
Config Lcd = 16 * 2
Cursor Off
Cls

'Enable Interrupts

$baud = 9600
Config Com1 = Dummy , Synchrone = 0 , Parity = None , Stopbits = 1 , Databits = 8 , Clockpol = 0

Dim Txt As String * 16

Gosub Display_loading

Do
   Input Txt
   Gosub Display_text
Loop

End

'**********************************************
Display_text:
   Cls
   Locate 1 , 1 : Lcd Txt
Return

'**********************************************
Display_loading:
   Cls
   Locate 1 , 1 : Lcd "Testing the LCD"
   Locate 2 , 1 : Lcd "Loading ..."
   Waitms 500 : Cls
Return