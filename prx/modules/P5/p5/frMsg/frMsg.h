#ifdef GAME_P5
#ifndef FRMSG_H 
#define FRMSG_H 

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

const int* gMessageTagLevel;

typedef struct {
    int field0_0x0;
    int field1_0x4;
    int X;
    int Y;
    u32 Z;
    u8 Style;
    u8 ColNo;
    u8 Tp;
    u8 Spd;
    u8 *pMsg;
    void *pFRQ;
    int Ofs;
    u8 FrqFlag;
    u8 RetFlag;
    u16 AlphaDelay;
    u32 Color;
    u8 field16_0x2c;
    u8 field17_0x2d;
    u8 field18_0x2e;
    u8 field19_0x2f;
    void *callback;
    void *callback_userdata;
    void *tag_callback;
    void* (*tag_callback_userdata)(void*, int, int);
}frMsgInfo;

#endif
#endif
