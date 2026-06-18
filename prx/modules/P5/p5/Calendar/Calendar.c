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

#include "Calendar.h"

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

void GetDayMonth(int dayTotal, int* monthBuffer, int* dayBuffer)
{
  SHK_FUNCTION_CALL_3(0x4951c, void, int, dayTotal, int*, monthBuffer, int*, dayBuffer);
}

int GetWeekday(int dayTotal)
{
  SHK_FUNCTION_CALL_1(0x490ac, int, int, dayTotal);
}

undefined8 check_next_day_public_holiday( int a1 )
{
    SHK_FUNCTION_CALL_1( 0x4a55c, undefined8, int, a1 );
}

int calculateDayCount( int month, int day )
{
    SHK_FUNCTION_CALL_2( 0x495c8, int, int, month, int, day );
}

u8 Get_Weather_Index( longlong a1, uint a2 )
{
    SHK_FUNCTION_CALL_2( 0x4a268, u8, longlong, a1, uint, a2 );
}

#endif