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

#include "Field.h"

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

int IsInDungeon( short a1 ){
    SHK_FUNCTION_CALL_1( 0x2978d4, int, short, a1 );
}

int IsInMementosField( int a1 ){
    SHK_FUNCTION_CALL_1( 0x32083c, int, int, a1 );
}

void FldGetFloor( long a1, vector3* a2, double a3, double a4 )
{
    SHK_FUNCTION_CALL_4( 0x325e38, void, long, a1, vector3*, a2, double, a3, double, a4 );
}

void playerSnapToGround(PlayerParams* player)
{
    vector3* currentTranslate = &player->Translate;
    FldGetFloor(player->PFMWK, currentTranslate, 40.0, 10000000000.0);
}

#endif