'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m16def.dat"
$crystal = 11059200

Config Lcdpin = Pin , Rs = Porta.3 , E = Porta.5 , Db4 = Porta.6 , Db5 = Porta.7 , Db6 = Portc.7 , Db7 = Portc.6
'config Lcdpin = Pin , Rs = Portc.0 , E = Portc.2 , Db4 = Portc.4 , Db5 = Portc.5 , Db6 = Portc.6 , Db7 = Portc.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

$baud = 9600
On Urxc Usart_rx_isr
Enable Urxc

Activate_led Alias 1
Deactivate_led Alias 0
Led0 Alias Portc.5 : Config Led0 = Output : Led0 = Deactivate_led
Led1 Alias Portc.4 : Config Led1 = Output : Led1 = Deactivate_led
Led2 Alias Portc.3 : Config Led2 = Output : Led2 = Deactivate_led
Led3 Alias Portc.2 : Config Led3 = Output : Led3 = Deactivate_led
Led4 Alias Portc.0 : Config Led4 = Output : Led4 = Deactivate_led
Led5 Alias Portd.7 : Config Led5 = Output : Led5 = Deactivate_led
Led6 Alias Portb.2 : Config Led6 = Output : Led6 = Deactivate_led
Led7 Alias Portd.3 : Config Led7 = Output : Led7 = Deactivate_led

Dim Data_uart(3) As Byte
Dim Number As Word
Dim Number_msb As Byte
Dim Number_lsb As Byte
Dim Flag As Bit
Dim Cs As Byte                                              'check sum
Dim Count As Byte

Dim Value As Byte

'Gosub Display_loading
Value = 0 : Gosub Set_leds

Do
Loop

End

'**********************************
Set_leds:
   Led0 = Value.0
   Led1 = Value.1
   Led2 = Value.2
   Led3 = Value.3
   Led4 = Value.4
   Led5 = Value.5
   Led6 = Value.6
   Led7 = Value.7
Return

'**********************************
Usart_rx_isr:
   Dim Buffer As Byte

   Buffer = Udr
   If Flag = 0 Then
      If Buffer = &HAA Then                                 'Finding the first byte of the frame
         Flag = 1
         Cs = Buffer
         Count = 1
      End If
   Else
      Data_uart(count) = Buffer
      If Count = 3 Then
         If Cs = Data_uart(3) Then
            Number_msb = Data_uart(1)
            Number_lsb = Data_uart(2)
            Number = Makeint(number_lsb , Number_msb)
            'Cls : Lcd "Number:" ; Number
            Value = Number_lsb : Gosub Set_leds
         End If
         Count = 0 : Flag = 0
      End If
      Incr Count
      Cs = Cs + Buffer
   End If
Return

'**********************************************
Display_loading:
   Cls
   Locate 1 , 1 : Lcd "Testing the LCD"
   Locate 2 , 1 : Lcd "Loading ..."
   Waitms 500 : Cls
Return