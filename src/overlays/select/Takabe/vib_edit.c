#include "Game/game.h"
#include "Game/vibrate.h"
#include "libgcl/libgcl.h"
#include "libgv/libgv.h"

typedef struct _VibEditPrims
{
    TILE    tiles1[16];
    TILE    tiles2[16];
    TILE    tiles3[16];
    TILE    tiles4[16];
    LINE_F2 lines1[3];
    LINE_F2 lines2[3];
} VibEditPrims;

typedef struct VibPair
{
    unsigned char first;
    unsigned char second;
} VibPair;

typedef struct _VibEditWork
{
    GV_ACT        actor;
    int           field_20_status;
    int           field_24;
    int           field_28;
    int           field_2C;
    int           field_30;
    int           field_34;
    int           field_38;
    int           field_3C;
    int           field_40;
    VibEditPrims *field_44_prims;
    Actor_Vibrate *field_48_vibrate;
    VibPair       field_4C_pairs[16];
    int           field_6C;
    VibPair       field_70_pairs[16];
    int           field_90;
    VibPair       field_94_pairs[32][32];
    VibPair       field_894_pairs[16];
    VibPair       field_8B4_pairs[16];
} VibEditWork;

extern int    GM_GameStatus_800AB3CC;
extern int    GM_PlayerStatus_800ABA50;
extern GV_PAD GV_PadData_800B05C0[4];

extern const char select_aSavevibrationeditordata_800C52A4[]; // = "Save vibration editor data !\n"
extern char       select_aVibeditdat_800C52C4[];              // = "VIB_EDIT.DAT"
extern const char select_aVibeditc_800C52D4[];                // = "vib_edit.c"
extern const char select_aDd_800C50E4[];
extern const char select_aDd_800C5124[];
extern const char select_aHigh_800C50DC[];
extern const char select_aLow_800C50F0[];
extern const char select_aPadvibationparameterforgcl_800C50B8[];
extern const char select_aPadvibationparameterforprogram_800C50F8[];
extern const char select_a_800C50EC[];
extern const char select_a_800C5120[];
extern const char select_a_800C512C[];
extern const char select_aChangelengthlr_800C518C[];
extern const char select_aChangepowerud_800C51A8[];
extern const char select_aDdd_800C5280[];
extern const char select_aDispparamy_800C520C[];
extern const char select_aEddd_800C5270[];
extern const char select_aEditmenu_800C5130[];
extern const char select_aEditmenur_800C5224[];
extern const char select_aEditvibrationtyped_800C5254[];
extern const char select_aExitl_800C51C4[];
extern const char select_aFilemenu_800C513C[];
extern const char select_aFilemenul_800C523C[];
extern const char select_aPlaya_800C51DC[];
extern const char select_aSd_800C5148[];
extern const char select_aSelectparamlr_800C5170[];
extern const char select_aTypechangex_800C51F4[];
extern const char select_aVibrationeditorver_800C5150[];
extern char      *select_dword_800C3220[4];
extern char      *select_dword_800C3230[5];
// VibEditGetResources is calling this with two missing parameters for some reason.
int PCopen_80014B1C(const char *name);
int PCread_80014B24(int fd, char *buff, int len);
int PCclose_80014B2C(int fd);

// For some reason VibEditDie_800C467C calls this with a missing
// last argument!? But it's not bad - PsyQ documentation says
// that argument is ignored anyways...
int PCcreat(char *name /*, int perms */);
int PCwrite(int fd, char *buff, int len);

int select_800C4F28(const char *);     // PCopen
int select_800C4F48(int, char *, int); // PCwrite

int THING_Gcl_GetInt(int param);

#define EXEC_LEVEL 3

void VibEdit_800C34F0(VibEditWork *work)
{
    VibEditPrims *prims;
    TILE         *tile1;
    TILE         *tile2;
    int           i;
    LINE_F2      *line;

    work->field_44_prims = GV_Malloc_8001620C(sizeof(VibEditPrims));
    prims = work->field_44_prims;

    tile1 = prims->tiles1;
    tile2 = prims->tiles2;

    for (i = 16; i > 0; i--)
    {
        setTile(tile1);
        *tile2++ = *tile1++;
    }

    tile1 = prims->tiles3;
    tile2 = prims->tiles4;

    for (i = 16; i > 0; i--)
    {
        setTile(tile1);
        *tile2++ = *tile1++;
    }

    line = &prims->lines1[0];
    setLineF2(line);
    setXY2(line, 16, 155, 320, 155);
    setRGB0(line, 0, 180, 0);
    prims->lines2[0] = *line;

    line = &prims->lines1[1];
    setLineF2(line);
    setXY2(line, 16, 70, 320, 70);
    setRGB0(line, 180, 0, 0);
    prims->lines2[1] = *line;

    line = &prims->lines1[2];
    setLineF2(line);
    setXY2(line, 16, 155, 16, 70);
    setRGB0(line, 0, 0, 180);
    prims->lines2[2] = *line;
}

#pragma INCLUDE_ASM("asm/overlays/select/select_800C36BC.s")
void select_800C36BC(VibEditWork *work);

void select_800C3974(VibEditWork *work)
{
    int      i;
    VibPair *iter;

    printf(select_aPadvibationparameterforgcl_800C50B8);
    printf(select_aHigh_800C50DC);

    iter = work->field_4C_pairs;
    for (i = 0; i < 16; iter++, i++)
    {
        if (iter->first == 0 && iter->second == 0)
        {
            break;
        }
        printf(select_aDd_800C50E4, iter->first, iter->second);
    }
    printf(select_a_800C50EC);
    printf(select_aLow_800C50F0);
    iter = work->field_70_pairs;
    for (i = 0; i < 16; iter++, i++)
    {
        if (iter->first == 0 && iter->second == 0)
        {
            break;
        }
        printf(select_aDd_800C50E4, iter->first, iter->second);
    }
    printf(select_a_800C50EC);
    printf(select_aPadvibationparameterforprogram_800C50F8);
    printf(select_aHigh_800C50DC);

    iter = work->field_4C_pairs;
    for (i = 0; i < 16; iter++, i++)
    {
        if (iter->first == 0 && iter->second == 0)
        {
            printf(select_a_800C5120, iter->first, iter->second); // unnecessary args...
            break;
        }
        printf(select_aDd_800C5124, iter->first, iter->second);
    }
    printf(select_a_800C50EC);
    printf(select_aHigh_800C50DC);
    iter = work->field_70_pairs;
    for (i = 0; i < 16; iter++, i++)
    {
        if (iter->first == 0 && iter->second == 0)
        {
            printf(select_a_800C5120, iter->first, iter->second); // unnecessary args...
            break;
        }
        printf(select_aDd_800C5124, iter->first, iter->second);
    }
    printf(select_a_800C512C);
}

void select_800C3BB8(VibPair *ptr, int cnt)
{
    int i;
    ptr += cnt;
    for (i = 16 - cnt; i > 0; i--)
    {
        ptr[0] = ptr[1];
        ptr++;
    }
}

void select_800C3BF4(VibPair *ptr, int cnt)
{
    int i;
    for (i = 15 - cnt, ptr += 15; i > 0; i--)
    {
        ptr[0] = ptr[-1];
        ptr--;
    }
}

void select_800C3C28(VibPair *ptr, int cnt)
{
    VibPair pair;

    if (cnt >= 15)
    {
        return;
    }

    pair = ptr[cnt + 1];
    ptr[cnt + 1] = ptr[cnt];
    ptr[cnt] = pair;
}

void select_800C3C74(VibPair *ptr, int cnt)
{
    VibPair pair;

    if (cnt <= 0)
    {
        return;
    }

    pair = ptr[cnt - 1];
    ptr[cnt - 1] = ptr[cnt];
    ptr[cnt] = pair;
}

void VibEdit_800C3CBC(VibEditWork *work, int idx)
{
    VibPair *dst, *src;
    int      i;

    dst = work->field_94_pairs[idx];
    src = work->field_4C_pairs;
    for (i = 16; i > 0; i--)
    {
        *dst++ = *src++;
    }

    src = work->field_70_pairs;
    for (i = 16; i > 0; i--)
    {
        *dst++ = *src++;
    }
}

// VibEdit_800C3CBC but with dst/src swapped:
void VibEdit_800C3D20(VibEditWork *work, int idx)
{
    VibPair *dst, *src;
    int      i;

    src = work->field_94_pairs[idx];
    dst = work->field_4C_pairs;
    for (i = 16; i > 0; i--)
    {
        *dst++ = *src++;
    }

    dst = work->field_70_pairs;
    for (i = 16; i > 0; i--)
    {
        *dst++ = *src++;
    }
}

void select_800C3D84(VibPair *src, VibPair *dst)
{
    int i;
    for (i = 16; i > 0; i--)
    {
        *dst++ = *src++;
    }
}

void VibEditAct_800C3DB0(VibEditWork *work)
{
    int      i, j, idx;
    int      old_field_28, sum;
    VibPair *pairs, *cur_pair;
    int      pad;

    pairs = work->field_3C == 0 ? work->field_70_pairs : work->field_4C_pairs;

    switch (work->field_24)
    {
    case 0:
        pad = GV_PadData_800B05C0[0].press;
        if (pad & PAD_L1)
        {
            if (work->field_38 > 0)
            {
                work->field_38--;
            }
        }
        if (pad & PAD_R1)
        {
            if (work->field_38 < 15)
            {
                work->field_38++;
            }
        }

        pad = GV_PadData_800B05C0[0].status;
        cur_pair = &pairs[work->field_38];
        if (pad & PAD_RIGHT)
        {
            if (cur_pair->second < 127)
            {
                cur_pair->second++;
            }
        }
        if (pad & PAD_LEFT)
        {
            if (cur_pair->second)
            {
                cur_pair->second--;
            }
        }
        if (work->field_3C == 0)
        {
            if (pad & PAD_UP)
            {
                if (cur_pair->first < 255)
                {
                    cur_pair->first++;
                }
            }
            if (pad & PAD_DOWN)
            {
                if (cur_pair->first)
                {
                    cur_pair->first--;
                }
            }
        }
        else
        {
            if (pad & PAD_UP)
            {
                cur_pair->first = 127;
            }
            if (pad & PAD_DOWN)
            {
                cur_pair->first = 0;
            }
        }
        pad = GV_PadData_800B05C0[0].status;
        if (pad & PAD_R2)
        {
            work->field_2C = 0;
            work->field_24 = 2;
        }
        if (pad & PAD_L2)
        {
            work->field_2C = 0;
            work->field_24 = 3;
        }
        pad = GV_PadData_800B05C0[0].press;
        if (pad & PAD_TRIANGLE)
        {
            work->field_3C ^= 1;
        }
        if (pad & PAD_SQUARE)
        {
            select_800C3974(work);
        }
        if (pad & PAD_CIRCLE)
        {
            work->field_48_vibrate = NewPadVibration_8005D58C((unsigned char *)work->field_4C_pairs, 1);
            work->field_48_vibrate = NewPadVibration_8005D58C((unsigned char *)work->field_70_pairs, 2);
            work->field_24 = 1;
            work->field_34 = 0;
            work->field_30 = 0;

            sum = 0;

            for (i = 0; i < 16; i++)
            {
                if (work->field_4C_pairs[i].second == 0 && work->field_4C_pairs[i].first == 0)
                {
                    break;
                }
                work->field_30 += work->field_4C_pairs[i].second;
            }

            for (i = 0; i < 16; i++)
            {
                if (work->field_70_pairs[i].second == 0 && work->field_70_pairs[i].first == 0)
                {
                    break;
                }
                sum += work->field_70_pairs[i].second;
            }

            if (work->field_30 < sum)
            {
                work->field_30 = sum;
            }
        }
        break;
    case 1:
        if (GV_PadData_800B05C0[0].press & PAD_CROSS)
        {
            work->field_30 = -1;
        }
        work->field_34++;
        if (--work->field_30 < 0)
        {
            work->field_24 = 0;
            work->field_34 = 0;
        }
        break;
    case 2:
        if (GV_PadData_800B05C0[0].status & PAD_R2)
        {
            pad = GV_PadData_800B05C0[0].press;
            if (pad & (PAD_LEFT | PAD_UP))
            {
                work->field_2C--;
            }
            if (pad & (PAD_RIGHT | PAD_DOWN))
            {
                work->field_2C++;
            }
            if (work->field_2C < 0)
            {
                work->field_2C = 3;
            }
            if (work->field_2C >= 4)
            {
                work->field_2C = 0;
            }
            if (pad & PAD_CIRCLE)
            {
                switch (work->field_2C)
                {
                case 0:
                    select_800C3BF4(pairs, work->field_38);
                    break;
                case 1:
                    select_800C3BB8(pairs, work->field_38);
                    break;
                case 2:
                    select_800C3C28(pairs, work->field_38);
                    if (work->field_38 < 15)
                    {
                        work->field_38++;
                    }
                    break;
                case 3:
                    select_800C3C74(pairs, work->field_38);
                    if (work->field_38 > 0)
                    {
                        work->field_38--;
                    }
                    break;
                }
            }
            menu_Text_XY_Flags_80038B34(230, 160, 0);
            menu_Text_80038C38(select_aEditmenu_800C5130);
            for (i = 0; i < 4; i++)
            {
                if (work->field_2C == i)
                {
                    menu_Text_XY_Flags_80038B34(230, 180 + (i - 1) * 8, 0);
                }
                else
                {
                    menu_Text_XY_Flags_80038B34(238, 180 + (i - 1) * 8, 0);
                }
                menu_Text_80038C38(select_dword_800C3220[i]);
            }
        }
        else
        {
            work->field_24 = 0;
        }
        break;
    case 3:
        if (GV_PadData_800B05C0[0].status & PAD_L2)
        {
            pad = GV_PadData_800B05C0[0].press;
            if (pad & PAD_UP)
            {
                work->field_2C--;
            }
            if (pad & PAD_DOWN)
            {
                work->field_2C++;
            }
            if (work->field_2C < 0)
            {
                work->field_2C = 4;
            }
            if (work->field_2C >= 5)
            {
                work->field_2C = 0;
            }
            if (work->field_2C == 0)
            {
                old_field_28 = work->field_28;
                if (pad & PAD_LEFT)
                {
                    if (work->field_28 > 0)
                    {
                        work->field_28--;
                    }
                }
                if (pad & PAD_RIGHT)
                {
                    if (work->field_28 < 31)
                    {
                        work->field_28++;
                    }
                }
                if (old_field_28 != work->field_28)
                {
                    VibEdit_800C3CBC(work, old_field_28);
                    VibEdit_800C3D20(work, work->field_28);
                }
            }
            if (pad & PAD_CIRCLE)
            {
                switch (work->field_2C)
                {
                case 0:
                    break;
                case 1:
                    select_800C3D84(work->field_4C_pairs, work->field_894_pairs);
                    break;
                case 2:
                    select_800C3D84(work->field_70_pairs, work->field_8B4_pairs);
                    break;
                case 3:
                    select_800C3D84(work->field_894_pairs, work->field_4C_pairs);
                    break;
                case 4:
                    select_800C3D84(work->field_8B4_pairs, work->field_70_pairs);
                    break;
                }
                work->field_24 = 0;
            }

            menu_Text_XY_Flags_80038B34(230, 160, 0);
            menu_Text_80038C38(select_aFilemenu_800C513C);
            if (work->field_2C == 0)
            {
                menu_Text_XY_Flags_80038B34(230, 172, 0);
            }
            else
            {
                menu_Text_XY_Flags_80038B34(238, 172, 0);
            }
            menu_Text_80038C38(select_aSd_800C5148, select_dword_800C3230[0], work->field_28);

            for (i = 1; i < 5; i++)
            {
                if (work->field_2C == i)
                {
                    menu_Text_XY_Flags_80038B34(230, 180 + (i - 1) * 8, 0);
                }
                else
                {
                    menu_Text_XY_Flags_80038B34(238, 180 + (i - 1) * 8, 0);
                }

                menu_Text_80038C38(select_dword_800C3230[i]);
            }
        }
        else
        {
            work->field_24 = 0;
        }
        break;
    }
    menu_Text_XY_Flags_80038B34(32, 16, 0);
    menu_Text_80038C38(select_aVibrationeditorver_800C5150);
    menu_Text_80038C38(select_aSelectparamlr_800C5170);
    menu_Text_80038C38(select_aChangelengthlr_800C518C);
    menu_Text_80038C38(select_aChangepowerud_800C51A8);
    menu_Text_80038C38(select_aExitl_800C51C4);
    menu_Text_XY_Flags_80038B34(168, 24, 0);
    menu_Text_80038C38(select_aPlaya_800C51DC);
    menu_Text_80038C38(select_aTypechangex_800C51F4);
    menu_Text_80038C38(select_aDispparamy_800C520C);
    menu_Text_80038C38(select_aEditmenur_800C5224);
    menu_Text_80038C38(select_aFilemenul_800C523C);
    menu_Text_XY_Flags_80038B34(32, 64, 0);
    menu_Text_80038C38(select_aEditvibrationtyped_800C5254, 2 - work->field_3C);

    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 8; i++)
        {
            idx = j * 8 + i;
            cur_pair = &pairs[idx];
            menu_Text_XY_Flags_80038B34(32 + 100 * j, 160 + i * 8, 0);
            if (idx == work->field_38)
            {
                menu_Text_80038C38(select_aEddd_800C5270, idx, cur_pair->first, cur_pair->second);
            }
            else
            {
                menu_Text_80038C38(select_aDdd_800C5280, idx, cur_pair->first, cur_pair->second);
            }
        }
    }

    select_800C36BC(work);

    if (GV_PadData_800B05C0[0].press & 0x200)
    {
        if (work->field_40)
        {
            GCL_ExecProc_8001FF2C(work->field_40, 0);
        }
        GV_DestroyActor_800151C8(&work->actor);
    }

    GM_GameStatus_800AB3CC |= 0x4A2000;
}
void VibEditDie_800C467C(VibEditWork *work)
{
    int fd;

    printf(select_aSavevibrationeditordata_800C52A4);

    VibEdit_800C3CBC(work, work->field_28);

    fd = PCcreat(select_aVibeditdat_800C52C4);
    PCwrite(fd, (char *)work->field_94_pairs, sizeof(work->field_94_pairs));
    PCclose_80014B2C(fd);

    GM_GameStatus_800AB3CC &= ~(work->field_20_status & 0x4A2000);
    GM_PlayerStatus_800ABA50 &= ~PLAYER_PAD_OFF;
}

int VibEditGetResources_800C4720(VibEditWork *work, int flags, int perms)
{
    int fd;

    work->field_40 = THING_Gcl_GetInt('e');

    VibEdit_800C34F0(work);

    // Should have 3 args
    fd = PCopen_80014B1C(select_aVibeditdat_800C52C4);
    PCread_80014B24(fd, (char *)work->field_94_pairs, sizeof(work->field_94_pairs));
    PCclose_80014B2C(fd);

    VibEdit_800C3D20(work, work->field_28);

    work->field_20_status = GM_GameStatus_800AB3CC;
    GM_PlayerStatus_800ABA50 |= PLAYER_PAD_OFF;

    return 0;
}

GV_ACT *NewVibEdit_800C47B4(int flags, int perms)
{
    VibEditWork *work;

    work = (VibEditWork *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(VibEditWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)VibEditAct_800C3DB0,
                                  (TActorFunction)VibEditDie_800C467C, select_aVibeditc_800C52D4);

        if (VibEditGetResources_800C4720(work, flags, perms) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }

    return &work->actor;
}
