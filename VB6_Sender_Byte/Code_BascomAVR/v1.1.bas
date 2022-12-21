'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 11059200

Config Lcdpin = Pin , Rs = Portc.0 , E = Portc.2 , Db4 = Portc.4 , Db5 = Portc.5 , Db6 = Portc.6 , Db7 = Portc.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

$baud = 9600
On Urxc Usart_rx_isr
Enable Urxc

Dim Data_uart(3) As Byte
Dim Number1 As Byte
Dim Number2 As Byte
Dim Flag As Bit
Dim Cs As Byte                                              'check sum
Dim Count As Byte

Dim Value As Byte

Gosub Display_loading

Do
Loop

End

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
            Number1 = Data_uart(1)
            Number2 = Data_uart(2)
            Gosub Display_numbers
         End If
         Count = 0 : Flag = 0
      End If
      Incr Count
      Cs = Cs + Buffer
   End If
Return

'**********************************************
Display_numbers:
   Cls
   Locate 1 , 1 : Lcd "Number1:" ; Number1
   Locate 2 , 1 : Lcd "Number2:" ; Number2
Return

'**********************************************
Display_loading:
   Cls
   Locate 1 , 1 : Lcd "Testing the LCD"
   Locate 2 , 1 : Lcd "Loading ..."
   Waitms 500 : Cls
Return