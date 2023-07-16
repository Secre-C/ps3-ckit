#ifdef GAME_P5
// PS3 system includes
#include <sys/prx.h>
#include <sys/tty.h>
#include <sys/syscall.h>
// Pre-prepared libraries exist in lib
// Common includes things like printf for printing, strlen, etc.
// PRX dont have access to the usual C libraries, so any functionality that you need from it
// will have to be reimplemented in there.
#include "lib/common.h"

// SHK (Static Hook library)
#include "lib/shk.h"

// Include this to use config variables
#include "lib/config.h"

#include "Sprite.h"

#define DEBUG_LOG( msg, ... ) \
  if ( CONFIG_ENABLED( debug ) ) printf( "DEBUG: " msg, ##__VA_ARGS__ )

#define FUNC_LOG( msg, ... ) \
  if ( CONFIG_ENABLED( functest ) ) printf( "DEBUG: " msg, ##__VA_ARGS__ )

#define byte u8
#define sbyte s8
#define short s16
#define ushort u16
#define uint u32
#define ulonglong u64
#define longlong s64

sprite* spd_open_and_process( char* filename, ulonglong a2, ulonglong a3 )
{
  SHK_FUNCTION_CALL_3(0x1c2d18, sprite*, char*, filename, ulonglong, a2, ulonglong, a3);
}

void spd_sprite_create(sprite* spd, uint sprite_id)
{
  SHK_FUNCTION_CALL_2(0x1c4438, void, sprite*, spd, uint, sprite_id);
}

void sprite_set_visible(sprite* spd)
{
  SHK_FUNCTION_CALL_1(0x118e10, void, sprite*, spd);
}

void SPRITE_001c5254(sprite* spd, u8 a2)
{
  SHK_FUNCTION_CALL_2(0x1c5254, void, sprite*, spd, u8, a2);
}

void sprite_set_screen_position(double x, double y, sprite* spd)
{
  SHK_FUNCTION_CALL_3(0x1c4ed0, void, double, x, double, y, sprite*, spd);
}

#endif