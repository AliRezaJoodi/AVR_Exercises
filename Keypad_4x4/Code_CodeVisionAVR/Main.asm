
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
	.DEF _number=R5
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
	.DB  0x20,0x20,0x20,0x20,0x0,0x34,0x78,0x34
	.DB  0x20,0x4B,0x65,0x79,0x70,0x61,0x64,0x0
	.DB  0x34,0x78,0x34,0x4B,0x65,0x79,0x70,0x61
	.DB  0x64,0x20,0x44,0x72,0x69,0x76,0x65,0x72
	.DB  0x0,0x4C,0x6F,0x61,0x64,0x69,0x6E,0x67
	.DB  0x20,0x2E,0x2E,0x2E,0x0
_0x2005C:
	.DB  0xFF,0x0,0x1,0xFF,0x2,0xFF,0xFF,0xFF
	.DB  0x3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
_0x2000060:
	.DB  0x1
_0x2000000:
	.DB  0x2D,0x4E,0x41,0x4E,0x0,0x49,0x4E,0x46
	.DB  0x0
_0x2020003:
	.DB  0x80,0xC0

__GLOBAL_INI_TBL:
	.DW  0x10
	.DW  _table_ctz4_G001
	.DW  _0x2005C*2

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
;void LCD_Config(void);
;void LCD_DisplayloadingPage(void);
;void LCD_DisplayMainPage(char);
;uint8_t number;
;void main(void){
; 0000 0017 void main(void){

	.CSEG
_main:
; .FSTART _main
; 0000 0018 uint8_t number_last = 0;
; 0000 0019 
; 0000 001A LCD_Config();
;	number_last -> R17
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
_0x3:
; 0000 001E number = Keypad4x4_GetKey();
	RCALL _Keypad4x4_GetKey
	MOV  R5,R30
; 0000 001F 
; 0000 0020 if(number_last != number){
	CP   R5,R17
	BREQ _0x6
; 0000 0021 number_last = number;
	MOV  R17,R5
; 0000 0022 LCD_DisplayMainPage(number);
	MOV  R26,R5
	RCALL _LCD_DisplayMainPage
; 0000 0023 }
; 0000 0024 }
_0x6:
	RJMP _0x3
; 0000 0025 }
_0x7:
	RJMP _0x7
; .FEND
;void LCD_DisplayMainPage(uint8_t number){
; 0000 0028 void LCD_DisplayMainPage(uint8_t number){
_LCD_DisplayMainPage:
; .FSTART _LCD_DisplayMainPage
; 0000 0029 char txt[16];
; 0000 002A 
; 0000 002B lcd_clear();
	ST   -Y,R26
	SBIW R28,16
;	number -> Y+16
;	txt -> Y+0
	CALL SUBOPT_0x0
; 0000 002C lcd_gotoxy(0,0); itoa(number, txt); lcd_puts(txt); lcd_putsf("    ");
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
; 0000 002D lcd_gotoxy(0,1); lcd_putsf("4x4 Keypad");
	__POINTW2FN _0x0,5
	CALL _lcd_putsf
; 0000 002E }
	ADIW R28,17
	RET
; .FEND
;void LCD_Config(void){
; 0000 0031 void LCD_Config(void){
_LCD_Config:
; .FSTART _LCD_Config
; 0000 0032 lcd_init(16); lcd_clear();
	LDI  R26,LOW(16)
	CALL _lcd_init
	CALL _lcd_clear
; 0000 0033 }
	RET
; .FEND
;void LCD_DisplayloadingPage(void){
; 0000 0036 void LCD_DisplayloadingPage(void){
_LCD_DisplayloadingPage:
; .FSTART _LCD_DisplayloadingPage
; 0000 0037 lcd_clear();
	CALL SUBOPT_0x0
; 0000 0038 lcd_gotoxy(0,0); lcd_putsf("4x4Keypad Driver");
	__POINTW2FN _0x0,16
	CALL SUBOPT_0x1
; 0000 0039 lcd_gotoxy(0,1); lcd_putsf("Loading ...");
	__POINTW2FN _0x0,33
	CALL _lcd_putsf
; 0000 003A }
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
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+4
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+2
;	pos -> Y+1
;	status -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;	*reg -> Y+1
;	pos -> Y+0
;static const uint8_t table_ctz4[16] = {
;KEYPAD4X4_NO_INDEX, // 0000
;0U,                 // 0001
;1U,                 // 0010
;KEYPAD4X4_NO_INDEX, // 0011
;2U,                 // 0100
;KEYPAD4X4_NO_INDEX, // 0101
;KEYPAD4X4_NO_INDEX, // 0110
;KEYPAD4X4_NO_INDEX, // 0111
;3U,                 // 1000
;KEYPAD4X4_NO_INDEX, // 1001
;KEYPAD4X4_NO_INDEX, // 1010
;KEYPAD4X4_NO_INDEX, // 1011
;KEYPAD4X4_NO_INDEX, // 1100
;KEYPAD4X4_NO_INDEX, // 1101
;KEYPAD4X4_NO_INDEX, // 1110
;KEYPAD4X4_NO_INDEX  // 1111
;};

	.DSEG
;uint8_t Keypad4x4_GetKey(void){
; 0001 001E uint8_t Keypad4x4_GetKey(void){

	.CSEG
_Keypad4x4_GetKey:
; .FSTART _Keypad4x4_GetKey
; 0001 001F uint8_t number = 0xFFU;
; 0001 0020 uint8_t rows = 0U, cols = 0U;
; 0001 0021 
; 0001 0022 Keypad4x4_R1_SetOutput();
	CALL __SAVELOCR4
;	number -> R17
;	rows -> R16
;	cols -> R19
	LDI  R17,255
	LDI  R16,0
	LDI  R19,0
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(0)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0023 Keypad4x4_R1_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(0)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0024 
; 0001 0025 Keypad4x4_R2_SetOutput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(1)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0026 Keypad4x4_R2_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(1)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0027 
; 0001 0028 Keypad4x4_R3_SetOutput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(2)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0029 Keypad4x4_R3_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(2)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 002A 
; 0001 002B Keypad4x4_R4_SetOutput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(3)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 002C Keypad4x4_R4_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(3)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 002D 
; 0001 002E cols |= (!Keypad4x4_C1_Read());
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(4)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	OR   R19,R30
; 0001 002F cols |= (!Keypad4x4_C2_Read()) << 1;
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(5)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	LSL  R30
	OR   R19,R30
; 0001 0030 cols |= (!Keypad4x4_C3_Read()) << 2;
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(6)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	LSL  R30
	LSL  R30
	OR   R19,R30
; 0001 0031 cols |= (!Keypad4x4_C4_Read()) << 3;
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(7)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	LSL  R30
	LSL  R30
	LSL  R30
	OR   R19,R30
; 0001 0032 
; 0001 0033 cols = table_ctz4[cols & 0x0F];
	MOV  R30,R19
	ANDI R30,LOW(0xF)
	LDI  R31,0
	SUBI R30,LOW(-_table_ctz4_G001)
	SBCI R31,HIGH(-_table_ctz4_G001)
	LD   R19,Z
; 0001 0034 
; 0001 0035 Keypad4x4_R1_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(0)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0036 Keypad4x4_R1_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(0)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0037 
; 0001 0038 Keypad4x4_R2_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(1)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0039 Keypad4x4_R2_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(1)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 003A 
; 0001 003B Keypad4x4_R3_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(2)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 003C Keypad4x4_R3_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(2)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 003D 
; 0001 003E Keypad4x4_R4_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(3)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 003F Keypad4x4_R4_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(3)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0040 
; 0001 0041 Keypad4x4_C1_SetOutput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(4)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0042 Keypad4x4_C1_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(4)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0043 
; 0001 0044 Keypad4x4_C2_SetOutput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(5)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0045 Keypad4x4_C2_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(5)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0046 
; 0001 0047 Keypad4x4_C3_SetOutput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(6)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0048 Keypad4x4_C3_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(6)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0049 
; 0001 004A Keypad4x4_C4_SetOutput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(7)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 004B Keypad4x4_C4_WriteLow();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(7)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 004C 
; 0001 004D rows |= (!Keypad4x4_R1_Read());
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(0)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	OR   R16,R30
; 0001 004E rows |= (!Keypad4x4_R2_Read()) << 1;
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(1)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	LSL  R30
	OR   R16,R30
; 0001 004F rows |= (!Keypad4x4_R3_Read()) << 2;
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(2)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	LSL  R30
	LSL  R30
	OR   R16,R30
; 0001 0050 rows |= (!Keypad4x4_R4_Read()) << 3;
	LDI  R30,LOW(51)
	LDI  R31,HIGH(51)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(3)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R26,X
	LD   R30,Y
	CALL __LSRB12
	ANDI R30,LOW(0x1)
	ADIW R28,3
	CALL __LNEGB1
	LSL  R30
	LSL  R30
	LSL  R30
	OR   R16,R30
; 0001 0051 
; 0001 0052 rows = table_ctz4[rows & 0x0F];
	MOV  R30,R16
	ANDI R30,LOW(0xF)
	LDI  R31,0
	SUBI R30,LOW(-_table_ctz4_G001)
	SBCI R31,HIGH(-_table_ctz4_G001)
	LD   R16,Z
; 0001 0053 
; 0001 0054 Keypad4x4_C1_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(4)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0055 Keypad4x4_C1_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(4)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0056 
; 0001 0057 Keypad4x4_C2_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(5)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0058 Keypad4x4_C2_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(5)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 0059 
; 0001 005A Keypad4x4_C3_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(6)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 005B Keypad4x4_C3_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(6)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 005C 
; 0001 005D Keypad4x4_C4_SetInput();
	LDI  R30,LOW(52)
	LDI  R31,HIGH(52)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(7)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	COM  R30
	AND  R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 005E Keypad4x4_C4_SetPullUp();
	LDI  R30,LOW(53)
	LDI  R31,HIGH(53)
	ST   -Y,R31
	ST   -Y,R30
	LDI  R26,LOW(7)
	ST   -Y,R26
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	LD   R1,X
	LD   R30,Y
	LDI  R26,LOW(1)
	CALL __LSLB12
	OR   R30,R1
	LDD  R26,Y+1
	LDD  R27,Y+1+1
	ST   X,R30
	ADIW R28,3
; 0001 005F 
; 0001 0060 return (cols << 2) | rows;
	MOV  R30,R19
	LSL  R30
	LSL  R30
	OR   R30,R16
	CALL __LOADLOCR4
	ADIW R28,4
	RET
; 0001 0061 }
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
	RJMP _0x20C0002
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
_0x20C0002:
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
_table_ctz4_G001:
	.BYTE 0x10
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
__SAVELOCR4:
	ST   -Y,R19
__SAVELOCR3:
	ST   -Y,R18
__SAVELOCR2:
	ST   -Y,R17
	ST   -Y,R16
	RET

__LOADLOCR4:
	LDD  R19,Y+3
__LOADLOCR3:
	LDD  R18,Y+2
__LOADLOCR2:
	LDD  R17,Y+1
	LD   R16,Y
	RET

__LSLB12:
	TST  R30
	MOV  R0,R30
	MOV  R30,R26
	BREQ __LSLB12R
__LSLB12L:
	LSL  R30
	DEC  R0
	BRNE __LSLB12L
__LSLB12R:
	RET

__LSRB12:
	TST  R30
	MOV  R0,R30
	MOV  R30,R26
	BREQ __LSRB12R
__LSRB12L:
	LSR  R30
	DEC  R0
	BRNE __LSRB12L
__LSRB12R:
	RET

__LNEGB1:
	TST  R30
	LDI  R30,1
	BREQ __LNEGB1F
	CLR  R30
__LNEGB1F:
	RET

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
