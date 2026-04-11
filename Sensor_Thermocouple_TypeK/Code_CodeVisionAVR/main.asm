
;CodeVisionAVR C Compiler V3.40 Advanced
;(C) Copyright 1998-2020 Pavel Haiduc, HP InfoTech S.R.L.
;http://www.hpinfotech.ro

;Build configuration    : Debug
;Chip type              : ATmega32A
;Program type           : Application
;Clock frequency        : 1.000000 MHz
;Memory model           : Small
;Optimize for           : Size
;(s)printf features     : float, width, precision
;(s)scanf features      : int, width
;External RAM size      : 0
;Data Stack size        : 512 byte(s)
;Heap size              : 0 byte(s)
;Promote 'char' to 'int': Yes
;'char' is unsigned     : Yes
;8 bit enums            : Yes
;Global 'const' stored in FLASH: Yes
;Enhanced function parameter passing: Mode 1
;Enhanced core instructions: On
;Automatic register allocation for global variables: On
;Smart register allocation: On

	#define _MODEL_SMALL_

	#pragma AVRPART ADMIN PART_NAME ATmega32A
	#pragma AVRPART MEMORY PROG_FLASH 32768
	#pragma AVRPART MEMORY EEPROM 1024
	#pragma AVRPART MEMORY INT_SRAM SIZE 2048
	#pragma AVRPART MEMORY INT_SRAM START_ADDR 0x60

	#define CALL_SUPPORTED 1

	.LISTMAC
	.EQU UDRE=0x5
	.EQU RXC=0x7
	.EQU USR=0xB
	.EQU UDR=0xC
	.EQU SPSR=0xE
	.EQU SPDR=0xF
	.EQU EERE=0x0
	.EQU EEWE=0x1
	.EQU EEMWE=0x2
	.EQU EECR=0x1C
	.EQU EEDR=0x1D
	.EQU EEARL=0x1E
	.EQU EEARH=0x1F
	.EQU WDTCR=0x21
	.EQU MCUCR=0x35
	.EQU SPL=0x3D
	.EQU SPH=0x3E
	.EQU SREG=0x3F

	.DEF R0X0=R0
	.DEF R0X1=R1
	.DEF R0X2=R2
	.DEF R0X3=R3
	.DEF R0X4=R4
	.DEF R0X5=R5
	.DEF R0X6=R6
	.DEF R0X7=R7
	.DEF R0X8=R8
	.DEF R0X9=R9
	.DEF R0XA=R10
	.DEF R0XB=R11
	.DEF R0XC=R12
	.DEF R0XD=R13
	.DEF R0XE=R14
	.DEF R0XF=R15
	.DEF R0X10=R16
	.DEF R0X11=R17
	.DEF R0X12=R18
	.DEF R0X13=R19
	.DEF R0X14=R20
	.DEF R0X15=R21
	.DEF R0X16=R22
	.DEF R0X17=R23
	.DEF R0X18=R24
	.DEF R0X19=R25
	.DEF R0X1A=R26
	.DEF R0X1B=R27
	.DEF R0X1C=R28
	.DEF R0X1D=R29
	.DEF R0X1E=R30
	.DEF R0X1F=R31

	.EQU __SRAM_START=0x0060
	.EQU __SRAM_END=0x085F
	.EQU __DSTACK_SIZE=0x0200
	.EQU __HEAP_SIZE=0x0000
	.EQU __CLEAR_SRAM_SIZE=__SRAM_END-__SRAM_START+1

	.MACRO __CPD1N
	CPI  R30,LOW(@0)
	LDI  R26,HIGH(@0)
	CPC  R31,R26
	LDI  R26,BYTE3(@0)
	CPC  R22,R26
	LDI  R26,BYTE4(@0)
	CPC  R23,R26
	.ENDM

	.MACRO __CPD2N
	CPI  R26,LOW(@0)
	LDI  R30,HIGH(@0)
	CPC  R27,R30
	LDI  R30,BYTE3(@0)
	CPC  R24,R30
	LDI  R30,BYTE4(@0)
	CPC  R25,R30
	.ENDM

	.MACRO __CPWRR
	CP   R@0,R@2
	CPC  R@1,R@3
	.ENDM

	.MACRO __CPWRN
	CPI  R@0,LOW(@2)
	LDI  R30,HIGH(@2)
	CPC  R@1,R30
	.ENDM

	.MACRO __ADDB1MN
	SUBI R30,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDB2MN
	SUBI R26,LOW(-@0-(@1))
	.ENDM

	.MACRO __ADDW1MN
	SUBI R30,LOW(-@0-(@1))
	SBCI R31,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW2MN
	SUBI R26,LOW(-@0-(@1))
	SBCI R27,HIGH(-@0-(@1))
	.ENDM

	.MACRO __ADDW1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1FN
	SUBI R30,LOW(-2*@0-(@1))
	SBCI R31,HIGH(-2*@0-(@1))
	SBCI R22,BYTE3(-2*@0-(@1))
	.ENDM

	.MACRO __ADDD1N
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	SBCI R22,BYTE3(-@0)
	SBCI R23,BYTE4(-@0)
	.ENDM

	.MACRO __ADDD2N
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	SBCI R24,BYTE3(-@0)
	SBCI R25,BYTE4(-@0)
	.ENDM

	.MACRO __SUBD1N
	SUBI R30,LOW(@0)
	SBCI R31,HIGH(@0)
	SBCI R22,BYTE3(@0)
	SBCI R23,BYTE4(@0)
	.ENDM

	.MACRO __SUBD2N
	SUBI R26,LOW(@0)
	SBCI R27,HIGH(@0)
	SBCI R24,BYTE3(@0)
	SBCI R25,BYTE4(@0)
	.ENDM

	.MACRO __ANDBMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ANDWMNN
	LDS  R30,@0+(@1)
	ANDI R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ANDI R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ANDD1N
	ANDI R30,LOW(@0)
	ANDI R31,HIGH(@0)
	ANDI R22,BYTE3(@0)
	ANDI R23,BYTE4(@0)
	.ENDM

	.MACRO __ANDD2N
	ANDI R26,LOW(@0)
	ANDI R27,HIGH(@0)
	ANDI R24,BYTE3(@0)
	ANDI R25,BYTE4(@0)
	.ENDM

	.MACRO __ORBMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	.ENDM

	.MACRO __ORWMNN
	LDS  R30,@0+(@1)
	ORI  R30,LOW(@2)
	STS  @0+(@1),R30
	LDS  R30,@0+(@1)+1
	ORI  R30,HIGH(@2)
	STS  @0+(@1)+1,R30
	.ENDM

	.MACRO __ORD1N
	ORI  R30,LOW(@0)
	ORI  R31,HIGH(@0)
	ORI  R22,BYTE3(@0)
	ORI  R23,BYTE4(@0)
	.ENDM

	.MACRO __ORD2N
	ORI  R26,LOW(@0)
	ORI  R27,HIGH(@0)
	ORI  R24,BYTE3(@0)
	ORI  R25,BYTE4(@0)
	.ENDM

	.MACRO __DELAY_USB
	LDI  R24,LOW(@0)
__DELAY_USB_LOOP:
	DEC  R24
	BRNE __DELAY_USB_LOOP
	.ENDM

	.MACRO __DELAY_USW
	LDI  R24,LOW(@0)
	LDI  R25,HIGH(@0)
__DELAY_USW_LOOP:
	SBIW R24,1
	BRNE __DELAY_USW_LOOP
	.ENDM

	.MACRO __GETD1S
	LDD  R30,Y+@0
	LDD  R31,Y+@0+1
	LDD  R22,Y+@0+2
	LDD  R23,Y+@0+3
	.ENDM

	.MACRO __GETD2S
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	LDD  R24,Y+@0+2
	LDD  R25,Y+@0+3
	.ENDM

	.MACRO __PUTD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R31
	STD  Y+@0+2,R22
	STD  Y+@0+3,R23
	.ENDM

	.MACRO __PUTD2S
	STD  Y+@0,R26
	STD  Y+@0+1,R27
	STD  Y+@0+2,R24
	STD  Y+@0+3,R25
	.ENDM

	.MACRO __PUTDZ2
	STD  Z+@0,R26
	STD  Z+@0+1,R27
	STD  Z+@0+2,R24
	STD  Z+@0+3,R25
	.ENDM

	.MACRO __CLRD1S
	STD  Y+@0,R30
	STD  Y+@0+1,R30
	STD  Y+@0+2,R30
	STD  Y+@0+3,R30
	.ENDM

	.MACRO __POINTB1MN
	LDI  R30,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW1MN
	LDI  R30,LOW(@0+(@1))
	LDI  R31,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD1M
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __POINTW1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	LDI  R22,BYTE3(2*@0+(@1))
	LDI  R23,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTB2MN
	LDI  R26,LOW(@0+(@1))
	.ENDM

	.MACRO __POINTW2MN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	.ENDM

	.MACRO __POINTD2M
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __POINTW2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	.ENDM

	.MACRO __POINTD2FN
	LDI  R26,LOW(2*@0+(@1))
	LDI  R27,HIGH(2*@0+(@1))
	LDI  R24,BYTE3(2*@0+(@1))
	LDI  R25,BYTE4(2*@0+(@1))
	.ENDM

	.MACRO __POINTBRM
	LDI  R@0,LOW(@1)
	.ENDM

	.MACRO __POINTWRM
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __POINTBRMN
	LDI  R@0,LOW(@1+(@2))
	.ENDM

	.MACRO __POINTWRMN
	LDI  R@0,LOW(@2+(@3))
	LDI  R@1,HIGH(@2+(@3))
	.ENDM

	.MACRO __POINTWRFN
	LDI  R@0,LOW(@2*2+(@3))
	LDI  R@1,HIGH(@2*2+(@3))
	.ENDM

	.MACRO __GETD1N
	LDI  R30,LOW(@0)
	LDI  R31,HIGH(@0)
	LDI  R22,BYTE3(@0)
	LDI  R23,BYTE4(@0)
	.ENDM

	.MACRO __GETD2N
	LDI  R26,LOW(@0)
	LDI  R27,HIGH(@0)
	LDI  R24,BYTE3(@0)
	LDI  R25,BYTE4(@0)
	.ENDM

	.MACRO __GETB1MN
	LDS  R30,@0+(@1)
	.ENDM

	.MACRO __GETB1HMN
	LDS  R31,@0+(@1)
	.ENDM

	.MACRO __GETW1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	.ENDM

	.MACRO __GETD1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	LDS  R22,@0+(@1)+2
	LDS  R23,@0+(@1)+3
	.ENDM

	.MACRO __GETBRMN
	LDS  R@0,@1+(@2)
	.ENDM

	.MACRO __GETWRMN
	LDS  R@0,@2+(@3)
	LDS  R@1,@2+(@3)+1
	.ENDM

	.MACRO __GETWRZ
	LDD  R@0,Z+@2
	LDD  R@1,Z+@2+1
	.ENDM

	.MACRO __GETD2Z
	LDD  R26,Z+@0
	LDD  R27,Z+@0+1
	LDD  R24,Z+@0+2
	LDD  R25,Z+@0+3
	.ENDM

	.MACRO __GETB2MN
	LDS  R26,@0+(@1)
	.ENDM

	.MACRO __GETW2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	.ENDM

	.MACRO __GETD2MN
	LDS  R26,@0+(@1)
	LDS  R27,@0+(@1)+1
	LDS  R24,@0+(@1)+2
	LDS  R25,@0+(@1)+3
	.ENDM

	.MACRO __PUTB1MN
	STS  @0+(@1),R30
	.ENDM

	.MACRO __PUTW1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	.ENDM

	.MACRO __PUTD1MN
	STS  @0+(@1),R30
	STS  @0+(@1)+1,R31
	STS  @0+(@1)+2,R22
	STS  @0+(@1)+3,R23
	.ENDM

	.MACRO __PUTB1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRB
	.ENDM

	.MACRO __PUTW1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRW
	.ENDM

	.MACRO __PUTD1EN
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMWRD
	.ENDM

	.MACRO __PUTBR0MN
	STS  @0+(@1),R0
	.ENDM

	.MACRO __PUTBMRN
	STS  @0+(@1),R@2
	.ENDM

	.MACRO __PUTWMRN
	STS  @0+(@1),R@2
	STS  @0+(@1)+1,R@3
	.ENDM

	.MACRO __PUTBZR
	STD  Z+@1,R@0
	.ENDM

	.MACRO __PUTWZR
	STD  Z+@2,R@0
	STD  Z+@2+1,R@1
	.ENDM

	.MACRO __GETW1R
	MOV  R30,R@0
	MOV  R31,R@1
	.ENDM

	.MACRO __GETW2R
	MOV  R26,R@0
	MOV  R27,R@1
	.ENDM

	.MACRO __GETWRN
	LDI  R@0,LOW(@2)
	LDI  R@1,HIGH(@2)
	.ENDM

	.MACRO __PUTW1R
	MOV  R@0,R30
	MOV  R@1,R31
	.ENDM

	.MACRO __PUTW2R
	MOV  R@0,R26
	MOV  R@1,R27
	.ENDM

	.MACRO __ADDWRN
	SUBI R@0,LOW(-@2)
	SBCI R@1,HIGH(-@2)
	.ENDM

	.MACRO __ADDWRR
	ADD  R@0,R@2
	ADC  R@1,R@3
	.ENDM

	.MACRO __SUBWRN
	SUBI R@0,LOW(@2)
	SBCI R@1,HIGH(@2)
	.ENDM

	.MACRO __SUBWRR
	SUB  R@0,R@2
	SBC  R@1,R@3
	.ENDM

	.MACRO __ANDWRN
	ANDI R@0,LOW(@2)
	ANDI R@1,HIGH(@2)
	.ENDM

	.MACRO __ANDWRR
	AND  R@0,R@2
	AND  R@1,R@3
	.ENDM

	.MACRO __ORWRN
	ORI  R@0,LOW(@2)
	ORI  R@1,HIGH(@2)
	.ENDM

	.MACRO __ORWRR
	OR   R@0,R@2
	OR   R@1,R@3
	.ENDM

	.MACRO __EORWRR
	EOR  R@0,R@2
	EOR  R@1,R@3
	.ENDM

	.MACRO __GETWRS
	LDD  R@0,Y+@2
	LDD  R@1,Y+@2+1
	.ENDM

	.MACRO __PUTBSR
	STD  Y+@1,R@0
	.ENDM

	.MACRO __PUTWSR
	STD  Y+@2,R@0
	STD  Y+@2+1,R@1
	.ENDM

	.MACRO __MOVEWRR
	MOV  R@0,R@2
	MOV  R@1,R@3
	.ENDM

	.MACRO __INWR
	IN   R@0,@2
	IN   R@1,@2+1
	.ENDM

	.MACRO __OUTWR
	OUT  @2+1,R@1
	OUT  @2,R@0
	.ENDM

	.MACRO __CALL1MN
	LDS  R30,@0+(@1)
	LDS  R31,@0+(@1)+1
	ICALL
	.ENDM

	.MACRO __CALL1FN
	LDI  R30,LOW(2*@0+(@1))
	LDI  R31,HIGH(2*@0+(@1))
	CALL __GETW1PF
	ICALL
	.ENDM

	.MACRO __CALL2EN
	PUSH R26
	PUSH R27
	LDI  R26,LOW(@0+(@1))
	LDI  R27,HIGH(@0+(@1))
	CALL __EEPROMRDW
	POP  R27
	POP  R26
	ICALL
	.ENDM

	.MACRO __CALL2EX
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	CALL __EEPROMRDD
	ICALL
	.ENDM

	.MACRO __GETW1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R31,Z
	MOV  R30,R0
	.ENDM

	.MACRO __GETD1STACK
	IN   R30,SPL
	IN   R31,SPH
	ADIW R30,@0+1
	LD   R0,Z+
	LD   R1,Z+
	LD   R22,Z
	MOVW R30,R0
	.ENDM

	.MACRO __NBST
	BST  R@0,@1
	IN   R30,SREG
	LDI  R31,0x40
	EOR  R30,R31
	OUT  SREG,R30
	.ENDM


	.MACRO __PUTB1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SN
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNS
	LDD  R26,Y+@0
	LDD  R27,Y+@0+1
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMN
	LDS  R26,@0
	LDS  R27,@0+1
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1PMNS
	LDS  R26,@0
	LDS  R27,@0+1
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RN
	MOVW R26,R@0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RNS
	MOVW R26,R@0
	ADIW R26,@1
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RNS
	MOVW R26,R@0
	ADIW R26,@1
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RON
	MOV  R26,R@0
	MOV  R27,R@1
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	CALL __PUTDP1
	.ENDM

	.MACRO __PUTB1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X,R30
	.ENDM

	.MACRO __PUTW1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1RONS
	MOV  R26,R@0
	MOV  R27,R@1
	ADIW R26,@2
	CALL __PUTDP1
	.ENDM


	.MACRO __GETB1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R30,Z
	.ENDM

	.MACRO __GETB1HSX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	.ENDM

	.MACRO __GETW1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	CALL __GETW1Z
	.ENDM

	.MACRO __GETD1SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	CALL __GETD1Z
	.ENDM

	.MACRO __GETB2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R26,X
	.ENDM

	.MACRO __GETW2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	CALL __GETW2X
	.ENDM

	.MACRO __GETD2SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	CALL __GETD2X
	.ENDM

	.MACRO __GETBRSX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	LD   R@0,Z
	.ENDM

	.MACRO __GETWRSX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	LD   R@0,Z+
	LD   R@1,Z
	.ENDM

	.MACRO __GETBRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	LD   R@0,X
	.ENDM

	.MACRO __GETWRSX2
	MOVW R26,R28
	SUBI R26,LOW(-@2)
	SBCI R27,HIGH(-@2)
	LD   R@0,X+
	LD   R@1,X
	.ENDM

	.MACRO __LSLW8SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	LD   R31,Z
	CLR  R30
	.ENDM

	.MACRO __PUTB1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __CLRW1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __CLRD1SX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	ST   X+,R30
	ST   X+,R30
	ST   X+,R30
	ST   X,R30
	.ENDM

	.MACRO __PUTB2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z,R26
	.ENDM

	.MACRO __PUTW2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z,R27
	.ENDM

	.MACRO __PUTD2SX
	MOVW R30,R28
	SUBI R30,LOW(-@0)
	SBCI R31,HIGH(-@0)
	ST   Z+,R26
	ST   Z+,R27
	ST   Z+,R24
	ST   Z,R25
	.ENDM

	.MACRO __PUTBSRX
	MOVW R30,R28
	SUBI R30,LOW(-@1)
	SBCI R31,HIGH(-@1)
	ST   Z,R@0
	.ENDM

	.MACRO __PUTWSRX
	MOVW R30,R28
	SUBI R30,LOW(-@2)
	SBCI R31,HIGH(-@2)
	ST   Z+,R@0
	ST   Z,R@1
	.ENDM

	.MACRO __PUTB1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X,R30
	.ENDM

	.MACRO __PUTW1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X,R31
	.ENDM

	.MACRO __PUTD1SNX
	MOVW R26,R28
	SUBI R26,LOW(-@0)
	SBCI R27,HIGH(-@0)
	LD   R0,X+
	LD   R27,X
	MOV  R26,R0
	SUBI R26,LOW(-@1)
	SBCI R27,HIGH(-@1)
	ST   X+,R30
	ST   X+,R31
	ST   X+,R22
	ST   X,R23
	.ENDM

	.MACRO __MULBRR
	MULS R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRRU
	MUL  R@0,R@1
	MOVW R30,R0
	.ENDM

	.MACRO __MULBRR0
	MULS R@0,R@1
	.ENDM

	.MACRO __MULBRRU0
	MUL  R@0,R@1
	.ENDM

	.MACRO __MULBNWRU
	LDI  R26,@2
	MUL  R26,R@0
	MOVW R30,R0
	MUL  R26,R@1
	ADD  R31,R0
	.ENDM

;NAME DEFINITIONS FOR GLOBAL VARIABLES ALLOCATED TO REGISTERS
	.DEF __lcd_x=R5
	.DEF __lcd_y=R4
	.DEF __lcd_maxx=R7

	.CSEG
	.ORG 0x00

;START OF CODE MARKER
__START_OF_CODE:

;INTERRUPT VECTORS
	JMP  __RESET
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00
	JMP  0x00

_TC_K_Table10C_G001:
	.DB  0xC6,0xE6,0xFF,0xFF,0xD7,0xE6,0xFF,0xFF
	.DB  0xFC,0xE6,0xFF,0xFF,0x38,0xE7,0xFF,0xFF
	.DB  0x8A,0xE7,0xFF,0xFF,0xF2,0xE7,0xFF,0xFF
	.DB  0x6D,0xE8,0xFF,0xFF,0xFD,0xE8,0xFF,0xFF
	.DB  0x9E,0xE9,0xFF,0xFF,0x52,0xEA,0xFF,0xFF
	.DB  0x16,0xEB,0xFF,0xFF,0xEB,0xEB,0xFF,0xFF
	.DB  0xCF,0xEC,0xFF,0xFF,0xC3,0xED,0xFF,0xFF
	.DB  0xC5,0xEE,0xFF,0xFF,0xD6,0xEF,0xFF,0xFF
	.DB  0xF4,0xF0,0xFF,0xFF,0x1E,0xF2,0xFF,0xFF
	.DB  0x55,0xF3,0xFF,0xFF,0x98,0xF4,0xFF,0xFF
	.DB  0xE5,0xF5,0xFF,0xFF,0x3D,0xF7,0xFF,0xFF
	.DB  0x9F,0xF8,0xFF,0xFF,0x9,0xFA,0xFF,0xFF
	.DB  0x7C,0xFB,0xFF,0xFF,0xF6,0xFC,0xFF,0xFF
	.DB  0x78,0xFE,0xFF,0xFF,0x0,0x0,0x0,0x0
	.DB  0x8D,0x1,0x0,0x0,0x1E,0x3,0x0,0x0
	.DB  0xB3,0x4,0x0,0x0,0x4C,0x6,0x0,0x0
	.DB  0xE7,0x7,0x0,0x0,0x84,0x9,0x0,0x0
	.DB  0x23,0xB,0x0,0x0,0xC3,0xC,0x0,0x0
	.DB  0x62,0xE,0x0,0x0,0x0,0x10,0x0,0x0
	.DB  0x9D,0x11,0x0,0x0,0x38,0x13,0x0,0x0
	.DB  0xD0,0x14,0x0,0x0,0x67,0x16,0x0,0x0
	.DB  0xFA,0x17,0x0,0x0,0x8C,0x19,0x0,0x0
	.DB  0x1D,0x1B,0x0,0x0,0xAC,0x1C,0x0,0x0
	.DB  0x3B,0x1E,0x0,0x0,0xCA,0x1F,0x0,0x0
	.DB  0x5B,0x21,0x0,0x0,0xEC,0x22,0x0,0x0
	.DB  0x7F,0x24,0x0,0x0,0x13,0x26,0x0,0x0
	.DB  0xA9,0x27,0x0,0x0,0x41,0x29,0x0,0x0
	.DB  0xDB,0x2A,0x0,0x0,0x76,0x2C,0x0,0x0
	.DB  0x13,0x2E,0x0,0x0,0xB1,0x2F,0x0,0x0
	.DB  0x50,0x31,0x0,0x0,0xF0,0x32,0x0,0x0
	.DB  0x91,0x34,0x0,0x0,0x32,0x36,0x0,0x0
	.DB  0xD5,0x37,0x0,0x0,0x79,0x39,0x0,0x0
	.DB  0x1D,0x3B,0x0,0x0,0xC2,0x3C,0x0,0x0
	.DB  0x67,0x3E,0x0,0x0,0xD,0x40,0x0,0x0
	.DB  0xB4,0x41,0x0,0x0,0x5B,0x43,0x0,0x0
	.DB  0x3,0x45,0x0,0x0,0xAB,0x46,0x0,0x0
	.DB  0x54,0x48,0x0,0x0,0xFD,0x49,0x0,0x0
	.DB  0xA6,0x4B,0x0,0x0,0x50,0x4D,0x0,0x0
	.DB  0xFA,0x4E,0x0,0x0,0xA4,0x50,0x0,0x0
	.DB  0x4F,0x52,0x0,0x0,0xF9,0x53,0x0,0x0
	.DB  0xA4,0x55,0x0,0x0,0x4E,0x57,0x0,0x0
	.DB  0xF8,0x58,0x0,0x0,0xA3,0x5A,0x0,0x0
	.DB  0x4D,0x5C,0x0,0x0,0xF7,0x5D,0x0,0x0
	.DB  0xA0,0x5F,0x0,0x0,0x49,0x61,0x0,0x0
	.DB  0xF2,0x62,0x0,0x0,0x9B,0x64,0x0,0x0
	.DB  0x43,0x66,0x0,0x0,0xEA,0x67,0x0,0x0
	.DB  0x91,0x69,0x0,0x0,0x37,0x6B,0x0,0x0
	.DB  0xDD,0x6C,0x0,0x0,0x81,0x6E,0x0,0x0
	.DB  0x26,0x70,0x0,0x0,0xC9,0x71,0x0,0x0
	.DB  0x6C,0x73,0x0,0x0,0xD,0x75,0x0,0x0
	.DB  0xAE,0x76,0x0,0x0,0x4E,0x78,0x0,0x0
	.DB  0xED,0x79,0x0,0x0,0x8C,0x7B,0x0,0x0
	.DB  0x29,0x7D,0x0,0x0,0xC5,0x7E,0x0,0x0
	.DB  0x61,0x80,0x0,0x0,0xFB,0x81,0x0,0x0
	.DB  0x95,0x83,0x0,0x0,0x2D,0x85,0x0,0x0
	.DB  0xC5,0x86,0x0,0x0,0x5C,0x88,0x0,0x0
	.DB  0xF1,0x89,0x0,0x0,0x86,0x8B,0x0,0x0
	.DB  0x19,0x8D,0x0,0x0,0xAC,0x8E,0x0,0x0
	.DB  0x3D,0x90,0x0,0x0,0xCE,0x91,0x0,0x0
	.DB  0x5D,0x93,0x0,0x0,0xEC,0x94,0x0,0x0
	.DB  0x7A,0x96,0x0,0x0,0x6,0x98,0x0,0x0
	.DB  0x92,0x99,0x0,0x0,0x1C,0x9B,0x0,0x0
	.DB  0xA5,0x9C,0x0,0x0,0x2E,0x9E,0x0,0x0
	.DB  0xB5,0x9F,0x0,0x0,0x3C,0xA1,0x0,0x0
	.DB  0xC1,0xA2,0x0,0x0,0x45,0xA4,0x0,0x0
	.DB  0xC8,0xA5,0x0,0x0,0x4A,0xA7,0x0,0x0
	.DB  0xCB,0xA8,0x0,0x0,0x4B,0xAA,0x0,0x0
	.DB  0xCA,0xAB,0x0,0x0,0x47,0xAD,0x0,0x0
	.DB  0xC4,0xAE,0x0,0x0,0x3F,0xB0,0x0,0x0
	.DB  0xB9,0xB1,0x0,0x0,0x31,0xB3,0x0,0x0
	.DB  0xA9,0xB4,0x0,0x0,0x1F,0xB6,0x0,0x0
	.DB  0x93,0xB7,0x0,0x0,0x7,0xB9,0x0,0x0
	.DB  0x79,0xBA,0x0,0x0,0xE9,0xBB,0x0,0x0
	.DB  0x59,0xBD,0x0,0x0,0xC6,0xBE,0x0,0x0
	.DB  0x32,0xC0,0x0,0x0,0x9D,0xC1,0x0,0x0
	.DB  0x6,0xC3,0x0,0x0,0x6E,0xC4,0x0,0x0
	.DB  0xD4,0xC5,0x0,0x0,0x38,0xC7,0x0,0x0
	.DB  0x9B,0xC8,0x0,0x0,0xFC,0xC9,0x0,0x0
	.DB  0x5C,0xCB,0x0,0x0,0xBA,0xCC,0x0,0x0
	.DB  0x17,0xCE,0x0,0x0,0x72,0xCF,0x0,0x0
	.DB  0xCB,0xD0,0x0,0x0,0x23,0xD2,0x0,0x0
	.DB  0x7A,0xD3,0x0,0x0,0xCF,0xD4,0x0,0x0
	.DB  0x23,0xD6,0x0,0x0

_0x0:
	.DB  0x48,0x4A,0x28,0x75,0x56,0x29,0x3A,0x0
	.DB  0x20,0x20,0x0,0x54,0x65,0x6D,0x70,0x28
	.DB  0x43,0x29,0x3A,0x0
_0x20003:
	.DB  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	.DB  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
_0x2000A:
	.DB  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
	.DB  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
_0x2000060:
	.DB  0x1
_0x2000000:
	.DB  0x2D,0x4E,0x41,0x4E,0x0,0x49,0x4E,0x46
	.DB  0x0
_0x2020000:
	.DB  0x2D,0x4E,0x41,0x4E,0x0
_0x2040003:
	.DB  0x80,0xC0

__GLOBAL_INI_TBL:
	.DW  0x01
	.DW  __seed_G100
	.DW  _0x2000060*2

	.DW  0x02
	.DW  __base_y_G102
	.DW  _0x2040003*2

_0xFFFFFFFF:
	.DW  0

#define __GLOBAL_INI_TBL_PRESENT 1

__RESET:
	CLI
	CLR  R30
	OUT  EECR,R30

;INTERRUPT VECTORS ARE PLACED
;AT THE START OF FLASH
	LDI  R31,1
	OUT  MCUCR,R31
	OUT  MCUCR,R30

;CLEAR R2-R14
	LDI  R24,(14-2)+1
	LDI  R26,2
	CLR  R27
__CLEAR_REG:
	ST   X+,R30
	DEC  R24
	BRNE __CLEAR_REG

;CLEAR SRAM
	LDI  R24,LOW(__CLEAR_SRAM_SIZE)
	LDI  R25,HIGH(__CLEAR_SRAM_SIZE)
	LDI  R26,__SRAM_START
__CLEAR_SRAM:
	ST   X+,R30
	SBIW R24,1
	BRNE __CLEAR_SRAM

;GLOBAL VARIABLES INITIALIZATION
	LDI  R30,LOW(__GLOBAL_INI_TBL*2)
	LDI  R31,HIGH(__GLOBAL_INI_TBL*2)
__GLOBAL_INI_NEXT:
	LPM  R24,Z+
	LPM  R25,Z+
	SBIW R24,0
	BREQ __GLOBAL_INI_END
	LPM  R26,Z+
	LPM  R27,Z+
	LPM  R0,Z+
	LPM  R1,Z+
	MOVW R22,R30
	MOVW R30,R0
__GLOBAL_INI_LOOP:
	LPM  R0,Z+
	ST   X+,R0
	SBIW R24,1
	BRNE __GLOBAL_INI_LOOP
	MOVW R30,R22
	RJMP __GLOBAL_INI_NEXT
__GLOBAL_INI_END:

;HARDWARE STACK POINTER INITIALIZATION
	LDI  R30,LOW(__SRAM_END-__HEAP_SIZE)
	OUT  SPL,R30
	LDI  R30,HIGH(__SRAM_END-__HEAP_SIZE)
	OUT  SPH,R30

;DATA STACK POINTER INITIALIZATION
	LDI  R28,LOW(__SRAM_START+__DSTACK_SIZE)
	LDI  R29,HIGH(__SRAM_START+__DSTACK_SIZE)

	JMP  _main

	.ESEG
	.ORG 0x00

	.DSEG
	.ORG 0x260

	.CSEG
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
;unsigned int read_adc(unsigned char adc_input){
; 0000 0014 unsigned int read_adc(unsigned char adc_input){

	.CSEG
_read_adc:
; .FSTART _read_adc
; 0000 0015 ADMUX=adc_input | ADC_VREF_TYPE;
	ST   -Y,R26
;	adc_input -> Y+0
	LD   R30,Y
	ORI  R30,0x40
	OUT  0x7,R30
; 0000 0016 // Delay needed for the stabilization of the ADC input voltage
; 0000 0017 delay_us(10);
	__DELAY_USB 3
; 0000 0018 // Start the AD conversion
; 0000 0019 ADCSRA|=(1<<ADSC);
	SBI  0x6,6
; 0000 001A // Wait for the AD conversion to complete
; 0000 001B while ((ADCSRA & (1<<ADIF))==0);
_0x3:
	SBIS 0x6,4
	RJMP _0x3
; 0000 001C ADCSRA|=(1<<ADIF);
	SBI  0x6,4
; 0000 001D return ADCW;
	IN   R30,0x4
	IN   R31,0x4+1
	JMP  _0x20C0001
; 0000 001E }
; .FEND
;void ADC_Init(void);
;void LCD_Config(void);
;void LCD_DisplayMainPage(int32_t uv, int16_t temp);
;void main(void){
; 0000 0026 void main(void){
_main:
; .FSTART _main
; 0000 0027 typedef struct{
; 0000 0028 int32_t tc_uv;      // measured thermocouple voltage (TC = HJ - CJ)
; 0000 0029 int32_t cj_uv;      // cold junction equivalent voltage
; 0000 002A int32_t hj_uv;      // hot junction equivalent voltage (HJ = TC + CJ)
; 0000 002B 
; 0000 002C int16_t cj_temp;
; 0000 002D int16_t hj_temp;
; 0000 002E } TC_K_t;
; 0000 002F 
; 0000 0030 TC_K_t oven;
; 0000 0031 
; 0000 0032 int16_t buf = 0;
; 0000 0033 int16_t buf_last = 0;
; 0000 0034 int32_t mv= 0;
; 0000 0035 
; 0000 0036 uint8_t lcd_flag = 0;
; 0000 0037 
; 0000 0038 LCD_Config();
	SBIW R28,20
	LDI  R30,LOW(0)
	ST   Y,R30
	STD  Y+1,R30
	STD  Y+2,R30
	STD  Y+3,R30
;	TC_K_t -> Y+20
;	oven -> Y+4
;	buf -> R16,R17
;	buf_last -> R18,R19
;	mv -> Y+0
;	lcd_flag -> R21
	__GETWRN 16,17,0
	__GETWRN 18,19,0
	LDI  R21,0
	RCALL _LCD_Config
; 0000 0039 ADC_Init();
	RCALL _ADC_Init
; 0000 003A 
; 0000 003B while (1){
_0x6:
; 0000 003C buf = read_adc(TC_CH);
	LDI  R26,LOW(0)
	RCALL _read_adc
	MOVW R16,R30
; 0000 003D if(buf != buf_last){
	__CPWRR 18,19,16,17
	BRNE PC+2
	RJMP _0x9
; 0000 003E buf_last = buf;
	MOVW R18,R16
; 0000 003F mv = ((uint32_t)buf * ADC_VREF) >> ADC_RESOLUTION_BIT;
	MOVW R26,R16
	CALL __CWD2
	__GETD1N 0x1388
	CALL __MULD12U
	MOVW R26,R30
	MOVW R24,R22
	LDI  R30,LOW(10)
	CALL __LSRD12
	CALL __PUTD1S0
; 0000 0040 oven.tc_uv = (mv * 1000) / TC_GAIN;
	__GETD2N 0x3E8
	CALL __MULD12
	MOVW R26,R30
	MOVW R24,R22
	__GETD1N 0x5A
	CALL __DIVD21
	__PUTD1S 4
; 0000 0041 oven.cj_temp = 50;  // Must be measured using a temperature sensor, for example  ...
	LDI  R30,LOW(50)
	LDI  R31,HIGH(50)
	STD  Y+16,R30
	STD  Y+16+1,R31
; 0000 0042 oven.cj_uv = TC_ConvertTempToMicroVolt(oven.cj_temp);
	LDD  R26,Y+16
	LDD  R27,Y+16+1
	RCALL _TC_ConvertTempToMicroVolt
	CALL SUBOPT_0x0
; 0000 0043 oven.hj_uv = oven.tc_uv + oven.cj_uv;
	CALL SUBOPT_0x1
	__GETD2S 4
	CALL __ADDD12
	__PUTD1S 12
; 0000 0044 oven.hj_temp = TC_ConvertMicroVoltToTemp(oven.hj_uv);
	__GETD2S 12
	RCALL _TC_ConvertMicroVoltToTemp
	STD  Y+18,R30
	STD  Y+18+1,R31
; 0000 0045 
; 0000 0046 lcd_flag = 1;
	LDI  R21,LOW(1)
; 0000 0047 }
; 0000 0048 
; 0000 0049 if(lcd_flag == 1){
_0x9:
	CPI  R21,1
	BRNE _0xA
; 0000 004A lcd_flag = 0;
	LDI  R21,LOW(0)
; 0000 004B LCD_DisplayMainPage(oven.hj_uv, oven.hj_temp);
	__GETD1S 12
	CALL __PUTPARD1
	LDD  R26,Y+22
	LDD  R27,Y+22+1
	RCALL _LCD_DisplayMainPage
; 0000 004C }
; 0000 004D }
_0xA:
	RJMP _0x6
; 0000 004E }
_0xB:
	RJMP _0xB
; .FEND
;void LCD_DisplayMainPage(int32_t uv, int16_t temp){
; 0000 0051 void LCD_DisplayMainPage(int32_t uv, int16_t temp){
_LCD_DisplayMainPage:
; .FSTART _LCD_DisplayMainPage
; 0000 0052 char txt[6];
; 0000 0053 
; 0000 0054 ltoa(uv, txt);
	ST   -Y,R27
	ST   -Y,R26
	SBIW R28,6
;	uv -> Y+8
;	temp -> Y+6
;	txt -> Y+0
	CALL SUBOPT_0x1
	CALL __PUTPARD1
	MOVW R26,R28
	ADIW R26,4
	CALL _ltoa
; 0000 0055 lcd_gotoxy(0,0);
	LDI  R30,LOW(0)
	ST   -Y,R30
	LDI  R26,LOW(0)
	CALL _lcd_gotoxy
; 0000 0056 lcd_putsf("HJ(uV):");   // hot junction
	__POINTW2FN _0x0,0
	CALL SUBOPT_0x2
; 0000 0057 lcd_puts(txt);
; 0000 0058 lcd_putsf("  ");
; 0000 0059 
; 0000 005A itoa(temp, txt);
	LDD  R30,Y+6
	LDD  R31,Y+6+1
	ST   -Y,R31
	ST   -Y,R30
	MOVW R26,R28
	ADIW R26,2
	CALL _itoa
; 0000 005B lcd_gotoxy(0,1);
	LDI  R30,LOW(0)
	ST   -Y,R30
	LDI  R26,LOW(1)
	CALL _lcd_gotoxy
; 0000 005C lcd_putsf("Temp(C):");
	__POINTW2FN _0x0,11
	CALL SUBOPT_0x2
; 0000 005D lcd_puts(txt);
; 0000 005E lcd_putsf("  ");
; 0000 005F }
	JMP  _0x20C0003
; .FEND
;void LCD_Config(void){
; 0000 0078 void LCD_Config(void){
_LCD_Config:
; .FSTART _LCD_Config
; 0000 0079 lcd_init(16);
	LDI  R26,LOW(16)
	CALL _lcd_init
; 0000 007A lcd_clear();
	CALL _lcd_clear
; 0000 007B }
	RET
; .FEND
;void ADC_Init(void){
; 0000 007E void ADC_Init(void){
_ADC_Init:
; .FSTART _ADC_Init
; 0000 007F // ADC initialization
; 0000 0080 // ADC Clock frequency: 125.000 kHz
; 0000 0081 // ADC Voltage Reference: AVCC pin
; 0000 0082 // ADC Auto Trigger Source: ADC Stopped
; 0000 0083 ADMUX=ADC_VREF_TYPE;
	LDI  R30,LOW(64)
	OUT  0x7,R30
; 0000 0084 ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | ...
	LDI  R30,LOW(134)
	OUT  0x6,R30
; 0000 0085 SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);
	LDI  R30,LOW(0)
	OUT  0x30,R30
; 0000 0086 }
	RET
; .FEND
;static const int32_t TC_K_Table10C[]={
;-6458, // -270^C
;-6441, // -260^C
;-6404, // -250^C
;-6344, // -240^C
;-6262, // -230^C
;-6158, // -220^C
;-6035, // -210^C
;-5891, // -200^C
;-5730, // -190^C
;-5550, // -180^C
;-5354, // -170^C
;-5141, // -160^C
;-4913, // -150^C
;-4669, // -140^C
;-4411, // -130^C
;-4138, // -120^C
;-3852, // -110^C
;-3554, // -100^C
;-3243, // -90^C
;-2920, // -80^C
;-2587, // -70^C
;-2243, // -60^C
;-1889, // -50^C
;-1527, // -40^C
;-1156, // -30^C
;-778,  // -20^C
;-392,  // -10^C
;0,     // 0^C
;397,   // 10^C
;798,   // 20^C
;1203,  // 30^C
;1612,  // 40^C
;2023,  // 50^C
;2436,  // 60^C
;2851,  // 70^C
;3267,  // 80^C
;3682,  // 90^C
;4096,  // 100^C
;4509,  // 110^C
;4920,  // 120^C
;5328,  // 130^C
;5735,  // 140^C
;6138,  // 150^C
;6540,  // 160^C
;6941,  // 170^C
;7340,  // 180^C
;7739,  // 190^C
;8138,  // 200^C
;8539,  // 210^C
;8940,  // 220^C
;9343,  // 230^C
;9747,  // 240^C
;10153, // 250^C
;10561, // 260^C
;10971, // 270^C
;11382, // 280^C
;11795, // 290^C
;12209, // 300^C
;12624, // 310^C
;13040, // 320^C
;13457, // 330^C
;13874, // 340^C
;14293, // 350^C
;14713, // 360^C
;15133, // 370^C
;15554, // 380^C
;15975, // 390^C
;16397, // 400^C
;16820, // 410^C
;17243, // 420^C
;17667, // 430^C
;18091, // 440^C
;18516, // 450^C
;18941, // 460^C
;19366, // 470^C
;19792, // 480^C
;20218, // 490^C
;20644, // 500^C
;21071, // 510^C
;21497, // 520^C
;21924, // 530^C
;22350, // 540^C
;22776, // 550^C
;23203, // 560^C
;23629, // 570^C
;24055, // 580^C
;24480, // 590^C
;24905, // 600^C
;25330, // 610^C
;25755, // 620^C
;26179, // 630^C
;26602, // 640^C
;27025, // 650^C
;27447, // 660^C
;27869, // 670^C
;28289, // 680^C
;28710, // 690^C
;29129, // 700^C
;29548, // 710^C
;29965, // 720^C
;30382, // 730^C
;30798, // 740^C
;31213, // 750^C
;31628, // 760^C
;32041, // 770^C
;32453, // 780^C
;32865, // 790^C
;33275, // 800^C
;33685, // 810^C
;34093, // 820^C
;34501, // 830^C
;34908, // 840^C
;35313, // 850^C
;35718, // 860^C
;36121, // 870^C
;36524, // 880^C
;36925, // 890^C
;37326, // 900^C
;37725, // 910^C
;38124, // 920^C
;38522, // 930^C
;38918, // 940^C
;39314, // 950^C
;39708, // 960^C
;40101, // 970^C
;40494, // 980^C
;40885, // 990^C
;41276, // 1000^C
;41665, // 1010^C
;42053, // 1020^C
;42440, // 1030^C
;42826, // 1040^C
;43211, // 1050^C
;43595, // 1060^C
;43978, // 1070^C
;44359, // 1080^C
;44740, // 1090^C
;45119, // 1100^C
;45497, // 1110^C
;45873, // 1120^C
;46249, // 1130^C
;46623, // 1140^C
;46995, // 1150^C
;47367, // 1160^C
;47737, // 1170^C
;48105, // 1180^C
;48473, // 1190^C
;48838, // 1200^C
;49202, // 1210^C
;49565, // 1220^C
;49926, // 1230^C
;50286, // 1240^C
;50644, // 1250^C
;51000, // 1260^C
;51355, // 1270^C
;51708, // 1280^C
;52060, // 1290^C
;52410, // 1300^C
;52759, // 1310^C
;53106, // 1320^C
;53451, // 1330^C
;53795, // 1340^C
;54138, // 1350^C
;54479, // 1360^C
;54819  // 1370^C
;};
;int16_t TC_ConvertMicroVoltToTemp(int32_t uv){
; 0001 00B0 int16_t TC_ConvertMicroVoltToTemp(int32_t uv){

	.CSEG
_TC_ConvertMicroVoltToTemp:
; .FSTART _TC_ConvertMicroVoltToTemp
; 0001 00B1 int16_t i = 0;
; 0001 00B2 int32_t uv0 = 0;
; 0001 00B3 int32_t uv1 = 0;
; 0001 00B4 int32_t t0 = 0;
; 0001 00B5 int32_t result = 0;
; 0001 00B6 
; 0001 00B7 if(uv <= TC_K_Table10C[0]){
	CALL __PUTPARD2
	SBIW R28,16
	LDI  R24,16
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	LDI  R30,LOW(_0x20003*2)
	LDI  R31,HIGH(_0x20003*2)
	CALL __INITLOCB
	ST   -Y,R17
	ST   -Y,R16
;	uv -> Y+18
;	i -> R16,R17
;	uv0 -> Y+14
;	uv1 -> Y+10
;	t0 -> Y+6
;	result -> Y+2
	__GETWRN 16,17,0
	LDI  R30,LOW(_TC_K_Table10C_G001*2)
	LDI  R31,HIGH(_TC_K_Table10C_G001*2)
	CALL SUBOPT_0x3
	CALL __CPD12
	BRLT _0x20004
; 0001 00B8 return TC_K_TEMP_MIN;
	LDI  R30,LOW(65266)
	LDI  R31,HIGH(65266)
	RJMP _0x20C0005
; 0001 00B9 }
; 0001 00BA 
; 0001 00BB if(uv >= TC_K_Table10C[TC_K_TABLE_SIZE-1]){
_0x20004:
	__POINTW1FN _TC_K_Table10C_G001,656
	CALL SUBOPT_0x3
	CALL __CPD21
	BRLT _0x20005
; 0001 00BC return TC_K_TEMP_MAX;
	LDI  R30,LOW(1370)
	LDI  R31,HIGH(1370)
	RJMP _0x20C0005
; 0001 00BD }
; 0001 00BE 
; 0001 00BF for(i = 0; i < (TC_K_TABLE_SIZE-1); i++){
_0x20005:
	__GETWRN 16,17,0
_0x20007:
	__CPWRN 16,17,164
	BRLT PC+2
	RJMP _0x20008
; 0001 00C0 if(uv < TC_K_Table10C[i+1]){
	CALL SUBOPT_0x4
	CALL SUBOPT_0x3
	CALL __CPD21
	BRLT PC+2
	RJMP _0x20009
; 0001 00C1 uv0 = TC_K_Table10C[i];
	CALL SUBOPT_0x5
	__PUTD1S 14
; 0001 00C2 uv1 = TC_K_Table10C[i+1];
	CALL SUBOPT_0x4
	CALL __GETD1PF
	__PUTD1S 10
; 0001 00C3 
; 0001 00C4 t0 = TC_K_TEMP_MIN + ((int32_t)i * 10);
	MOVW R26,R16
	CALL __CWD2
	CALL SUBOPT_0x6
	CALL __MULD12
	__ADDD1N -270
	__PUTD1S 6
; 0001 00C5 
; 0001 00C6 result = (t0 + (((uv - uv0) * 10) / (uv1 - uv0)));
	__GETD2S 14
	__GETD1S 18
	CALL __SUBD12
	__GETD2N 0xA
	CALL __MULD12
	PUSH R23
	PUSH R22
	PUSH R31
	PUSH R30
	__GETD2S 14
	__GETD1S 10
	CALL __SUBD12
	POP  R26
	POP  R27
	POP  R24
	POP  R25
	CALL __DIVD21
	__GETD2S 6
	CALL __ADDD12
	CALL SUBOPT_0x7
; 0001 00C7 return (int16_t)result;
	LDD  R30,Y+2
	LDD  R31,Y+2+1
	RJMP _0x20C0005
; 0001 00C8 }
; 0001 00C9 }
_0x20009:
	__ADDWRN 16,17,1
	RJMP _0x20007
_0x20008:
; 0001 00CA 
; 0001 00CB return TC_K_ERROR;
	LDI  R30,LOW(1371)
	LDI  R31,HIGH(1371)
_0x20C0005:
	LDD  R17,Y+1
	LDD  R16,Y+0
	ADIW R28,22
	RET
; 0001 00CC }
; .FEND
;int32_t TC_ConvertTempToMicroVolt(int16_t temp){
; 0001 00CF int32_t TC_ConvertTempToMicroVolt(int16_t temp){
_TC_ConvertTempToMicroVolt:
; .FSTART _TC_ConvertTempToMicroVolt
; 0001 00D0 int16_t index = 0;
; 0001 00D1 int16_t t0 = 0;
; 0001 00D2 int16_t dt = 0;
; 0001 00D3 int32_t uv0 = 0;
; 0001 00D4 int32_t uv1 = 0;
; 0001 00D5 int32_t duv = 0;
; 0001 00D6 int32_t result = 0;
; 0001 00D7 
; 0001 00D8 // Clamp temperature to table limits (-270°C to +1370°C)
; 0001 00D9 if (temp <= -270){
	ST   -Y,R27
	ST   -Y,R26
	SBIW R28,16
	LDI  R24,16
	LDI  R26,LOW(0)
	LDI  R27,HIGH(0)
	LDI  R30,LOW(_0x2000A*2)
	LDI  R31,HIGH(_0x2000A*2)
	CALL __INITLOCB
	CALL __SAVELOCR6
;	temp -> Y+22
;	index -> R16,R17
;	t0 -> R18,R19
;	dt -> R20,R21
;	uv0 -> Y+18
;	uv1 -> Y+14
;	duv -> Y+10
;	result -> Y+6
	__GETWRN 16,17,0
	__GETWRN 18,19,0
	__GETWRN 20,21,0
	LDD  R26,Y+22
	LDD  R27,Y+22+1
	LDI  R30,LOW(65266)
	LDI  R31,HIGH(65266)
	CP   R30,R26
	CPC  R31,R27
	BRLT _0x2000B
; 0001 00DA return TC_K_Table10C[0];
	LDI  R30,LOW(_TC_K_Table10C_G001*2)
	LDI  R31,HIGH(_TC_K_Table10C_G001*2)
	CALL __GETD1PF
	RJMP _0x20C0004
; 0001 00DB }
; 0001 00DC 
; 0001 00DD if (temp >= 1370){
_0x2000B:
	LDD  R26,Y+22
	LDD  R27,Y+22+1
	CPI  R26,LOW(0x55A)
	LDI  R30,HIGH(0x55A)
	CPC  R27,R30
	BRLT _0x2000C
; 0001 00DE return TC_K_Table10C[TC_K_TABLE_SIZE - 1];
	__POINTW1FN _TC_K_Table10C_G001,656
	CALL __GETD1PF
	RJMP _0x20C0004
; 0001 00DF }
; 0001 00E0 
; 0001 00E1 // Compute table index (each entry represents 10°C)
; 0001 00E2 index = (temp + 270) / 10;
_0x2000C:
	LDD  R26,Y+22
	LDD  R27,Y+22+1
	SUBI R26,LOW(-270)
	SBCI R27,HIGH(-270)
	LDI  R30,LOW(10)
	LDI  R31,HIGH(10)
	CALL __DIVW21
	MOVW R16,R30
; 0001 00E3 
; 0001 00E4 // Base temperature for this table cell
; 0001 00E5 t0 = (index * 10) - 270;
	LDI  R26,LOW(10)
	LDI  R27,HIGH(10)
	CALL __MULW12
	SUBI R30,LOW(270)
	SBCI R31,HIGH(270)
	MOVW R18,R30
; 0001 00E6 
; 0001 00E7 // Lookup microvolt values
; 0001 00E8 uv0 = TC_K_Table10C[index];       // µV at t0
	CALL SUBOPT_0x5
	__PUTD1S 18
; 0001 00E9 uv1 = TC_K_Table10C[index + 1];   // µV at t0 + 10°C
	CALL SUBOPT_0x4
	CALL __GETD1PF
	__PUTD1S 14
; 0001 00EA 
; 0001 00EB // If temperature exactly matches a 10°C grid point
; 0001 00EC if (temp == t0){
	LDD  R26,Y+22
	LDD  R27,Y+22+1
	CP   R18,R26
	CPC  R19,R27
	BRNE _0x2000D
; 0001 00ED return uv0;
	__GETD1S 18
	RJMP _0x20C0004
; 0001 00EE }
; 0001 00EF 
; 0001 00F0 // Linear interpolation (integer math, no floats)
; 0001 00F1 dt  = temp - t0;   // offset from base temperature (0..10)
_0x2000D:
	LDD  R30,Y+22
	LDD  R31,Y+22+1
	SUB  R30,R18
	SBC  R31,R19
	MOVW R20,R30
; 0001 00F2 duv = uv1 - uv0;   // delta µV between table entries
	__GETD2S 18
	__GETD1S 14
	CALL __SUBD12
	__PUTD1S 10
; 0001 00F3 
; 0001 00F4 // Return interpolated microvolt value
; 0001 00F5 result = uv0 + ((duv * dt) / 10);
	MOVW R30,R20
	__GETD2S 10
	CALL __CWD1
	CALL __MULD12
	MOVW R26,R30
	MOVW R24,R22
	CALL SUBOPT_0x6
	CALL __DIVD21
	__GETD2S 18
	CALL __ADDD12
	__PUTD1S 6
; 0001 00F6 return result;
_0x20C0004:
	CALL __LOADLOCR6
	ADIW R28,24
	RET
; 0001 00F7 }
; .FEND

	.CSEG
_itoa:
; .FSTART _itoa
	ST   -Y,R27
	ST   -Y,R26
    ld   r26,y+
    ld   r27,y+
    ld   r30,y+
    ld   r31,y+
    adiw r30,0
    brpl __itoa0
    com  r30
    com  r31
    adiw r30,1
    ldi  r22,'-'
    st   x+,r22
__itoa0:
    clt
    ldi  r24,low(10000)
    ldi  r25,high(10000)
    rcall __itoa1
    ldi  r24,low(1000)
    ldi  r25,high(1000)
    rcall __itoa1
    ldi  r24,100
    clr  r25
    rcall __itoa1
    ldi  r24,10
    rcall __itoa1
    mov  r22,r30
    rcall __itoa5
    clr  r22
    st   x,r22
    ret

__itoa1:
    clr	 r22
__itoa2:
    cp   r30,r24
    cpc  r31,r25
    brlo __itoa3
    inc  r22
    sub  r30,r24
    sbc  r31,r25
    brne __itoa2
__itoa3:
    tst  r22
    brne __itoa4
    brts __itoa5
    ret
__itoa4:
    set
__itoa5:
    subi r22,-0x30
    st   x+,r22
    ret
; .FEND
_ltoa:
; .FSTART _ltoa
	ST   -Y,R27
	ST   -Y,R26
	SBIW R28,4
	ST   -Y,R17
	ST   -Y,R16
	__GETD1N 0x3B9ACA00
	CALL SUBOPT_0x7
	LDI  R16,LOW(0)
	LDD  R26,Y+11
	TST  R26
	BRPL _0x2000003
	CALL SUBOPT_0x1
	CALL __ANEGD1
	CALL SUBOPT_0x0
	CALL SUBOPT_0x8
	LDI  R30,LOW(45)
	ST   X,R30
_0x2000003:
_0x2000005:
	CALL SUBOPT_0x9
	CALL __DIVD21U
	MOV  R17,R30
	CPI  R17,0
	BRNE _0x2000008
	CPI  R16,0
	BRNE _0x2000008
	__GETD2S 2
	__CPD2N 0x1
	BRNE _0x2000007
_0x2000008:
	CALL SUBOPT_0x8
	MOV  R30,R17
	SUBI R30,-LOW(48)
	ST   X,R30
	LDI  R16,LOW(1)
_0x2000007:
	CALL SUBOPT_0x9
	CALL __MODD21U
	CALL SUBOPT_0x0
	__GETD2S 2
	CALL SUBOPT_0x6
	CALL __DIVD21U
	CALL SUBOPT_0x7
	__GETD1S 2
	CALL __CPD10
	BRNE _0x2000005
	LDD  R26,Y+6
	LDD  R27,Y+6+1
	LDI  R30,LOW(0)
	ST   X,R30
	LDD  R17,Y+1
	LDD  R16,Y+0
_0x20C0003:
	ADIW R28,12
	RET
; .FEND

	.DSEG

	.CSEG
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif

	.CSEG
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif

	.DSEG

	.CSEG
__lcd_write_nibble_G102:
; .FSTART __lcd_write_nibble_G102
	ST   -Y,R26
	IN   R30,0x12
	ANDI R30,LOW(0xF)
	MOV  R26,R30
	LD   R30,Y
	ANDI R30,LOW(0xF0)
	OR   R30,R26
	OUT  0x12,R30
	__DELAY_USB 2
	SBI  0x12,2
	__DELAY_USB 2
	CBI  0x12,2
	__DELAY_USB 2
	RJMP _0x20C0001
; .FEND
__lcd_write_data:
; .FSTART __lcd_write_data
	ST   -Y,R26
	LD   R26,Y
	RCALL __lcd_write_nibble_G102
    ld    r30,y
    swap  r30
    st    y,r30
	LD   R26,Y
	RCALL __lcd_write_nibble_G102
	__DELAY_USB 17
	RJMP _0x20C0001
; .FEND
_lcd_gotoxy:
; .FSTART _lcd_gotoxy
	ST   -Y,R26
	LD   R30,Y
	LDI  R31,0
	SUBI R30,LOW(-__base_y_G102)
	SBCI R31,HIGH(-__base_y_G102)
	LD   R30,Z
	LDD  R26,Y+1
	ADD  R26,R30
	RCALL __lcd_write_data
	LDD  R5,Y+1
	LDD  R4,Y+0
	ADIW R28,2
	RET
; .FEND
_lcd_clear:
; .FSTART _lcd_clear
	LDI  R26,LOW(2)
	CALL SUBOPT_0xA
	LDI  R26,LOW(12)
	RCALL __lcd_write_data
	LDI  R26,LOW(1)
	CALL SUBOPT_0xA
	LDI  R30,LOW(0)
	MOV  R4,R30
	MOV  R5,R30
	RET
; .FEND
_lcd_putchar:
; .FSTART _lcd_putchar
	ST   -Y,R26
	LD   R26,Y
	CPI  R26,LOW(0xA)
	BREQ _0x2040005
	CP   R5,R7
	BRLO _0x2040004
_0x2040005:
	LDI  R30,LOW(0)
	ST   -Y,R30
	INC  R4
	MOV  R26,R4
	RCALL _lcd_gotoxy
	LD   R26,Y
	CPI  R26,LOW(0xA)
	BRNE _0x2040007
	RJMP _0x20C0001
_0x2040007:
_0x2040004:
	INC  R5
	SBI  0x12,0
	LD   R26,Y
	RCALL __lcd_write_data
	CBI  0x12,0
	RJMP _0x20C0001
; .FEND
_lcd_puts:
; .FSTART _lcd_puts
	ST   -Y,R27
	ST   -Y,R26
	ST   -Y,R17
_0x2040008:
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R30,X+
	STD  Y+1,R26
	STD  Y+1+1,R27
	MOV  R17,R30
	CPI  R30,0
	BREQ _0x204000A
	MOV  R26,R17
	RCALL _lcd_putchar
	RJMP _0x2040008
_0x204000A:
	RJMP _0x20C0002
; .FEND
_lcd_putsf:
; .FSTART _lcd_putsf
	ST   -Y,R27
	ST   -Y,R26
	ST   -Y,R17
_0x204000B:
	LDD  R30,Y+1
	LDD  R31,Y+1+1
	ADIW R30,1
	STD  Y+1,R30
	STD  Y+1+1,R31
	SBIW R30,1
	LPM  R30,Z
	MOV  R17,R30
	CPI  R30,0
	BREQ _0x204000D
	MOV  R26,R17
	RCALL _lcd_putchar
	RJMP _0x204000B
_0x204000D:
_0x20C0002:
	LDD  R17,Y+0
	ADIW R28,3
	RET
; .FEND
_lcd_init:
; .FSTART _lcd_init
	ST   -Y,R26
	IN   R30,0x11
	ORI  R30,LOW(0xF0)
	OUT  0x11,R30
	SBI  0x11,2
	SBI  0x11,0
	SBI  0x11,1
	CBI  0x12,2
	CBI  0x12,0
	CBI  0x12,1
	LDD  R7,Y+0
	LD   R30,Y
	SUBI R30,-LOW(128)
	__PUTB1MN __base_y_G102,2
	LD   R30,Y
	SUBI R30,-LOW(192)
	__PUTB1MN __base_y_G102,3
	LDI  R26,LOW(20)
	LDI  R27,0
	CALL _delay_ms
	CALL SUBOPT_0xB
	CALL SUBOPT_0xB
	CALL SUBOPT_0xB
	LDI  R26,LOW(32)
	RCALL __lcd_write_nibble_G102
	__DELAY_USB 33
	LDI  R26,LOW(40)
	RCALL __lcd_write_data
	LDI  R26,LOW(4)
	RCALL __lcd_write_data
	LDI  R26,LOW(133)
	RCALL __lcd_write_data
	LDI  R26,LOW(6)
	RCALL __lcd_write_data
	RCALL _lcd_clear
_0x20C0001:
	ADIW R28,1
	RET
; .FEND

	.CSEG

	.CSEG

	.CSEG

	.DSEG
__seed_G100:
	.BYTE 0x4
__base_y_G102:
	.BYTE 0x4

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x0:
	__PUTD1S 8
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x1:
	__GETD1S 8
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0x2:
	CALL _lcd_putsf
	MOVW R26,R28
	CALL _lcd_puts
	__POINTW2FN _0x0,8
	JMP  _lcd_putsf

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0x3:
	CALL __GETD1PF
	__GETD2S 18
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0x4:
	MOVW R30,R16
	CALL __LSLW2
	__ADDW1FN _TC_K_Table10C_G001,4
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:4 WORDS
SUBOPT_0x5:
	MOVW R30,R16
	LDI  R26,LOW(_TC_K_Table10C_G001*2)
	LDI  R27,HIGH(_TC_K_Table10C_G001*2)
	CALL __LSLW2
	ADD  R30,R26
	ADC  R31,R27
	CALL __GETD1PF
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x6:
	__GETD1N 0xA
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x7:
	__PUTD1S 2
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x8:
	LDD  R26,Y+6
	LDD  R27,Y+6+1
	ADIW R26,1
	STD  Y+6,R26
	STD  Y+6+1,R27
	SBIW R26,1
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0x9:
	__GETD1S 2
	__GETD2S 8
	RET

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0xA:
	CALL __lcd_write_data
	LDI  R26,LOW(3)
	LDI  R27,0
	JMP  _delay_ms

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:5 WORDS
SUBOPT_0xB:
	LDI  R26,LOW(48)
	CALL __lcd_write_nibble_G102
	__DELAY_USB 33
	RET

;RUNTIME LIBRARY

	.CSEG
__SAVELOCR6:
	ST   -Y,R21
__SAVELOCR5:
	ST   -Y,R20
__SAVELOCR4:
	ST   -Y,R19
__SAVELOCR3:
	ST   -Y,R18
__SAVELOCR2:
	ST   -Y,R17
	ST   -Y,R16
	RET

__LOADLOCR6:
	LDD  R21,Y+5
__LOADLOCR5:
	LDD  R20,Y+4
__LOADLOCR4:
	LDD  R19,Y+3
__LOADLOCR3:
	LDD  R18,Y+2
__LOADLOCR2:
	LDD  R17,Y+1
	LD   R16,Y
	RET

__INITLOCB:
__INITLOCW:
	ADD  R26,R28
	ADC  R27,R29
__INITLOC0:
	LPM  R0,Z+
	ST   X+,R0
	DEC  R24
	BRNE __INITLOC0
	RET

__ADDD12:
	ADD  R30,R26
	ADC  R31,R27
	ADC  R22,R24
	ADC  R23,R25
	RET

__SUBD12:
	SUB  R30,R26
	SBC  R31,R27
	SBC  R22,R24
	SBC  R23,R25
	RET

__ANEGW1:
	NEG  R31
	NEG  R30
	SBCI R31,0
	RET

__ANEGD1:
	COM  R31
	COM  R22
	COM  R23
	NEG  R30
	SBCI R31,-1
	SBCI R22,-1
	SBCI R23,-1
	RET

__ANEGD2:
	COM  R27
	COM  R24
	COM  R25
	NEG  R26
	SBCI R27,-1
	SBCI R24,-1
	SBCI R25,-1
	RET

__LSRD12:
	TST  R30
	MOV  R0,R30
	LDI  R30,8
	MOV  R1,R30
	MOVW R30,R26
	MOVW R22,R24
	BREQ __LSRD12R
__LSRD12S8:
	CP   R0,R1
	BRLO __LSRD12L
	MOV  R30,R31
	MOV  R31,R22
	MOV  R22,R23
	LDI  R23,0
	SUB  R0,R1
	BRNE __LSRD12S8
	RET
__LSRD12L:
	LSR  R23
	ROR  R22
	ROR  R31
	ROR  R30
	DEC  R0
	BRNE __LSRD12L
__LSRD12R:
	RET

__LSLW2:
	LSL  R30
	ROL  R31
	LSL  R30
	ROL  R31
	RET

__CWD1:
	MOV  R22,R31
	ADD  R22,R22
	SBC  R22,R22
	MOV  R23,R22
	RET

__CWD2:
	MOV  R24,R27
	ADD  R24,R24
	SBC  R24,R24
	MOV  R25,R24
	RET

__MULW12U:
	MUL  R31,R26
	MOV  R31,R0
	MUL  R30,R27
	ADD  R31,R0
	MUL  R30,R26
	MOV  R30,R0
	ADD  R31,R1
	RET

__MULD12U:
	MUL  R23,R26
	MOV  R23,R0
	MUL  R22,R27
	ADD  R23,R0
	MUL  R31,R24
	ADD  R23,R0
	MUL  R30,R25
	ADD  R23,R0
	MUL  R22,R26
	MOV  R22,R0
	ADD  R23,R1
	MUL  R31,R27
	ADD  R22,R0
	ADC  R23,R1
	MUL  R30,R24
	ADD  R22,R0
	ADC  R23,R1
	CLR  R24
	MUL  R31,R26
	MOV  R31,R0
	ADD  R22,R1
	ADC  R23,R24
	MUL  R30,R27
	ADD  R31,R0
	ADC  R22,R1
	ADC  R23,R24
	MUL  R30,R26
	MOV  R30,R0
	ADD  R31,R1
	ADC  R22,R24
	ADC  R23,R24
	RET

__MULW12:
	RCALL __CHKSIGNW
	RCALL __MULW12U
	BRTC __MULW121
	RCALL __ANEGW1
__MULW121:
	RET

__MULD12:
	RCALL __CHKSIGND
	RCALL __MULD12U
	BRTC __MULD121
	RCALL __ANEGD1
__MULD121:
	RET

__DIVW21U:
	CLR  R0
	CLR  R1
	LDI  R25,16
__DIVW21U1:
	LSL  R26
	ROL  R27
	ROL  R0
	ROL  R1
	SUB  R0,R30
	SBC  R1,R31
	BRCC __DIVW21U2
	ADD  R0,R30
	ADC  R1,R31
	RJMP __DIVW21U3
__DIVW21U2:
	SBR  R26,1
__DIVW21U3:
	DEC  R25
	BRNE __DIVW21U1
	MOVW R30,R26
	MOVW R26,R0
	RET

__DIVW21:
	RCALL __CHKSIGNW
	RCALL __DIVW21U
	BRTC __DIVW211
	RCALL __ANEGW1
__DIVW211:
	RET

__DIVD21U:
	PUSH R19
	PUSH R20
	PUSH R21
	CLR  R0
	CLR  R1
	MOVW R20,R0
	LDI  R19,32
__DIVD21U1:
	LSL  R26
	ROL  R27
	ROL  R24
	ROL  R25
	ROL  R0
	ROL  R1
	ROL  R20
	ROL  R21
	SUB  R0,R30
	SBC  R1,R31
	SBC  R20,R22
	SBC  R21,R23
	BRCC __DIVD21U2
	ADD  R0,R30
	ADC  R1,R31
	ADC  R20,R22
	ADC  R21,R23
	RJMP __DIVD21U3
__DIVD21U2:
	SBR  R26,1
__DIVD21U3:
	DEC  R19
	BRNE __DIVD21U1
	MOVW R30,R26
	MOVW R22,R24
	MOVW R26,R0
	MOVW R24,R20
	POP  R21
	POP  R20
	POP  R19
	RET

__DIVD21:
	RCALL __CHKSIGND
	RCALL __DIVD21U
	BRTC __DIVD211
	RCALL __ANEGD1
__DIVD211:
	RET

__MODD21U:
	RCALL __DIVD21U
	MOVW R30,R26
	MOVW R22,R24
	RET

__CHKSIGNW:
	CLT
	SBRS R31,7
	RJMP __CHKSW1
	RCALL __ANEGW1
	SET
__CHKSW1:
	SBRS R27,7
	RJMP __CHKSW2
	NEG  R27
	NEG  R26
	SBCI R27,0
	BLD  R0,0
	INC  R0
	BST  R0,0
__CHKSW2:
	RET

__CHKSIGND:
	CLT
	SBRS R23,7
	RJMP __CHKSD1
	RCALL __ANEGD1
	SET
__CHKSD1:
	SBRS R25,7
	RJMP __CHKSD2
	RCALL __ANEGD2
	BLD  R0,0
	INC  R0
	BST  R0,0
__CHKSD2:
	RET

__GETD1PF:
	LPM  R0,Z+
	LPM  R1,Z+
	LPM  R22,Z+
	LPM  R23,Z
	MOVW R30,R0
	RET

__PUTD1S0:
	ST   Y,R30
	STD  Y+1,R31
	STD  Y+2,R22
	STD  Y+3,R23
	RET

__PUTPARD1:
	ST   -Y,R23
	ST   -Y,R22
	ST   -Y,R31
	ST   -Y,R30
	RET

__PUTPARD2:
	ST   -Y,R25
	ST   -Y,R24
	ST   -Y,R27
	ST   -Y,R26
	RET

__CPD10:
	SBIW R30,0
	SBCI R22,0
	SBCI R23,0
	RET

__CPD12:
	CP   R30,R26
	CPC  R31,R27
	CPC  R22,R24
	CPC  R23,R25
	RET

__CPD21:
	CP   R26,R30
	CPC  R27,R31
	CPC  R24,R22
	CPC  R25,R23
	RET

_delay_ms:
	adiw r26,0
	breq __delay_ms1
__delay_ms0:
	wdr
	__DELAY_USW 0xFA
	sbiw r26,1
	brne __delay_ms0
__delay_ms1:
	ret

;END OF CODE MARKER
__END_OF_CODE:
