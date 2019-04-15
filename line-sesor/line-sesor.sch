EESchema Schematic File Version 4
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
L Device:R R3
U 1 1 5CAC8E0C
P 5950 4300
F 0 "R3" V 5743 4300 50  0000 C CNN
F 1 "10K" V 5834 4300 50  0000 C CNN
F 2 "" V 5880 4300 50  0001 C CNN
F 3 "~" H 5950 4300 50  0001 C CNN
	1    5950 4300
	0    1    1    0   
$EndComp
$Comp
L Device:D_Photo D2
U 1 1 5CAC8E59
P 4750 4250
F 0 "D2" V 4746 4172 50  0000 R CNN
F 1 "D_Photo" V 4655 4172 50  0000 R CNN
F 2 "" H 4700 4250 50  0001 C CNN
F 3 "~" H 4700 4250 50  0001 C CNN
	1    4750 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1
U 1 1 5CAC910A
P 4300 4300
F 0 "D1" V 4338 4183 50  0000 R CNN
F 1 "LED" V 4247 4183 50  0000 R CNN
F 2 "" H 4300 4300 50  0001 C CNN
F 3 "~" H 4300 4300 50  0001 C CNN
	1    4300 4300
	0    -1   -1   0   
$EndComp
$Comp
L Comparator:LM339 U1
U 1 1 5CAC91E9
P 5950 3850
F 0 "U1" H 5950 4217 50  0000 C CNN
F 1 "LM339" H 5950 4126 50  0000 C CNN
F 2 "" H 5900 3950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm339.pdf" H 6000 4050 50  0001 C CNN
	1    5950 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5CAC92A5
P 6500 3550
F 0 "R4" H 6570 3596 50  0000 L CNN
F 1 "10K" H 6570 3505 50  0000 L CNN
F 2 "" V 6430 3550 50  0001 C CNN
F 3 "~" H 6500 3550 50  0001 C CNN
	1    6500 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CAC92EF
P 4300 3900
F 0 "R1" H 4370 3946 50  0000 L CNN
F 1 "220" H 4370 3855 50  0000 L CNN
F 2 "" V 4230 3900 50  0001 C CNN
F 3 "~" H 4300 3900 50  0001 C CNN
	1    4300 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5CAC937C
P 4750 3500
F 0 "R2" H 4820 3546 50  0000 L CNN
F 1 "R" H 4820 3455 50  0000 L CNN
F 2 "" V 4680 3500 50  0001 C CNN
F 3 "~" H 4750 3500 50  0001 C CNN
	1    4750 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CAC93D8
P 6250 5250
F 0 "C1" H 6365 5296 50  0000 L CNN
F 1 "C" H 6365 5205 50  0000 L CNN
F 2 "" H 6288 5100 50  0001 C CNN
F 3 "~" H 6250 5250 50  0001 C CNN
	1    6250 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5CAC9482
P 6600 5250
F 0 "C2" H 6715 5296 50  0000 L CNN
F 1 "C" H 6715 5205 50  0000 L CNN
F 2 "" H 6638 5100 50  0001 C CNN
F 3 "~" H 6600 5250 50  0001 C CNN
	1    6600 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5CAC94B9
P 5700 4900
F 0 "#PWR02" H 5700 4650 50  0001 C CNN
F 1 "GND" H 5705 4727 50  0000 C CNN
F 2 "" H 5700 4900 50  0001 C CNN
F 3 "" H 5700 4900 50  0001 C CNN
	1    5700 4900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5CAC9509
P 5400 3000
F 0 "#PWR01" H 5400 2850 50  0001 C CNN
F 1 "+5V" H 5415 3173 50  0000 C CNN
F 2 "" H 5400 3000 50  0001 C CNN
F 3 "" H 5400 3000 50  0001 C CNN
	1    5400 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 3950 5600 3950
Wire Wire Line
	5800 4300 5600 4300
Wire Wire Line
	5600 4300 5600 3950
Connection ~ 5600 3950
Wire Wire Line
	5600 3950 5650 3950
Wire Wire Line
	6100 4300 6300 4300
Wire Wire Line
	6300 4300 6300 3850
Wire Wire Line
	6300 3850 6250 3850
Wire Wire Line
	6300 3850 6500 3850
Wire Wire Line
	6500 3850 6500 3700
Connection ~ 6300 3850
Wire Wire Line
	6700 3850 6500 3850
Connection ~ 6500 3850
Wire Wire Line
	5700 4900 5700 4650
Wire Wire Line
	5700 4650 5400 4650
Wire Wire Line
	5700 4650 6700 4650
Wire Wire Line
	6700 3850 6700 4650
Connection ~ 5700 4650
Wire Wire Line
	4750 4450 4750 4650
Wire Wire Line
	4750 4650 4300 4650
Wire Wire Line
	4300 4650 4300 4450
Connection ~ 4750 4650
$Comp
L Device:R_POT RV1
U 1 1 5CACA252
P 5400 3950
F 0 "RV1" H 5330 3996 50  0000 R CNN
F 1 "R_POT" H 5330 3905 50  0000 R CNN
F 2 "" H 5400 3950 50  0001 C CNN
F 3 "~" H 5400 3950 50  0001 C CNN
	1    5400 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3750 4750 3750
Wire Wire Line
	4750 3750 4750 4150
Wire Wire Line
	5400 4100 5400 4650
Connection ~ 5400 4650
Wire Wire Line
	5400 4650 4750 4650
Wire Wire Line
	5400 3000 5400 3100
Wire Wire Line
	6500 3400 6500 3100
Wire Wire Line
	6500 3100 5400 3100
Connection ~ 5400 3100
Wire Wire Line
	4750 3350 4750 3100
Wire Wire Line
	4750 3100 5400 3100
Wire Wire Line
	5400 3100 5400 3800
Wire Wire Line
	4750 3650 4750 3750
Connection ~ 4750 3750
Wire Wire Line
	4300 4150 4300 4050
Wire Wire Line
	4300 3750 4300 3100
Wire Wire Line
	4300 3100 4750 3100
Connection ~ 4750 3100
$EndSCHEMATC