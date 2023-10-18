#include "libgv/libgv.h"
#include "Game/game.h"
#include "Game/object.h"

typedef struct BoxKeriWork
{
    GV_ACT  actor;
    OBJECT  field_20_obj;
    SVECTOR field_44;
    SVECTOR field_48;
    int     field_54[8];
    short   field_74;
    short   field_76;
    short   field_78;
    short   field_7A;
    MATRIX  field_7C_mat;
    char    pad2[0x20];
} BoxKeriWork;

extern const char s00a_aBoxkeric_800E09F0[];
extern SVECTOR    DG_ZeroVector_800AB39C;
extern CONTROL   *GM_PlayerControl_800AB9F4;
extern SVECTOR    GM_PlayerPosition_800ABA10;
extern int        dword_800ABA0C;
extern char       s00a_aCbbox_800E09E8[];
extern char       s00a_dword_800E09D0[];
extern char       s00a_dword_800E09DC[];

#pragma INCLUDE_ASM("asm/overlays/s00a/s00a_boxkeri_800D219C.s")
void s00a_boxkeri_800D219C(BoxKeriWork *);

void s00a_boxkeri_800D23D0(BoxKeriWork *work)
{
    GM_FreeObject_80034BF8(&work->field_20_obj);
}

void s00a_boxkeri_800D23F0()
{
    GV_MSG msg;

    msg.address = GV_StrCode_80016CCC(s00a_dword_800E09D0);
    msg.message[0] = GV_StrCode_80016CCC(s00a_dword_800E09DC);
    msg.message[1] = 1;
    msg.message_len = 2;
    GV_SendMessage_80016504(&msg);
}

int s00a_boxkeri_800D2440(SVECTOR *pos, SVECTOR *svec2)
{
    SVECTOR svec;

    GV_SubVec3_80016D40(svec2, pos, &svec);
    return GV_YawVec3_80016EF8(&svec);
}

int s00a_boxkeri_800D2474(BoxKeriWork *work, int *arg1, SVECTOR *arg2)
{
    OBJECT *obj;
    int     dir;

    obj = &work->field_20_obj;
    GM_CurrentMap_800AB9B0 = dword_800ABA0C;
    GM_InitObjectNoRots_800349B0((OBJECT_NO_ROTS *)obj, GV_StrCode_80016CCC(s00a_aCbbox_800E09E8), 0x6D, 0);
    GM_ConfigObjectLight_80034C44(obj, &work->field_7C_mat);

    work->field_20_obj.objs->objs[0].raise = 500;

    work->field_44 = DG_ZeroVector_800AB39C;
    work->field_48 = DG_ZeroVector_800AB39C;

    work->field_78 = 0;
    work->field_7A = 0;

    dir = GV_DiffDirU_80017040(GM_PlayerControl_800AB9F4->field_8_rotator.vy,
                               s00a_boxkeri_800D2440(&GM_PlayerPosition_800ABA10, arg2));
    if (dir < 512 || dir >= 3607)
    {
        work->field_76 = 0;
    }
    else
    {
        if (dir >= 1536)
        {
            if (dir >= 2584)
            {
                work->field_76 = 3;
            }
            else
            {
                work->field_76 = 2;
            }
        }
        else
        {
            work->field_76 = 1;
        }
    }

    memcpy(work->field_54, arg1, sizeof(work->field_54));
    work->field_74 = 0;
    s00a_boxkeri_800D23F0();
    return 0;
}

GV_ACT *NewBoxKeri_800D2600(int name, int where, int argc, char **argv)
{
    BoxKeriWork *work;

    work = (BoxKeriWork *)GV_NewActor_800150E4(4, sizeof(BoxKeriWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)s00a_boxkeri_800D219C,
                                  (TActorFunction)s00a_boxkeri_800D23D0, s00a_aBoxkeric_800E09F0);
        if (s00a_boxkeri_800D2474(work, (int *)name, (SVECTOR *)where) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }
    return &work->actor;
}