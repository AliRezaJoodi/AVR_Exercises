'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

$baud = 9600
Config Com1 = Dummy , Synchrone = 0 , Parity = None , Stopbits = 1 , Databits = 8 , Clockpol = 0
Config Serialin = Buffered , Size = 20

Dim Index As Integer
Dim Value As Byte
Dim Value_int As Integer
Dim Value_long As Long
Dim Entries As Byte
Dim Txt As String * 8
Dim I As Byte

Gosub Display_

Gosub Test_lookdown
Gosub Test_lookup
Gosub Test_lookupstr
Gosub Test1_restore
Gosub Test2_restore
Gosub Test3_restore
Gosub Test4_restore

Do

Loop

End

'********************************
Test4_restore:
   Restore Table4
   Print
   Read Value_long
   Print "Restore Table4 (1)= " ; Value_long

Return

'********************************
Test3_restore:
   Restore Table3
   Print
   Read Txt
   Print "Restore Table3 (1)= " ; Txt
   Read Txt
   Print "Restore Table3 (2)= " ; Txt
   Read Txt
   Print "Restore Table3 (3)= " ; Txt
Return

'********************************
Test2_restore:
   Restore Table2
   Print
   For I = 1 To 4                                           '
      Read Value_int
      Print "Restore Table2 (" ; I ; ")= " ; Value_int
   Next
Return

'********************************
Test1_restore:
   Restore Tablel
   Print
   For I = 1 To 6                                           '
      Read Value
      Print "Restore Tablel (" ; I ; ")= " ; Value
   Next
Return

'********************************
Test_lookupstr:
   Dim S As String * 8 , Idx As Byte
   Idx = 0 : Txt = Lookupstr(idx , Table3)
   Print
   Print "Lookupstr(0, Table3)" ; " ==> Txt: " ; Txt
Return

'********************************
Test_lookup:
   Index = 4
   Value = Lookup(index , Tablel)
   Print
   Print "Lookup(4, Tablel)" ; " ==> value: " ; Value

   Index = 1
   Value_int = Lookup(index , Table2)
   Print "Lookup(1, Table2)" ; " ==> value: " ; Value_int
Return

'********************************
'We want to search for the value 3
'There are 5 entries in the table
'Looking for integer or word data requires that the search variable is of the type integer !
Test_lookdown:
   Value = 3 : Entries = 5
   Index = Lookdown(value , Tablel , Entries)
   Print "Lookdown(3, Table1,5)" ; " ==> Index: " ; Index

   Value = 4 : Entries = 5
   Index = Lookdown(value , Tablel , Entries)
   Print "Lookdown(4, Table1,5)" ; " ==> Index: " ; Index

   Value = 100 : Entries = 0
   Index = Lookdown(value , Tablel , Entries)
   Print "Lookdown(100, Table1, 0)" ; " ==> Index: " ; Index

   Value_int = 400 : Entries = 0
   Index = Lookdown(value_int , Table2 , Entries)
   Print "Lookdown(400, Table2, 0)" ; " ==> Index: " ; Index
Return

'********************************
Display_:
   Print "Syntax Exercise"
   Print "Lookdown: Returns the index of a series of data."
   Print "Lookup: Returns a value from a table."
   Print "Lookupstr: Returns a string from a table."
   Print "Restore: "
   Print

   Print "Table1: &B10  , &HFF , 1    , 4     , 9     , 100"
   Print "Table2: 1000  , 200  , 400  , 300"
   Print "Table3: Yellow, Read , Green"
   Print "Table4: 123456789"
   Print
Return

'----------------------------------------
Tablel:
Data &B10 , &HFF , 1 , 4 , 9 , 100

'----------------------------------------
'Note that integer values (>255 or <0) must end with the %-sign
Table2:
Data 1000% , 200% , 400% , 300%

'----------------------------------------
Table3:
Data "Yellow" , "Read" , "Green"

'-------------------------------
'Note that LONG values must end with the &-sign
'Also note that the data type must match the variable type that is used for the READ statement
Table4:
Data 123456789&
