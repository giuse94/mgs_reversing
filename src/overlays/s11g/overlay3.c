#include "linker.h"

int s11g_dword_800C3598 = 0x0BB81388;
int s11g_dword_800C359C = 0x00001388;
int s11g_dword_800C35A0 = 0x00000064;
int s11g_dword_800C35A4 = 0x00000000;

const char s11g_aHindc_800DD0DC[] = "hind.c";
const char s11g_aHind_800DD0E4[] = "hind";
const char s11g_aHindmsil_800DD0EC[] = "hindmsil";
const char s11g_dword_800DD0F8[] = {0x0, 0x0, 0x0, 0x0};
const int s11g_dword_800DD0FC = 0x800D20EC;
const int s11g_dword_800DD100 = 0x800D20EC;
const int s11g_dword_800DD104 = 0x800D20F8;
const int s11g_dword_800DD108 = 0x800D20F8;
const int s11g_dword_800DD10C = 0x800D2190;
const char s11g_dword_800DD110[] = {0x0, 0x0, 0x0, 0x0};
const int s11g_dword_800DD114 = 0x800D2B48;
const int s11g_dword_800DD118 = 0x800D2B48;
const int s11g_dword_800DD11C = 0x800D2B5C;
const int s11g_dword_800DD120 = 0x800D2B70;
const int s11g_dword_800DD124 = 0x800D2B84;
const char s11g_aHind_800DD128[] = "HIND";
const char s11g_aBulletoff_800DD130[] = "bullet_off";
const char s11g_aBulleton_800DD13C[] = "bullet_on";
const char s11g_aDestroy_800DD148[] = "destroy";
const int s11g_dword_800DD150 = 0x800D3818;
const int s11g_dword_800DD154 = 0x800D36F8;
const int s11g_dword_800DD158 = 0x800D3704;
const int s11g_dword_800DD15C = 0x800D3734;
const int s11g_dword_800DD160 = 0x800D37E8;
const int s11g_dword_800DD164 = 0x800D4E10;
const int s11g_dword_800DD168 = 0x800D4E40;
const int s11g_dword_800DD16C = 0x800D4EA8;
const int s11g_dword_800DD170 = 0x800D4F94;
const int s11g_dword_800DD174 = 0x800D50B0;
const char s11g_dword_800DD178[] = {0x0, 0x0, 0x0, 0x0};
const int s11g_dword_800DD17C = 0x800D5BE8;
const int s11g_dword_800DD180 = 0x800D5BD0;
const int s11g_dword_800DD184 = 0x800D5BFC;
const int s11g_dword_800DD188 = 0x800D5C18;
const int s11g_dword_800DD18C = 0x800D5C34;
const int s11g_dword_800DD190 = 0x800D68E0;
const int s11g_dword_800DD194 = 0x800D68F0;
const int s11g_dword_800DD198 = 0x800D69E4;
const int s11g_dword_800DD19C = 0x800D7628;
const int s11g_dword_800DD1A0 = 0x800D7628;
const int s11g_dword_800DD1A4 = 0x800D7020;
const int s11g_dword_800DD1A8 = 0x800D70A8;
const int s11g_dword_800DD1AC = 0x800D724C;
const int s11g_dword_800DD1B0 = 0x800D743C;
const int s11g_dword_800DD1B4 = 0x800D7628;
const int s11g_dword_800DD1B8 = 0x800D7628;
const int s11g_dword_800DD1BC = 0x800D7628;
const int s11g_dword_800DD1C0 = 0x800D7628;
const int s11g_dword_800DD1C4 = 0x800D7628;
const int s11g_dword_800DD1C8 = 0x800D7628;
const int s11g_dword_800DD1CC = 0x800D7628;
const int s11g_dword_800DD1D0 = 0x800D7628;
const int s11g_dword_800DD1D4 = 0x800D6A54;
const int s11g_dword_800DD1D8 = 0x800D6BE0;
const int s11g_dword_800DD1DC = 0x800D7628;
const int s11g_dword_800DD1E0 = 0x800D7628;
const int s11g_dword_800DD1E4 = 0x800D6D40;
const int s11g_dword_800DD1E8 = 0x800D7700;
const int s11g_dword_800DD1EC = 0x800D776C;
const int s11g_dword_800DD1F0 = 0x800D7868;
const int s11g_dword_800DD1F4 = 0x800D9260;
const int s11g_dword_800DD1F8 = 0x800D9260;
const int s11g_dword_800DD1FC = 0x800D7FB4;
const int s11g_dword_800DD200 = 0x800D80D8;
const int s11g_dword_800DD204 = 0x800D827C;
const int s11g_dword_800DD208 = 0x800D8458;
const int s11g_dword_800DD20C = 0x800D8D58;
const int s11g_dword_800DD210 = 0x800D90B4;
const int s11g_dword_800DD214 = 0x800D9260;
const int s11g_dword_800DD218 = 0x800D9260;
const int s11g_dword_800DD21C = 0x800D9260;
const int s11g_dword_800DD220 = 0x800D9260;
const int s11g_dword_800DD224 = 0x800D9260;
const int s11g_dword_800DD228 = 0x800D9260;
const int s11g_dword_800DD22C = 0x800D78D8;
const int s11g_dword_800DD230 = 0x800D7A68;
const int s11g_dword_800DD234 = 0x800D9260;
const int s11g_dword_800DD238 = 0x800D9260;
const int s11g_dword_800DD23C = 0x800D7C3C;
const int s11g_dword_800DD240 = 0x800D96F0;
const int s11g_dword_800DD244 = 0x800D9B70;
const int s11g_dword_800DD248 = 0x800D9B70;
const int s11g_dword_800DD24C = 0x800D9B70;
const int s11g_dword_800DD250 = 0x800D974C;
const int s11g_dword_800DD254 = 0x800D9858;
const int s11g_dword_800DD258 = 0x800D9A74;
const int s11g_dword_800DD25C = 0x800D9B40;
const int s11g_dword_800DD260 = 0x800D9BC4;
const int s11g_dword_800DD264 = 0x800DA520;
const int s11g_dword_800DD268 = 0x800DA520;
const int s11g_dword_800DD26C = 0x800DA520;
const int s11g_dword_800DD270 = 0x800D9C08;
const int s11g_dword_800DD274 = 0x800D9D74;
const int s11g_dword_800DD278 = 0x800D9FD8;
const int s11g_dword_800DD27C = 0x800DA0E0;
const int s11g_dword_800DD280 = 0x800DA2B4;
const char s11g_dword_800DD284[] = {0x0, 0x0, 0x0, 0x0};
const int s11g_dword_800DD288 = 0x800DA808;
const int s11g_dword_800DD28C = 0x800DAAB4;
const int s11g_dword_800DD290 = 0x800DAAB4;
const int s11g_dword_800DD294 = 0x800DAAB4;
const int s11g_dword_800DD298 = 0x800DA83C;
const int s11g_dword_800DD29C = 0x800DA85C;
const int s11g_dword_800DD2A0 = 0x800DA9B4;
const int s11g_dword_800DD2A4 = 0x800DAA48;
const int s11g_dword_800DD2A8 = 0x800DAA84;
const char s11g_aBombfl_800DD2AC[] = "bomb1_fl";
const char s11g_dword_800DD2B8[] = {'b', 'l', 'a', 's'};
const char s11g_dword_800DD2BC[] = {'t', 'o', 'f', 'f'};
const char s11g_dword_800DD2C0[] = {'.', 'c', 0x0, 0x8};
const int s11g_dword_800DD2C4 = 0x800DC774;
const int s11g_dword_800DD2C8 = 0x800DC774;
const int s11g_dword_800DD2CC = 0x800DC77C;
const int s11g_dword_800DD2D0 = 0x800DC77C;
const int s11g_dword_800DD2D4 = 0x800DC784;


int SECTION("overlay.bss") s11g_dword_800DD34C;
int SECTION("overlay.bss") s11g_dword_800DD350;
int SECTION("overlay.bss") s11g_dword_800DD354;
int SECTION("overlay.bss") s11g_dword_800DD358;
int SECTION("overlay.bss") s11g_dword_800DD35C;
int SECTION("overlay.bss") s11g_dword_800DD360;
int SECTION("overlay.bss") s11g_dword_800DD364;
int SECTION("overlay.bss") s11g_dword_800DD368;
int SECTION("overlay.bss") s11g_dword_800DD36C;
int SECTION("overlay.bss") s11g_dword_800DD370;
int SECTION("overlay.bss") s11g_dword_800DD374;
int SECTION("overlay.bss") s11g_dword_800DD378;