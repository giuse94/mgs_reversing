	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_eyeflash_800D2B50
s02c_eyeflash_800D2B50:
	dw 0x27BDFFE8 ; 800D2B50
	dw 0xAFBF0014 ; 800D2B54
	dw 0xAFB00010 ; 800D2B58
	dw 0x8C900028 ; 800D2B5C
	dw 0x00000000 ; 800D2B60
	dw 0x12000005 ; 800D2B64
	dw 0x00000000 ; 800D2B68
	dw 0x0C0060B8 ; 800D2B6C
	dw 0x02002021 ; 800D2B70
	dw 0x0C006F01 ; 800D2B74
	dw 0x02002021 ; 800D2B78
	dw 0x8FBF0014 ; 800D2B7C
	dw 0x8FB00010 ; 800D2B80
	dw 0x03E00008 ; 800D2B84
	dw 0x27BD0018 ; 800D2B88