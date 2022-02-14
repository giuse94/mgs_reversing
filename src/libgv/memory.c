#include "libgv.h"
#include "mts_new.h"

GV_Heap SECTION(".MemorySystems_800AD2F0") MemorySystems_800AD2F0[3];

void* System_FindAlloc_80015758(GV_Heap* pHeap, void* a1)
{
    int                  i ;
    GV_MemoryAllocation* pAlloc;
    GV_MemoryAllocation* pAlloc2;

    if ( a1 < pHeap->mStartAddr || a1 >= pHeap->mEndAddr ) return 0 ;
    
    pAlloc = pHeap->mAllocs;

    for (i = pHeap->mUnitsCount ; i >= 2 ; i /= 2)
    {
        pAlloc2 = &pAlloc[ i / 2 ] ;

        if (a1 == pAlloc2->mPDataStart) return pAlloc2 ;

        if (pAlloc2->mPDataStart < a1)
        {
            i--;
            pAlloc =  pAlloc2 + 1;
        }
    }

    if ( i <= 0 || pAlloc->mPDataStart != a1) return 0;

    return pAlloc;
}

GV_MemoryAllocation* sub_80015818( GV_Heap* pHeap, int a1 )
{
    int                     i, j, k;
    GV_MemoryAllocation*    pAlloc;

    j = (int)pHeap->mAllocs[0].mPDataStart;
    pAlloc = pHeap->mAllocs;

    for ( i = pHeap->mUnitsCount ; i > 0 ; --i )
    {
        k = (int)pAlloc[1].mPDataStart;
        j = k - j;

        if (j >= a1)
        {
            if (!pAlloc->mAllocType) return pAlloc;
        }
        j = k;
        pAlloc++;
    }
    return 0;
}

void sub_80015874( GV_Heap* pHeap, GV_MemoryAllocation* pAlloc )
{
    int                     i, x;
    int                     size;
    GV_MemoryAllocation*    pAlloc2;

    x = pHeap->mUnitsCount;
    pAlloc2  = &pHeap->mAllocs[x];

    size = (pAlloc - pHeap->mAllocs);

    for ( i = x - size ; i > -1 ; --i )
    {
        pAlloc2[1] = pAlloc2[0];
        pAlloc2--;
    }

    pHeap->mUnitsCount++;
}

void sub_800158C8( GV_Heap *pHeap, GV_MemoryAllocation *pAlloc, int n_unit )
{

    int i ;
    GV_MemoryAllocation *pAlloc2 = &pAlloc[ n_unit ] ;

    i = pHeap->mUnitsCount - (pAlloc - pHeap->mAllocs);

    for ( i = i - n_unit ; i > -1 ; --i )
    {
        *pAlloc = *pAlloc2 ;
        pAlloc++ ;
        pAlloc2++ ;
    }

    pHeap->mUnitsCount -= n_unit ;
}

void System_voided_reset_80015924(GV_Heap *pHeap)
{
    int	i, bUnknown;
    GV_MemoryAllocation* pAlloc  = pHeap->mAllocs;
    GV_MemoryAllocation* pAlloc2 = pAlloc;

    bUnknown = 0;
    for ( i = pHeap->mUnitsCount ; i > 0 ; --i )
    {
        if (pAlloc2->mAllocType >= (unsigned int)2)
        {
            *pAlloc = *pAlloc2;
            pAlloc++;
            bUnknown = 0;
        }
        else
        {
            if (!bUnknown)
            {
                bUnknown = 1;
                pAlloc->mPDataStart = pAlloc2->mPDataStart ;
                pAlloc->mAllocType = 0;
                pAlloc++;
            }
        }

        pAlloc2++;
    }

    pAlloc->mPDataStart = pHeap->mEndAddr;
    pAlloc->mAllocType = 2;

    pHeap->mUnitsCount = (pAlloc - pHeap->mAllocs);
}

void System_dynamic_reset_800159B8(GV_Heap* pHeap)
{
    int                     i;
    int                     diff;
    int                     alloc_type;
    void*                   addr;
    void*                   pDataStart;
    GV_MemoryAllocation*    pAlloc;
    GV_MemoryAllocation*    pAlloc2;
    
    pAlloc  = pHeap->mAllocs;
    addr    = pHeap->mStartAddr;
    pAlloc2 = pAlloc;

    for (i = pHeap->mUnitsCount ; i > 0 ; --i )
    {
        alloc_type = pAlloc2->mAllocType;
        if ( alloc_type >= (unsigned int)2)
        {
            pDataStart = pAlloc2->mPDataStart;
            diff = pAlloc2[1].mPDataStart - pDataStart;
            if ( pDataStart != addr )
            {
                pAlloc->mPDataStart = addr;
                pAlloc->mAllocType  = alloc_type;
                *(int*)alloc_type   = (int)addr; //this seems wrong
                GV_CopyMemory_800160D8(pDataStart, addr, diff);
            }
            addr += diff;
            pAlloc++;
        }
        pAlloc2++;
    }

    if ( addr != pHeap->mEndAddr )
    {
        pAlloc->mPDataStart = addr;
        pAlloc->mAllocType = 0;
        pAlloc++;
    }

    pAlloc->mPDataStart = pHeap->mEndAddr;
    pAlloc->mAllocType = 2;

    pHeap->mUnitsCount = (pAlloc - pHeap->mAllocs);
}


void GV_InitMemorySystemAll_80015AB0(void)
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        GV_InitMemorySystem_80015AF4(i, 0, 0, 0);
    }
}

void GV_InitMemorySystem_80015AF4(int index, int bIsDynamic, void *pMemory, int size)
{
    GV_Heap *pHeap = &MemorySystems_800AD2F0[index];
    GV_MemoryAllocation *pAllocs = &pHeap->mAllocs[0];
    unsigned char *alignedEndPtr = ((unsigned char *)pMemory) + (size & 0xfffffff0); // align

    pHeap->mFlags = bIsDynamic != 0;
    pHeap->mStartAddr = pMemory;

    pHeap->mEndAddr = alignedEndPtr;
    pHeap->mUnitsCount = 1;

    // First entry is free
    pAllocs[0].mPDataStart = pMemory;
    pAllocs[0].mAllocType = GV_MemoryAllocation_States_Free_0;

    // Second is used and is the entire space
    pAllocs[1].mPDataStart = alignedEndPtr;
    pAllocs[1].mAllocType = GV_MemoryAllocation_States_Used_2;
}

void GV_ClearMemorySystem_80015B4C( int which )
{
    GV_Heap *pHeap = &MemorySystems_800AD2F0[which];
    int flags = pHeap->mFlags;
    if (flags & (GV_Heap_Flags_Failed_4 | GV_Heap_Flags_Voided_2))
    {
        if (flags & GV_Heap_Flags_Failed_4)
        {
            if (flags & GV_Heap_Flags_Dynamic_1)
            {
                System_dynamic_reset_800159B8(pHeap);
                pHeap->mFlags &= ~(GV_Heap_Flags_Failed_4 | GV_Heap_Flags_Voided_2);
            }
        }
        if (flags & GV_Heap_Flags_Voided_2)
        {
            System_voided_reset_80015924(pHeap);
            pHeap->mFlags &= ~GV_Heap_Flags_Voided_2;
        }
    }
    pHeap->mFlags &= ~(GV_Heap_Flags_Failed_4 | GV_Heap_Flags_Voided_2);
}


extern const char aSystemD[];
extern const char aDynamic[];
extern const char asc_800AB360[];
extern const char aAddr08x08xUnit[];
extern const char aFreeDDVoidedDM[];

void GV_CheckMemorySystem_80015BF8(int heapIdx)
{
    int maxFree;
    int voidedCount;
    int freeCount;

    int size;

    int unitCounter;
    GV_MemoryAllocation *pAllocIter;

    GV_Heap *pHeap = &MemorySystems_800AD2F0[heapIdx];

    mts_printf_8008BBA0(aSystemD, heapIdx);

    if (pHeap->mFlags & GV_Heap_Flags_Dynamic_1)
    {
        mts_printf_8008BBA0(aDynamic);
    }

    if (pHeap->mFlags & GV_Heap_Flags_Voided_2)
    {
        mts_printf_8008BBA0("voided ");
    }

    if (pHeap->mFlags & GV_Heap_Flags_Failed_4)
    {
        mts_printf_8008BBA0("failed ");
    }

    mts_printf_8008BBA0(")\n");
    mts_printf_8008BBA0(aAddr08x08xUnit, pHeap->mStartAddr, pHeap->mEndAddr, pHeap->mUnitsCount);
    size = pHeap->mEndAddr - pHeap->mStartAddr;

    freeCount = 0;
    voidedCount = 0;
    maxFree = 0;

    pAllocIter = &pHeap->mAllocs[0];

    for (unitCounter = pHeap->mUnitsCount; unitCounter > 0; unitCounter--)
    {
        int type = pAllocIter->mAllocType;

        unsigned char *firstSize = pAllocIter->mPDataStart;
        unsigned char *nextSize = pAllocIter[1].mPDataStart;

        int allocSize = nextSize - firstSize;

        if (type == GV_MemoryAllocation_States_Free_0)
        {
            freeCount += allocSize;
            if (maxFree < allocSize)
            {
                maxFree = allocSize;
            }
        }
        else if (type == GV_MemoryAllocation_States_Void_1)
        {
            voidedCount += allocSize;
        }

        pAllocIter++;
    }

    mts_printf_8008BBA0(aFreeDDVoidedDM,
                       freeCount,
                       size,
                       voidedCount,
                       maxFree);
}

extern const char aDynamic[];
extern const char a8dBytesFrom08x[];
extern const char a8dBytesFrom08x_0[];
extern const char a8dBytesFrom08x_1[];
extern const char a8dBytesFrom08x_2[];

void GV_DumpMemorySystem_80015D48(int heapIdx)
{
    int unitCounter;
    GV_MemoryAllocation *pAllocIter;

    GV_Heap *pHeap = &MemorySystems_800AD2F0[heapIdx];
    mts_printf_8008BBA0(aSystemD, heapIdx);

    if (!(pHeap->mFlags & GV_Heap_Flags_Dynamic_1))
    {
        mts_printf_8008BBA0("static ");
    }
    else
    {
        mts_printf_8008BBA0(aDynamic);
    }

    if (pHeap->mFlags & GV_Heap_Flags_Voided_2)
    {
        mts_printf_8008BBA0("voided ");
    }

    if (pHeap->mFlags & GV_Heap_Flags_Failed_4)
    {
        mts_printf_8008BBA0("failed ");
    }

    mts_printf_8008BBA0(")\n");

    pAllocIter = &pHeap->mAllocs[0];

    for (unitCounter = pHeap->mUnitsCount; unitCounter > 0; unitCounter--)
    {
        int allocType = pAllocIter->mAllocType;
        unsigned char *firstSize = pAllocIter->mPDataStart;
        unsigned char *nextSize = pAllocIter[1].mPDataStart;

        int allocSize = nextSize - firstSize;

        if (allocType == GV_MemoryAllocation_States_Free_0)
        {
            mts_printf_8008BBA0(a8dBytesFrom08x, allocSize, pAllocIter->mPDataStart);
        }
        else if (allocType == GV_MemoryAllocation_States_Void_1)
        {
            mts_printf_8008BBA0(a8dBytesFrom08x_0, allocSize, pAllocIter->mPDataStart);
        }
        else if (allocType == GV_MemoryAllocation_States_Used_2)
        {
            mts_printf_8008BBA0(a8dBytesFrom08x_1, allocSize, pAllocIter->mPDataStart);
        }
        else
        {
            mts_printf_8008BBA0(a8dBytesFrom08x_2, allocSize, pAllocIter->mPDataStart, allocType);
        }

        pAllocIter++;
    }

    mts_printf_8008BBA0("\n");
}

void *GV_AllocMemory_80015EB8( int which, int size )
{
    return GV_AllocMemory2_80015ED8( which, size, (void** )2 );
}

void *GV_AllocMemory2_80015ED8( int which, int size, void** type)
{
    int                     two;
    void*                   pDataStart;
    GV_Heap*                pHeap;
    GV_MemoryAllocation*    pAlloc;

    pHeap = &MemorySystems_800AD2F0[which] ;
    two = GV_MemoryAllocation_States_Used_2;

    if ( pHeap->mUnitsCount < 511 ) 
    {

        size = (size + 15) & -16;

        pAlloc = sub_80015818(  pHeap, size );

        if (!pAlloc)
        {
            pHeap->mFlags |= GV_Heap_Flags_Failed_4;
        }
        else
        {
            pDataStart = pAlloc->mPDataStart;

            if ( size < pAlloc[1].mPDataStart - pDataStart )
            {
                sub_80015874( pHeap, pAlloc );
                pAlloc[1].mPDataStart = pDataStart + size;
                pAlloc[1].mAllocType  = 0;
            }

            pAlloc->mAllocType = (int)type;

            if ( (int)type != two )
            {
                type[0] = pDataStart;
            }

            return pDataStart;
        }
    }

    return 0;
}