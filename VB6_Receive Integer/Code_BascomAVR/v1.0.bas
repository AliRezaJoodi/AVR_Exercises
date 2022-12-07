'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m16def.dat"
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

Dim Number As Word : Number = 300
Dim Number_msb As Byte
Dim Number_lsb As Byte
Dim Relay_out As Bit
Dim Cs_temp As Byte

Do
   Incr Number
   Gosub Converter
   Toggle Relay_out : Rly0 = Relay_out

   Gosub Display_lcd
   Gosub Send_uart

   Waitms 1000
Loop

End

'**********************************
Converter:
   Number_msb = High(number)
   Number_lsb = Low(number)
Return

'**********************************
Display_lcd:
   Cls
   Locate 1 , 1 : Lcd "Number:" ; Number ; " "
   Locate 2 , 1 : Lcd "MSB:" ; Number_msb ; " "
   Locate 2 , 8 : Lcd "LSB:" ; Number_lsb ; " "
   'Locate 2 , 1 : Lcd "Integer to VB6"
Return

'**********************************
Send_uart:
   Dim Buffer As Byte

   Udr = &HEB : Waitms 5                                    'send first byte of frame
   Udr = Number_MSB : Waitms 5
   Udr = Number_LSB : Waitms 5
   Buffer = Relay_out : Udr = Buffer : Waitms 5
   Cs_temp = &HEB + Number_MSB : Cs_temp = Cs_temp + Number_LSB : Cs_temp = Cs_temp + Relay_out       'calculate check sum                             '
   Udr = Cs_temp : Waitms 5                                 'send check sum of previous 4 byte
   Cs_temp = 0
Return