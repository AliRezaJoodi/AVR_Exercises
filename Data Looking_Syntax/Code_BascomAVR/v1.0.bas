'Github Account: Github.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

$baud = 9600
Config Com1 = Dummy , Synchrone = 0 , Parity = None , Stopbits = 1 , Databits = 8 , Clockpol = 0
Config Serialin = Buffered , Size = 20

Dim Index As Integer
Dim Value As Byte
Dim Value_int As Integer
Dim Entries As Byte
Dim Txt As String * 8

Gosub Display_

Gosub Test_lookdown
Gosub Test_lookup
Gosub Test_Lookupstr

Do

Loop

End

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
   Print

   Print "Table1: 2     , 7    , 1    , 4     , 9     , 100"
   Print "Table2: 1000% , 200% , 400% , 300%"
   Print "Table3: Yellow, Read , Green"
   Print
Return

'----------------------------------------
Tablel:
Data 2 , 7 , 1 , 4 , 9 , 100

'----------------------------------------
Table2:
Data 1000% , 200% , 400% , 300%

'----------------------------------------
Table3:
Data "Yellow" , "Read" , "Green"

