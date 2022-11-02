'Github Account: Github.com/Alirezajoodi

$regfile = "m32def.dat"
$crystal = 1000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Config Portb.1 = Input : Portb.1 = 1 : Key_up Alias Pinb.1
Config Portb.0 = Input : Portb.0 = 1 : Key_down Alias Pinb.0

Dim I As Byte
Dim I_eerom As Eram Byte

Gosub Eeprom_load
Gosub Display_value

Do
   If Key_up = 0 Then
      Incr I
      Gosub Eeprom_save
      Gosub Display_value
      Waitms 200
   End If

   If Key_down = 0 Then
      Decr I
      Gosub Eeprom_save
      Gosub Display_value
      Waitms 200
   End If
Loop

End

'*********************************************
Display_value:
   Cls : Lcd "Number= " ; I
   Locate 2 , 1 : Lcd "Internal EEPROM"
Return

'*********************************************
Eeprom_load:
   I = I_eerom
Return

'*********************************************
Eeprom_save:
   I_eerom = I
Return

