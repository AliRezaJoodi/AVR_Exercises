'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Lcdpin = Pin , Rs = Portd.0 , E = Portd.2 , Db4 = Portd.4 , Db5 = Portd.5 , Db6 = Portd.6 , Db7 = Portd.7
Config Lcd = 16 * 2
Cursor Off
Cls
Gosub Display_loading

Enable Interrupts

Ddrb.2 = 0 : Portb.2 = 1
Config Int2 = Falling
On Int2 Int1_tasks
Enable Int2

$lib "i2c_twi.lbx"
'$lib "I2C_TWI-MULTI.lib" 'important for using 2 TWI interfaces
Config Scl = Portc.0
Config Sda = Portc.1
I2cinit
Config Twi = 100000                                         'speed 100 KHz

Const Ds1307w = &HD0
Const Ds1307r = &HD1

Dim Strg_x As String * 2
Dim _sec As Byte
Dim _min As Byte
Dim _hour As Byte
Dim _weekday As Byte
Dim _day As Byte
Dim _month As Byte
Dim _year As Byte

Dim Task_time_1s As Byte : Task_time_1s = 0

Gosub Config_ds1307

Do
   If Task_time_1s = 1 Then
      Task_time_1s = 0
      Gosub Read_of_the_ds1307
      Gosub Display_time
   End If
Loop
End

'*****************************************
Config_ds1307:
   I2cstart
   I2cwbyte Ds1307w
   I2cwbyte &H00
   I2cwbyte &B00000000
   I2cstop

   Waitms 10
   I2cstart
   I2cwbyte Ds1307w
   I2cwbyte &H07
   I2cwbyte &B00010000
   I2cstop
Return

'****************************************
Int1_tasks:
   Task_time_1s = 1
Return

'*****************************************
Display_loading:
   Cls
   Locate 1 , 1 : Lcd "Loading ..."
Return

'*****************************************
Read_of_the_ds1307:
   I2cstart
   I2cwbyte Ds1307w
   I2cwbyte 0
   I2cstart
   I2cwbyte Ds1307r
   I2crbyte _sec , Ack
   I2crbyte _min , Ack
   I2crbyte _hour , Ack
   I2crbyte _weekday , Ack
   I2crbyte _day , Ack
   I2crbyte _month , Ack
   I2crbyte _year , Nack
   I2cstop

   _hour = _hour And &B00111111
   _sec = _sec And &B01111111
   Gosub Bcd_to_decimal
Return

'*****************************************
Write_to_ds1307:
   Gosub Decimal_to_bcd
   _sec = _sec And &B01111111
   _hour = _hour And &B00111111
   I2cstart
   I2cwbyte Ds1307w
   I2cwbyte 0
   I2cwbyte _sec
   I2cwbyte _min
   I2cwbyte _hour
   I2cwbyte _weekday
   I2cwbyte _day
   I2cwbyte _month
   I2cwbyte _year
   I2cstop
Return

'*****************************************
Bcd_to_decimal:
   _sec = Makedec(_sec)
   _min = Makedec(_min)
   _hour = Makedec(_hour)
   _weekday = Makedec(_weekday)
   _day = Makedec(_day)
   _month = Makedec(_month)
    _year = Makedec(_year)
Return

'*****************************************
Decimal_to_bcd:
   _sec = Makebcd(_sec)
   _min = Makebcd(_min)
   _hour = Makebcd(_hour)
   _weekday = Makebcd(_weekday)
   _day = Makebcd(_day)
   _month = Makebcd(_month)
   _year = Makebcd(_year)
Return

'*****************************************
Display_time:
   Locate 1 , 1 : Lcd "Time:"
   Strg_x = Str(_hour) : Strg_x = Format(strg_x , "00") : Lcd Strg_x : Lcd ":"
   Strg_x = Str(_min) : Strg_x = Format(strg_x , "00") : Lcd Strg_x : Lcd ":"
   Strg_x = Str(_sec) : Strg_x = Format(strg_x , "00") : Lcd Strg_x : Lcd " "
   Locate 2 , 1 : Lcd "Date:"
   Strg_x = Str(_day) : Strg_x = Format(strg_x , "00") : Lcd Strg_x : Lcd "-"
   Strg_x = Str(_month) : Strg_x = Format(strg_x , "00") : Lcd Strg_x : Lcd "-"
   Strg_x = Str(_year) : Strg_x = Format(strg_x , "00") : Lcd Strg_x : Lcd ""
Return
