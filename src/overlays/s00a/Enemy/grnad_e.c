#include "libgv/libgv.h"
#include "Bullet/tenage.h"
#include "Game/control.h"
#include "Game/game.h"
#include "Game/object.h"
#include "Weapon/grenade.h"
#include "strcode.h"

typedef struct _GrenadeEnemyWork
{
    GV_ACT   actor;
    CONTROL *control;
    OBJECT  *parent;
    OBJECT   object;
    int      num_parent;
    int     *f110;
    SVECTOR  f114;
    int      timer;
    int      type;
} GrenadeEnemyWork;

extern int GM_CurrentMap_800AB9B0;

SVECTOR svec_800C360C[2] = {{0, 80, 80, 0}, {0, 20, 500, 0}};

GV_ACT *NewBlast_8006DFDC(MATRIX *);

#define EXEC_LEVEL 5

void GrenadeEnemyAct_800D1DDC(GrenadeEnemyWork *work)
{
    SVECTOR  pos;
    SVECTOR  step;
    int      temp_s3;
    MATRIX  *world;
    CONTROL *control;
    SVECTOR *var_s2;
    int      dist;

    GM_CurrentMap_800AB9B0 = work->control->map->index;

    GM_ActObject2_80034B88(&work->object);

    temp_s3 = *work->f110;
    world = &work->parent->objs->objs[work->num_parent].world;

    if (temp_s3 & 0x1)
    {
        if (--work->timer <= 0)
        {
            // Missing second argument `pBlastData`.
            NewBlast_8006DFDC(world);
            work->timer = 120;
        }

        if (temp_s3 & 0x6)
        {
            control = work->control;
            DG_SetPos2(&control->mov, &control->rot);

            var_s2 = (temp_s3 & 0x4) ? &svec_800C360C[1] : &svec_800C360C[0];

            work->f114.vy = control->mov.vy;

            dist = GV_DiffVec3(&control->mov, &work->f114);

            if (temp_s3 & 0x2)
            {
                dist /= 2;
            }

            var_s2->vz = dist / 8;

            DG_RotVector(var_s2, &step, 1);

            pos.vx = world->t[0];
            pos.vy = world->t[1];
            pos.vz = world->t[2];

            NewTenage3_8006A128(&pos, &step, work->timer, work->type, KMD_GRENADE, 0, 0);
            work->timer = 120;
        }

        DG_VisibleObjs(work->object.objs);
    }
    else
    {
        DG_InvisibleObjs(work->object.objs);
        work->timer = 120;
    }
}

void GrenadeEnemyDie_800D1FAC(GrenadeEnemyWork *work)
{
    GM_FreeObject_80034BF8(&work->object);
}

int GrenadeEnemyGetResources_800D1FCC(GrenadeEnemyWork *work, OBJECT *parent, int num_parent, int unused)
{
    OBJECT *object;

    object = &work->object;

    printf("grenade model=%d \n", KMD_GRENADE);

    GM_InitObject_80034A18(object, KMD_GRENADE, 0x36D, 0);
    GM_ConfigObjectRoot_80034C5C(object, parent, num_parent);

    return 0;
}

GV_ACT * NewGrenadeEnemy_800D203C(CONTROL *control, OBJECT *parent, int num_parent, int *arg3, int unused, SVECTOR *arg6, int type)
{
    GrenadeEnemyWork *work;

    work = (GrenadeEnemyWork *)GV_NewActor(EXEC_LEVEL, sizeof(GrenadeEnemyWork));
    if (work != NULL)
    {
        GV_SetNamedActor(&work->actor, (TActorFunction)GrenadeEnemyAct_800D1DDC, (TActorFunction)GrenadeEnemyDie_800D1FAC, "grnad_e.c");

        if (GrenadeEnemyGetResources_800D1FCC(work, parent, num_parent, type) < 0)
        {
            GV_DestroyActor(&work->actor);
            return NULL;
        }

        work->control = control;
        work->parent = parent;
        work->num_parent = num_parent;

        work->f110 = arg3;
        work->timer = 120;
        work->type = type;

        work->f114 = *arg6;
    }

    return &work->actor;
}

void NewGrenadeEnemy_800D2138(CONTROL *control, OBJECT *parent, int num_parent, int *arg3, SVECTOR *arg4, int arg5)
{
    NewGrenadeEnemy_800D203C(control, parent, num_parent, arg3, arg5, arg4, GRD_GRENADE);
}

void NewGrenadeEnemy_800D2168(CONTROL *control, OBJECT *parent, int num_parent, int *arg3, SVECTOR *arg4, int arg5)
{
    NewGrenadeEnemy_800D203C(control, parent, num_parent, arg3, arg5, arg4, GRD_STUN);
}
