VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   BackColor       =   &H00C0E0FF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Monitoring Tools"
   ClientHeight    =   1770
   ClientLeft      =   5100
   ClientTop       =   3675
   ClientWidth     =   8370
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1770
   ScaleWidth      =   8370
   Begin VB.Frame Frame1 
      BackColor       =   &H00C0C0FF&
      Caption         =   "Monitoring"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   178
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1800
      Left            =   4200
      TabIndex        =   5
      Top             =   0
      Width           =   4200
      Begin VB.TextBox Txt1 
         Alignment       =   2  'Center
         Appearance      =   0  'Flat
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   3000
         Locked          =   -1  'True
         TabIndex        =   7
         Top             =   240
         Width           =   915
      End
      Begin VB.TextBox Txt2 
         Alignment       =   2  'Center
         Appearance      =   0  'Flat
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   3000
         Locked          =   -1  'True
         TabIndex        =   6
         Top             =   750
         Width           =   915
      End
      Begin VB.Label Label1 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Relay Status"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   2
         Left            =   240
         TabIndex        =   10
         Top             =   1300
         Width           =   1335
      End
      Begin VB.Label Label1 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Number2 (Byte)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   1
         Left            =   240
         TabIndex        =   9
         Top             =   750
         Width           =   1455
      End
      Begin VB.Label Label1 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Number1 (Byte)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   0
         Left            =   240
         TabIndex        =   8
         Top             =   240
         Width           =   1455
      End
      Begin VB.Shape Relay 
         BackColor       =   &H00C0C0C0&
         BackStyle       =   1  'Opaque
         FillColor       =   &H00C0C0C0&
         Height          =   285
         Left            =   3360
         Shape           =   3  'Circle
         Top             =   1300
         Width           =   330
      End
   End
   Begin VB.Frame Frame4 
      BackColor       =   &H00FFFFC0&
      Caption         =   "Communication"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   178
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1800
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   4200
      Begin VB.CommandButton Button2 
         Caption         =   "Disconnect"
         Height          =   375
         Left            =   2160
         TabIndex        =   4
         Top             =   960
         Width           =   1935
      End
      Begin VB.CommandButton Button1 
         Caption         =   "Connect"
         Height          =   375
         Left            =   120
         TabIndex        =   3
         Top             =   960
         Width           =   1935
      End
      Begin VB.ComboBox Combo1 
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   11.25
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2640
         TabIndex        =   1
         Text            =   "1"
         Top             =   350
         Width           =   1215
      End
      Begin MSCommLib.MSComm MSComm1 
         Left            =   2040
         Top             =   0
         _ExtentX        =   1005
         _ExtentY        =   1005
         _Version        =   393216
         CommPort        =   9
         DTREnable       =   -1  'True
         InputLen        =   1
         RThreshold      =   1
         SThreshold      =   1
      End
      Begin VB.Label Label2 
         BackStyle       =   0  'Transparent
         Caption         =   "GitHub.com/AliRezaJoodi"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   11
         Top             =   1440
         Width           =   2535
      End
      Begin VB.Label Label7 
         BackColor       =   &H00FFFFC0&
         Caption         =   "COM Port Number"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   240
         TabIndex        =   2
         Top             =   350
         Width           =   1815
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'GitHub Account: GitHub.com/AliRezaJoodi

Dim buf As Variant
Dim data(5) As Variant
Dim counter As Variant
Dim cs As Variant
Private Sub Form_Load()
    MSComm1.Settings = "9600,N,8,1"
    MSComm1.RThreshold = 1
    MSComm1.SThreshold = 1
    MSComm1.InputLen = 1
    
    For CPN = 1 To 16
        Combo1.AddItem Str(CPN)
    Next CPN
    Combo1.Text = Combo1.List(0)
    
    Button1.Enabled = True: Button2.Enabled = False
    Txt1.Text = "": Txt2.Text = ""
    Relay.BackColor = RGB(160, 160, 160)
End Sub
Private Sub Button1_Click()
    Dim CPN As Byte
    CPN = Val(Combo1.Text): MSComm1.CommPort = CPN: MSComm1.PortOpen = True
    Combo1.Enabled = False
    Button1.Enabled = False: Button2.Enabled = True
End Sub
Private Sub Button2_Click()
    MSComm1.PortOpen = False
    Combo1.Enabled = True
    Button1.Enabled = True: Button2.Enabled = False
    Txt1.Text = "": Txt2.Text = ""
    Relay.BackColor = RGB(160, 160, 160)
End Sub
Private Sub MSComm1_OnComm()
    Select Case MSComm1.CommEvent
        Case comEvReceive
            buf = MSComm1.Input: buf = Asc(buf)
            Debug.Print buf
            If buf = &HEB And counter = 0 Then
                counter = 1
                data(counter) = buf
                cs = buf
                Exit Sub
            End If
            
            If counter <> 0 Then
                counter = counter + 1
                data(counter) = buf
                If counter = 5 Then
                    cs = cs And 255
                    If data(5) = cs Then
                        Txt1.Text = data(2)
                        Txt2.Text = data(3)
                        If data(4) = 0 Then Relay.BackColor = RGB(160, 160, 160) Else Relay.BackColor = RGB(255, 0, 0) 'relay out
                    End If
                    counter = 0
                End If
                cs = cs + buf
            End If
    End Select
End Sub


