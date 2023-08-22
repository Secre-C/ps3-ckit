#ifdef GAME_P5
#ifndef CLOTHTBL_H
#define CLOTHTBL_H

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

typedef struct processed_cloth_tbl processed_cloth_tbl, *Pprocessed_cloth_tbl;

typedef struct clothTbl_ids clothTbl_ids, *PclothTbl_ids;

struct processed_cloth_tbl {
    ushort cMajor;
    ushort some_count;
    struct clothTbl_ids * cloth_ids;
};

struct clothTbl_ids {
    short ids_unk0;
    u8 ids_unk2;
    u8 ids_unk3;
    u8 ids_unk4;
    u8 ids_unk5;
    u8 ids_unk6;
    u8 ids_unk7;
};

#endif
#endif