VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   BackColor       =   &H00C0E0FF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Monitoring Tools"
   ClientHeight    =   3000
   ClientLeft      =   5100
   ClientTop       =   3675
   ClientWidth     =   3825
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3000
   ScaleWidth      =   3825
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
      Height          =   1680
      Left            =   0
      TabIndex        =   5
      Top             =   1320
      Width           =   3840
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
         ForeColor       =   &H8000000B&
         Height          =   255
         Left            =   240
         TabIndex        =   11
         Top             =   1320
         Width           =   2535
      End
      Begin VB.Label Label_Num2 
         BackColor       =   &H00C0C0FF&
         Caption         =   "255"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   13.5
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000000&
         Height          =   300
         Left            =   2800
         TabIndex        =   10
         Top             =   550
         Width           =   450
      End
      Begin VB.Label Label_Num1 
         BackColor       =   &H00C0C0FF&
         Caption         =   "255"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   13.5
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000000&
         Height          =   300
         Left            =   2800
         TabIndex        =   9
         Top             =   200
         Width           =   450
      End
      Begin VB.Label Label5 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Relay Status:"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   250
         Left            =   240
         TabIndex        =   8
         Top             =   950
         Width           =   1500
      End
      Begin VB.Label Label3 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Number1 (Byte):"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   250
         Left            =   240
         TabIndex        =   7
         Top             =   250
         Width           =   1500
      End
      Begin VB.Label Label4 
         BackColor       =   &H00C0C0FF&
         Caption         =   "Number2 (Byte):"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   178
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   250
         Left            =   240
         TabIndex        =   6
         Top             =   600
         Width           =   1500
      End
      Begin VB.Shape Relay 
         BackColor       =   &H00C0C0C0&
         BackStyle       =   1  'Opaque
         FillColor       =   &H00C0C0C0&
         Height          =   285
         Left            =   2850
         Shape           =   3  'Circle
         Top             =   950
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
      Height          =   1320
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   3840
      Begin VB.CommandButton Button2 
         Caption         =   "Disconnect"
         Height          =   375
         Left            =   2160
         TabIndex        =   4
         Top             =   840
         Width           =   1500
      End
      Begin VB.CommandButton Button1 
         Caption         =   "Connect"
         Height          =   375
         Left            =   120
         TabIndex        =   3
         Top             =   840
         Width           =   1500
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
         Left            =   2400
         TabIndex        =   1
         Text            =   "1"
         Top             =   350
         Width           =   1215
      End
      Begin MSCommLib.MSComm MSComm1 
         Left            =   120
         Top             =   240
         _ExtentX        =   1005
         _ExtentY        =   1005
         _Version        =   393216
         CommPort        =   9
         DTREnable       =   -1  'True
         InputLen        =   1
         RThreshold      =   1
         SThreshold      =   1
      End
      Begin VB.Label Label1 
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
         Height          =   250
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
    Call Setting_Default
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
    Call Setting_Default
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
                        Label_Num1.Caption = data(2)
                        Label_Num2.Caption = data(3)
                        If data(4) = 0 Then Relay.BackColor = RGB(160, 160, 160) Else Relay.BackColor = RGB(255, 0, 0) 'relay out
                    End If
                    counter = 0
                End If
                cs = cs + buf
            End If
    End Select
End Sub
Public Sub Setting_Default()
    Label_Num1.Caption = "xxx": Label_Num2.Caption = "xxx"
    Relay.BackColor = RGB(160, 160, 160)
End Sub


