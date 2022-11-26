'GitHub Account: GitHub.com/AliRezaJoodi

$regfile = "m32def.dat"
$crystal = 8000000

Config Portd.0 = Output : Portd.0 = 0 : Data_0 Alias Portd.0
Config Portd.1 = Output : Portd.1 = 0 : Data_1 Alias Portd.1
Config Portd.2 = Output : Portd.2 = 0 : Data_2 Alias Portd.2
Config Portd.3 = Output : Portd.3 = 0 : Data_3 Alias Portd.3
Config Portd.4 = Output : Portd.4 = 0 : Data_4 Alias Portd.4
Config Portd.5 = Output : Portd.5 = 0 : Data_5 Alias Portd.5
Config Portd.6 = Output : Portd.6 = 0 : Data_6 Alias Portd.6
Config Portd.7 = Output : Portd.7 = 0 : Data_7 Alias Portd.7

Config Porta.0 = Output : Porta.0 = 0 : Column_a Alias Porta.0
Config Porta.1 = Output : Porta.1 = 0 : Column_b Alias Porta.1
Config Porta.2 = Output : Porta.2 = 0 : Column_c Alias Porta.2
Config Porta.3 = Output : Porta.3 = 0 : Column_d Alias Porta.3
Config Porta.4 = Output : Porta.4 = 0 : Column_e Alias Porta.4
Config Porta.5 = Output : Porta.5 = 0 : Column_f Alias Porta.5
Config Porta.6 = Output : Porta.6 = 0 : Column_g Alias Porta.6
Config Porta.7 = Output : Porta.7 = 0 : Column_h Alias Porta.7

Dim S As String * 1 : S = "X"
Dim Scan As Word : Scan = &B00000001
Dim Data_(8) As Byte
Dim D As Byte
Dim I As Byte
Dim A As Word : A = 0
Dim B As Word : B = 0
Dim Index As Word

Dim Text As String * 4 : Text = "ABCD"
Dim J1 As Word : J1 = 0
Dim J2 As Byte : J2 = 1

Do
   Incr J1
   If J1 > 150 Then
      S = Mid(text , J2 , 1) : Incr J2 : If J2 > 4 Then J2 = 1
      J1 = 0
   End If

   'S = "X"
   A = Asc(s)
   A = A -30 : A = A * 8
   B = A + 7
   Index = 1
   For Scan = A To B
      Data_(index) = Lookup(scan , Data_table) : Incr Index
   Next Scan
   Scan = &B00000001
   For I = 1 To 8
      D = Data_(i)
      Gosub Driver_segment : Waitms 1
      Rotate Scan , Left , 1
      Gosub Off_segment
   Next I
Loop

End

'**************************************
Off_segment:
   Reset Column_h : Reset Column_g : Reset Column_f : Reset Column_e : Reset Column_d : Reset Column_c : Reset Column_b : Reset Column_a
Return

'**************************************
Driver_segment:
   Data_7 = D.7 : Data_6 = D.6 : Data_5 = D.5 : Data_4 = D.4 : Data_3 = D.3 : Data_2 = D.2 : Data_1 = D.1 : Data_0 = D.0
   Column_h = Scan.7 : Column_g = Scan.6 : Column_f = Scan.5 : Column_e = Scan.4 : Column_d = Scan.3 : Column_c = Scan.2 : Column_b = Scan.1 : Column_a = Scan.0
Return

'**************************************
Erase_data:
   For I = 1 To 8
      Data_(i) = 0
   Next I
Return

'---------------------------------------
Data_table:
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00
Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00
Data &H00 , &H00 , &H60 , &HFA , &HFA , &H60 , &H00 , &H00  '!
Data &H00 , &HC0 , &HE0 , &H00 , &H00 , &HE0 , &HC0 , &H00 '"
Data &H28 , &HFE , &HFE , &H28 , &HFE , &HFE , &H28 , &H00  '#
Data &H00 , &H24 , &H74 , &HD6 , &HD6 , &H5C , &H48 , &H00  '$
Data &H62 , &H66 , &H0C , &H18 , &H30 , &H66 , &H46 , &H00  '%
Data &H0C , &H5E , &HF2 , &HBA , &HEC , &H5E , &H12 , &H00  '&
Data &H00 , &H00 , &H20 , &HE0 , &HC0 , &H00 , &H00 , &H00  ''
Data &H00 , &H00 , &H38 , &H7C , &HC6 , &H82 , &H00 , &H00  '
Data &H00 , &H00 , &H82 , &HC6 , &H7C , &H38 , &H00 , &H00  ')
Data &H10 , &H54 , &H7C , &H38 , &H38 , &H7C , &H54 , &H10  '*
Data &H00 , &H10 , &H10 , &H7C , &H7C , &H10 , &H10 , &H00  '+
Data &H00 , &H00 , &H01 , &H07 , &H06 , &H00 , &H00 , &H00  ',
Data &H00 , &H10 , &H10 , &H10 , &H10 , &H10 , &H10 , &H00  '-
Data &H00 , &H00 , &H00 , &H06 , &H06 , &H00 , &H00 , &H00  '.
Data &H06 , &H0C , &H18 , &H30 , &H60 , &HC0 , &H80 , &H00  '/
Data &H38 , &H7C , &HC6 , &H92 , &HC6 , &H7C , &H38 , &H00  '0
Data &H00 , &H02 , &H42 , &HFE , &HFE , &H02 , &H02 , &H00  '1
Data &H42 , &HC6 , &H8E , &H9A , &H92 , &HF6 , &H66 , &H00  '2
Data &H44 , &HC6 , &H92 , &H92 , &H92 , &HFE , &H6C , &H00  '3
Data &H18 , &H38 , &H68 , &HCA , &HFE , &HFE , &H0A , &H00  '4
Data &HF4 , &HF6 , &H92 , &H92 , &H92 , &H9E , &H8C , &H00  '5
Data &H3C , &H7E , &HD2 , &H92 , &H92 , &H1E , &H0C , &H00  '6
Data &HC0 , &HC0 , &H8E , &H9E , &HB0 , &HE0 , &HC0 , &H00  '7
Data &H6C , &HFE , &H92 , &H92 , &H92 , &HFE , &H6C , &H00  '8
Data &H60 , &HF2 , &H92 , &H92 , &H96 , &HFC , &H78 , &H00  '9
Data &H00 , &H00 , &H00 , &H66 , &H66 , &H00 , &H00 , &H00  ':
Data &H00 , &H00 , &H01 , &H67 , &H66 , &H00 , &H00 , &H00  ';
Data &H00 , &H00 , &H10 , &H38 , &H6C , &HC6 , &H82 , &H00  '<
Data &H00 , &H24 , &H24 , &H24 , &H24 , &H24 , &H24 , &H00  '=
Data &H00 , &H82 , &HC6 , &H6C , &H38 , &H10 , &H00 , &H00  '>
Data &H40 , &HC0 , &H80 , &H9A , &HBA , &HE0 , &H40 , &H00  '?
Data &H7C , &HFE , &H82 , &HBA , &HBA , &HF8 , &H78 , &H00  '@
Data &H3E , &H7E , &HD0 , &H90 , &HD0 , &H7E , &H3E , &H00  'A
Data &H82 , &HFE , &HFE , &H92 , &H92 , &HFE , &H6C , &H00  'B
Data &H38 , &H7C , &HC6 , &H82 , &H82 , &HC6 , &H44 , &H00  'C
Data &H82 , &HFE , &HFE , &H82 , &HC6 , &H7C , &H38 , &H00  'D
Data &H82 , &HFE , &HFE , &H92 , &HBA , &H82 , &HC6 , &H00  'E
Data &H82 , &HFE , &HFE , &H92 , &HB8 , &H80 , &HC0 , &H00  'F
Data &H38 , &H7C , &HC6 , &H82 , &H8A , &HCC , &H4E , &H00  'G
Data &HFE , &HFE , &H10 , &H10 , &H10 , &HFE , &HFE , &H00  'H
Data &H00 , &H00 , &H82 , &HFE , &HFE , &H82 , &H00 , &H00  'I
Data &H0C , &H0E , &H02 , &H82 , &HFE , &HFC , &H80 , &H00  'J
Data &H82 , &HFE , &HFE , &H10 , &H38 , &HEE , &HC6 , &H00  'K
Data &H82 , &HFE , &HFE , &H82 , &H02 , &H06 , &H0E , &H00  'L
Data &HFE , &HFE , &H70 , &H38 , &H70 , &HFE , &HFE , &H00  'M
Data &HFE , &HFE , &H60 , &H30 , &H18 , &HFE , &HFE , &H00  'N
Data &H7C , &HFE , &H82 , &H82 , &H82 , &HFE , &H7C , &H00  'O
Data &H82 , &HFE , &HFE , &H92 , &H90 , &HF0 , &H60 , &H00  'P
Data &H7C , &HFE , &H82 , &H82 , &H87 , &HFF , &H7D , &H00  'Q
Data &H82 , &HFE , &HFE , &H90 , &H98 , &HFE , &H66 , &H00  'R
Data &H00 , &H44 , &HE6 , &HB2 , &H9A , &HCE , &H44 , &H00  'S
Data &H00 , &HE0 , &HC2 , &HFE , &HFE , &HC2 , &HE0 , &H00  'T
Data &HFC , &HFE , &H02 , &H02 , &H02 , &HFE , &HFC , &H00  'U
Data &HF8 , &HFC , &H06 , &H02 , &H06 , &HFC , &HF8 , &H00  'V
Data &HFC , &HFE , &H06 , &H1C , &H06 , &HFE , &HFC , &H00  'W
Data &HC6 , &HEE , &H38 , &H10 , &H38 , &HEE , &HC6 , &H00  'X
Data &H00 , &HE0 , &HF2 , &H1E , &H1E , &HF2 , &HE0 , &H00  'Y
Data &HE2 , &HC6 , &H8E , &H9A , &HB2 , &HE6 , &HCE , &H00  'Z
Data &H00 , &H00 , &HFE , &HFE , &H82 , &H82 , &H00 , &H00  '[
Data &H80 , &HC0 , &H60 , &H30 , &H18 , &H0C , &H06 , &H00  '\
Data &H00 , &H00 , &H82 , &H82 , &HFE , &HFE , &H00 , &H00  ']
Data &H10 , &H30 , &H60 , &HC0 , &H60 , &H30 , &H10 , &H00  '^
Data &H01 , &H01 , &H01 , &H01 , &H01 , &H01 , &H01 , &H01  '_
Data &H00 , &H00 , &H20 , &HE0 , &HC0 , &H00 , &H00 , &H00  ''
Data &H04 , &H2E , &H2A , &H2A , &H3C , &H1E , &H02 , &H00  'a
Data &H82 , &HFE , &HFC , &H22 , &H22 , &H3E , &H1C , &H00  'b
Data &H1C , &H3E , &H22 , &H22 , &H22 , &H36 , &H14 , &H00  'c
Data &H1C , &H3E , &H22 , &HA2 , &HFC , &HFE , &H02 , &H00  'd
Data &H1C , &H3E , &H2A , &H2A , &H2A , &H3A , &H18 , &H00  'e
Data &H12 , &H7E , &HFE , &H92 , &H90 , &HC0 , &H40 , &H00  'f
Data &H19 , &H3D , &H25 , &H25 , &H1F , &H3E , &H20 , &H00  'g
Data &H82 , &HFE , &HFE , &H10 , &H20 , &H3E , &H1E , &H00  'h
Data &H00 , &H00 , &H22 , &HBE , &HBE , &H02 , &H00 , &H00  'i
Data &H00 , &H06 , &H07 , &H01 , &H01 , &HBF , &HBE , &H00  'j
Data &H82 , &HFE , &HFE , &H08 , &H1C , &H36 , &H22 , &H00  'k
Data &H00 , &H00 , &H82 , &HFE , &HFE , &H02 , &H00 , &H00  'l
Data &H3E , &H3E , &H30 , &H1E , &H30 , &H3E , &H1E , &H00  'm
Data &H20 , &H3E , &H1E , &H20 , &H20 , &H3E , &H1E , &H00  'n
Data &H1C , &H3E , &H22 , &H22 , &H22 , &H3E , &H1C , &H00  'o
Data &H21 , &H3F , &H1F , &H25 , &H24 , &H3C , &H18 , &H00  'p
Data &H18 , &H3C , &H24 , &H25 , &H1F , &H3F , &H21 , &H00  'q
Data &H22 , &H3E , &H1E , &H32 , &H20 , &H30 , &H10 , &H00  'r
Data &H12 , &H3A , &H2A , &H2A , &H2A , &H2E , &H24 , &H00  's
Data &H20 , &H20 , &HFC , &HFE , &H22 , &H26 , &H04 , &H00  't
Data &H3C , &H3E , &H02 , &H02 , &H3C , &H3E , &H02 , &H00  'u
Data &H38 , &H3C , &H06 , &H02 , &H06 , &H3C , &H38 , &H00  'v
Data &H3C , &H3E , &H06 , &H1C , &H06 , &H3E , &H3C , &H00  'w
Data &H22 , &H36 , &H1C , &H08 , &H1C , &H36 , &H22 , &H00  'x
Data &H39 , &H3D , &H05 , &H05 , &H05 , &H3F , &H3E , &H00  'y
Data &H00 , &H32 , &H26 , &H2E , &H3A , &H32 , &H26 , &H00  'z
Data &H00 , &H10 , &H10 , &H7C , &HEE , &H82 , &H82 , &H00  '{
Data &H00 , &H00 , &H00 , &HFE , &HFE , &H00 , &H00 , &H00  '|
Data &H00 , &H82 , &H82 , &HEE , &H7C , &H10 , &H10 , &H00  '}
Data &H40 , &HC0 , &H80 , &HC0 , &H40 , &HC0 , &H80 , &H00  '~
'Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00
'Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00
'Data &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00 , &H00