	opt	c+, at+, e+, n-
	section overlay.text

	xdef d03a_800C7910
d03a_800C7910:
	dw 0x24020004 ; 800C7910
	dw 0xA0820003 ; 800C7914
	dw 0x24020064 ; 800C7918
	dw 0x03E00008 ; 800C791C
	dw 0xA0820007 ; 800C7920
	dw 0x00000000 ; 800C7924
	dw 0x00000000 ; 800C7928
	dw 0x00000000 ; 800C792C
