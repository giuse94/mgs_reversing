	opt	c+, at+, e+, n-
	section overlay.text

	xdef s13a_800CCCD8
s13a_800CCCD8:
	dw 0x8C820B28 ; 800CCCD8
	dw 0x00000000 ; 800CCCDC
	dw 0x2C420003 ; 800CCCE0
	dw 0x14400006 ; 800CCCE4
	dw 0x00000000 ; 800CCCE8
	dw 0x8C820B70 ; 800CCCEC
	dw 0x00000000 ; 800CCCF0
	dw 0x30420001 ; 800CCCF4
	dw 0x14400006 ; 800CCCF8
	dw 0x24020001 ; 800CCCFC
	dw 0x8C830B28 ; 800CCD00
	dw 0x00001021 ; 800CCD04
	dw 0x24630001 ; 800CCD08
	dw 0x03E00008 ; 800CCD0C
	dw 0xAC830B28 ; 800CCD10
	dw 0x03E00008 ; 800CCD14
	dw 0x00000000 ; 800CCD18
