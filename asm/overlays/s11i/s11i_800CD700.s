	opt	c+, at+, e+, n-
	section overlay.text

	xdef s11i_800CD700
s11i_800CD700:
	dw 0x00003021 ; 800CD700
	dw 0x3C02800C ; 800CD704
	dw 0x244233E0 ; 800CD708
	dw 0x00052880 ; 800CD70C
	dw 0x00A21821 ; 800CD710
	dw 0x8C820B00 ; 800CD714
	dw 0x00000000 ; 800CD718
	dw 0x14400005 ; 800CD71C
	dw 0x24C60001 ; 800CD720
	dw 0x8C630000 ; 800CD724
	dw 0x24020001 ; 800CD728
	dw 0x03E00008 ; 800CD72C
	dw 0xAC830B00 ; 800CD730
	dw 0x28C20008 ; 800CD734
	dw 0x1440FFF6 ; 800CD738
	dw 0x24840004 ; 800CD73C
	dw 0x03E00008 ; 800CD740
	dw 0x00001021 ; 800CD744
