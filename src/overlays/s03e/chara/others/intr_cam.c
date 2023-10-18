#include "libgv/libgv.h"
#include "Game/game.h"
#include "Game/camera.h"

typedef struct IntrCamWork
{
    GV_ACT  actor;
    int     field_20;
    int     field_24;
    int     field_28;
    SVECTOR field_2C;
    SVECTOR field_34;
} IntrCamWork;

extern char             s03e_dword_800CBFD0[];
extern PlayerStatusFlag GM_PlayerStatus_800ABA50;
extern UnkCameraStruct  gUnkCameraStruct_800B77B8;

void s03e_intr_cam_800C5548(IntrCamWork *work)
{
    GV_MSG *msgs;
    int     count;

    count = GV_ReceiveMessage_80016620(work->field_20, &msgs);
    if (count <= 0)
    {
        return;
    }

    while (--count >= 0)
    {
        switch (msgs->message[0])
        {
        case 0x3223:
            work->field_24 = 3;
            break;
        case 0xE4E:
            work->field_24 = 1;
            work->field_34 = gUnkCameraStruct_800B77B8.field_0;
            break;
        case 0xC927:
            work->field_24 = 2;
            break;
        }
        msgs++;
    }
}

void s03e_intr_cam_800C5638(IntrCamWork *work)
{
    int field_28;

    s03e_intr_cam_800C5548(work);
    if (!(GM_PlayerStatus_800ABA50 & PLAYER_FIRST_PERSON_DUCT))
    {
        work->field_28 = 8;
        return;
    }

    if (work->field_24 >= 2)
    {
        if (work->field_24 == 3)
        {
            GV_DestroyActor_800151C8(&work->actor);
        }
        work->field_28 = 8;
        return;
    }

    field_28 = work->field_28;
    if (work->field_28 > 0)
    {
        work->field_28--;
    }
    GV_NearTimeSV_800268AC(&work->field_34.vx, &work->field_2C.vx, field_28, 3);
    gUnkCameraStruct_800B77B8.field_0 = work->field_34;
}

void s03e_intr_cam_800C56F0(IntrCamWork *work)
{
}

int s03e_intr_cam_800C56F8(IntrCamWork *work)
{
    GCL_GetOption_80020968('p');
    GCL_StrToSV_80020A14(GCL_Get_Param_Result_80020AA4(), &work->field_2C);
    work->field_24 = 2;
    work->field_28 = 8;
    return 0;
}

GV_ACT *s03e_intr_cam_800C5748(int name, int where, int argc, char **argv)
{
    IntrCamWork *work;

    work = (IntrCamWork *)GV_NewActor_800150E4(7, sizeof(IntrCamWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)s03e_intr_cam_800C5638,
                                  (TActorFunction)s03e_intr_cam_800C56F0, s03e_dword_800CBFD0);
        if (s03e_intr_cam_800C56F8(work) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
        work->field_20 = name;
    }
    return &work->actor;
}