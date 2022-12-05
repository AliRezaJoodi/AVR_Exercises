'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 11059200

'Config Lcdpin = Pin , Rs = Porta.3 , E = Porta.5 , Db4 = Porta.6 , Db5 = Porta.7 , Db6 = Portc.7 , Db7 = Portc.6
Config Lcdpin = Pin , Rs = Portc.0 , E = Portc.2 , Db4 = Portc.4 , Db5 = Portc.5 , Db6 = Portc.6 , Db7 = Portc.7
Config Lcd = 16 * 2
Cursor Off
Cls

$baud = 9600

Active_led Alias 1
Deactive_led Alias 0

'Rly0 Alias Portc.1 : Config Rly0 = Output : Rly0 = Deactive_led
Rly0 Alias Portb.0 : Config Rly0 = Output : Rly0 = Deactive_led

Dim Number1 As Byte : Number1 = 0
Dim Number2 As Byte : Number2 = 100
Dim Relay_out As Bit
Dim Cs_temp As Byte

Do
   Incr Number1
   Decr Number2
   Toggle Relay_out : Rly0 = Relay_out

   Gosub Display_lcd
   Gosub Display_uart

   Waitms 1000
Loop

End

'**********************************
Display_lcd:
   Cls
   Locate 1 , 1 : Lcd "N1:" : Lcd Number1 : Lcd " "
   Locate 1 , 8 : Lcd "N2:" : Lcd Number2 : Lcd " "
   Locate 2 , 1 : Lcd "Byte to VB6"
Return

'**********************************
Display_uart:
   Dim Buffer As Byte

   Udr = &HEB : Waitms 5                                    'send first byte of frame
   Udr = Number1 : Waitms 5
   Udr = Number2 : Waitms 5
   Buffer = Relay_out : Udr = Buffer : Waitms 5
   Cs_temp = &HEB + Number1 : Cs_temp = Cs_temp + Number2 : Cs_temp = Cs_temp + Relay_out       'calculate check sum                             '
   Udr = Cs_temp : Waitms 5                                 'send check sum of previous 4 byte
   Cs_temp = 0
Return