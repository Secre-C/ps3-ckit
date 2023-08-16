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

#include "PlayerObject.h"

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

ushort ModelGetMajorID(ResourceHandleStruct* modelResource)
{
  if (modelResource != 0)
    return (modelResource->ModelIDs >> 0x14) & 0xffff;
}

ushort ModelGetMinorID(ResourceHandleStruct* modelResource)
{
  if (modelResource != 0)
    return (ushort)modelResource->ModelIDs & 0xfff;
}

u8 ModelGetSubID(ResourceHandleStruct* modelResource)
{
  if (modelResource != 0)
    return (u8)(modelResource->ModelIDs >> 0xc) & 0xff;
}

int PCGetReshndAddr(ModelAnim* modelAnim)
{
	return modelAnim->PlayerModelResource;
}

ulonglong FUN_0001ee3c( int a1 )
{
    SHK_FUNCTION_CALL_1( 0x1ee3c, ulonglong, int, a1 );
}

ulonglong * char_af_addmotion( ResourceHandleStruct* model, int animId )
{
    SHK_FUNCTION_CALL_2( 0x3366f0, ulonglong *, ResourceHandleStruct*, model, int, animId );
}

ResourceHandleStruct * GetModelResourceFromHandle( int ResourceTable, int ResourceHandle )
{
    SHK_FUNCTION_CALL_2( 0x1282c, ResourceHandleStruct *, int, ResourceTable, int, ResourceHandle );
}

#endif