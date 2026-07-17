#ifdef GAME_P5
#ifndef SAVEDATA_H
#define SAVEDATA_H

// PS3 system includes
#include "lib/common.h"
#include "lib/shk.h"

#define byte u8
#define sbyte s8
#define short s16
#define ushort u16
#define uint u32
#define ulonglong u64
#define longlong s64

typedef struct
{
    int counts[128];
    u8 bits[128];
}newSaveData;

#endif
#endif