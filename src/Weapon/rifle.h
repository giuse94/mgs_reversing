#ifndef _RIFLE_H_
#define _RIFLE_H_

#include "Game/game.h"
#include "libgv/libgv.h"

// PSG1

typedef struct _RifleWork
{
    GV_ACT         field_0_actor;
    OBJECT_NO_ROTS field_20_obj;
    CONTROL       *field_44_pCtrl;
    OBJECT        *field_48_pParentObj;
    int            field_4c_numParent;
    int           *field_50;
    int            field_54;
    int            field_58;
    void          *field_5c;
} RifleWork;

STATIC_ASSERT_SIZE(RifleWork, 0x60);

int rifle_act_helper_80067BFC(void);

void rifle_act_80067D60(RifleWork *work);
void rifle_kill_80068118(RifleWork *work);

int rifle_loader_80068184(RifleWork *work, OBJECT *pParentObj, int numParent);

GV_ACT *NewRifle_80068214(CONTROL *pCtrl, OBJECT *pParentObj, int numParent, int *a4, int a5);

#endif // _RIFLE_H_
