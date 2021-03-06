EESchema Schematic File Version 4
LIBS:pcb_relay_main-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L microchip_pic16mcu:PIC16(L)F1455-I_ST U1
U 1 1 5BA0930F
P 5100 3950
F 0 "U1" H 3350 4550 50  0000 C CNN
F 1 "PIC16(L)F1455-I_ST" H 6600 3300 50  0000 C CNN
F 2 "SMD_Packages:SSOP-14" H 5100 3950 50  0001 C CNN
F 3 "" H 5100 3950 50  0001 C CNN
	1    5100 3950
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C3
U 1 1 5BA09675
P 4150 2800
F 0 "C3" H 4242 2846 50  0000 L CNN
F 1 "100u" H 4242 2755 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4150 2800 50  0001 C CNN
F 3 "~" H 4150 2800 50  0001 C CNN
	1    4150 2800
	1    0    0    -1  
$EndComp
$Comp
L device:C_Small C2
U 1 1 5BA097D7
P 3750 2800
F 0 "C2" H 3842 2846 50  0000 L CNN
F 1 "1u" H 3842 2755 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3750 2800 50  0001 C CNN
F 3 "~" H 3750 2800 50  0001 C CNN
	1    3750 2800
	1    0    0    -1  
$EndComp
$Comp
L conn:USB_A J2
U 1 1 5BA0992C
P 2150 3850
F 0 "J2" H 1950 4200 50  0000 C CNN
F 1 "USB_A" H 2000 4250 50  0001 C CNN
F 2 "Connectors:USB_Mini-B" H 2300 3800 50  0001 C CNN
F 3 "" H 2300 3800 50  0001 C CNN
	1    2150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 4250 2050 4250
$Comp
L power:GND #PWR0101
U 1 1 5BA09B0E
P 2050 4250
F 0 "#PWR0101" H 2050 4000 50  0001 C CNN
F 1 "GND" H 2055 4077 50  0000 C CNN
F 2 "" H 2050 4250 50  0001 C CNN
F 3 "" H 2050 4250 50  0001 C CNN
	1    2050 4250
	1    0    0    -1  
$EndComp
Connection ~ 2050 4250
$Comp
L power:+5V #PWR0102
U 1 1 5BA09B5E
P 2450 3650
F 0 "#PWR0102" H 2450 3500 50  0001 C CNN
F 1 "+5V" H 2465 3823 50  0000 C CNN
F 2 "" H 2450 3650 50  0001 C CNN
F 3 "" H 2450 3650 50  0001 C CNN
	1    2450 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5BA09C2C
P 4150 2900
F 0 "#PWR0103" H 4150 2650 50  0001 C CNN
F 1 "GND" H 4155 2727 50  0000 C CNN
F 2 "" H 4150 2900 50  0001 C CNN
F 3 "" H 4150 2900 50  0001 C CNN
	1    4150 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5BA09C9B
P 4150 2700
F 0 "#PWR0104" H 4150 2550 50  0001 C CNN
F 1 "+5V" H 4165 2873 50  0000 C CNN
F 2 "" H 4150 2700 50  0001 C CNN
F 3 "" H 4150 2700 50  0001 C CNN
	1    4150 2700
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x05_Male J1
U 1 1 5BA09DC9
P 1900 2900
F 0 "J1" H 1850 3150 50  0000 L CNN
F 1 "PROG" V 1850 2800 50  0000 L CNN
F 2 "ucan_custom:prog_con" H 1900 2900 50  0001 C CNN
F 3 "~" H 1900 2900 50  0001 C CNN
	1    1900 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5BA09FF7
P 5100 4650
F 0 "#PWR0105" H 5100 4400 50  0001 C CNN
F 1 "GND" H 5105 4477 50  0000 C CNN
F 2 "" H 5100 4650 50  0001 C CNN
F 3 "" H 5100 4650 50  0001 C CNN
	1    5100 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5BA0A00C
P 5100 3250
F 0 "#PWR0106" H 5100 3100 50  0001 C CNN
F 1 "+5V" H 5115 3423 50  0000 C CNN
F 2 "" H 5100 3250 50  0001 C CNN
F 3 "" H 5100 3250 50  0001 C CNN
	1    5100 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5BA0A17E
P 2350 2800
F 0 "#PWR0107" H 2350 2650 50  0001 C CNN
F 1 "+5V" V 2350 3000 50  0000 C CNN
F 2 "" H 2350 2800 50  0001 C CNN
F 3 "" H 2350 2800 50  0001 C CNN
	1    2350 2800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5BA0A193
P 2100 2900
F 0 "#PWR0108" H 2100 2650 50  0001 C CNN
F 1 "GND" V 2100 2700 50  0000 C CNN
F 2 "" H 2100 2900 50  0001 C CNN
F 3 "" H 2100 2900 50  0001 C CNN
	1    2100 2900
	0    -1   -1   0   
$EndComp
$Comp
L device:C_Small C1
U 1 1 5BA0A21C
P 3000 3650
F 0 "C1" V 2771 3650 50  0000 C CNN
F 1 "0,47u" V 2862 3650 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603" H 3000 3650 50  0001 C CNN
F 3 "~" H 3000 3650 50  0001 C CNN
	1    3000 3650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5BA0A35D
P 2900 3650
F 0 "#PWR0109" H 2900 3400 50  0001 C CNN
F 1 "GND" H 2950 3500 50  0000 C CNN
F 2 "" H 2900 3650 50  0001 C CNN
F 3 "" H 2900 3650 50  0001 C CNN
	1    2900 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2800 2350 2800
Text GLabel 2350 3000 2    50   Input ~ 0
ICSPDAT
Wire Wire Line
	2350 3000 2100 3000
Text GLabel 2350 3100 2    50   Input ~ 0
ICSPCLK
Wire Wire Line
	2350 3100 2100 3100
Text GLabel 2300 2700 2    50   Input ~ 0
VPP
Wire Wire Line
	2300 2700 2100 2700
Text GLabel 3100 4050 0    50   Input ~ 0
VPP
Text GLabel 7200 3600 1    50   Input ~ 0
ICSPDAT
Text GLabel 7350 3600 1    50   Input ~ 0
ICSPCLK
Wire Wire Line
	2450 3850 3100 3850
Wire Wire Line
	2450 3950 3100 3950
$Comp
L power:+5V #PWR0110
U 1 1 5BA0AE29
P 3750 2700
F 0 "#PWR0110" H 3750 2550 50  0001 C CNN
F 1 "+5V" H 3765 2873 50  0000 C CNN
F 2 "" H 3750 2700 50  0001 C CNN
F 3 "" H 3750 2700 50  0001 C CNN
	1    3750 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5BA0AE40
P 3750 2900
F 0 "#PWR0111" H 3750 2650 50  0001 C CNN
F 1 "GND" H 3755 2727 50  0000 C CNN
F 2 "" H 3750 2900 50  0001 C CNN
F 3 "" H 3750 2900 50  0001 C CNN
	1    3750 2900
	1    0    0    -1  
$EndComp
$Comp
L conn:Conn_01x10 J3
U 1 1 5BA0B28F
P 8150 3950
F 0 "J3" H 8230 3942 50  0000 L CNN
F 1 "Conn_01x10" H 8230 3851 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 8150 3950 50  0001 C CNN
F 3 "~" H 8150 3950 50  0001 C CNN
	1    8150 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 3650 7200 3650
Wire Wire Line
	7200 3650 7200 3600
Wire Wire Line
	7100 3750 7350 3750
Wire Wire Line
	7350 3750 7350 3600
Connection ~ 7200 3650
Wire Wire Line
	7200 3650 7950 3650
Wire Wire Line
	7950 3750 7350 3750
Connection ~ 7350 3750
Wire Wire Line
	7100 3850 7950 3850
Wire Wire Line
	7100 3950 7950 3950
Wire Wire Line
	7100 4050 7950 4050
$Comp
L power:GND #PWR0113
U 1 1 5BA0BBFD
P 7950 4450
F 0 "#PWR0113" H 7950 4200 50  0001 C CNN
F 1 "GND" V 7955 4322 50  0000 R CNN
F 2 "" H 7950 4450 50  0001 C CNN
F 3 "" H 7950 4450 50  0001 C CNN
	1    7950 4450
	0    1    1    0   
$EndComp
Text GLabel 7950 4250 0    50   Input ~ 0
RA4
Text GLabel 7950 4350 0    50   Input ~ 0
RA5
Text GLabel 3100 4150 0    50   Input ~ 0
RA4
Text GLabel 3100 4250 0    50   Input ~ 0
RA5
Wire Wire Line
	7100 4150 7950 4150
$Comp
L power:+5V #PWR0112
U 1 1 5BA0B7DC
P 7950 3550
F 0 "#PWR0112" H 7950 3400 50  0001 C CNN
F 1 "+5V" H 7965 3723 50  0000 C CNN
F 2 "" H 7950 3550 50  0001 C CNN
F 3 "" H 7950 3550 50  0001 C CNN
	1    7950 3550
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
