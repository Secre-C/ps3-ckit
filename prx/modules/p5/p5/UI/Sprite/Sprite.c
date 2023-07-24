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

sprite* spd_open_and_process( char* filename )
{
  SHK_FUNCTION_CALL_1(0x1c2c74, sprite*, char*, filename);
}

void spd_sprite_create(sprite* spd, uint sprite_id)
{
  SHK_FUNCTION_CALL_2(0x1c4438, void, sprite*, spd, uint, sprite_id);
}

void sprite_toggle_visibility(sprite* spd)
{
  SHK_FUNCTION_CALL_1(0x118e10, void, sprite*, spd);
}

void SPRITE_001c5254(sprite* spd, u8 a2)
{
  SHK_FUNCTION_CALL_2(0x1c5254, void, sprite*, spd, u8, a2);
}

void sprite_set_screen_position( double x, double y, sprite* spd)
{
  SHK_FUNCTION_CALL_3(0x1c4ed0, void, sprite*, spd, double, x, double, y);
}

bool sprite_adjust_pos(sprite *spd, double x, double y)
{
  SHK_FUNCTION_CALL_3(0x1c4c7c, bool, sprite*, spd, double, x, double, y);
}

bool sprite_set_scale(sprite *spd, double x, double y)
{
  SHK_FUNCTION_CALL_3(0x1c509c, bool, sprite*, spd, double, x, double, y);
}

bool sprite_set_color(sprite* spd, int color)
{
  SHK_FUNCTION_CALL_2(0x1c5134, bool, sprite*, spd, int, color);
}

void sprite_set_draw_method(int a1, short a2, u8 draw_method)
{
  SHK_FUNCTION_CALL_3(0x9477e8, void, int, a1, short, a2, u8, draw_method);
}

void sprite_set_color_bounds(int a1, short a2, u8 draw_method)
{
  SHK_FUNCTION_CALL_3(0x946e4c, void, int, a1, short, a2, u8, draw_method);
}

bool sprite_set_bound(sprite *spd, double a2)
{
  SHK_FUNCTION_CALL_2(0x1c4f54, bool, sprite*, spd, double, a2);
}

int SPRITE_00116b78(void)
{
  SHK_FUNCTION_CALL_0(0x116b78, int);
}

void SPRITE_00947894(int a1, short a2, short a3, short a4, short a5)
{
  SHK_FUNCTION_CALL_5(0x947894, void, int, a1, short, a2, short, a3, short, a4, short, a5);
}

void SPRITE_0094774c( ulonglong a1, ulonglong a2 )
{
    SHK_FUNCTION_CALL_2( 0x94774c, void, ulonglong, a1, ulonglong, a2 );
}

double SRPITE_001c4958( sprite* spd )
{
    SHK_FUNCTION_CALL_1( 0x1c4958, double, sprite*, spd );
}

#endif