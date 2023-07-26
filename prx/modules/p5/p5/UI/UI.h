#ifdef GAME_P5
#ifndef UI_H
#define UI_H

// PS3 system includes
#include "lib/common.h"
#include "lib/shk.h"

#include "Sprite/Sprite.h"
#include "Calendar/Field_Day.h"

#define byte u8
#define sbyte s8
#define short s16
#define ushort u16
#define uint u32
#define ulonglong u64
#define longlong s64

typedef struct image image, *Pimage;

struct image {
    int field0_0x0;
    int field1_0x4;
    undefined field2_0x8;
    undefined field3_0x9;
    undefined field4_0xa;
    undefined field5_0xb;
    char * texture_name;
    undefined field7_0x10;
    undefined field8_0x11;
    undefined field9_0x12;
    undefined field10_0x13;
    undefined field11_0x14;
    undefined field12_0x15;
    undefined field13_0x16;
    undefined field14_0x17;
    undefined field15_0x18;
    undefined field16_0x19;
    undefined field17_0x1a;
    undefined field18_0x1b;
    undefined field19_0x1c;
    undefined field20_0x1d;
    undefined field21_0x1e;
    undefined field22_0x1f;
    int field23_0x20;
    uint field24_0x24;
    uint bitfield28_0x28;
};

#endif
#endif