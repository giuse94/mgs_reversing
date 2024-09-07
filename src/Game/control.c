#include "linker.h"
#include "control.h"
#include "mts/mts_new.h"
#include "libgv/libgv.h"
#include "libdg/libdg.h"
#include "libgcl/libgcl.h"
#include "libhzd/libhzd.h"
#include "Game/map.h"
#include "strcode.h"

int SECTION(".sbss") GM_CurrentMap_800AB9B0;
int SECTION(".sbss") gControlCount_800AB9B4;

extern CONTROL *GM_WhereList_800B56D0[96];
extern CONTROL  gDefaultControl_800B5650;
extern SVECTOR DG_ZeroVector_800AB39C;

int GM_ControlPushBack_800258B0(CONTROL *pControlToAdd)
{
    // sna_init must always be the first item
    if (pControlToAdd->name == CHARA_SNAKE)
    {
        GM_WhereList_800B56D0[0] = pControlToAdd;
    }
    else
    {
        if (gControlCount_800AB9B4 > MAX_CONTROLS - 1)
        {
            return -1;
        }
        GM_WhereList_800B56D0[gControlCount_800AB9B4] = pControlToAdd;
        gControlCount_800AB9B4++;
    }

    return 0;
}

void GM_ControlRemove_80025904(CONTROL *pControl)
{
    int i = gControlCount_800AB9B4;
    int totalCount = gControlCount_800AB9B4;

    CONTROL **pControlIter = GM_WhereList_800B56D0;

    while (i > 0)
    {
        i--;

        if (*pControlIter == pControl)
        {
            goto found;
        }
        pControlIter++;
    }

    return;

found:

    if (pControlIter != GM_WhereList_800B56D0)
    {
        *pControlIter = GM_WhereList_800B56D0[--totalCount];
        gControlCount_800AB9B4 = totalCount;
    }
    else
    {
        GM_WhereList_800B56D0[0] = &gDefaultControl_800B5650;
    }
}

void GM_InitWhereSystem_8002597C(void)
{
    GM_WhereList_800B56D0[0] = &gDefaultControl_800B5650;
    gControlCount_800AB9B4 = 1;
}

int GM_InitControl_8002599C(CONTROL *pControl, int scriptData, int scriptBinds)
{
    MAP *pMapRec;
    const int          mapId = scriptBinds ? scriptBinds : GM_CurrentMap_800AB9B0;
    GM_CurrentMap_800AB9B0 = mapId;

    GV_ZeroMemory(pControl, sizeof(CONTROL));

    pMapRec = Map_FromId_800314C0(mapId);
    pControl->map = pMapRec;
    if (!pMapRec)
    {
        printf("InitControl : no map %X\n", mapId);
        return -1;
    }

    pControl->name = scriptData;
    if (scriptData)
    {
        HZD_SetEvent_80029AB4(&pControl->field_10_events, scriptData);
        if (GM_ControlPushBack_800258B0(pControl) < 0)
        {
            return -1;
        }
    }

    pControl->height = 850;
    pControl->hzd_height = -32767;
    pControl->field_38 = 450;
    pControl->field_36 = 450;
    pControl->field_59 = 2;
    pControl->skip_flag = CTRL_SKIP_TRAP;
    pControl->levels[0] = -32000;
    pControl->levels[1] = 32000;

    return 0;
}


extern SVECTOR DG_ZeroVector_800AB39C;

static inline void GM_ActControl_helper_80025A7C(CONTROL *pControl)
{
    int         scriptData;
    int         count;
    GV_MSG     *pMsg;
    int         hash1, hash2;
    MAP *pMap;

    scriptData = pControl->name;

    if ((scriptData != 0) && !(pControl->skip_flag & CTRL_SKIP_MESSAGE))
    {
        count = GV_ReceiveMessage(scriptData, &pControl->field_5C_mesg);
        pControl->field_56 = count;

        pMsg = pControl->field_5C_mesg;

        hash1 = 0xF9AD;
        hash2 = 0x89CB;

        for (count--; count >= 0; count--, pMsg++)
        {
            if (pMsg->message[0] == hash1)
            {
                pMap = Map_FindByNum_80031504(pMsg->message[1]);

                if (pMap)
                {
                    pControl->map = pMap;
                }
            }
            else if (pMsg->message[0] == hash2)
            {
                pControl->mov.vx = pMsg->message[1];
                pControl->mov.vy = pMsg->message[2];
                pControl->mov.vz = pMsg->message[3];
                pControl->levels[0] = -32000;
                pControl->levels[1] = 32000;
            }
        }
    }
}

static inline void GM_ActControl_helper2_80025A7C(CONTROL *pControl, HZD_HDL *pHzd)
{
    SVECTOR vec;
    int     vx;
    int     new_var;
    int     len;
    int     diff;

    vx = pControl->step.vx;
    new_var = pControl->field_36 / 2;

    if (vx < 0)
    {
        vx = -vx;
    }

    if (pControl->step.vz > 0)
    {
        vx += pControl->step.vz;
    }
    else
    {
        vx -= pControl->step.vz;
    }

    if ((vx > new_var) || (pControl->skip_flag & (CTRL_BOTH_CHECK | CTRL_SKIP_NEAR_CHECK)))
    {
        GV_AddVec3(&pControl->mov, &pControl->step, &vec);

        if (sub_80028454(pHzd, &pControl->mov, &vec, 15, pControl->field_59))
        {
            pControl->field_58 = 0x1;
            pControl->field_70[0] = sub_80028820();
            pControl->field_5A[0] = sub_80028830();

            GetVecFromScratchpad_80028840(pControl->field_60_vecs_ary);

            len = GV_VecLen3(pControl->field_60_vecs_ary);
            diff = len - new_var;

            if (diff < 0)
            {
                diff = -diff;
                GV_LenVec3(pControl->field_60_vecs_ary, &vec, len, diff);
                GV_SubVec3(&DG_ZeroVector_800AB39C, &vec, &vec);
            }
            else
            {
                GV_LenVec3(pControl->field_60_vecs_ary, &vec, len, diff);
            }

            pControl->step = vec;
        }
    }
}

static inline void GM_ActControl_helper3_80025A7C(CONTROL *pControl, HZD_HDL *pHzd)
{
    SVECTOR vec;
    SVECTOR vec2;
    int     bVar7;
    int     i;

    bVar7 = 0;

    if (pControl->skip_flag & CTRL_SKIP_NEAR_CHECK)
    {
        return;
    }

retry:
    i = sub_80029098(pHzd,&pControl->mov, 500, 12, pControl->field_59);

    if (i <= 0)
    {
        return;
    }

    pControl->field_58 = i;

    GM_ActControl_helper3_800292E4(pControl->field_70);
    GM_ActControl_helper4_80029304(pControl->field_5A);
    GM_ActControl_helper5_80029324(pControl->field_60_vecs_ary);

    if (!GM_ActControl_helper_80026C68(pControl->field_60_vecs_ary, i, pControl->field_36, &vec) && !bVar7)
    {
        GV_LenVec3(&pControl->step, &vec2, GV_VecLen3(&pControl->step), pControl->field_36 / 2);
        bVar7 = 1;
        vec2.vy = 0;
        GV_SubVec3(&pControl->mov,&vec2,&pControl->mov);
        goto retry;
    }
    else
    {
        pControl->mov.vx += vec.vx;
        pControl->mov.vz += vec.vz;
    }
}

static inline void GM_ActControl_helper4_80025A7C(CONTROL *pControl, HZD_HDL *pHzd)
{
    HZD_VEC vec;
    int     vy, vz;
    int     iVar11;
    int     uVar14;
    int     uVar15;
    int     uVar16;

    vy = pControl->mov.vy + pControl->step.vy;
    vz = pControl->height;

    pControl->field_57 = 0;
    uVar14 = sub_800296C4(pHzd, &pControl->mov, 3);
    sub_800298DC(&vec);
    pControl->field_60_vecs_ary[0].pad = sub_80029A2C();
    uVar15 = uVar14 & 1;

    if (((uVar14 & 2) != 0) && ((vec.long_access[1] - pControl->levels[0]) + 199U < 399))
    {
        vec.long_access[0] = vec.long_access[1];
        uVar14 &= ~2;
        uVar14 |= 1;
        uVar15 = uVar14 & 1;
    }

    uVar16 = uVar14 & 2;

    if (uVar15 == 0)
    {
        vec.long_access[0] = 0;
    }

    if (uVar16 == 0)
    {
        vec.long_access[1] = 32000;
    }

    iVar11 = vz;

    if (uVar15 != 0)
    {
        iVar11 = vz + vec.long_access[0];
    }

    if (iVar11 > vy)
    {
        vy = iVar11;
        pControl->field_57 = 1;
    }
    else if (uVar16 != 0)
    {
        iVar11 = vec.long_access[1] - vz;

        if (iVar11 < vy)
        {
            vy = iVar11;
            pControl->field_57 = 2;
        }
    }

    pControl->levels[0] = vec.long_access[0];
    pControl->levels[1] = vec.long_access[1];
    pControl->mov.vy = vy;
}

extern void GM_ActControl_helper6_8002A538(HZD_HDL *pMap, HZD_EVT *arg1);

void GM_ActControl_80025A7C(CONTROL *pControl)
{
    HZD_HDL *pHzd;
    int      vy;
    int      time;

    pHzd = pControl->map->hzd;

    GM_ActControl_helper_80025A7C(pControl);

    GM_CurrentMap_800AB9B0 = pControl->map->index;

    if (pControl->field_36 > 0)
    {
        pControl->field_58 = 0;

        if (pControl->hzd_height != -0x7fff)
        {
            vy = pControl->mov.vy;
            pControl->mov.vy = pControl->hzd_height;
        }

        GM_ActControl_helper2_80025A7C(pControl, pHzd);

        pControl->mov.vx += pControl->step.vx;
        pControl->mov.vz += pControl->step.vz;

        GM_ActControl_helper3_80025A7C(pControl, pHzd);

        if (pControl->hzd_height != -0x7fff)
        {
            pControl->mov.vy = vy;
        }

        time = pControl->field_54;

        if (pControl->field_54 == 0)
        {
            GV_NearExp4PV(&pControl->rot.vx, &pControl->turn.vx, 3);
        }
        else
        {
            GV_NearTimePV(&pControl->rot.vx, &pControl->turn.vx, pControl->field_54, 3);
            pControl->field_54 = time - 1;
        }

        GM_ActControl_helper4_80025A7C(pControl, pHzd);
    }
    else if (pControl->field_36 < 0)
    {
        pControl->field_58 = 0;

        time = pControl->field_54;

        pControl->mov.vx += pControl->step.vx;
        pControl->mov.vz += pControl->step.vz;

        if (time == 0)
        {
            GV_NearExp4PV(&pControl->rot.vx, &pControl->turn.vx, 3);
        }
        else
        {
            GV_NearTimePV(&pControl->rot.vx, &pControl->turn.vx, time, 3);
            pControl->field_54 = time - 1;
        }

        if (pControl->field_36 >= -1)
        {
            GM_ActControl_helper4_80025A7C(pControl, pHzd);
        }
    }

    if (!(pControl->skip_flag & CTRL_SKIP_TRAP))
    {
        pControl->field_10_events.field_14_vec = pControl->mov;
        pControl->field_10_events.field_14_vec.pad = pControl->rot.vy;
        GM_ActControl_helper6_8002A538(pHzd, &pControl->field_10_events);
    }

    DG_SetPos2(&pControl->mov, &pControl->rot);
}


void GM_FreeControl_800260CC(CONTROL *pControl)
{
    if (pControl->name)
    {
        GM_ControlRemove_80025904(pControl);
    }
}

void GM_ConfigControlVector_800260FC(CONTROL *pControl, SVECTOR *pVec1, SVECTOR *pVec2)
{
    if (pVec1)
    {
        pControl->mov = *pVec1;
    }

    if (pVec2)
    {
        pControl->rot = *pVec2;
    }
}

void GM_ConfigControlMatrix_80026154(CONTROL *pControl, MATRIX *pMatrix)
{
    pControl->mov.vx = pMatrix->t[0];
    pControl->mov.vy = pMatrix->t[1];
    pControl->mov.vz = pMatrix->t[2];

    DG_MatrixRotYXZ(pMatrix, &pControl->rot);

    pControl->turn = pControl->rot;
}

void GM_ConfigControlString_800261C0(CONTROL *pControl, char *param_pos, char *param_dir)
{
    if (param_pos)
    {
        GCL_StrToSV(param_pos, &pControl->mov);
    }

    if (param_dir)
    {
        GCL_StrToSV(param_dir, &pControl->rot);
    }

    pControl->turn = pControl->rot;
}

void GM_ConfigControlHazard_8002622C(CONTROL *pControl, short height, short f36, short f38)
{
    pControl->height = height;
    pControl->field_36 = f36;
    pControl->field_38 = f38;
}

void GM_ConfigControlAttribute_8002623C(CONTROL *pControl, int radar_atr)
{
    pControl->radar_atr = radar_atr;
}

void GM_ConfigControlInterp_80026244(CONTROL *pControl, char f5a)
{
    pControl->field_54 = f5a;
}

int GM_CheckControlTouches_8002624C(CONTROL *pControl, int param_2)
{
    if (pControl->field_58 == 0)
    {
        return 0;
    }

    if (pControl->field_58 == 2)
    {
        if (pControl->field_70[1]->b1.h < 0 || GV_VecLen3(&pControl->field_60_vecs_ary[1]) <= param_2)
        {
            return 2;
        }
    }

    if (pControl->field_70[0]->b1.h < 0 || GV_VecLen3(&pControl->field_60_vecs_ary[0]) <= param_2)
    {
        return 1;
    }

    return 0;
}

void GM_ConfigControlRadarparam_800262EC(CONTROL *control, short dir, short len, short ang, short pad)
{
    RADAR_CONE *cone;

    cone = &control->radar_cone;
    cone->dir = dir;
    cone->len = len;
    cone->ang = ang;
    cone->_pad = pad;
}

void GM_ConfigControlTrapCheck_80026308(CONTROL *pControl)
{
    pControl->skip_flag &= ~CTRL_SKIP_TRAP;
}

GV_MSG *GM_CheckMessage_8002631C(GV_ACT *pActor, int msgType, int toFind)
{
    GV_MSG *pMsg;
    int     foundCount;
    for (foundCount = GV_ReceiveMessage(msgType, &pMsg) - 1; foundCount >= 0; foundCount--)
    {
        if (pMsg->message[0] == toFind)
        {
            return pMsg;
        }
        pMsg++;
    }
    return 0;
}
