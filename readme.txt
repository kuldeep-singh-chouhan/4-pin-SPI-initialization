PCB
14 | 62 | RES
15 | 63 | A0
changed to 
32 | 146 | RES | 9
33 | 147 | A0 | 8
sda connected to cs1b (change wiring)
21 scl/k11 -> 440mV
22 sda11 -> 0
23 s011 -> signal
31 scl/k00 -> 1.76 V
30 si00/sda00 -> 1.44V
serial uses
p51 23 data s011
p30 21 clock scl11 (can be changed)
p40 2 tool0 (used for uart comm) idts kaam aayegi
removed tick of pull up in p40

--------------------------------------------------
pins
--------------------------------------------------
changed to channel 0
31	p10   clock		07
29	p12	data		06
02	p40	idk
34	p27	cs1b		10
32	p146	res		09
33	p147	A0		08

--------------------------------------------------
Init LCD()
--------------------------------------------------
e2	11100010	reset
2c	00101100	power control (booster)
2e	00101110	power control (booster | regulator)
2f	00101111	power control (booster | regulator | follower)
25	00100101	regulation ratio (5.5) RR[2:0] 101
81	10000001	set EV
1d	00011101	EV[5:0] 011101
a2	10100010	bias setting 1/9
a0	10100000	SEG direction MX = 0 normal direction
c8	11001000	COM direction MY = 1 reverse direction
40	01000000	Set start line (L0)
af	10101111	Display ON

----------------------------------------------------
a4
a6
a0
c8
40
25
81
1b
a2
2c
2e
2f
af

--------------------------------------------------

