#ifdef GAME_P5
#ifndef COLORPUZZLE_H
#define COLORPUZZLE_H

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

typedef struct GMC_Color_Switch GMC_Color_Switch, *PGMC_Color_Switch;

struct GMC_Color_Switch
{
    int cnv_reshnd;
    int gmc_id;
    int gmc_group;
    int color_bitfield;
    GMC_Color_Switch* next;
};

#endif
#endif