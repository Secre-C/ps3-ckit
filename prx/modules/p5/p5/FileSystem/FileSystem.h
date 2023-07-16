#ifdef GAME_P5
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

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
  u64 fileStatus;
  char filename[128];
  u32 bufferSize;
  u32 unk2;
  u32 unk3;
  u32 pointerToFile;
}fileHandleStruct;

#endif
#endif