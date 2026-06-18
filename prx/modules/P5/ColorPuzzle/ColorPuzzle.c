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

#include "ColorPuzzle.h"

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

GMC_Color_Switch* gmc_switches = NULL;

GMC_Color_Switch* fld_gmc_get_light(int gmc_id, int gmc_group)
{
  GMC_Color_Switch* current = gmc_switches;

  while (current != NULL)
  {
    DEBUG_LOG("cur -> %x\ncnv -> %d\nid -> %d\ngroup -> %d\n", current, current->cnv_reshnd, current->gmc_id, current->gmc_group);
    if (gmc_id == current->gmc_id && gmc_group == current->gmc_group)
    {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

inline int FLD_GMC_LIGHT_ADD()
{
  GMC_Color_Switch* head = gmc_switches;
  GMC_Color_Switch* current = head;

  GMC_Color_Switch* new_switch = malloc(20);
  
  new_switch->cnv_reshnd = FLW_GetIntArg(0);
  new_switch->gmc_id = FLW_GetIntArg(1);
  new_switch->gmc_group = FLW_GetIntArg(2);
  new_switch->color_bitfield = FLW_GetIntArg(3);
  new_switch->next = NULL;

  if (head == NULL)
  {
    gmc_switches = new_switch;
    head = new_switch;
  }
  else
  {
    while (current != NULL)
    {
      if (current->cnv_reshnd == new_switch->cnv_reshnd || current->gmc_id == new_switch->gmc_id)
      {
        new_switch->next = current->next;
        free(current);
        current = new_switch;
        break;
      }
      else if (current->next == NULL)
      {
        current->next = new_switch;
        break;
      }

      current = current->next;
    }
  }

  return 1;
}

inline int FLD_GMC_LIGHT_GET_UID()
{
  int gmc_id = FLW_GetIntArg( 0 );
  int gmc_group = FLW_GetIntArg( 1 );

  GMC_Color_Switch* gmc_switch = fld_gmc_get_light(gmc_id, gmc_group);

  if (gmc_switch != NULL)
  {
    FLW_SetIntReturn(gmc_switch->cnv_reshnd);
  }
  else
  {
    FLW_SetIntReturn(-1);
  }

  return 1;
}

inline int FLD_GMC_LIGHT_CTRL()
{
  int gmc_id = FLW_GetIntArg(0);
  int gmc_group = FLW_GetIntArg(1);
  int color = FLW_GetIntArg(2);

  GMC_Color_Switch* light_switch = fld_gmc_get_light(gmc_id, gmc_group);

  if (light_switch != NULL)
  {
    FLW_SetIntReturn(light_switch->color_bitfield);
  }
  else
  {
    FLW_SetIntReturn(0);
  }

  return 1;
}

void FLD_GMC_LIGHT_FREE()
{
  GMC_Color_Switch* current = gmc_switches;

  while (current != NULL)
  {
    GMC_Color_Switch* tmp = current;
    current = current->next;
    free(tmp);
  }

  DEBUG_LOG("Freed GMC_LIGHT data");
  gmc_switches = NULL;

  return;
}

#endif