	opt	c+, at+, e+, n-
	section overlay.text

	xdef s06a_fadeio_800DEBEC
s06a_fadeio_800DEBEC:
	dw 0x27BDFFE8 ; 800DEBEC
	dw 0xAFB00010 ; 800DEBF0
	dw 0x00808021 ; 800DEBF4
	dw 0xAFBF0014 ; 800DEBF8
	dw 0x8CA60000 ; 800DEBFC
	dw 0x0C00C7C1 ; 800DEC00
	dw 0x24A50004 ; 800DEC04
	dw 0x0C037B08 ; 800DEC08
	dw 0x02002021 ; 800DEC0C
	dw 0x8FBF0014 ; 800DEC10
	dw 0x8FB00010 ; 800DEC14
	dw 0x03E00008 ; 800DEC18
	dw 0x27BD0018 ; 800DEC1C