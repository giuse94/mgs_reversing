	opt	c+, at+, e+, n-
	section overlay.text

	xdef s01a_blink_tx_800DE700
s01a_blink_tx_800DE700:
	dw 0x8C820C1C ; 800DE700
	dw 0x00000000 ; 800DE704
	dw 0x24420001 ; 800DE708
	dw 0x03E00008 ; 800DE70C
	dw 0xAC820C1C ; 800DE710