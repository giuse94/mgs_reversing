#include "bomb.h"
#include "Bullet/bakudan.h"
#include "Game/object.h"
#include "map/map.h"

// c4 (in hands)

extern char       aC4Bomb[]; // "c4_bomb"
extern char       aBombC[];  // "bomb.c"
extern short      d_800AB9EC_mag_size;
extern short      d_800ABA2C_ammo;

extern int        DG_CurrentGroupID_800AB968;
extern GM_Target *GM_BombSeg_800ABBD8;
extern int        GM_CurrentMap_800AB9B0;
extern int        used_counter_8009F42C;

extern short      gGameState_800B4D98[0x60];

void bomb_act_8006788C( Actor_Bomb *actor )
{
    int ammo;
    int f50;
    MATRIX *world;
    DG_OBJS *parent;

    GM_CurrentMap_800AB9B0 = actor->field_20_pCtrl->field_2C_map->field_0_map_index_bit;
    DG_GroupObjs( actor->f28_obj.objs, DG_CurrentGroupID_800AB968 );
    if ( actor->parent_obj->objs->flag & 0x80 )
    {
        DG_InvisibleObjs(  actor->f28_obj.objs );
    }
    else if ( actor->f54 == 0 )
    {
        DG_VisibleObjs(  actor->f28_obj.objs );
    }

    ammo = *GM_WeaponC4;
    parent = actor->parent_obj->objs;
    world = &parent->objs[ actor->num_parent ].world;

    f50 = *actor->f50;

    if ( ( f50 & 1 ) && ( ammo > 0 ) && ( used_counter_8009F42C < 16 ) )
    {
        if ( f50 & 2 )
        {
            if (NewBakudan_8006A6CC(
                world,
                NULL,
                0,
                actor->f58,
                GM_BombSeg_800ABBD8))
            {
                *GM_WeaponC4 = --ammo;
                GM_SeSet_80032858( &actor->field_20_pCtrl->field_0_position, 0x31 );
                actor->f54 = 0x18;
                DG_InvisibleObjs(  actor->f28_obj.objs );
            }

        }
        else if ( f50 & 4 )
        {
            *GM_WeaponC4 = --ammo;
            actor->f54 = 0x18;
            DG_InvisibleObjs(  actor->f28_obj.objs );
        }
    }
    if ( ( actor->f54 > 0 ) && ( --actor->f54 == 0 ) )
    {
        DG_VisibleObjs(  actor->f28_obj.objs );
    }
    if ( ammo == 0 )
    {
        DG_InvisibleObjs(  actor->f28_obj.objs );
    }
}

void bomb_kill_80067A74(Actor_Bomb *actor)
{
    GM_FreeObject_80034BF8(&actor->f28_obj);
}

int bomb_loader_80067A94(Actor_Bomb *actor_bomb, OBJECT *parent_obj, int num_parent)
{
    OBJECT *obj = &actor_bomb->f28_obj;

    GM_InitObjectNoRots_800349B0((OBJECT_NO_ROTS *)obj, GV_StrCode_80016CCC(aC4Bomb), WEAPON_FLAG, 0);

    if (!obj->objs)
        return -1;

    GM_ConfigObjectRoot_80034C5C(obj, parent_obj, num_parent);
    return 0;
}

Actor_Bomb *NewBomb_80067B20(GM_Control *ctrl, OBJECT *parent_obj, int num_parent, int *a4, int a5)
{
    Actor_Bomb *actor = (Actor_Bomb *)GV_NewActor_800150E4(6, sizeof(Actor_Bomb));
    if (actor)
    {
        GV_SetNamedActor_8001514C(&actor->field_0_actor, (TActorFunction)bomb_act_8006788C,
                                  (TActorFunction)bomb_kill_80067A74, aBombC);
        if (bomb_loader_80067A94(actor, parent_obj, num_parent) < 0)
        {
            GV_DestroyActor_800151C8(&actor->field_0_actor);
            return 0;
        }

        actor->field_20_pCtrl = ctrl;
        actor->parent_obj = parent_obj;
        actor->num_parent = num_parent;
        actor->f50 = a4;
        actor->f54 = 0;
        actor->f58 = a5;
    }

    d_800ABA2C_ammo = 0;
    d_800AB9EC_mag_size = 0;

    return actor;
}
