	opt	c+, at+, e+, n-
	section .text

	xdef snake_vr_sna_init_80054888
snake_vr_sna_init_80054888:
	dw 0x27BDFFD0 ; 80054888
	dw 0xAFB20020 ; 8005488C
	dw 0x00809021 ; 80054890
	dw 0xAFB30024 ; 80054894
	dw 0x265309E0 ; 80054898
	dw 0xAFBF0028 ; 8005489C
	dw 0xAFB1001C ; 800548A0
	dw 0x14A0007C ; 800548A4
	dw 0xAFB00018 ; 800548A8
	dw 0x3C028005 ; 800548AC
	dw 0x24422AC0 ; 800548B0
	dw 0xAE4209C4 ; 800548B4
	dw 0x0C013CBE ; 800548B8
	dw 0xAE4209C8 ; 800548BC
	dw 0x3C042000 ; 800548C0
	dw 0x0C0138CB ; 800548C4
	dw 0x34848000 ; 800548C8
	dw 0x02402021 ; 800548CC
	dw 0x0C013C98 ; 800548D0
	dw 0x00002821 ; 800548D4
	dw 0x0C0138D3 ; 800548D8
	dw 0x24040060 ; 800548DC
	dw 0x264409FC ; 800548E0
	dw 0x2402FFFF ; 800548E4
	dw 0x3C03800B ; 800548E8
	dw 0x8C639650 ; 800548EC
	dw 0x8E45004C ; 800548F0
	dw 0x265009F0 ; 800548F4
	dw 0xAE420A04 ; 800548F8
	dw 0xAE4309FC ; 800548FC
	dw 0xAE430A08 ; 80054900
	dw 0x8CA50008 ; 80054904
	dw 0x0C017EA0 ; 80054908
	dw 0x02003021 ; 8005490C
	dw 0x8E42004C ; 80054910
	dw 0x8E460A00 ; 80054914
	dw 0x8C440008 ; 80054918
	dw 0x0C016EE9 ; 8005491C
	dw 0x02002821 ; 80054920
	dw 0x00021C00 ; 80054924
	dw 0x00031E02 ; 80054928
	dw 0x240400FF ; 8005492C
	dw 0x10640005 ; 80054930
	dw 0x304200FF ; 80054934
	dw 0x10440003 ; 80054938
	dw 0x00000000 ; 8005493C
	dw 0x10620005 ; 80054940
	dw 0x00000000 ; 80054944
	dw 0x96620008 ; 80054948
	dw 0x00000000 ; 8005494C
	dw 0x34420200 ; 80054950
	dw 0xA6620008 ; 80054954
	dw 0x96620008 ; 80054958
	dw 0x00000000 ; 8005495C
	dw 0x30420200 ; 80054960
	dw 0x1040000B ; 80054964
	dw 0x26450020 ; 80054968
	dw 0x26640010 ; 8005496C
	dw 0x0C005B2E ; 80054970
	dw 0x27A60010 ; 80054974
	dw 0x0C005B9C ; 80054978
	dw 0x27A40010 ; 8005497C
	dw 0xA642006E ; 80054980
	dw 0x2402FFFF ; 80054984
	dw 0xA6420058 ; 80054988
	dw 0xA6420056 ; 8005498C
	dw 0xA6420A24 ; 80054990
	dw 0x2402FFFF ; 80054994
	dw 0xA6420A34 ; 80054998
	dw 0x96620008 ; 8005499C
	dw 0x00000000 ; 800549A0
	dw 0x30420100 ; 800549A4
	dw 0x1440000E ; 800549A8
	dw 0x00000000 ; 800549AC
	dw 0x0C0138C5 ; 800549B0
	dw 0x24041000 ; 800549B4
	dw 0x14400006 ; 800549B8
	dw 0x00000000 ; 800549BC
	dw 0x8E4209A8 ; 800549C0
	dw 0x00000000 ; 800549C4
	dw 0x30420002 ; 800549C8
	dw 0x10400005 ; 800549CC
	dw 0x00000000 ; 800549D0
	dw 0x964209A4 ; 800549D4
	dw 0x02402021 ; 800549D8
	dw 0x0C013C74 ; 800549DC
	dw 0xA6420A34 ; 800549E0
	dw 0x8E42091C ; 800549E4
	dw 0x2403FFFF ; 800549E8
	dw 0x30420200 ; 800549EC
	dw 0x10400005 ; 800549F0
	dw 0xA6430A36 ; 800549F4
	dw 0x96420918 ; 800549F8
	dw 0x02402021 ; 800549FC
	dw 0x0C013C49 ; 80054A00
	dw 0xA6420A36 ; 80054A04
	dw 0x96630008 ; 80054A08
	dw 0x00000000 ; 80054A0C
	dw 0x30620100 ; 80054A10
	dw 0x10400008 ; 80054A14
	dw 0x00008821 ; 80054A18
	dw 0x8E4209B0 ; 80054A1C
	dw 0x00000000 ; 80054A20
	dw 0x8C420018 ; 80054A24
	dw 0x00000000 ; 80054A28
	dw 0x90500003 ; 80054A2C
	dw 0x080152A0 ; 80054A30
	dw 0xA6510A22 ; 80054A34
	dw 0x30620001 ; 80054A38
	dw 0x1040000A ; 80054A3C
	dw 0x24110002 ; 80054A40
	dw 0x8E4209B0 ; 80054A44
	dw 0x00000000 ; 80054A48
	dw 0x8C420004 ; 80054A4C
	dw 0x00000000 ; 80054A50
	dw 0x90500003 ; 80054A54
	dw 0x0C0138CB ; 80054A58
	dw 0x24040040 ; 80054A5C
	dw 0x080152A0 ; 80054A60
	dw 0xA6510A22 ; 80054A64
	dw 0x8E4209B0 ; 80054A68
	dw 0x00000000 ; 80054A6C
	dw 0x8C420004 ; 80054A70
	dw 0x00008821 ; 80054A74
	dw 0x90500000 ; 80054A78
	dw 0xA6510A22 ; 80054A7C
	dw 0x02402021 ; 80054A80
	dw 0x02002821 ; 80054A84
	dw 0x0C0138A9 ; 80054A88
	dw 0x24060004 ; 80054A8C
	dw 0x0C0138CB ; 80054A90
	dw 0x24040010 ; 80054A94
	dw 0x96620008 ; 80054A98
	dw 0x00000000 ; 80054A9C
	dw 0x30420200 ; 80054AA0
	dw 0x14400008 ; 80054AA4
	dw 0x26510028 ; 80054AA8
	dw 0x264409FC ; 80054AAC
	dw 0x3C02800B ; 80054AB0
	dw 0x8C429650 ; 80054AB4
	dw 0x26450020 ; 80054AB8
	dw 0x0C017EEC ; 80054ABC
	dw 0xAE4209FC ; 80054AC0
	dw 0x26510028 ; 80054AC4
	dw 0x02202021 ; 80054AC8
	dw 0x2650006C ; 80054ACC
	dw 0x02002821 ; 80054AD0
	dw 0x0C009AB4 ; 80054AD4
	dw 0x24060003 ; 80054AD8
	dw 0x02202021 ; 80054ADC
	dw 0x02002821 ; 80054AE0
	dw 0x0C009AB4 ; 80054AE4
	dw 0x24060003 ; 80054AE8
	dw 0x264409FC ; 80054AEC
	dw 0x0C017ECA ; 80054AF0
	dw 0x26450020 ; 80054AF4
	dw 0x86630016 ; 80054AF8
	dw 0x00000000 ; 80054AFC
	dw 0x0043102A ; 80054B00
	dw 0x10400059 ; 80054B04
	dw 0x00000000 ; 80054B08
	dw 0x0C013CAB ; 80054B0C
	dw 0x02402021 ; 80054B10
	dw 0x0C0138D3 ; 80054B14
	dw 0x24040010 ; 80054B18
	dw 0x02402021 ; 80054B1C
	dw 0x0C0138DB ; 80054B20
	dw 0x3C050020 ; 80054B24
	dw 0x3C042000 ; 80054B28
	dw 0x0C0138D3 ; 80054B2C
	dw 0x34848000 ; 80054B30
	dw 0x96620008 ; 80054B34
	dw 0x00000000 ; 80054B38
	dw 0x30420200 ; 80054B3C
	dw 0x10400004 ; 80054B40
	dw 0x240201C2 ; 80054B44
	dw 0xA6420058 ; 80054B48
	dw 0xA6420056 ; 80054B4C
	dw 0xA6420A24 ; 80054B50
	dw 0x96620008 ; 80054B54
	dw 0x00000000 ; 80054B58
	dw 0x30420002 ; 80054B5C
	dw 0x1440001A ; 80054B60
	dw 0x00000000 ; 80054B64
	dw 0x86430A34 ; 80054B68
	dw 0x86440A36 ; 80054B6C
	dw 0x04600007 ; 80054B70
	dw 0x3C02800B ; 80054B74
	dw 0xA4432A16 ; 80054B78
	dw 0x2462FFFE ; 80054B7C
	dw 0x2C420003 ; 80054B80
	dw 0x10400002 ; 80054B84
	dw 0x00000000 ; 80054B88
	dw 0xA6400A22 ; 80054B8C
	dw 0x0480000E ; 80054B90
	dw 0x3C02800B ; 80054B94
	dw 0xA4442A14 ; 80054B98
	dw 0x24020001 ; 80054B9C
	dw 0x3C01800B ; 80054BA0
	dw 0xA4229638 ; 80054BA4
	dw 0x24020009 ; 80054BA8
	dw 0x14820004 ; 80054BAC
	dw 0x24020004 ; 80054BB0
	dw 0x24020002 ; 80054BB4
	dw 0x080152F3 ; 80054BB8
	dw 0xA6420A22 ; 80054BBC
	dw 0x14820002 ; 80054BC0
	dw 0x00000000 ; 80054BC4
	dw 0xA6400A22 ; 80054BC8
	dw 0x96620008 ; 80054BCC
	dw 0x00000000 ; 80054BD0
	dw 0x30420008 ; 80054BD4
	dw 0x14400005 ; 80054BD8
	dw 0x00000000 ; 80054BDC
	dw 0x92420075 ; 80054BE0
	dw 0x00000000 ; 80054BE4
	dw 0x304200FD ; 80054BE8
	dw 0xA2420075 ; 80054BEC
	dw 0x96620008 ; 80054BF0
	dw 0x00000000 ; 80054BF4
	dw 0x30420001 ; 80054BF8
	dw 0x10400006 ; 80054BFC
	dw 0x00000000 ; 80054C00
	dw 0x0C0140D4 ; 80054C04
	dw 0x02402021 ; 80054C08
	dw 0x02402021 ; 80054C0C
	dw 0x0C0138E0 ; 80054C10
	dw 0x24050004 ; 80054C14
	dw 0x96620008 ; 80054C18
	dw 0x00000000 ; 80054C1C
	dw 0x30420100 ; 80054C20
	dw 0x10400004 ; 80054C24
	dw 0x02402021 ; 80054C28
	dw 0x3C058005 ; 80054C2C
	dw 0x08015314 ; 80054C30
	dw 0x24A54364 ; 80054C34
	dw 0x3C03800A ; 80054C38
	dw 0x86420A22 ; 80054C3C
	dw 0x2463CBDC ; 80054C40
	dw 0x00021080 ; 80054C44
	dw 0x00431021 ; 80054C48
	dw 0x8C450000 ; 80054C4C
	dw 0x0C01389B ; 80054C50
	dw 0x00000000 ; 80054C54
	dw 0x86620004 ; 80054C58
	dw 0x96640004 ; 80054C5C
	dw 0x04400002 ; 80054C60
	dw 0x00000000 ; 80054C64
	dw 0xA644006E ; 80054C68
	dw 0x8FBF0028 ; 80054C6C
	dw 0x8FB30024 ; 80054C70
	dw 0x8FB20020 ; 80054C74
	dw 0x8FB1001C ; 80054C78
	dw 0x8FB00018 ; 80054C7C
	dw 0x03E00008 ; 80054C80
	dw 0x27BD0030 ; 80054C84
