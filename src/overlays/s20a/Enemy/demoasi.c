#include "libdg/libdg.h"
#include "libgcl/hash.h"
#include "libgv/libgv.h"

typedef struct _DemoasiWork
{
    GV_ACT   actor;
    int      map;
    DG_PRIM *prim;
    DG_TEX  *tex;
    MATRIX  *world;
    char     pad2[0x10];
    SVECTOR  prim_vecs[4];
    int      f60;
    int      f64;
} DemoasiWork;

extern int GM_CurrentMap_800AB9B0;

#define EXEC_LEVEL 4

void Demoasi_800C3D88(DG_PRIM *prim, DG_TEX *tex, int r, int g, int b)
{
    POLY_FT4 *poly;

    poly = &prim->packs[0]->poly_ft4;
    setRGB0(poly, r, g, b);

    poly = &prim->packs[1]->poly_ft4;
    setRGB0(poly, r, g, b);
}

void Demoasi_800C3DB4(SVECTOR *vec, int x, int y, int z)
{
    vec->vx = x;
    vec->vy = y;
    vec->vz = z;
}

void DemoasiAct_800C3DC4(DemoasiWork *work)
{
    int t;
    int shade;

    if (++work->f64 > (work->f60 - 300))
    {
        GV_DestroyActor_800151C8(&work->actor);
    }

    t = work->f60 - work->f64;
    if (t < 690)
    {
        shade = 48 - ((690 - t) * 48) / 690;
        Demoasi_800C3D88(work->prim, work->tex, shade, shade, shade);
    }
}

void Demoasi_800C3E6C(POLY_FT4 *poly, DG_TEX *tex, int abr, int r, int g, int b)
{
    int x, y, w, h;
    int x2, y2, w2, h2;

    setPolyFT4(poly);
    setRGB0(poly, r, g, b);

    if (abr < 4)
    {
        setSemiTrans(poly, 1);

        x = tex->off_x;
        w = tex->w;
        y = tex->off_y;
        h = tex->h;
        setUVWH(poly, x, y, w, h);

        poly->tpage = tex->tpage;
        poly->clut = tex->clut;

        poly->tpage = (poly->tpage & ~0x60) | (abr << 5);
    }
    else
    {
        x2 = tex->off_x;
        w2 = tex->w;
        y2 = tex->off_y;
        h2 = tex->h;
        setUVWH(poly, x2, y2, w2, h2);

        poly->tpage = tex->tpage;
        poly->clut = tex->clut;
    }
}

int DemoasiGetResources_800C3F60(DemoasiWork *work, int which, int height, int arg3)
{
    DG_PRIM *prim;
    DG_TEX  *tex;

    work->f60 = arg3;

    if (which == 1)
    {
        Demoasi_800C3DB4(&work->prim_vecs[1], -70, 0, -140);
        Demoasi_800C3DB4(&work->prim_vecs[0], 70, 0, -140);
        Demoasi_800C3DB4(&work->prim_vecs[3], -70, 0, 140);
        Demoasi_800C3DB4(&work->prim_vecs[2], 70, 0, 140);
    }
    else
    {
        Demoasi_800C3DB4(&work->prim_vecs[0], -70, 0, -140);
        Demoasi_800C3DB4(&work->prim_vecs[1], 70, 0, -140);
        Demoasi_800C3DB4(&work->prim_vecs[2], -70, 0, 140);
        Demoasi_800C3DB4(&work->prim_vecs[3], 70, 0, 140);
    }

    prim = DG_GetPrim(0x12, 1, 0, work->prim_vecs, NULL);
    work->prim = prim;
    if (prim == NULL)
    {
        return -1;
    }

    work->f64 = 0;
    work->map = GM_CurrentMap_800AB9B0;

    work->world->t[1] = height;

    tex = DG_GetTexture_8001D830(PCX_ASIATO);
    work->tex = tex;
    if (tex == NULL)
    {
        return -1;
    }

    Demoasi_800C3E6C(&prim->packs[0]->poly_ft4, tex, 2, 48, 48, 48);
    Demoasi_800C3E6C(&prim->packs[1]->poly_ft4, tex, 2, 48, 48, 48);

    DG_SetPos_8001BC44(work->world);
    DG_PutPrim_8001BE00(&work->prim->world);

    return 0;
}

void DemoasiDie_800C4110(DemoasiWork *work)
{
    DG_PRIM *prim;

    prim = work->prim;
    if (prim != NULL)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }
}

GV_ACT * NewDemoasi_800C414C(MATRIX *world, int which, int height)
{
    DemoasiWork *work;

    work = (DemoasiWork *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(DemoasiWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)DemoasiAct_800C3DC4, (TActorFunction)DemoasiDie_800C4110, "demoasi.c");

        work->world = world;

        if (DemoasiGetResources_800C3F60(work, which, height, 690) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }

    return &work->actor;
}

GV_ACT * NewDemoasi_800C41F4(MATRIX *world, int which, int height, int arg3)
{
    DemoasiWork *work;

    work = (DemoasiWork *)GV_NewActor_800150E4(EXEC_LEVEL, sizeof(DemoasiWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)DemoasiAct_800C3DC4, (TActorFunction)DemoasiDie_800C4110, "demoasi.c");

        work->world = world;

        if (DemoasiGetResources_800C3F60(work, which, height, arg3) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
    }

    return &work->actor;
}
