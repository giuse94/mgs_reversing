	opt	c+, at+, e+, n-
	section .text

	xdef mts_start_8008AAEC
mts_start_8008AAEC:
	dw 0x27BDFFD0 ; 0x8008AAEC
	dw 0xAFB3001C ; 0x8008AAF0
	dw 0x00809821 ; 0x8008AAF4
	dw 0xAFB50024 ; 0x8008AAF8
	dw 0x00A0A821 ; 0x8008AAFC
	dw 0xAFB40020 ; 0x8008AB00
	dw 0x00C0A021 ; 0x8008AB04
	dw 0x24040010 ; 0x8008AB08
	dw 0x2405000C ; 0x8008AB0C
	dw 0x3C06801F ; 0x8008AB10
	dw 0x34C6FF00 ; 0x8008AB14
	dw 0xAFBF0028 ; 0x8008AB18
	dw 0xAFB20018 ; 0x8008AB1C
	dw 0xAFB10014 ; 0x8008AB20
	dw 0x0C0265EF ; 0x8008AB24
	dw 0xAFB00010 ; 0x8008AB28
	dw 0x0C0260C6 ; 0x8008AB2C
	dw 0x00000000 ; 0x8008AB30
	dw 0x3C048001 ; 0x8008AB34
	dw 0x24843F48 ; 0x8008AB38
	dw 0x3C058001 ; 0x8008AB3C
	dw 0x24A53F74 ; 0x8008AB40
	dw 0x3C068001 ; 0x8008AB44
	dw 0x24C63F80 ; 0x8008AB48
	dw 0x0C022EE8 ; 0x8008AB4C
	dw 0x00000000 ; 0x8008AB50
	dw 0x0C023166 ; 0x8008AB54
	dw 0x00000000 ; 0x8008AB58
	dw 0x3C048001 ; 0x8008AB5C
	dw 0x24843F8C ; 0x8008AB60
	dw 0x0C022EE8 ; 0x8008AB64
	dw 0x00402821 ; 0x8008AB68
	dw 0x0C02654B ; 0x8008AB6C
	dw 0x00000000 ; 0x8008AB70
	dw 0x3C04F000 ; 0x8008AB74
	dw 0x34840010 ; 0x8008AB78
	dw 0x24051000 ; 0x8008AB7C
	dw 0x3C078009 ; 0x8008AB80
	dw 0x24E7BBC0 ; 0x8008AB84
	dw 0x0C02651B ; 0x8008AB88
	dw 0x24061000 ; 0x8008AB8C
	dw 0x00408021 ; 0x8008AB90
	dw 0x3C01800A ; 0x8008AB94
	dw 0xAC303D70 ; 0x8008AB98
	dw 0x0C02652B ; 0x8008AB9C
	dw 0x02002021 ; 0x8008ABA0
	dw 0x0C026527 ; 0x8008ABA4
	dw 0x02002021 ; 0x8008ABA8
	dw 0x0C02654F ; 0x8008ABAC
	dw 0x00000000 ; 0x8008ABB0
	dw 0x00001821 ; 0x8008ABB4
	dw 0x3C01800C ; 0x8008ABB8
	dw 0x00230821 ; 0x8008ABBC
	dw 0xA0200C30 ; 0x8008ABC0
	dw 0x3C01800C ; 0x8008ABC4
	dw 0x00230821 ; 0x8008ABC8
	dw 0xAC200C40 ; 0x8008ABCC
	dw 0x3C01800C ; 0x8008ABD0
	dw 0x00230821 ; 0x8008ABD4
	dw 0xAC200C44 ; 0x8008ABD8
	dw 0x24630020 ; 0x8008ABDC
	dw 0x2C620180 ; 0x8008ABE0
	dw 0x1440FFF4 ; 0x8008ABE4
	dw 0x2404FFFF ; 0x8008ABE8
	dw 0x2403001F ; 0x8008ABEC
	dw 0x3C02800C ; 0x8008ABF0
	dw 0x24420C2F ; 0x8008ABF4
	dw 0xA0440000 ; 0x8008ABF8
	dw 0x2463FFFF ; 0x8008ABFC
	dw 0x0461FFFD ; 0x8008AC00
	dw 0x2442FFFF ; 0x8008AC04
	dw 0x3C01800C ; 0x8008AC08
	dw 0xAC200DB4 ; 0x8008AC0C
	dw 0x00002021 ; 0x8008AC10
	dw 0x3C11800C ; 0x8008AC14
	dw 0x26310FC0 ; 0x8008AC18
	dw 0x02202821 ; 0x8008AC1C
	dw 0x0C022D92 ; 0x8008AC20
	dw 0x24060200 ; 0x8008AC24
	dw 0x0C026553 ; 0x8008AC28
	dw 0x00000000 ; 0x8008AC2C
	dw 0x3C128009 ; 0x8008AC30
	dw 0x2652B0A4 ; 0x8008AC34
	dw 0x3C10800C ; 0x8008AC38
	dw 0x26100C30 ; 0x8008AC3C
	dw 0x12400003 ; 0x8008AC40
	dw 0x00000000 ; 0x8008AC44
	dw 0x16200015 ; 0x8008AC48
	dw 0x2402FFFF ; 0x8008AC4C
	dw 0x3C048001 ; 0x8008AC50
	dw 0x24843DE8 ; 0x8008AC54
	dw 0x3C058001 ; 0x8008AC58
	dw 0x24A53E10 ; 0x8008AC5C
	dw 0x3C07800C ; 0x8008AC60
	dw 0x8CE70DB0 ; 0x8008AC64
	dw 0x0C022EE8 ; 0x8008AC68
	dw 0x240602CD ; 0x8008AC6C
	dw 0x3C048001 ; 0x8008AC70
	dw 0x24843E58 ; 0x8008AC74
	dw 0x02402821 ; 0x8008AC78
	dw 0x0C022EE8 ; 0x8008AC7C
	dw 0x02203021 ; 0x8008AC80
	dw 0x3C048001 ; 0x8008AC84
	dw 0x24843E2C ; 0x8008AC88
	dw 0x0C022EE8 ; 0x8008AC8C
	dw 0x00000000 ; 0x8008AC90
	dw 0x0C022DDF ; 0x8008AC94
	dw 0x00000000 ; 0x8008AC98
	dw 0x2402FFFF ; 0x8008AC9C
	dw 0xA2020002 ; 0x8008ACA0
	dw 0xA2020001 ; 0x8008ACA4
	dw 0xAE120008 ; 0x8008ACA8
	dw 0x0C026587 ; 0x8008ACAC
	dw 0xAE000004 ; 0x8008ACB0
	dw 0x3C048009 ; 0x8008ACB4
	dw 0x2484BBC8 ; 0x8008ACB8
	dw 0x3C05800C ; 0x8008ACBC
	dw 0x24A50FC0 ; 0x8008ACC0
	dw 0x0C026533 ; 0x8008ACC4
	dw 0x00403021 ; 0x8008ACC8
	dw 0xAE020018 ; 0x8008ACCC
	dw 0x304200FF ; 0x8008ACD0
	dw 0x00021840 ; 0x8008ACD4
	dw 0x00621821 ; 0x8008ACD8
	dw 0x8C020110 ; 0x8008ACDC
	dw 0x00031980 ; 0x8008ACE0
	dw 0x00431021 ; 0x8008ACE4
	dw 0x24030400 ; 0x8008ACE8
	dw 0xAE02001C ; 0x8008ACEC
	dw 0xAC430094 ; 0x8008ACF0
	dw 0x3C02800C ; 0x8008ACF4
	dw 0x8C420DB4 ; 0x8008ACF8
	dw 0x24030003 ; 0x8008ACFC
	dw 0xA2030000 ; 0x8008AD00
	dw 0x34420001 ; 0x8008AD04
	dw 0x3C01800C ; 0x8008AD08
	dw 0xAC220DB4 ; 0x8008AD0C
	dw 0x0C02655B ; 0x8008AD10
	dw 0xA200000E ; 0x8008AD14
	dw 0x2404000B ; 0x8008AD18
	dw 0x3C11800C ; 0x8008AD1C
	dw 0x263113C0 ; 0x8008AD20
	dw 0x02202821 ; 0x8008AD24
	dw 0x0C022D92 ; 0x8008AD28
	dw 0x24060400 ; 0x8008AD2C
	dw 0x0C026553 ; 0x8008AD30
	dw 0x00000000 ; 0x8008AD34
	dw 0x3C128009 ; 0x8008AD38
	dw 0x2652BA88 ; 0x8008AD3C
	dw 0x3C10800C ; 0x8008AD40
	dw 0x26100D90 ; 0x8008AD44
	dw 0x12400003 ; 0x8008AD48
	dw 0x00000000 ; 0x8008AD4C
	dw 0x16200015 ; 0x8008AD50
	dw 0x2402FFFF ; 0x8008AD54
	dw 0x3C048001 ; 0x8008AD58
	dw 0x24843DE8 ; 0x8008AD5C
	dw 0x3C058001 ; 0x8008AD60
	dw 0x24A53E10 ; 0x8008AD64
	dw 0x3C07800C ; 0x8008AD68
	dw 0x8CE70DB0 ; 0x8008AD6C
	dw 0x0C022EE8 ; 0x8008AD70
	dw 0x240602CD ; 0x8008AD74
	dw 0x3C048001 ; 0x8008AD78
	dw 0x24843E58 ; 0x8008AD7C
	dw 0x02402821 ; 0x8008AD80
	dw 0x0C022EE8 ; 0x8008AD84
	dw 0x02203021 ; 0x8008AD88
	dw 0x3C048001 ; 0x8008AD8C
	dw 0x24843E2C ; 0x8008AD90
	dw 0x0C022EE8 ; 0x8008AD94
	dw 0x00000000 ; 0x8008AD98
	dw 0x0C022DDF ; 0x8008AD9C
	dw 0x00000000 ; 0x8008ADA0
	dw 0x2402FFFF ; 0x8008ADA4
	dw 0xA2020002 ; 0x8008ADA8
	dw 0xA2020001 ; 0x8008ADAC
	dw 0xAE120008 ; 0x8008ADB0
	dw 0x0C026587 ; 0x8008ADB4
	dw 0xAE000004 ; 0x8008ADB8
	dw 0x3C048009 ; 0x8008ADBC
	dw 0x2484BBC8 ; 0x8008ADC0
	dw 0x3C05800C ; 0x8008ADC4
	dw 0x24A513C0 ; 0x8008ADC8
	dw 0x0C026533 ; 0x8008ADCC
	dw 0x00403021 ; 0x8008ADD0
	dw 0xAE020018 ; 0x8008ADD4
	dw 0x304200FF ; 0x8008ADD8
	dw 0x00021840 ; 0x8008ADDC
	dw 0x00621821 ; 0x8008ADE0
	dw 0x8C020110 ; 0x8008ADE4
	dw 0x00031980 ; 0x8008ADE8
	dw 0x00431021 ; 0x8008ADEC
	dw 0x24030400 ; 0x8008ADF0
	dw 0xAE02001C ; 0x8008ADF4
	dw 0xAC430094 ; 0x8008ADF8
	dw 0x3C02800C ; 0x8008ADFC
	dw 0x8C420DB4 ; 0x8008AE00
	dw 0x24030003 ; 0x8008AE04
	dw 0xA2030000 ; 0x8008AE08
	dw 0x34420800 ; 0x8008AE0C
	dw 0x3C01800C ; 0x8008AE10
	dw 0xAC220DB4 ; 0x8008AE14
	dw 0x0C02655B ; 0x8008AE18
	dw 0xA200000E ; 0x8008AE1C
	dw 0x2662FFFF ; 0x8008AE20
	dw 0x2C42000A ; 0x8008AE24
	dw 0x14400013 ; 0x8008AE28
	dw 0x00000000 ; 0x8008AE2C
	dw 0x3C048001 ; 0x8008AE30
	dw 0x24843DE8 ; 0x8008AE34
	dw 0x3C058001 ; 0x8008AE38
	dw 0x24A53E10 ; 0x8008AE3C
	dw 0x3C07800C ; 0x8008AE40
	dw 0x8CE70DB0 ; 0x8008AE44
	dw 0x0C022EE8 ; 0x8008AE48
	dw 0x240604AF ; 0x8008AE4C
	dw 0x3C048001 ; 0x8008AE50
	dw 0x24843FA0 ; 0x8008AE54
	dw 0x0C022EE8 ; 0x8008AE58
	dw 0x02602821 ; 0x8008AE5C
	dw 0x3C048001 ; 0x8008AE60
	dw 0x24843E2C ; 0x8008AE64
	dw 0x0C022EE8 ; 0x8008AE68
	dw 0x00000000 ; 0x8008AE6C
	dw 0x0C022DDF ; 0x8008AE70
	dw 0x00000000 ; 0x8008AE74
	dw 0x3C06800A ; 0x8008AE78
	dw 0x8CC63D94 ; 0x8008AE7C
	dw 0x00000000 ; 0x8008AE80
	dw 0x18C00003 ; 0x8008AE84
	dw 0x02602021 ; 0x8008AE88
	dw 0x0C022D92 ; 0x8008AE8C
	dw 0x02802821 ; 0x8008AE90
	dw 0x0C026553 ; 0x8008AE94
	dw 0x00000000 ; 0x8008AE98
	dw 0x00131940 ; 0x8008AE9C
	dw 0x3C02800C ; 0x8008AEA0
	dw 0x24420C30 ; 0x8008AEA4
	dw 0x12A00003 ; 0x8008AEA8
	dw 0x00628021 ; 0x8008AEAC
	dw 0x16800015 ; 0x8008AEB0
	dw 0x2402FFFF ; 0x8008AEB4
	dw 0x3C048001 ; 0x8008AEB8
	dw 0x24843DE8 ; 0x8008AEBC
	dw 0x3C058001 ; 0x8008AEC0
	dw 0x24A53E10 ; 0x8008AEC4
	dw 0x3C07800C ; 0x8008AEC8
	dw 0x8CE70DB0 ; 0x8008AECC
	dw 0x0C022EE8 ; 0x8008AED0
	dw 0x240602CD ; 0x8008AED4
	dw 0x3C048001 ; 0x8008AED8
	dw 0x24843E58 ; 0x8008AEDC
	dw 0x02A02821 ; 0x8008AEE0
	dw 0x0C022EE8 ; 0x8008AEE4
	dw 0x02803021 ; 0x8008AEE8
	dw 0x3C048001 ; 0x8008AEEC
	dw 0x24843E2C ; 0x8008AEF0
	dw 0x0C022EE8 ; 0x8008AEF4
	dw 0x00000000 ; 0x8008AEF8
	dw 0x0C022DDF ; 0x8008AEFC
	dw 0x00000000 ; 0x8008AF00
	dw 0x2402FFFF ; 0x8008AF04
	dw 0xA2020002 ; 0x8008AF08
	dw 0xA2020001 ; 0x8008AF0C
	dw 0xAE150008 ; 0x8008AF10
	dw 0x0C026587 ; 0x8008AF14
	dw 0xAE000004 ; 0x8008AF18
	dw 0x3C048009 ; 0x8008AF1C
	dw 0x2484BBC8 ; 0x8008AF20
	dw 0x02802821 ; 0x8008AF24
	dw 0x0C026533 ; 0x8008AF28
	dw 0x00403021 ; 0x8008AF2C
	dw 0xAE020018 ; 0x8008AF30
	dw 0x304200FF ; 0x8008AF34
	dw 0x00021840 ; 0x8008AF38
	dw 0x00621821 ; 0x8008AF3C
	dw 0x8C020110 ; 0x8008AF40
	dw 0x00031980 ; 0x8008AF44
	dw 0x00431021 ; 0x8008AF48
	dw 0x24030400 ; 0x8008AF4C
	dw 0xAE02001C ; 0x8008AF50
	dw 0xAC430094 ; 0x8008AF54
	dw 0x24020003 ; 0x8008AF58
	dw 0xA2020000 ; 0x8008AF5C
	dw 0x24020001 ; 0x8008AF60
	dw 0x3C03800C ; 0x8008AF64
	dw 0x8C630DB4 ; 0x8008AF68
	dw 0x02621004 ; 0x8008AF6C
	dw 0x00621825 ; 0x8008AF70
	dw 0x3C01800C ; 0x8008AF74
	dw 0xAC230DB4 ; 0x8008AF78
	dw 0x0C02655B ; 0x8008AF7C
	dw 0xA200000E ; 0x8008AF80
	dw 0x2402008C ; 0x8008AF84
	dw 0x3C01800C ; 0x8008AF88
	dw 0x00220821 ; 0x8008AF8C
	dw 0xAC2013D4 ; 0x8008AF90
	dw 0x2442FFEC ; 0x8008AF94
	dw 0x0441FFFB ; 0x8008AF98
	dw 0x00000000 ; 0x8008AF9C
	dw 0x2402FFFF ; 0x8008AFA0
	dw 0x3C01800C ; 0x8008AFA4
	dw 0xAC220DB0 ; 0x8008AFA8
	dw 0x0C026553 ; 0x8008AFAC
	dw 0x00000000 ; 0x8008AFB0
	dw 0x3C01800C ; 0x8008AFB4
	dw 0xAC2013C0 ; 0x8008AFB8
	dw 0x3C03800C ; 0x8008AFBC
	dw 0x8C6313C0 ; 0x8008AFC0
	dw 0x3C02800C ; 0x8008AFC4
	dw 0x8C420DB0 ; 0x8008AFC8
	dw 0x00000000 ; 0x8008AFCC
	dw 0x14620003 ; 0x8008AFD0
	dw 0x24020001 ; 0x8008AFD4
	dw 0x08022BFA ; 0x8008AFD8
	dw 0x00001021 ; 0x8008AFDC
	dw 0x3C01800C ; 0x8008AFE0
	dw 0xAC230DB0 ; 0x8008AFE4
	dw 0x1040000A ; 0x8008AFE8
	dw 0x00000000 ; 0x8008AFEC
	dw 0x3C02800C ; 0x8008AFF0
	dw 0x8C420DB0 ; 0x8008AFF4
	dw 0x00000000 ; 0x8008AFF8
	dw 0x00021140 ; 0x8008AFFC
	dw 0x3C01800C ; 0x8008B000
	dw 0x00220821 ; 0x8008B004
	dw 0x8C240C48 ; 0x8008B008
	dw 0x0C02653B ; 0x8008B00C
	dw 0x00000000 ; 0x8008B010
	dw 0x0C02655B ; 0x8008B014
	dw 0x00000000 ; 0x8008B018
	dw 0x8FBF0028 ; 0x8008B01C
	dw 0x8FB50024 ; 0x8008B020
	dw 0x8FB40020 ; 0x8008B024
	dw 0x8FB3001C ; 0x8008B028
	dw 0x8FB20018 ; 0x8008B02C
	dw 0x8FB10014 ; 0x8008B030
	dw 0x8FB00010 ; 0x8008B034
	dw 0x27BD0030 ; 0x8008B038
	dw 0x03E00008 ; 0x8008B03C
	dw 0x00000000 ; 0x8008B040
