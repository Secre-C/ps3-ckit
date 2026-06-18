#ifdef GAME_P5
#ifndef math_H
#define math_H

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

typedef struct {
  float x;
  float y;
  float z;
  float pad;
}vector3;

typedef struct {
  float x;
  float y;
  float z;
  float w;
}quaternion;

#endif
#endif