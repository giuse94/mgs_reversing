#include "linker.h"


int s03c_dword_800C32C0 = 0x00000AFF;
int s03c_dword_800C32C4 = 0x000004FF;
int s03c_dword_800C32C8 = 0x00000000;
int s03c_dword_800C32CC = 0x00000000;
int s03c_dword_800C32D0 = 0x00001B58;
int s03c_dword_800C32D4 = 0x00000000;
int s03c_dword_800C32D8 = 0x00000064;
int s03c_dword_800C32DC = 0x0000FC00;
int s03c_dword_800C32E0 = 0x00000000;
int s03c_dword_800C32E4 = 0x00000000;
int s03c_dword_800C32E8 = 0x00000DAC;
int s03c_dword_800C32EC = 0x00000000;
int s03c_dword_800C32F0 = 0x0000012C;
int s03c_dword_800C32F4 = 0x02EE012C;
int s03c_dword_800C32F8 = 0x0000012C;
int s03c_dword_800C32FC = 0x0001DCD3;
int s03c_dword_800C3300 = 0x00010001;
int s03c_dword_800C3304 = 0x01F40001;
int s03c_dword_800C3308 = 0x00500001;
int s03c_dword_800C330C = 0x00000050;
int s03c_dword_800C3310 = 0x00000000;
int s03c_dword_800C3314 = 0x800D75D8;
int s03c_dword_800C3318 = 0x0001FAD3;
int s03c_dword_800C331C = 0x00010001;
int s03c_dword_800C3320 = 0x01F40001;
int s03c_dword_800C3324 = 0x00500001;
int s03c_dword_800C3328 = 0x00000050;
int s03c_dword_800C332C = 0x00000000;
int s03c_dword_800C3330 = 0x800D773C;
int s03c_dword_800C3334 = 0x0001FAD3;
int s03c_dword_800C3338 = 0x00010001;
int s03c_dword_800C333C = 0x01F40001;
int s03c_dword_800C3340 = 0x00500001;
int s03c_dword_800C3344 = 0x00000050;
int s03c_dword_800C3348 = 0x00000000;
int s03c_dword_800C334C = 0x800D7840;
int s03c_dword_800C3350 = 0x00011968;
int s03c_dword_800C3354 = 0x00010001;
int s03c_dword_800C3358 = 0x00000001;
int s03c_dword_800C335C = 0x00460001;
int s03c_dword_800C3360 = 0x00FF0046;
int s03c_dword_800C3364 = 0x00000000;
int s03c_dword_800C3368 = 0x800D7944;
int s03c_dword_800C336C = 0xFAD3DCD3;
int s03c_dword_800C3370 = 0x00001968;
int s03c_dword_800C3374 = 0x0001F314;
int s03c_dword_800C3378 = 0x00010001;
int s03c_dword_800C337C = 0x03200001;
int s03c_dword_800C3380 = 0x02580003;
int s03c_dword_800C3384 = 0x00FA0258;
int s03c_dword_800C3388 = 0x00000000;
int s03c_dword_800C338C = 0x800D79AC;
int s03c_dword_800C3390 = 0x0001F7BB;
int s03c_dword_800C3394 = 0x00010001;
int s03c_dword_800C3398 = 0x00000001;
int s03c_dword_800C339C = 0x00020001;
int s03c_dword_800C33A0 = 0x00000002;
int s03c_dword_800C33A4 = 0x00000000;
int s03c_dword_800C33A8 = 0x800D79D0;
int s03c_dword_800C33AC = 0xFE0C0005;
int s03c_dword_800C33B0 = 0x00000050;
int s03c_dword_800C33B4 = 0x00000000;
int s03c_dword_800C33B8 = 0x00000000;
int s03c_dword_800C33BC = 0xFFFFFFFF;
int s03c_dword_800C33C0 = 0xFFFFFFFF;
int s03c_dword_800C33C4 = 0x00000000;
int s03c_dword_800C33C8 = 0x00000000;
int s03c_dword_800C33CC = 0x00000000;
int s03c_dword_800C33D0 = 0x00000000;
int s03c_dword_800C33D4 = 0x00000000;


const char s03c_dword_800D7538[] = {0xc6, 0xfe, 0xa4, 0xeb};
const char s03c_dword_800D753C[] = {0x0, 0x0, 0x0, 0x0};
const char s03c_aRoutobira_800D7540[] = "rou_tobira";
const char s03c_dword_800D754C[] = {0xbd, 0xd0, 0xa4, 0xeb};
const char s03c_dword_800D7550[] = {0x0, 0x0, 0x0, 0x0};
const char s03c_dword_800D7554[] = {0x0, 0x0, 0x0, 0x0};
const int s03c_dword_800D7558 = 0x800C7CB0;
const int s03c_dword_800D755C = 0x800C7CEC;
const int s03c_dword_800D7560 = 0x800C7D54;
const int s03c_dword_800D7564 = 0x800C7D54;
const int s03c_dword_800D7568 = 0x800C7E94;
const int s03c_dword_800D756C = 0x800C7F1C;
const char s03c_dword_800D7570[] = {0xa5, 0xb9, 0xa5, 0xcd};
const char s03c_dword_800D7574[] = {0xa1, 0xbc, 0xa5, 0xaf};
const char s03c_dword_800D7578[] = {0x0, 0x0, 0x0, 0x0};
const char s03c_aRunmove_800D757C[] = "run_move";
const char s03c_dword_800D7588[] = {0xa5, 0xb8, 0xa5, 0xe7};
const char s03c_dword_800D758C[] = {0xa5, 0xcb, 0xa1, 0xbc};
const char s03c_dword_800D7590[] = {0x0, 0x0, 0x0, 0x0};
const char s03c_dword_800D7594[] = {0x0, 0x0, 0x0, 0x0};
const int s03c_dword_800D7598 = 0x800C9E40;
const int s03c_dword_800D759C = 0x800C9E50;
const int s03c_dword_800D75A0 = 0x800C9E60;
const int s03c_dword_800D75A4 = 0x800C9E70;
const int s03c_dword_800D75A8 = 0x800C9E80;
const int s03c_dword_800D75AC = 0x800C9E90;
const int s03c_dword_800D75B0 = 0x800C9EA0;
const int s03c_dword_800D75B4 = 0x800C9EB0;
const int s03c_dword_800D75B8 = 0x800C9EC0;
const char s03c_aJohnny_800D75BC[] = "johnny";
const char s03c_aJohc_800D75C4[] = "joh_03c";
const char s03c_dword_800D75CC[] = {'j', 'o', 'h', 'n'};
const char s03c_dword_800D75D0[] = {'n', 'y', '.', 'c'};
const char s03c_dword_800D75D4[] = {0x0, 'A', 'H', 0x8};
const char s03c_dword_800D75D8[] = {0x1, 'V', 0x4, 0x0};
const char s03c_dword_800D75DC[] = {0xb, 0x0, '^', 0x0};
const char s03c_dword_800D75E0[] = {0xb1, 0x1, 0x9, 0x1};
const char s03c_dword_800D75E4[] = {0x0, 0xc, 0x0, 0x4};
const char s03c_dword_800D75E8[] = {'\n', 0x0, 'd', 0x0};
const char s03c_dword_800D75EC[] = {'d', 0x8, '2', 0x19};
const char s03c_dword_800D75F0[] = {0x14, 0x2, 0x0, 0x1};
const char s03c_dword_800D75F4[] = {0xd, '\n', 0x0, 'd'};
const char s03c_dword_800D75F8[] = {0x0, 'd', 0x8, '2'};
const char s03c_dword_800D75FC[] = {0x96, 0xaa, 0x2, 0x0};
const char s03c_dword_800D7600[] = {0x3, '\n', 0xff, 0x9c};
const char s03c_dword_800D7604[] = {0xff, 0x9c, 0x8, 0xce};
const char s03c_dword_800D7608[] = {'j', 'V', 0x2, 0x0};
const char s03c_dword_800D760C[] = {0x16, '\n', 0x1, ','};
const char s03c_dword_800D7610[] = {0xfe, 0x98, 0x8, 0xce};
const char s03c_dword_800D7614[] = {0xe7, 0xec, 0x2, 0x0};
const char s03c_dword_800D7618[] = {0x1, '\n', 0x1, ','};
const char s03c_dword_800D761C[] = {0xff, 0xe2, 0x8, 0xce};
const char s03c_dword_800D7620[] = {0xe7, 0xec, 0x2, 0x0};
const char s03c_dword_800D7624[] = {0x1, '\n', 0x1, ','};
const char s03c_dword_800D7628[] = {0xff, 0xf4, 0x2, 0x0};
const char s03c_dword_800D762C[] = {0x1, '\n', 0xfa, 0xba};
const char s03c_dword_800D7630[] = {0x0, 0xf0, 0x2, 0x0};
const char s03c_dword_800D7634[] = {0x1, 0xf, 0x1, 0x0};
const char s03c_dword_800D7638[] = {0xc, 0x0, 0x4, '\n'};
const char s03c_dword_800D763C[] = {0x0, '2', 0x0, '2'};
const char s03c_dword_800D7640[] = {0x8, '2', 0x19, 0x14};
const char s03c_dword_800D7644[] = {0x2, 0x0, 0x1, 0xd};
const char s03c_dword_800D7648[] = {'\n', 0x0, '2', 0x0};
const char s03c_dword_800D764C[] = {'2', 0x8, '2', 0x96};
const char s03c_dword_800D7650[] = {0xaa, 0x2, 0x0, 0x3};
const char s03c_dword_800D7654[] = {'\n', 0xff, 0xce, 0xff};
const char s03c_dword_800D7658[] = {0xce, 0x8, 0xce, 'j'};
const char s03c_dword_800D765C[] = {'V', 0x2, 0x0, 0x16};
const char s03c_dword_800D7660[] = {'\n', 0x0, 0x96, 0xff};
const char s03c_dword_800D7664[] = {'L', 0x8, 0xce, 0xe7};
const char s03c_dword_800D7668[] = {0xec, 0x2, 0x0, 0x1};
const char s03c_dword_800D766C[] = {'\n', 0x0, 0x96, 0xff};
const char s03c_dword_800D7670[] = {0xf1, 0x8, 0xce, 0xe7};
const char s03c_dword_800D7674[] = {0xec, 0x2, 0x0, 0x1};
const char s03c_dword_800D7678[] = {'\n', 0x0, 0x96, 0xff};
const char s03c_dword_800D767C[] = {0xfa, 0x2, 0x0, 0x1};
const char s03c_dword_800D7680[] = {'\n', 0xfd, ']', 0x0};
const char s03c_dword_800D7684[] = {'x', 0x2, 0x0, 0x1};
const char s03c_dword_800D7688[] = {0xf, '\n', 0xff, 0xd8};
const char s03c_dword_800D768C[] = {0xff, 0xd8, 0x1, 0x0};
const char s03c_dword_800D7690[] = {0xc, 0x0, 0x4, '\n'};
const char s03c_dword_800D7694[] = {0x0, 0x19, 0x0, 0x19};
const char s03c_dword_800D7698[] = {0x8, '2', 0x19, 0x14};
const char s03c_dword_800D769C[] = {0x2, 0x0, 0x1, 0xd};
const char s03c_dword_800D76A0[] = {'\n', 0x0, 0x19, 0x0};
const char s03c_dword_800D76A4[] = {0x19, 0x8, '2', 0x96};
const char s03c_dword_800D76A8[] = {0xaa, 0x2, 0x0, 0x3};
const char s03c_dword_800D76AC[] = {'\n', 0xff, 0xe7, 0xff};
const char s03c_dword_800D76B0[] = {0xe7, 0x8, 0xce, 'j'};
const char s03c_dword_800D76B4[] = {'V', 0x2, 0x0, 0x16};
const char s03c_dword_800D76B8[] = {'\n', 0x0, 'K', 0xff};
const char s03c_dword_800D76BC[] = {0xa6, 0x8, 0xce, 0xe7};
const char s03c_dword_800D76C0[] = {0xec, 0x2, 0x0, 0x1};
const char s03c_dword_800D76C4[] = {'\n', 0x0, 'K', 0xff};
const char s03c_dword_800D76C8[] = {0xf9, 0x8, 0xce, 0xe7};
const char s03c_dword_800D76CC[] = {0xec, 0x2, 0x0, 0x1};
const char s03c_dword_800D76D0[] = {'\n', 0x0, 'K', 0xff};
const char s03c_dword_800D76D4[] = {0xf9, 0x2, 0x0, 0x1};
const char s03c_dword_800D76D8[] = {'\n', 0xfe, 0xd4, 0x0};
const char s03c_dword_800D76DC[] = {'<', 0x2, 0x0, 0x1};
const char s03c_dword_800D76E0[] = {0xf, '\n', 0xff, 0xc4};
const char s03c_dword_800D76E4[] = {0xff, 0xc4, 0x1, 0x0};
const char s03c_dword_800D76E8[] = {0xc, 0x0, 0x4, '\n'};
const char s03c_dword_800D76EC[] = {0x0, '\n', 0x0, '\n'};
const char s03c_dword_800D76F0[] = {0x8, '2', 0x19, 0x14};
const char s03c_dword_800D76F4[] = {0x2, 0x0, 0x1, 0xd};
const char s03c_dword_800D76F8[] = {'\n', 0x0, '\n', 0x0};
const char s03c_dword_800D76FC[] = {'\n', 0x8, '2', 0x96};
const char s03c_dword_800D7700[] = {0xaa, 0x2, 0x0, 0x3};
const char s03c_dword_800D7704[] = {'\n', 0xff, 0xf6, 0xff};
const char s03c_dword_800D7708[] = {0xf6, 0x8, 0xce, 'j'};
const char s03c_dword_800D770C[] = {'V', 0x2, 0x0, 0x16};
const char s03c_dword_800D7710[] = {'\n', 0x0, 0x1e, 0xff};
const char s03c_dword_800D7714[] = {0xdc, 0x8, 0xce, 0xe7};
const char s03c_dword_800D7718[] = {0xec, 0x2, 0x0, 0x1};
const char s03c_dword_800D771C[] = {'\n', 0x0, 0x1e, 0xff};
const char s03c_dword_800D7720[] = {0xfe, 0x8, 0xce, 0xe7};
const char s03c_dword_800D7724[] = {0xec, 0x2, 0x0, 0x1};
const char s03c_dword_800D7728[] = {'\n', 0x0, 0x1e, 0xff};
const char s03c_dword_800D772C[] = {0xfe, 0x2, 0x0, 0x1};
const char s03c_dword_800D7730[] = {'\n', 0xff, 0xb0, 0x0};
const char s03c_dword_800D7734[] = {'\n', 0x2, 0x0, 0x1};
const char s03c_dword_800D7738[] = {0xf, 0x0, 0x0, 0x0};
const char s03c_dword_800D773C[] = {0x0, 0xf9, 0x3, 0x0};
const char s03c_dword_800D7740[] = {0x9, 0x0, '\\', 0x0};
const char s03c_dword_800D7744[] = {0xaf, 0x1, 0x0, 0xc};
const char s03c_dword_800D7748[] = {0x0, 0x4, '\n', 0x0};
const char s03c_dword_800D774C[] = {'d', 0x0, 'd', 0x8};
const char s03c_dword_800D7750[] = {'-', '#', 0x14, 0x2};
const char s03c_dword_800D7754[] = {0x0, 0x1, 0xd, '\n'};
const char s03c_dword_800D7758[] = {0x0, 'd', 0x0, 'd'};
const char s03c_dword_800D775C[] = {0x8, 'F', 'n', 0xaa};
const char s03c_dword_800D7760[] = {0x2, 0x0, 0x3, '\n'};
const char s03c_dword_800D7764[] = {0xff, 0x9c, 0xff, 0x9c};
const char s03c_dword_800D7768[] = {0x8, 0xba, 0x92, 'V'};
const char s03c_dword_800D776C[] = {0x2, 0x0, 0x16, '\n'};
const char s03c_dword_800D7770[] = {0x1, ',', 0xfe, 0x98};
const char s03c_dword_800D7774[] = {0x8, 0xd3, 0xdd, 0xec};
const char s03c_dword_800D7778[] = {0x2, 0x0, 0x1, '\n'};
const char s03c_dword_800D777C[] = {0x1, ',', 0xff, 0xe2};
const char s03c_dword_800D7780[] = {0x8, 0xd3, 0xdd, 0xec};
const char s03c_dword_800D7784[] = {0x2, 0x0, 0x1, '\n'};
const char s03c_dword_800D7788[] = {0x1, ',', 0xff, 0xf4};
const char s03c_dword_800D778C[] = {0x2, 0x0, 0x1, '\n'};
const char s03c_dword_800D7790[] = {0xfa, 0xba, 0x0, 0xf0};
const char s03c_dword_800D7794[] = {0x2, 0x0, 0x1, 0xf};
const char s03c_dword_800D7798[] = {0x1, 0x0, 0xc, 0x0};
const char s03c_dword_800D779C[] = {0x4, '\n', 0x0, '2'};
const char s03c_dword_800D77A0[] = {0x0, '2', 0x8, '-'};
const char s03c_dword_800D77A4[] = {'#', 0x14, 0x2, 0x0};
const char s03c_dword_800D77A8[] = {0x1, 0xd, '\n', 0x0};
const char s03c_dword_800D77AC[] = {'2', 0x0, '2', 0x8};
const char s03c_dword_800D77B0[] = {'F', 'n', 0xaa, 0x2};
const char s03c_dword_800D77B4[] = {0x0, 0x3, '\n', 0xff};
const char s03c_dword_800D77B8[] = {0xce, 0xff, 0xce, 0x8};
const char s03c_dword_800D77BC[] = {0xba, 0x92, 'V', 0x2};
const char s03c_dword_800D77C0[] = {0x0, 0x16, '\n', 0x0};
const char s03c_dword_800D77C4[] = {0x96, 0xff, 'L', 0x8};
const char s03c_dword_800D77C8[] = {0xd3, 0xdd, 0xec, 0x2};
const char s03c_dword_800D77CC[] = {0x0, 0x1, '\n', 0x0};
const char s03c_dword_800D77D0[] = {0x96, 0xff, 0xf1, 0x8};
const char s03c_dword_800D77D4[] = {0xd3, 0xdd, 0xec, 0x2};
const char s03c_dword_800D77D8[] = {0x0, 0x1, '\n', 0x0};
const char s03c_dword_800D77DC[] = {0x96, 0xff, 0xfa, 0x2};
const char s03c_dword_800D77E0[] = {0x0, 0x1, '\n', 0xfd};
const char s03c_dword_800D77E4[] = {']', 0x0, 'x', 0x2};
const char s03c_dword_800D77E8[] = {0x0, 0x1, 0xf, 0x1};
const char s03c_dword_800D77EC[] = {0x0, 0xc, 0x0, 0x4};
const char s03c_dword_800D77F0[] = {'\n', 0x0, 0x19, 0x0};
const char s03c_dword_800D77F4[] = {0x19, 0x8, '2', 0x19};
const char s03c_dword_800D77F8[] = {0x14, 0x2, 0x0, 0x1};
const char s03c_dword_800D77FC[] = {0xd, '\n', 0x0, 0x19};
const char s03c_dword_800D7800[] = {0x0, 0x19, 0x8, '2'};
const char s03c_dword_800D7804[] = {0x96, 0xaa, 0x2, 0x0};
const char s03c_dword_800D7808[] = {0x3, '\n', 0xff, 0xe7};
const char s03c_dword_800D780C[] = {0xff, 0xe7, 0x8, 0xce};
const char s03c_dword_800D7810[] = {'j', 'V', 0x2, 0x0};
const char s03c_dword_800D7814[] = {0x16, '\n', 0x0, 'K'};
const char s03c_dword_800D7818[] = {0xff, 0xa6, 0x8, 0xce};
const char s03c_dword_800D781C[] = {0xe7, 0xec, 0x2, 0x0};
const char s03c_dword_800D7820[] = {0x1, '\n', 0x0, 'K'};
const char s03c_dword_800D7824[] = {0xff, 0xf9, 0x8, 0xce};
const char s03c_dword_800D7828[] = {0xe7, 0xec, 0x2, 0x0};
const char s03c_dword_800D782C[] = {0x1, '\n', 0x0, 'K'};
const char s03c_dword_800D7830[] = {0xff, 0xf9, 0x2, 0x0};
const char s03c_dword_800D7834[] = {0x1, '\n', 0xfe, 0xd4};
const char s03c_dword_800D7838[] = {0x0, '<', 0x2, 0x0};
const char s03c_dword_800D783C[] = {0x1, 0xf, 0x0, 0x0};
const char s03c_dword_800D7840[] = {0x0, 0xf9, 0x3, 0x0};
const char s03c_dword_800D7844[] = {0x9, 0x0, '\\', 0x0};
const char s03c_dword_800D7848[] = {0xaf, 0x1, 0x0, 0xc};
const char s03c_dword_800D784C[] = {0x0, 0x4, '\n', 0x0};
const char s03c_dword_800D7850[] = {'d', 0x0, 'd', 0x8};
const char s03c_dword_800D7854[] = {0x19, '&', '-', 0x2};
const char s03c_dword_800D7858[] = {0x0, 0x1, 0xd, '\n'};
const char s03c_dword_800D785C[] = {0x0, 'd', 0x0, 'd'};
const char s03c_dword_800D7860[] = {0x8, 0x96, 'b', 'F'};
const char s03c_dword_800D7864[] = {0x2, 0x0, 0x3, '\n'};
const char s03c_dword_800D7868[] = {0xff, 0x9c, 0xff, 0x9c};
const char s03c_dword_800D786C[] = {0x8, 'j', 0x9e, 0xba};
const char s03c_dword_800D7870[] = {0x2, 0x0, 0x16, '\n'};
const char s03c_dword_800D7874[] = {0x1, ',', 0xfe, 0x98};
const char s03c_dword_800D7878[] = {0x8, 0xe7, 0xda, 0xd3};
const char s03c_dword_800D787C[] = {0x2, 0x0, 0x1, '\n'};
const char s03c_dword_800D7880[] = {0x1, ',', 0xff, 0xe2};
const char s03c_dword_800D7884[] = {0x8, 0xe7, 0xda, 0xd3};
const char s03c_dword_800D7888[] = {0x2, 0x0, 0x1, '\n'};
const char s03c_dword_800D788C[] = {0x1, ',', 0xff, 0xf4};
const char s03c_dword_800D7890[] = {0x2, 0x0, 0x1, '\n'};
const char s03c_dword_800D7894[] = {0xfa, 0xba, 0x0, 0xf0};
const char s03c_dword_800D7898[] = {0x2, 0x0, 0x1, 0xf};
const char s03c_dword_800D789C[] = {0x1, 0x0, 0xc, 0x0};
const char s03c_dword_800D78A0[] = {0x4, '\n', 0x0, '2'};
const char s03c_dword_800D78A4[] = {0x0, '2', 0x8, '-'};
const char s03c_dword_800D78A8[] = {'#', 0x14, 0x2, 0x0};
const char s03c_dword_800D78AC[] = {0x1, 0xd, '\n', 0x0};
const char s03c_dword_800D78B0[] = {'2', 0x0, '2', 0x8};
const char s03c_dword_800D78B4[] = {'F', 'n', 0xaa, 0x2};
const char s03c_dword_800D78B8[] = {0x0, 0x3, '\n', 0xff};
const char s03c_dword_800D78BC[] = {0xce, 0xff, 0xce, 0x8};
const char s03c_dword_800D78C0[] = {0xba, 0x92, 'V', 0x2};
const char s03c_dword_800D78C4[] = {0x0, 0x16, '\n', 0x0};
const char s03c_dword_800D78C8[] = {0x96, 0xff, 'L', 0x8};
const char s03c_dword_800D78CC[] = {0xd3, 0xdd, 0xec, 0x2};
const char s03c_dword_800D78D0[] = {0x0, 0x1, '\n', 0x0};
const char s03c_dword_800D78D4[] = {0x96, 0xff, 0xf1, 0x8};
const char s03c_dword_800D78D8[] = {0xd3, 0xdd, 0xec, 0x2};
const char s03c_dword_800D78DC[] = {0x0, 0x1, '\n', 0x0};
const char s03c_dword_800D78E0[] = {0x96, 0xff, 0xfa, 0x2};
const char s03c_dword_800D78E4[] = {0x0, 0x1, '\n', 0xfd};
const char s03c_dword_800D78E8[] = {']', 0x0, 'x', 0x2};
const char s03c_dword_800D78EC[] = {0x0, 0x1, 0xf, 0x1};
const char s03c_dword_800D78F0[] = {0x0, 0xc, 0x0, 0x4};
const char s03c_dword_800D78F4[] = {'\n', 0x0, 0x19, 0x0};
const char s03c_dword_800D78F8[] = {0x19, 0x8, '2', 0x19};
const char s03c_dword_800D78FC[] = {0x14, 0x2, 0x0, 0x1};
const char s03c_dword_800D7900[] = {0xd, '\n', 0x0, 0x19};
const char s03c_dword_800D7904[] = {0x0, 0x19, 0x8, '2'};
const char s03c_dword_800D7908[] = {0x96, 0xaa, 0x2, 0x0};
const char s03c_dword_800D790C[] = {0x3, '\n', 0xff, 0xe7};
const char s03c_dword_800D7910[] = {0xff, 0xe7, 0x8, 0xce};
const char s03c_dword_800D7914[] = {'j', 'V', 0x2, 0x0};
const char s03c_dword_800D7918[] = {0x16, '\n', 0x0, 'K'};
const char s03c_dword_800D791C[] = {0xff, 0xa6, 0x8, 0xce};
const char s03c_dword_800D7920[] = {0xe7, 0xec, 0x2, 0x0};
const char s03c_dword_800D7924[] = {0x1, '\n', 0x0, 'K'};
const char s03c_dword_800D7928[] = {0xff, 0xf9, 0x8, 0xce};
const char s03c_dword_800D792C[] = {0xe7, 0xec, 0x2, 0x0};
const char s03c_dword_800D7930[] = {0x1, '\n', 0x0, 'K'};
const char s03c_dword_800D7934[] = {0xff, 0xf9, 0x2, 0x0};
const char s03c_dword_800D7938[] = {0x1, '\n', 0xfe, 0xd4};
const char s03c_dword_800D793C[] = {0x0, '<', 0x2, 0x0};
const char s03c_dword_800D7940[] = {0x1, 0xf, 0x0, 0x0};
const char s03c_dword_800D7944[] = {0x0, 0x4, 0x1, 0x0};
const char s03c_dword_800D7948[] = {0x5, 0x2, 0x0, 0x1};
const char s03c_dword_800D794C[] = {0xf, 0x0, 0x0, 0x0};
const int s03c_dword_800D7950 = 0x800CA940;
const int s03c_dword_800D7954 = 0x800CA950;
const int s03c_dword_800D7958 = 0x800CA968;
const int s03c_dword_800D795C = 0x800CA978;
const int s03c_dword_800D7960 = 0x800CA990;
const int s03c_dword_800D7964 = 0x800CA9A0;
const int s03c_dword_800D7968 = 0x800CA9B8;
const char s03c_dword_800D796C[] = {0x0, 0x0, 0x0, 0x0};
const int s03c_dword_800D7970 = 0x800CAA78;
const int s03c_dword_800D7974 = 0x800CAA88;
const int s03c_dword_800D7978 = 0x800CAAA0;
const int s03c_dword_800D797C = 0x800CAAB0;
const int s03c_dword_800D7980 = 0x800CAAC8;
const int s03c_dword_800D7984 = 0x800CAAD8;
const int s03c_dword_800D7988 = 0x800CAAF0;
const char s03c_dword_800D798C[] = {0x0, 0x0, 0x0, 0x0};
const int s03c_dword_800D7990 = 0x800CABB0;
const int s03c_dword_800D7994 = 0x800CABC4;
const int s03c_dword_800D7998 = 0x800CABDC;
const int s03c_dword_800D799C = 0x800CABEC;
const int s03c_dword_800D79A0 = 0x800CAC04;
const int s03c_dword_800D79A4 = 0x800CAC14;
const int s03c_dword_800D79A8 = 0x800CAC2C;
const char s03c_dword_800D79AC[] = {0x0, 0x1c, 0x1, 0x0};
const char s03c_dword_800D79B0[] = {0x5, 0x1, 0xfe, 0x4};
const char s03c_dword_800D79B4[] = {0x0, 0x0, 0x1, 0x90};
const char s03c_dword_800D79B8[] = {0x0, 0x0, 0xc, 0x0};
const char s03c_dword_800D79BC[] = {0x9, 0x1, 0xff, '\n'};
const char s03c_dword_800D79C0[] = {0x0, 0x14, 0x0, 0x14};
const char s03c_dword_800D79C4[] = {0x8, 0xe7, 0xe7, 0xe7};
const char s03c_dword_800D79C8[] = {0x2, 0x0, 0x1, 0xd};
const char s03c_dword_800D79CC[] = {0xf, 0x0, 0x0, 0x0};
const char s03c_dword_800D79D0[] = {0x0, 0x96, 0x3, 0x0};
const char s03c_dword_800D79D4[] = {0x9, 0x0, ';', 0x0};
const char s03c_dword_800D79D8[] = {'m', 0x8, 0x0, 0x2};
const char s03c_dword_800D79DC[] = {0x1e, 0x2, 0x0, 0x1};
const char s03c_dword_800D79E0[] = {0xc, 0x0, 0x19, 0x8};
const char s03c_dword_800D79E4[] = {0x4, 0x6, 0x6, '\n'};
const char s03c_dword_800D79E8[] = {0x0, 0x4, 0x0, 0x4};
const char s03c_dword_800D79EC[] = {0x4, 0x0, 0x4, 0x0};
const char s03c_dword_800D79F0[] = {0x14, 0x0, 0x0, 0x2};
const char s03c_dword_800D79F4[] = {0x0, 0x1, 0xd, 0xc};
const char s03c_dword_800D79F8[] = {0x0, 0xf, '\n', 0x0};
const char s03c_dword_800D79FC[] = {0x4, 0x0, 0x4, 0x4};
const char s03c_dword_800D7A00[] = {0x0, 0x4, 0x0, 0x14};
const char s03c_dword_800D7A04[] = {0x0, 0x0, 0x2, 0x0};
const char s03c_dword_800D7A08[] = {0x1, 0xd, 0xf, 0x8};
const char s03c_dword_800D7A0C[] = {0x0, 0x2, 0x1e, 0x2};
const char s03c_dword_800D7A10[] = {0x0, 0xb, 0xc, 0x0};
const char s03c_dword_800D7A14[] = {0x19, 0x8, 0x4, 0x6};
const char s03c_dword_800D7A18[] = {0x6, '\n', 0x0, 0x4};
const char s03c_dword_800D7A1C[] = {0x0, 0x4, 0x4, 0x0};
const char s03c_dword_800D7A20[] = {0x4, 0x0, 0x14, 0x0};
const char s03c_dword_800D7A24[] = {0x0, 0x2, 0x0, 0x1};
const char s03c_dword_800D7A28[] = {0xd, 0xc, 0x0, 0xf};
const char s03c_dword_800D7A2C[] = {'\n', 0x0, 0x4, 0x0};
const char s03c_dword_800D7A30[] = {0x4, 0x4, 0x0, 0x4};
const char s03c_dword_800D7A34[] = {0x0, 0x14, 0x0, 0x0};
const char s03c_dword_800D7A38[] = {0x2, 0x0, 0x1, 0xd};
const char s03c_dword_800D7A3C[] = {0xf, 0x8, 0x0, 0x2};
const char s03c_dword_800D7A40[] = {0x1e, 0x2, 0x0, 0x15};
const char s03c_dword_800D7A44[] = {0xc, 0x0, 0x19, 0x8};
const char s03c_dword_800D7A48[] = {0x4, 0x6, 0x6, '\n'};
const char s03c_dword_800D7A4C[] = {0x0, 0x4, 0x0, 0x4};
const char s03c_dword_800D7A50[] = {0x4, 0x0, 0x4, 0x0};
const char s03c_dword_800D7A54[] = {0x14, 0x0, 0x0, 0x2};
const char s03c_dword_800D7A58[] = {0x0, 0x1, 0xd, 0xc};
const char s03c_dword_800D7A5C[] = {0x0, 0xf, '\n', 0x0};
const char s03c_dword_800D7A60[] = {0x4, 0x0, 0x4, 0x4};
const char s03c_dword_800D7A64[] = {0x0, 0x4, 0x0, 0x14};
const char s03c_dword_800D7A68[] = {0x0, 0x0, 0x2, 0x0};
const char s03c_dword_800D7A6C[] = {0x1, 0xd, 0xf, 0x0};
const char s03c_aFamas_800D7A70[] = "famas";
const char s03c_aJfamasc_800D7A78[] = "jfamas.c";
const char s03c_aTimeoutd_800D7A84[] = "timeout %d\n";


int SECTION("overlay.bss") s03c_dword_800D7F3C;
int SECTION("overlay.bss") s03c_dword_800D7F40;
int SECTION("overlay.bss") s03c_dword_800D7F44;
int SECTION("overlay.bss") s03c_dword_800D7F48;
int SECTION("overlay.bss") s03c_dword_800D7F4C;
int SECTION("overlay.bss") s03c_dword_800D7F50;

