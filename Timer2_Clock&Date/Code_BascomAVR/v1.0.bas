'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Lcdpin = Pin , Rs = Pind.0 , E = Pind.2 , Db4 = Pind.4 , Db5 = Pind.5 , Db6 = Pind.6 , Db7 = Pind.7
Config Lcd = 16 * 2
Cursor Off
Cls

Enable Interrupts

Config Clock = Soft , Gosub = Sectic : Time$ = "23:59:50"
Config Date = Ymd , Separator = / : Date$ = "23/11/10"
'Enable Timer2
'Start Timer2

Dim Weekday_b As Byte
Dim Weekday_str As String * 10
Dim Task As Byte

Do
   If Task = 1 Then
      Task = 0
      Gosub Display_time
   End If
Loop
End

'*****************************************
Sectic:
   Task = 1
Return

'*****************************************
Display_time:
   Weekday_b = Dayofweek() : Weekday_str = Lookupstr(weekday_b , Data_weekdays)
   Locate 1 , 1 : Lcd Time$ ; "  "
   Locate 2 , 1 : Lcd Date$ ; "  "
   Locate 2 , 12 : Lcd Weekday_str ; "  "
Return

'*****************************************
Data_weekdays:
'Data "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"
Data "Mon." , "Tue." , "Wed." , "Thu." , "Fri." , "Sat." , "Sun."