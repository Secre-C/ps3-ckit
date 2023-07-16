#ifdef GAME_P5
#ifndef Input_H
#define Input_H

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

typedef struct Button Button, *PButton;
typedef struct Analog_Stick Analog_Stick, *PAnalog_Stick;

//Button Globals
Button *Button_Hold;
Button *Button_Interval;
Button *Button_Press;

//Analog Stick Globals
Analog_Stick *L_Stick;
Analog_Stick *R_Stick;

struct Button
{
    ushort Square : 1; //0x8000
    ushort Cross : 1; // 0x4000
    ushort Circle : 1; // 0x2000
    ushort Triangle : 1; // 0x1000
    ushort R1 : 1; // 0x800
    ushort L1 : 1; // 0x400
    ushort R2 : 1; // 0x200
    ushort L2 : 1; // 0x100
    ushort Dpad_Left : 1; // 0x80
    ushort Dpad_Down : 1; // 0x40
    ushort Dpad_Right : 1; // 0x20
    ushort Dpad_Up : 1; // 0x10
    ushort Start : 1; // 0x8
    ushort R3 : 1; // 0x4
    ushort L3 : 1; // 0x2
    ushort Select : 1; // 0x1
};

struct Analog_Stick
{
    s8 X; //Neutral is 128, Left goes down to 0, Right goes up to -1
    s8 Y; //Neutral is 128, Up goes down to 0, Down goes up to -1
};

#endif
#endif