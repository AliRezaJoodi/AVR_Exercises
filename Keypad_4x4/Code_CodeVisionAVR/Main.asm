
;CodeVisionAVR C Compiler V3.40 Advanced
;(C) Copyright 1998-2020 Pavel Haiduc, HP InfoTech S.R.L.
;http://www.hpinfotech.ro

;Build configuration    : Release
;Chip type              : ATmega32A
;Program type           : Application
;Clock frequency        : 8.000000 MHz
;Memory model           : Small
;Optimize for           : Size
;(s)printf features     : int, width
;(s)scanf features      : int, width
;External RAM size      : 0
;Data Stack size        : 512 byte(s)
;Heap size              : 0 byte(s)
;Promote 'char' to 'int': No
;'char' is unsigned     : Yes
;8 bit enums            : No
;Global 'const' stored in FLASH: No
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
	.DEF _numer=R5
	.DEF __lcd_x=R4
	.DEF __lcd_y=R7
	.DEF __lcd_maxx=R6

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

_tbl10_G105:
	.DB  0x10,0x27,0xE8,0x3,0x64,0x0,0xA,0x0
	.DB  0x1,0x0
_tbl16_G105:
	.DB  0x0,0x10,0x0,0x1,0x10,0x0,0x1,0x0

_0x0:
	.DB  0x20,0x20,0x0,0x34,0x78,0x34,0x20,0x4B
	.DB  0x65,0x79,0x70,0x61,0x64,0x0,0x34,0x78
	.DB  0x34,0x4B,0x65,0x79,0x70,0x61,0x64,0x20
	.DB  0x44,0x72,0x69,0x76,0x65,0x72,0x0,0x4C
	.DB  0x6F,0x61,0x64,0x69,0x6E,0x67,0x20,0x2E
	.DB  0x2E,0x2E,0x0
_0x2000060:
	.DB  0x1
_0x2000000:
	.DB  0x2D,0x4E,0x41,0x4E,0x0,0x49,0x4E,0x46
	.DB  0x0
_0x2020003:
	.DB  0x80,0xC0

__GLOBAL_INI_TBL:
	.DW  0x01
	.DW  __seed_G100
	.DW  _0x2000060*2

	.DW  0x02
	.DW  __base_y_G101
	.DW  _0x2020003*2

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

;DISABLE WATCHDOG
	LDI  R31,0x18
	OUT  WDTCR,R31
	OUT  WDTCR,R30

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
   .equ __lcd_port=0x12 ;PORTD
; 0000 000B #endasm
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;void LCD_Config(void);
;void LCD_DisplayloadingPage(void);
;void LCD_DisplayMainPage(char);
;unsigned char numer;
;void main(void){
; 0000 0017 void main(void){

	.CSEG
_main:
; .FSTART _main
; 0000 0018 unsigned char numer_old = 0;
; 0000 0019 
; 0000 001A LCD_Config();
;	numer_old -> R17
	LDI  R17,0
	RCALL _LCD_Config
; 0000 001B LCD_DisplayloadingPage(); delay_ms(250); lcd_clear();
	RCALL _LCD_DisplayloadingPage
	LDI  R26,LOW(250)
	LDI  R27,0
	CALL _delay_ms
	CALL _lcd_clear
; 0000 001C 
; 0000 001D while(1){
_0x21:
; 0000 001E numer = Keypad4x4_GetInitialNumber();
	RCALL _Keypad4x4_GetInitialNumber
	MOV  R5,R30
; 0000 001F numer = Keypad4x4_ConvertNumber(numer);
	MOV  R26,R5
	RCALL _Keypad4x4_ConvertNumber
	MOV  R5,R30
; 0000 0020 //        numer=Keypad4x4_GetNumber();
; 0000 0021 
; 0000 0022 if(numer_old != numer){
	CP   R5,R17
	BREQ _0x24
; 0000 0023 numer_old = numer;
	MOV  R17,R5
; 0000 0024 LCD_DisplayMainPage(numer);
	MOV  R26,R5
	RCALL _LCD_DisplayMainPage
; 0000 0025 }
; 0000 0026 }
_0x24:
	RJMP _0x21
; 0000 0027 }
_0x25:
	RJMP _0x25
; .FEND
;void LCD_DisplayMainPage(unsigned char x2){
; 0000 002B void LCD_DisplayMainPage(unsigned char x2){
_LCD_DisplayMainPage:
; .FSTART _LCD_DisplayMainPage
; 0000 002C char txt[16];
; 0000 002D 
; 0000 002E lcd_clear();
	ST   -Y,R26
	SBIW R28,16
;	x2 -> Y+16
;	txt -> Y+0
	CALL SUBOPT_0x0
; 0000 002F lcd_gotoxy(0,0); itoa(x2, txt); lcd_puts(txt); lcd_putsf("  ");
	LDD  R30,Y+16
	LDI  R31,0
	ST   -Y,R31
	ST   -Y,R30
	MOVW R26,R28
	ADIW R26,2
	CALL _itoa
	MOVW R26,R28
	CALL _lcd_puts
	__POINTW2FN _0x0,0
	CALL SUBOPT_0x1
; 0000 0030 lcd_gotoxy(0,1); lcd_putsf("4x4 Keypad");
	__POINTW2FN _0x0,3
	CALL _lcd_putsf
; 0000 0031 }
	ADIW R28,17
	RET
; .FEND
;void LCD_Config(void){
; 0000 0034 void LCD_Config(void){
_LCD_Config:
; .FSTART _LCD_Config
; 0000 0035 lcd_init(16); lcd_clear();
	LDI  R26,LOW(16)
	CALL _lcd_init
	CALL _lcd_clear
; 0000 0036 }
	RET
; .FEND
;void LCD_DisplayloadingPage(void){
; 0000 0039 void LCD_DisplayloadingPage(void){
_LCD_DisplayloadingPage:
; .FSTART _LCD_DisplayloadingPage
; 0000 003A lcd_clear();
	CALL SUBOPT_0x0
; 0000 003B lcd_gotoxy(0,0); lcd_putsf("4x4Keypad Driver");
	__POINTW2FN _0x0,14
	CALL SUBOPT_0x1
; 0000 003C lcd_gotoxy(0,1); lcd_putsf("Loading ...");
	__POINTW2FN _0x0,31
	CALL _lcd_putsf
; 0000 003D }
	RET
; .FEND
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
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	buf -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;	mode -> Y+0
;uint8_t Keypad4x4_GetInitialNumber(void){
; 0001 000D uint8_t Keypad4x4_GetInitialNumber(void){

	.CSEG
_Keypad4x4_GetInitialNumber:
; .FSTART _Keypad4x4_GetInitialNumber
; 0001 000E uint8_t numer = 0;
; 0001 000F 
; 0001 0010 //    Keypad4x4_ConfigPin(&KEYPAD_R1_DDR, &KEYPAD_R1_PORT, KEYPAD_R1_BIT, KEYPAD ...
; 0001 0011 
; 0001 0012 Keypad4x4_R1_ConfigPin(KEYPAD4X4_MODE_INPUT);
	ST   -Y,R17
;	numer -> R17
	LDI  R17,0
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x402600A
	SBI  0x14,0
	CBI  0x15,0
	RJMP _0x402600B
_0x402600A:
	CBI  0x14,0
	SBI  0x15,0
_0x402600B:
	ADIW R28,1
; 0001 0013 Keypad4x4_R2_ConfigPin(KEYPAD4X4_MODE_INPUT);
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x402700D
	SBI  0x14,1
	CBI  0x15,1
	RJMP _0x402700E
_0x402700D:
	CBI  0x14,1
	SBI  0x15,1
_0x402700E:
	ADIW R28,1
; 0001 0014 Keypad4x4_R3_ConfigPin(KEYPAD4X4_MODE_INPUT);
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x4028010
	SBI  0x14,2
	CBI  0x15,2
	RJMP _0x4028011
_0x4028010:
	CBI  0x14,2
	SBI  0x15,2
_0x4028011:
	ADIW R28,1
; 0001 0015 Keypad4x4_R4_ConfigPin(KEYPAD4X4_MODE_INPUT);
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x4029013
	SBI  0x14,3
	CBI  0x15,3
	RJMP _0x4029014
_0x4029013:
	CBI  0x14,3
	SBI  0x15,3
_0x4029014:
	ADIW R28,1
; 0001 0016 Keypad4x4_C1_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x402A016
	SBI  0x14,4
	CBI  0x15,4
	RJMP _0x402A017
_0x402A016:
	CBI  0x14,4
	SBI  0x15,4
_0x402A017:
	ADIW R28,1
; 0001 0017 Keypad4x4_C2_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x402B019
	SBI  0x14,5
	CBI  0x15,5
	RJMP _0x402B01A
_0x402B019:
	CBI  0x14,5
	SBI  0x15,5
_0x402B01A:
	ADIW R28,1
; 0001 0018 Keypad4x4_C3_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x402C01C
	SBI  0x14,6
	CBI  0x15,6
	RJMP _0x402C01D
_0x402C01C:
	CBI  0x14,6
	SBI  0x15,6
_0x402C01D:
	ADIW R28,1
; 0001 0019 Keypad4x4_C4_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x402D01F
	SBI  0x14,7
	CBI  0x15,7
	RJMP _0x402D020
_0x402D01F:
	CBI  0x14,7
	SBI  0x15,7
_0x402D020:
	ADIW R28,1
; 0001 001A 
; 0001 001B //    KEYPAD4x4_DDR=0b11110000; KEYPAD4x4_PORT=0b00001111; delay_us(2);
; 0001 001C numer = KEYPAD4x4_PIN;
	IN   R17,19
; 0001 001D 
; 0001 001E Keypad4x4_R1_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x802600A
	SBI  0x14,0
	CBI  0x15,0
	RJMP _0x802600B
_0x802600A:
	CBI  0x14,0
	SBI  0x15,0
_0x802600B:
	ADIW R28,1
; 0001 001F Keypad4x4_R2_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x802700D
	SBI  0x14,1
	CBI  0x15,1
	RJMP _0x802700E
_0x802700D:
	CBI  0x14,1
	SBI  0x15,1
_0x802700E:
	ADIW R28,1
; 0001 0020 Keypad4x4_R3_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x8028010
	SBI  0x14,2
	CBI  0x15,2
	RJMP _0x8028011
_0x8028010:
	CBI  0x14,2
	SBI  0x15,2
_0x8028011:
	ADIW R28,1
; 0001 0021 Keypad4x4_R4_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
	LDI  R26,LOW(1)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x8029013
	SBI  0x14,3
	CBI  0x15,3
	RJMP _0x8029014
_0x8029013:
	CBI  0x14,3
	SBI  0x15,3
_0x8029014:
	ADIW R28,1
; 0001 0022 Keypad4x4_C1_ConfigPin(KEYPAD4X4_MODE_INPUT);
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x802A016
	SBI  0x14,4
	CBI  0x15,4
	RJMP _0x802A017
_0x802A016:
	CBI  0x14,4
	SBI  0x15,4
_0x802A017:
	ADIW R28,1
; 0001 0023 Keypad4x4_C2_ConfigPin(KEYPAD4X4_MODE_INPUT);
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x802B019
	SBI  0x14,5
	CBI  0x15,5
	RJMP _0x802B01A
_0x802B019:
	CBI  0x14,5
	SBI  0x15,5
_0x802B01A:
	ADIW R28,1
; 0001 0024 Keypad4x4_C3_ConfigPin(KEYPAD4X4_MODE_INPUT);
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x802C01C
	SBI  0x14,6
	CBI  0x15,6
	RJMP _0x802C01D
_0x802C01C:
	CBI  0x14,6
	SBI  0x15,6
_0x802C01D:
	ADIW R28,1
; 0001 0025 Keypad4x4_C4_ConfigPin(KEYPAD4X4_MODE_INPUT);
	LDI  R26,LOW(0)
	ST   -Y,R26
	LD   R30,Y
	CPI  R30,0
	BREQ _0x802D01F
	SBI  0x14,7
	CBI  0x15,7
	RJMP _0x802D020
_0x802D01F:
	CBI  0x14,7
	SBI  0x15,7
_0x802D020:
	ADIW R28,1
; 0001 0026 
; 0001 0027 //KEYPAD4x4_DDR=0b00001111; KEYPAD4x4_PORT=0b11110000; delay_us(2);
; 0001 0028 numer=numer|KEYPAD4x4_PIN;
	IN   R30,0x13
	OR   R17,R30
; 0001 0029 
; 0001 002A return numer;
	MOV  R30,R17
	LD   R17,Y+
	RET
; 0001 002B }
; .FEND
;unsigned char Keypad4x4_ConvertNumber(unsigned char key){
; 0001 0036 unsigned char Keypad4x4_ConvertNumber(unsigned char key){
_Keypad4x4_ConvertNumber:
; .FSTART _Keypad4x4_ConvertNumber
; 0001 0037 switch (key){
	ST   -Y,R26
;	key -> Y+0
	LD   R30,Y
; 0001 0038 case N00:
	CPI  R30,LOW(0xD7)
	BRNE _0x20024
; 0001 0039 return 0; break;
	LDI  R30,LOW(0)
	JMP  _0x20C0001
; 0001 003A case N01:
_0x20024:
	CPI  R30,LOW(0xEB)
	BRNE _0x20025
; 0001 003B return 1; break;
	JMP  _0x20C0002
; 0001 003C case N02:
_0x20025:
	CPI  R30,LOW(0xDB)
	BRNE _0x20026
; 0001 003D return 2; break;
	LDI  R30,LOW(2)
	JMP  _0x20C0001
; 0001 003E case N03:
_0x20026:
	CPI  R30,LOW(0xBB)
	BRNE _0x20027
; 0001 003F return 3; break;
	LDI  R30,LOW(3)
	JMP  _0x20C0001
; 0001 0040 case N04:
_0x20027:
	CPI  R30,LOW(0xED)
	BRNE _0x20028
; 0001 0041 return 4; break;
	LDI  R30,LOW(4)
	JMP  _0x20C0001
; 0001 0042 case N05:
_0x20028:
	CPI  R30,LOW(0xDD)
	BRNE _0x20029
; 0001 0043 return 5; break;
	LDI  R30,LOW(5)
	JMP  _0x20C0001
; 0001 0044 case N06:
_0x20029:
	CPI  R30,LOW(0xBD)
	BRNE _0x2002A
; 0001 0045 return 6; break;
	LDI  R30,LOW(6)
	JMP  _0x20C0001
; 0001 0046 case N07:
_0x2002A:
	CPI  R30,LOW(0xEE)
	BRNE _0x2002B
; 0001 0047 return 7; break;
	LDI  R30,LOW(7)
	JMP  _0x20C0001
; 0001 0048 case N08:
_0x2002B:
	CPI  R30,LOW(0xDE)
	BRNE _0x2002C
; 0001 0049 return 8; break;
	LDI  R30,LOW(8)
	JMP  _0x20C0001
; 0001 004A case N09:
_0x2002C:
	CPI  R30,LOW(0xBE)
	BRNE _0x2002D
; 0001 004B return 9; break;
	LDI  R30,LOW(9)
	JMP  _0x20C0001
; 0001 004C case N10:
_0x2002D:
	CPI  R30,LOW(0x7E)
	BRNE _0x2002E
; 0001 004D return 10; break;
	LDI  R30,LOW(10)
	JMP  _0x20C0001
; 0001 004E case N11:
_0x2002E:
	CPI  R30,LOW(0x7D)
	BRNE _0x2002F
; 0001 004F return 11; break;
	LDI  R30,LOW(11)
	JMP  _0x20C0001
; 0001 0050 case N12:
_0x2002F:
	CPI  R30,LOW(0x7B)
	BRNE _0x20030
; 0001 0051 return 12; break;
	LDI  R30,LOW(12)
	JMP  _0x20C0001
; 0001 0052 case N13:
_0x20030:
	CPI  R30,LOW(0x77)
	BRNE _0x20031
; 0001 0053 return 13; break;
	LDI  R30,LOW(13)
	JMP  _0x20C0001
; 0001 0054 case N14:
_0x20031:
	CPI  R30,LOW(0xB7)
	BRNE _0x20032
; 0001 0055 return 14; break;
	LDI  R30,LOW(14)
	JMP  _0x20C0001
; 0001 0056 case N15:
_0x20032:
	CPI  R30,LOW(0xE7)
	BRNE _0x20034
; 0001 0057 return 15; break;
	LDI  R30,LOW(15)
	JMP  _0x20C0001
; 0001 0058 default:
_0x20034:
; 0001 0059 return 16;
	LDI  R30,LOW(16)
	JMP  _0x20C0001
; 0001 005A }
; 0001 005B }
; .FEND
;unsigned char Keypad4x4_GetNumber(void){
; 0001 006B unsigned char Keypad4x4_GetNumber(void){
; 0001 006C unsigned char numer_initial = 0;
; 0001 006D 
; 0001 006E numer_initial = Keypad4x4_GetInitialNumber();
;	numer_initial -> R17
; 0001 006F return Keypad4x4_ConvertNumber(numer_initial);
; 0001 0070 }

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
    .equ __lcd_direction=__lcd_port-1
    .equ __lcd_pin=__lcd_port-2
    .equ __lcd_rs=0
    .equ __lcd_rd=1
    .equ __lcd_enable=2
    .equ __lcd_busy_flag=7

	.DSEG

	.CSEG
__lcd_delay_G101:
; .FSTART __lcd_delay_G101
    ldi   r31,15
__lcd_delay0:
    dec   r31
    brne  __lcd_delay0
	RET
; .FEND
__lcd_ready:
; .FSTART __lcd_ready
    in    r26,__lcd_direction
    andi  r26,0xf                 ;set as input
    out   __lcd_direction,r26
    sbi   __lcd_port,__lcd_rd     ;RD=1
    cbi   __lcd_port,__lcd_rs     ;RS=0
__lcd_busy:
	RCALL __lcd_delay_G101
    sbi   __lcd_port,__lcd_enable ;EN=1
	RCALL __lcd_delay_G101
    in    r26,__lcd_pin
    cbi   __lcd_port,__lcd_enable ;EN=0
	RCALL __lcd_delay_G101
    sbi   __lcd_port,__lcd_enable ;EN=1
	RCALL __lcd_delay_G101
    cbi   __lcd_port,__lcd_enable ;EN=0
    sbrc  r26,__lcd_busy_flag
    rjmp  __lcd_busy
	RET
; .FEND
__lcd_write_nibble_G101:
; .FSTART __lcd_write_nibble_G101
    andi  r26,0xf0
    or    r26,r27
    out   __lcd_port,r26          ;write
    sbi   __lcd_port,__lcd_enable ;EN=1
	CALL __lcd_delay_G101
    cbi   __lcd_port,__lcd_enable ;EN=0
	CALL __lcd_delay_G101
	RET
; .FEND
__lcd_write_data:
; .FSTART __lcd_write_data
	ST   -Y,R26
    cbi  __lcd_port,__lcd_rd 	  ;RD=0
    in    r26,__lcd_direction
    ori   r26,0xf0 | (1<<__lcd_rs) | (1<<__lcd_rd) | (1<<__lcd_enable) ;set as output
    out   __lcd_direction,r26
    in    r27,__lcd_port
    andi  r27,0xf
    ld    r26,y
	RCALL __lcd_write_nibble_G101
    ld    r26,y
    swap  r26
	RCALL __lcd_write_nibble_G101
    sbi   __lcd_port,__lcd_rd     ;RD=1
	JMP  _0x20C0001
; .FEND
__lcd_read_nibble_G101:
; .FSTART __lcd_read_nibble_G101
    sbi   __lcd_port,__lcd_enable ;EN=1
	CALL __lcd_delay_G101
    in    r30,__lcd_pin           ;read
    cbi   __lcd_port,__lcd_enable ;EN=0
	CALL __lcd_delay_G101
    andi  r30,0xf0
	RET
; .FEND
_lcd_read_byte0_G101:
; .FSTART _lcd_read_byte0_G101
	CALL __lcd_delay_G101
	RCALL __lcd_read_nibble_G101
    mov   r26,r30
	RCALL __lcd_read_nibble_G101
    cbi   __lcd_port,__lcd_rd     ;RD=0
    swap  r30
    or    r30,r26
	RET
; .FEND
_lcd_gotoxy:
; .FSTART _lcd_gotoxy
	ST   -Y,R26
	CALL __lcd_ready
	LD   R30,Y
	LDI  R31,0
	SUBI R30,LOW(-__base_y_G101)
	SBCI R31,HIGH(-__base_y_G101)
	LD   R30,Z
	LDD  R26,Y+1
	ADD  R26,R30
	CALL __lcd_write_data
	LDD  R4,Y+1
	LDD  R7,Y+0
	ADIW R28,2
	RET
; .FEND
_lcd_clear:
; .FSTART _lcd_clear
	CALL __lcd_ready
	LDI  R26,LOW(2)
	CALL __lcd_write_data
	CALL __lcd_ready
	LDI  R26,LOW(12)
	CALL __lcd_write_data
	CALL __lcd_ready
	LDI  R26,LOW(1)
	CALL __lcd_write_data
	LDI  R30,LOW(0)
	MOV  R7,R30
	MOV  R4,R30
	RET
; .FEND
_lcd_putchar:
; .FSTART _lcd_putchar
	ST   -Y,R26
    push r30
    push r31
    ld   r26,y
    set
    cpi  r26,10
    breq __lcd_putchar1
    clt
	CP   R4,R6
	BRLO _0x2020004
	__lcd_putchar1:
	INC  R7
	LDI  R30,LOW(0)
	ST   -Y,R30
	MOV  R26,R7
	RCALL _lcd_gotoxy
	brts __lcd_putchar0
_0x2020004:
	INC  R4
    rcall __lcd_ready
    sbi  __lcd_port,__lcd_rs ;RS=1
	LD   R26,Y
	CALL __lcd_write_data
__lcd_putchar0:
    pop  r31
    pop  r30
	JMP  _0x20C0001
; .FEND
_lcd_puts:
; .FSTART _lcd_puts
	ST   -Y,R27
	ST   -Y,R26
	ST   -Y,R17
_0x2020005:
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R30,X+
	STD  Y+1,R26
	STD  Y+1+1,R27
	MOV  R17,R30
	CPI  R30,0
	BREQ _0x2020007
	MOV  R26,R17
	RCALL _lcd_putchar
	RJMP _0x2020005
_0x2020007:
	RJMP _0x20C0003
; .FEND
_lcd_putsf:
; .FSTART _lcd_putsf
	ST   -Y,R27
	ST   -Y,R26
	ST   -Y,R17
_0x2020008:
	LDD  R30,Y+1
	LDD  R31,Y+1+1
	ADIW R30,1
	STD  Y+1,R30
	STD  Y+1+1,R31
	SBIW R30,1
	LPM  R30,Z
	MOV  R17,R30
	CPI  R30,0
	BREQ _0x202000A
	MOV  R26,R17
	RCALL _lcd_putchar
	RJMP _0x2020008
_0x202000A:
_0x20C0003:
	LDD  R17,Y+0
	ADIW R28,3
	RET
; .FEND
__long_delay_G101:
; .FSTART __long_delay_G101
    clr   r26
    clr   r27
__long_delay0:
    sbiw  r26,1         ;2 cycles
    brne  __long_delay0 ;2 cycles
	RET
; .FEND
__lcd_init_write_G101:
; .FSTART __lcd_init_write_G101
	ST   -Y,R26
    cbi  __lcd_port,__lcd_rd 	  ;RD=0
    in    r26,__lcd_direction
    ori   r26,0xf7                ;set as output
    out   __lcd_direction,r26
    in    r27,__lcd_port
    andi  r27,0xf
    ld    r26,y
	CALL __lcd_write_nibble_G101
    sbi   __lcd_port,__lcd_rd     ;RD=1
	RJMP _0x20C0001
; .FEND
_lcd_init:
; .FSTART _lcd_init
	ST   -Y,R26
    cbi   __lcd_port,__lcd_enable ;EN=0
    cbi   __lcd_port,__lcd_rs     ;RS=0
	LDD  R6,Y+0
	LD   R30,Y
	SUBI R30,-LOW(128)
	__PUTB1MN __base_y_G101,2
	LD   R30,Y
	SUBI R30,-LOW(192)
	__PUTB1MN __base_y_G101,3
	CALL SUBOPT_0x2
	CALL SUBOPT_0x2
	CALL SUBOPT_0x2
	RCALL __long_delay_G101
	LDI  R26,LOW(32)
	RCALL __lcd_init_write_G101
	RCALL __long_delay_G101
	LDI  R26,LOW(40)
	CALL SUBOPT_0x3
	LDI  R26,LOW(4)
	CALL SUBOPT_0x3
	LDI  R26,LOW(133)
	CALL SUBOPT_0x3
    in    r26,__lcd_direction
    andi  r26,0xf                 ;set as input
    out   __lcd_direction,r26
    sbi   __lcd_port,__lcd_rd     ;RD=1
	CALL _lcd_read_byte0_G101
	CPI  R30,LOW(0x5)
	BREQ _0x202000B
	LDI  R30,LOW(0)
	RJMP _0x20C0001
_0x202000B:
	CALL __lcd_ready
	LDI  R26,LOW(6)
	CALL __lcd_write_data
	CALL _lcd_clear
_0x20C0002:
	LDI  R30,LOW(1)
_0x20C0001:
	ADIW R28,1
	RET
; .FEND

	.CSEG

	.CSEG

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

	.DSEG
__seed_G100:
	.BYTE 0x4
__base_y_G101:
	.BYTE 0x4

	.CSEG
;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x0:
	CALL _lcd_clear
	LDI  R30,LOW(0)
	ST   -Y,R30
	LDI  R26,LOW(0)
	JMP  _lcd_gotoxy

;OPTIMIZER ADDED SUBROUTINE, CALLED 2 TIMES, CODE SIZE REDUCTION:2 WORDS
SUBOPT_0x1:
	CALL _lcd_putsf
	LDI  R30,LOW(0)
	ST   -Y,R30
	LDI  R26,LOW(1)
	JMP  _lcd_gotoxy

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:3 WORDS
SUBOPT_0x2:
	CALL __long_delay_G101
	LDI  R26,LOW(48)
	JMP  __lcd_init_write_G101

;OPTIMIZER ADDED SUBROUTINE, CALLED 3 TIMES, CODE SIZE REDUCTION:1 WORDS
SUBOPT_0x3:
	CALL __lcd_write_data
	JMP  __long_delay_G101

;RUNTIME LIBRARY

	.CSEG
_delay_ms:
	adiw r26,0
	breq __delay_ms1
__delay_ms0:
	wdr
	__DELAY_USW 0x7D0
	sbiw r26,1
	brne __delay_ms0
__delay_ms1:
	ret

;END OF CODE MARKER
__END_OF_CODE:
