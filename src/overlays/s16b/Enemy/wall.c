#include "Game/game.h"
#include "Game/object.h"
#include "libgcl/hash.h"
#include "libgv/libgv.h"

typedef struct _Work
{
    GV_ACT  actor;
    OBJECT  object;
    char    pad[0x100];
    SVECTOR position;
    int     hash;
    int     f150;
    short   f154;
    short   f156;
} Work;

#define EXEC_LEVEL 5

extern SVECTOR DG_ZeroVector_800AB39C;
extern int     GM_CurrentMap_800AB9B0;

extern const char s16b_dword_800C5800[]; // = "destroy\n"
extern const char s16b_dword_800C580C[]; // = "box_01"
extern const char s16b_dword_800C5814[]; // = "dbx1"
extern const char s16b_dword_800C581C[]; // = "dbx2"
extern const char s16b_dword_800C5824[]; // = "wall.c"

#pragma INCLUDE_ASM("asm/overlays/s16b/asioto_800C3278.s")
void asioto_800C3278(void);

#pragma INCLUDE_ASM("asm/overlays/s16b/asioto_800C32D8.s")
void asioto_800C32D8(Work *work);

#pragma INCLUDE_ASM("asm/overlays/s16b/asioto_800C3320.s")

#pragma INCLUDE_ASM("asm/overlays/s16b/asioto_800C33A0.s")
void asioto_800C33A0(Work *work);

void WallAct_800C345C(Work *work)
{
    asioto_800C3278();
    asioto_800C32D8(work);
    asioto_800C33A0(work);

    if (GM_CheckMessage_8002631C(&work->actor, work->hash, HASH_KILL))
    {
        GV_DestroyActor_800151C8(&work->actor);
    }
}

void WallDie_800C34B0(Work *work)
{
    printf(s16b_dword_800C5800);

    work->object.objs->flag = DG_FLAG_ONEPIECE | DG_FLAG_BOUND | DG_FLAG_TRANS | DG_FLAG_PAINT | DG_FLAG_TEXT;
    GM_FreeObject_80034BF8(&work->object);
}

int WallGetResources_800C34F0(Work *work, SVECTOR *pos, SVECTOR *dir, int def_model, int map)
{
    SVECTOR position;
    VECTOR  scale;
    int     model;
    OBJECT *object;

    position = *pos;

    switch (def_model)
    {
    case 0:
        model = GV_StrCode_80016CCC(s16b_dword_800C580C);
        scale.vx = 8192;
        scale.vy = 16384;
        scale.vz = 8192;
        position.vy += 200;
        break;

    case 1:
        model = GV_StrCode_80016CCC(s16b_dword_800C5814);
        scale.vx = 4096;
        scale.vy = 4096;
        scale.vz = 4096;
        break;

    case 2:
        model = GV_StrCode_80016CCC(s16b_dword_800C581C);
        scale.vx = 4096;
        scale.vy = 4096;
        scale.vz = 4096;
        break;

    default:
        model = def_model;
        scale.vx = 4096;
        scale.vy = 4096;
        scale.vz = 4096;
        break;
    }

    GM_CurrentMap_800AB9B0 = map;
    object = &work->object;

    if (work->f154 == 0)
    {
        GM_InitObject_80034A18(object, model, 0x57, map);
    }
    else
    {
        GM_InitObject_80034A18(object, model, 0x35d, map);
    }

    GM_ConfigObjectJoint_80034CB4(object);

    work->position = position;

    DG_SetPos2_8001BC8C(&position, dir);
    DG_PutObjs_8001BDB8(work->object.objs);
    ScaleMatrix(&work->object.objs->world, &scale);
    GM_ReshadeObjs_80031660(object->objs);

    work->f150 = 1;
    work->f156 = 1;
    return 0;
}

GV_ACT *NewWall_800C3688(SVECTOR *pos, SVECTOR *dir)
{
    Work *work;

    work = (Work *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(Work));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, NULL, (TActorFunction)WallDie_800C34B0, s16b_dword_800C5824);

        // Why?
        if (((int (*)(Work *, SVECTOR *, SVECTOR *))WallGetResources_800C34F0)(work, pos, dir) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }

    return &work->actor;
}

GV_ACT *NewWall_800C3718(int name, int where, int argc, char **argv)
{
    SVECTOR pos;
    SVECTOR dir;
    Work   *work;
    int     model;
    char   *param;

    work = (Work *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(Work));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)WallAct_800C345C, (TActorFunction)WallDie_800C34B0, s16b_dword_800C5824);

        param = (char *)GCL_GetParam_80020968('t');
        if (param != 0)
        {
            model = GCL_GetNextInt_800209E8(param);
        }
        else
        {
            model = 0;
        }

        param = (char *)GCL_GetParam_80020968('m');
        if (param != 0)
        {
            model = GCL_GetNextInt_800209E8(param);
        }

        param = (char *)GCL_GetParam_80020968('p');
        if (param != 0)
        {
            GCL_GetSV_80020A14(param, &pos);
        }
        else
        {
            pos = DG_ZeroVector_800AB39C;
        }

        param = (char *)GCL_GetParam_80020968('d');
        if (param != 0)
        {
            GCL_GetSV_80020A14(param, &dir);
        } else
        {
            dir = DG_ZeroVector_800AB39C;
        }

        param = (char *)GCL_GetParam_80020968('g');
        if (param != 0)
        {
            work->f154 = GCL_GetNextInt_800209E8(param);
        }
        else
        {
            work->f154 = 0;
        }

        if (WallGetResources_800C34F0(work, &pos, &dir, model, where) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }

        work->hash = name;
    }

    return &work->actor;
}