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

#include "modules/p5/p5.h"
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

int ModelGetMajorID(ResourceHandleStruct* modelResource)
{
  if (modelResource != 0)
    return modelResource->ModelIDs >> 0x14;
}

int ModelGetMinorID(ResourceHandleStruct* modelResource)
{
  if (modelResource != 0)
    return modelResource->ModelIDs & 0xfff;
}

int PCGetReshndAddr(ModelAnim* modelAnim)
{
	return modelAnim->PlayerModelResource;
}

int PCHasActionStatus(PlayerParams* playerParams, ulonglong actionStatus)
{
	if (playerParams == 0)
		return 0;

	return (playerParams->ActionStatus & actionStatus) != 0;
}

#endif