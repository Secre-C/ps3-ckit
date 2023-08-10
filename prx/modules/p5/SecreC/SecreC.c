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
#include "SecreC.h"

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

// You need to declare hooks with SHK_HOOK before you can use them.
SHK_HOOK( undefined8, FUN_004eaca4, int a1 );
SHK_HOOK( void, FUN_005528f8, ParallelWipe *a1 );
SHK_HOOK( u64, FUN_00244250, CmmStruct *a1, double a2 );
SHK_HOOK( undefined8, FUN_0023c070, undefined8 a1, u32 a2, int a3 );
SHK_HOOK( void, FUN_0049eb90, int a1, u16 a2, undefined4 a3, char a4 );
SHK_HOOK( void, FUN_0049ee38, int a1, char a2, u32 a3, char a4 );
SHK_HOOK( int, FUN_003e8ff8, int a1 );
SHK_HOOK( void, FUN_005a4584, int a1, int a2 );
SHK_HOOK( undefined8, FUN_004e392c, short a1 );
SHK_HOOK( u64, FUN_00548c8c, short a1 );
SHK_HOOK( u64, FUN_00397f4c, int a1 );
SHK_HOOK( void, FUN_0059bb98, int a1 );
SHK_HOOK( void, FUN_005a7098, int a1, int a2);
SHK_HOOK( void, FUN_00597740, int a1 );
SHK_HOOK( void, FUN_00260340, u32 a1, u32 a2 );
SHK_HOOK( u64, FUN_000503d0, int a1 );
SHK_HOOK( undefined8, FUN_005a6b78, a1, a2, a3 );
SHK_HOOK( void, FUN_005a5130, int a1 );
SHK_HOOK( int, FUN_0031ad2c, int a1 );
SHK_HOOK( u64, FUN_003366f0, u64 *a1, int a2 );
SHK_HOOK( s64, FUN_00936488, uint a1 );
SHK_HOOK( void, FUN_002d87cc, int *a1, int a2, undefined8 a3, int a4 );
SHK_HOOK( float, FUN_00310cc0, float *a1, double a2, double a3, double a4 );
SHK_HOOK( undefined8, FUN_00281d4c, undefined4 a1, uint a2, undefined8 a3, undefined8 a4, ulonglong a5 );
SHK_HOOK( void, CueSelectTrack, undefined8 a1, undefined8 a2, undefined8 a3);
SHK_HOOK( s64, GetProcedureByName, int *scriptInstance, char* procedureName );
SHK_HOOK( void, FreeDungeonVoiceAcb, int a1 );
SHK_HOOK( ulonglong, SetupPlayerVariables, longlong a1);
SHK_HOOK( void, SetPlayerFieldSpeeds, PlayerParams* playerParams);
SHK_HOOK( void, SetPlayerDungeonSpeeds, PlayerParams* playerParams);
SHK_HOOK( void, SetMorganaCarSpeeds, PlayerParams* playerParams);
SHK_HOOK( int, IsPlayerAllowedSprint, int a1 );
SHK_HOOK( longlong, FUN_00325e38, longlong a1, float *a2, double a3, double a4 );
SHK_HOOK( void, PlayerSnapToGround, PlayerParams* player );
SHK_HOOK( void, ShowFieldTaskPrompt, double a1, undefined8 a2, undefined8 sprite, ulonglong sprite_id, float *a5 );
SHK_HOOK( u64, FUN_0030ab40, HitTable *a1, HitTable* a2, undefined8 a3, uint a4, uint *a5, longlong a6 );
SHK_HOOK( void, Draw_Date, undefined8 a1, int* a2 );

// The start function of the PRX. This gets executed when the loader loads the PRX at boot.
// This means game data is not initialized yet! If you want to modify anything that is initialized after boot,
// hook a function that is called after initialisation.

uint random_color()
{
	// randomize color
	FrameTiming = randomIntBetween( 0, 360 * 4 );
	FrameTiming += 1;
	hsv c;
	//c.h = ((P5_SIN((FrameTiming/3.0)) + 1.0f) / 2.0f) * 360;
	c.h = ( FrameTiming % ( 360 * 4 ) ) / 4;
	c.s = 1.0;
	c.v = 1.0;

	rgb cc = hsv2rgb(c);
	cc.r *= 255; 
	cc.g *= 255; 
	cc.b *= 255;
	return ((int)cc.r << 24) | ((int)cc.g << 16) | ((int)cc.b << 8) | 0xff;
}

undefined8 InverseItemPurchaseLimit( int a1 )
{
	FUNC_LOG("Loading InverseItemPurchaseLimit\n");

	if 	( a1 == ( 0x1000 + 14 )
		 || a1	== ( 0x1000 + 15 )
		 || a1	== ( 0x1000 + 48 )
		 || a1	== ( 0x1000 + 49 )
		 || a1	== ( 0x1000 + 68 )
		 || a1	== ( 0x1000 + 69 )
		 || a1	== ( 0x1000 + 88 )
		 || a1	== ( 0x1000 + 89 )
		 || a1	== ( 0x1000 + 108 )
		 || a1	== ( 0x1000 + 109 )
		 || a1	== ( 0x1000 + 0x80 )
		 || a1	== ( 0x1000 + 129 )
		 || a1	== ( 0x1000 + 148 )
		 || a1	== ( 0x1000 + 149 )
		 || a1	== ( 0x1000 + 168 )
		 || a1	== ( 0x1000 + 169 )
		 || a1	== ( 0x1000 + 188 )
		 || a1	== ( 0x1000 + 189 ) )
	{
		return 99 - GET_ITEM_NUM( a1 ); //reverses item purchase cap to be the amount of items you have
	}
	return GET_ITEM_NUM( a1 );	
}

void SubtractCurrencyForPurchase( int a1, int a2 )
{
	FUNC_LOG("Loading SubtractCurrencyForPurchase\n");

	if (a1 == 72)
	{
		ActualSetCount( 90, a2 );
	}
	else if (a1 == 75 || a1 == 76)
	{
		ActualSetCount( 162, a2 );
	}
	else if (a1 == 85)
	{
		ActualSetCount( 8, a2 );
	}
	else
	{
		SetMoney(a2);
	}
	return;
}

int ReturnSpendableCurrency( int a1 )
{
	FUNC_LOG("Loading ReturnSpendableCurrency\n");

	if (a1 == 72)
	{
		return ActualGetCount( 90 );
	}
	else if (a1 == 75 || a1 == 76)
	{
		return ActualGetCount( 162 );
	}
	else if (a1 == 85)
	{
		return ActualGetCount( 8 );
	}
	else
	{
		return GetMoneyCount();
	}
}

undefined8 GetLmapBitFlag( int a1 )
{
	FUNC_LOG("Loading GetLmapBitFlag\n");

	if( a1 == 2704 ) // Kasumi
	{
		if ( GetBitflagState (3583) == 1 ) return 1;
		return GetBitflagState( 2694 );
	}
	else if( a1 == 2706 ) //Maruki
	{
		if ( GetBitflagState (3583) == 1 ) return 1;
		return GetBitflagState( 2695 );
	}
	else if( a1 == 2680 ) //Akechi
	{
		if ( GetBitflagState (3583) == 1 ) return 1;
		return GetBitflagState( 2680 );
	}
	else
	{
		return GetBitflagState( a1 );
	}
}

int SetSpritetoYenorPoints( int a1 )
{
	FUNC_LOG("Loading SetSpritetoYenorPoints\n");

	if (a1 == 72 || a1 == 70 || a1 == 85)
	{
		return 75;
	}
	else
	{
		return a1;
	}
}

undefined8 SelPortraitFromModelID(SelPrompt *a1)
{
	FUNC_LOG("Loading SelPortraitFromModelID\n");

	//pseudo function replacing the ones at 0x5a6c84 and 0x5a526c
	if (a1 < 0x9000)
	{
		return InverseItemPurchaseLimit( a1 );
	}	
	//end pseudo function
	undefined8 result = SHK_CALL_HOOK( FUN_004eaca4, a1 );
	//if ( GetBitflagState( 2815 ) == 1 && GetTotalDays() == 231 ) //If In-game day is 11/18 and flag 2815 is enabled
	//{
	//	a1->PortraitID = 5; //cutin_005_000.dds
	//}
	return result;
}

void WipeParallelHook( ParallelWipe *a1 ) // needs - [ be32, 0x552960, 0x60000000 ] #removes og metaverse wipe call
{
	FUNC_LOG("Loading WipeParallelHook\n");

	SHK_CALL_HOOK( FUN_005528f8, a1 );
	/*if (GetTotalDays() >= 275 )
	{
	a1->Wipe_Pac = open_file("field/panel/wipe/wipeParallelTwistPack.pac",1);
	}
	else
	{
	a1->Wipe_Pac = open_file("field/panel/wipe/wipeParallelPack.pac",1);
	} */
	return; 
}

u64 RankupCardHook( CmmStruct *a1, double a2 ) //changes Kasumi card to Sumire's if the date is past 1/10 or later
 {
	FUNC_LOG("Loading RankupCardHook\n");

	if (GetTotalDays() >= 284 && a1->Field52->cardId == 21 && GetBitflagState( 164 ) == 1)
	{
		a1->Field52->cardId = 23;
	}
	return SHK_CALL_HOOK( FUN_00244250, a1, a2 );
 }

undefined8 ConfRankupHook( undefined8 a1, u32 a2, int a3 ) //makes kasumi rankup trigger sumire rankup animation if the date is 1/10 or later
{
	FUNC_LOG("Loading ConfRankupHook\n");

	if ( a2 == 33 && GetTotalDays() >= 284 && GetBitflagState( 164 ) == 1)
	{
		//a2 = 36;
	}
	return SHK_CALL_HOOK( FUN_0023c070, a1, a2, a3 );
}

void CharaTexHook( int a1, u16 a2, undefined4 a3, char a4 ) // makes Kasumi CharaTex in confidant menu show Sumire past 1/10
{
	FUNC_LOG("Loading CharaTexHook\n");

	if ( a2 == 10 && GetTotalDays() >= 284 && GetBitflagState( 164 ) == 1)
	{
		//a2 = 32;
	}
	return SHK_CALL_HOOK( FUN_0049eb90, a1, a2, a3, a4 );
}

void CommuCardHook( int a1, char a2, u32 a3, char a4 ) // makes Kasumi CardTex in confidant menu show Sumire's past 1/10
{
	FUNC_LOG("Loading CommuCardHook\n");

	if ( a2 == 22 && GetTotalDays() >= 284 && GetBitflagState( 164 ) == 1)
	{
		//a2 = 24;
	}
	return SHK_CALL_HOOK( FUN_0049ee38, a1, a2, a3, a4 );
}

int FUN_003e8ff8Hook( int a1 ) // increase offset to pointer by 4 bytes when fldMajor == 5
{
	FUNC_LOG("Loading FUN_003e8ff8Hook\n");

	//pseudo function for Getting Money Values from counts at 0x5a8f4c
	if (a1 > -1 && a1 < 90)
	{
		return ReturnSpendableCurrency( a1 );
	}
	//end pseudo function
	int result = SHK_CALL_HOOK( FUN_003e8ff8, a1 );
	if (result != -1)
	{
		u32 *puVar1 = FUN_0031f35c();
    	u32 fldMajor = (u32)*(u16 *)(puVar1[0xd] + 0x144);
		if (fldMajor == 5)
		{
			result = 6;
		}
	}
	return result;
}

void CallShopBannerHook( int a1, ShopStruct *a2 )
{
	FUNC_LOG("Loading CallShopBannerHook\n");

	//pseudo function for Getting Money/Point Values at 0x5a6fd8
	if (a1 > -1 && a1 < 90)
	{		
		SubtractCurrencyForPurchase( a1, a2 );
		return;
	}
	//end psuedo function
	SHK_CALL_HOOK( FUN_005a4584, a1, a2 );
	int iVar4;
	switch (a2->ShopID){

		case 70:
		iVar4 = FUN_00967abc("facility/fcl_ps_title/h_name_HURUGI.dds", 1);
		*(int *)(a1 + 0x924) = iVar4;
		break;

		case 77:
		iVar4 = FUN_00967abc("facility/fcl_ps_title/h_name_POWERSTONE.dds", 1);
		*(int *)(a1 + 0x924) = iVar4;
		break;

		case 81:
		iVar4 = FUN_00967abc("facility/fcl_ps_title/h_name_STATIONERY.dds", 1);
		*(int *)(a1 + 0x924) = iVar4;
		break;

		case 82:
		iVar4 = FUN_00967abc("facility/fcl_ps_title/h_name_FRIEDFOOD.dds", 1);
		*(int *)(a1 + 0x924) = iVar4;
		break;

		case 87:
		iVar4 = FUN_00967abc("facility/fcl_ps_title/h_name_FOOD.dds", 1);
		*(int *)(a1 + 0x924) = iVar4;
		break;

		case 88:
		iVar4 = FUN_00967abc("facility/fcl_ps_title/h_name_CHINESE.dds", 1);
		*(int *)(a1 + 0x924) = iVar4;
		break;
	}
	
	return;
}

undefined8 BuildGroupChatIconListHook( short a1 )
{	
	FUNC_LOG("Loading BuildGroupChatIconListHook\n");

	//pseudo function replacing GetBitflagState at 0xaf81c for Lmap Confidant Indicators
	if ( a1 >= 2671 ) 
	{
		return GetLmapBitFlag( a1 );
	}
	//pseudo function end
	
	undefined8 result = SHK_CALL_HOOK( FUN_004e392c, a1 );
	if (a1 == 10 && GetBitflagState(1175) == 1 ) // Check for flag 1175 before adding Kasumi to the PT group chat
	{
		result = 1; //add Kasumi to the Phantom Thieves Group chat
	}
	return result;
}

u64 GetConfidantListEntryHook( short cmmFormatEntry )
{
	FUNC_LOG("Loading GetConfidantListEntryHook\n");

	u8 confCount = GetActiveConfidantAmount(35); //returns how many confidants are active
	DEBUG_LOG("%d Active Confidants\n", confCount);
	u64 result = SHK_CALL_HOOK( FUN_00548c8c, cmmFormatEntry );
	
	if (confCount > 22)
	{
		if ((Button_Hold->R2) && ( cmmFormatEntry == 21)) //Before Adding Sae to the Confidant list Check if all Confidants are active, and if R2 is being held down
		{
			return 0; //remove Sae from the Confidant list
		}
		else if ((Button_Hold->R2) == 0 && cmmFormatEntry == 24) //Before Adding Maruki to the Confidant list Check if all Confidants are active, and if R2 is not being held down
		{
			return 0; //remove Maruki from the confidant list
		}
	}
	
	return result;
}

u64 LmapIdtoPointerList( int a1 )
{
	FUNC_LOG("Loading LmapIdtoPointerList\n");
	int result = SHK_CALL_HOOK( FUN_00397f4c, a1 );
	if ( a1 == 7 ) //Lmap Id 7 = Kichijoji
	{
		return 7; //pointer to field Id list at 0xd010b4 + 7 * 4
	}
	return result; // :hee_shake:
}

u64 FUN_000503d0Hook( int a1 )
{
	FUNC_LOG("Loading FUN_000503d0Hook\n");
	//pseudo function for 0x5a2d68
	if (a1 < 100)
	{
		return SetSpritetoYenorPoints(a1);
	}
	//end pseudo function
	u64 result = SHK_CALL_HOOK( FUN_000503d0, a1 );
	if (CONFIG_ENABLED(announceWeekday))
	{
		if (*(undefined4 *)(a1 + 0x3314) == 2) 
			hasJokerSaidWeekday = false;

		if (*(undefined4 *)(a1 + 0x3314) == 3 && !hasJokerSaidWeekday)
		{
			if ( GetBitflagState( 4182 ) == 1 && ( GetTotalDays() < 233 || GetTotalDays() > 237 ))
			{
				PlayFromSinglewordACB( 2, 51 );
			}
			else
			{
				int Variation = randomIntBetween( 0, 1 ); //Randomize between two voice line variations
				int DayOfWeek = GetTotalDays() % 7;
				switch(DayOfWeek){
				
				case 0: //Friday
				DayOfWeek = 4;
				break;
				
				case 1: //Saturday
				DayOfWeek = 5;
				break;

				case 2: //Sunday
				DayOfWeek = 6;
				break;

				case 3: //Monday
				DayOfWeek = 0;
				break;

				case 4: //Tuesday
				DayOfWeek = 1;
				break;

				case 5: //Wednesday
				DayOfWeek = 2;
				break;

				case 6: //Thursday
				DayOfWeek = 3;
				break;
				
				}
				int DayCue = 120 + Variation + (DayOfWeek * 2);
				PlayFromSinglewordACB( 2, DayCue );
			}
			hasJokerSaidWeekday = true; //Prevents the voice clip from playing 84759207594560879 times
		}
	}
	return result;
}

void ShopBannerColorHook( ShopStruct *a1 )
{
	FUNC_LOG("Loading ShopBannerColorHook\n");
	if ( CONFIG_ENABLED( enableRandomShopBannerColors ) ) //DC Copypasta :hee_cat:
  	{
	  a1->BannerColor = random_color();
    }

	if (a1->ShopID == 70)
	{
		a1->BannerColor = 0x20dff8ff;
	}
	SHK_CALL_HOOK( FUN_0059bb98, a1 );
}

void FUN_005a7098Hook( ShopStruct *a1, int a2 )
{
	FUNC_LOG("Loading FUN_005a7098Hook\n");
	if (a1->ShopID == 70)
	{
		a2 *= -1; //reverses the cost of items in shop 70
	}
	SHK_CALL_HOOK( FUN_005a7098, a1, a2 );
}

void FUN_00597740Hook( ShopStruct *a1 )
{
	FUNC_LOG("Loading FUN_00597740Hook\n");
	if (a1->ShopID == 70)
	{
		a1->PurchasePrice *= -1; //reverses the cost of items in shop 70
	}
	SHK_CALL_HOOK( FUN_00597740, a1 );
}

void SET_ITEM_NUM_Hook( u32 a1, u32 a2 )
{
	FUNC_LOG("Loading SET_ITEM_NUM_Hook\n");
	if (a1 > 0xa000) //runs when a1 is an address, making it outside the normal item range
	{
		char itemPosition = *(char *)(a1 + 0xf); //commence ghidra copypasta
    	s64 lVar9 = (s64)
            *(short *)(a1 + ((int)itemPosition + (int)*(short *)(a1 + 0x7f8)) * 2 + 0x84);
    	int iVar11 = a1 + (int)(lVar9 << 5) + (int)(lVar9 << 3);
		u16 purchaseQuantity = *(u16 *)(a1 + 0x18);
      	u16 itemID = *(u16 *)(iVar11 + 0x322);
      	s8 itemsPerUnit = *(s8 *)(iVar11 + 0x324);
		u16 itemPCInventory = GET_ITEM_NUM((u32)itemID);
		if (*(short *)(a1 + 0xc2) == 70)
		{
        	SET_ITEM_NUM((u32)itemID,itemPCInventory - ((u32)itemsPerUnit * (u32)purchaseQuantity & 0xff)); //reverses the amount of items you acquire when purchasing an item from shop 70
		}
		else
		{
			SET_ITEM_NUM((u32)itemID,itemPCInventory + ((u32)itemsPerUnit * (u32)purchaseQuantity & 0xff));
		}
		return;
	}
	
	const char* const itemCategoryStrings[] = {"Melee", "Armor", "Accessory", "Consumable", "KeyItem", "Material", "SkillCard", "Outfit", "RangedWeapon"};

	short itemId = a1;
	ItemCategoryID* item;
	item = &itemId;

	DEBUG_LOG("%s %d Total set to %d\n", itemCategoryStrings[item->Item_Category], item->Item_Id, a2);
	//printf("%d %d Total set to %d\n", itemType, (a1 - (itemType * 0x1000), a2));
	SHK_CALL_HOOK( FUN_00260340, a1, a2 );
}

undefined8 FUN_005a6b78Hook( ShopStruct *a1, int a2, int a3 )
{
	FUNC_LOG("Loading FUN_005a6b78Hook\n");
	if (a1->ShopID == 70)
	{
		a1->SpendableMoney = 9999999; //Make the game think your money is maxed out when calculating how many items you can buy
	}
	SHK_CALL_HOOK( FUN_005a6b78, a1, a2, a3 );
}

void FUN_005a5130Hook( ShopStruct *a1 )
{
	FUNC_LOG("Loading FUN_005a5130Hook\n");
	if (a1->ShopID == 70)
	{
		a1->SpendableMoney = 9999999; //Make the game think your money is maxed out when calculating how many items you can buy
	}
	SHK_CALL_HOOK( FUN_005a5130, a1 );
}

int FUN_0031ad2cHook( int a1 )
{
	FUNC_LOG("Loading FUN_0031ad2cHook\n");
	int result = SHK_CALL_HOOK( FUN_0031ad2c, a1 );
	if (isTakingWillSeed == 1)
	{
		return -1; //prevent party members from joining during the will seed get animation
	}
	else
	{
		return result;
	}
}

u64 *FUN_003366f0Hook( u64 *a1, int a2 )
{
	FUNC_LOG("Loading FUN_003366f0Hook\n");
	if (a2 == 51 && isTakingWillSeed == 1)
	{
		a2 = 52; //model/character/0001/field/af0001_052.GAP
	}
	SHK_CALL_HOOK( FUN_003366f0, a1, a2 );
}

s64 FUN_00936488Hook( uint a1 )
{
	FUNC_LOG("Loading FUN_00936488Hook\n");
	char *eplString = a1;

	if (strcmp( eplString, "field/effect/oneshot/fe_box_rare.EPL") == 0 && isTakingWillSeed == 1)
	{
		eplString = "field/effect/oneshot/fe_box_seed.EPL"; //dummy epl
	}

	return SHK_CALL_HOOK( FUN_00936488, eplString );
}

void FUN_002d87ccHook( int *a1, int a2, undefined8 a3, int a4 )
{
	FUNC_LOG("Loading FUN_002d87ccHook\n");
	if ( a3 == 1108 && isTakingWillSeed == 1 )
	{
		return; //skip chest opening sounds
	}
	SHK_CALL_HOOK( FUN_002d87cc, a1, a2, a3, a4 );
}

float FUN_00310cc0Hook( float *a1, double a2, double a3, double a4 )
{
	FUNC_LOG("Loading FUN_00310cc0Hook\n");
	if ( a2 == 16.0 && a4 == 112.0 && isTakingWillSeed == 1 )
	{
		a2 = -5.0; //X offset
		a4 = 105.0; //Z offset
	}
	return SHK_CALL_HOOK( FUN_00310cc0, a1, a2, a3, a4 );
}

undefined8 FadeoutHook( undefined4 a1, uint a2, undefined8 a3, undefined8 a4, ulonglong a5 )
{
	//printf("Fadeout -> %d\n", a1);
	//if ( a1 == 4 || a1 == 3 ) a1 = 18;
	return SHK_CALL_HOOK( FUN_00281d4c, a1, a2, a3, a4, a5 );
}

void CueSelectTrackHook( soundManagerStruct *a1, char* a2, char* a3 )
{
	FUNC_LOG("Loading CueSelectTrackHook\n");
	SHK_CALL_HOOK( CueSelectTrack, a1, a2, a3 );

	short* DoorActionTrackAdr = NULL;
	
	//Get address of DoorActionTrack from r4
	asm ("ori %1, r4, 0x0"
		: "=r" (DoorActionTrackAdr)
		: "r" (0)
		: "cc");

	short DoorActionTrack = *(DoorActionTrackAdr + 1);

	DEBUG_LOG("cue_filter -> %s\n", a2);
	
	if (strcmp(a2, "Selector_door") != 0)
		return;

	undefined8 DoorSoundInfo;
	
	asm ("ori %1, r27, 0x0"
		: "=r" (DoorSoundInfo)
		: "r" (0)
		: "cc");

	int* cueID = DoorSoundInfo + 0x20;

	DEBUG_LOG("DoorSoundMode -> %d\n", DoorSoundMode);

	if (DoorSoundMode & 1 == 1)
	{
		DEBUG_LOG("Changing Cue %d to Cue %d\n", *cueID, (*cueID * 10) + DoorActionTrack);
		*cueID = (*cueID * 10) + DoorActionTrack;
	}

	if ((DoorSoundMode & 2) == 2 && (DoorSoundMode & 0x10) == 0)
	{
		DEBUG_LOG("Storing Door Sound Struct info\n");

		Door_field4_0x4 = a1->field4_0x4;
		Door_Channel = a1->Channel;
		DoorStructAdr = a1;

		DEBUG_LOG("Setting Door Channel to SingleWord Channel\n");

		a1->field4_0x4 = 2;
		a1->Channel = 2;
		
		DEBUG_LOG("Finished Setting Door Channel to SingleWord Channel\n");
		DoorSoundMode = DoorSoundMode | 0x10;
	}

	DEBUG_LOG("%s -> %d\n", a3, DoorActionTrack);
	DEBUG_LOG("cue -> %d\n", *cueID);
}

s64 GetProcedureByNameHook(int* scriptInstance, char* procedureName)
{
	FUNC_LOG("Loading GetProcedureByNameHook\n");

	if (CONFIG_ENABLED(royalScheduler))
	{
		char *sdlMonth = GetSubstring(0, 5, procedureName);

		bool thirdSem = GetBitflagState( 164 );
		bool trueEnd = GetBitflagState( 165 );
		
		if (thirdSem)
		{
			if( strcmp(sdlMonth, "sdl12") == 0)
			{
				sprintf(procedureName, "%s%s", procedureName, "_S3");
			}
			else if( strcmp(sdlMonth, "sdl01") == 0)
			{
				sprintf(procedureName, "%s%s", procedureName, "_S3");
			}
			else if( strcmp(sdlMonth, "sdl01") == 0)
			{
				sprintf(procedureName, "%s%s", procedureName, "_S3");
			}
			else if( strcmp(sdlMonth, "sdl02") == 0 && trueEnd)
			{
				sprintf(procedureName, "%s%s", procedureName, "_RE");
			}
			else if( strcmp(sdlMonth, "sdl02") == 0)
			{
				sprintf(procedureName, "%s%s", procedureName, "_S3");
			}
			else if( strcmp(sdlMonth, "sdl03") == 0 && trueEnd)
			{
				sprintf(procedureName, "%s%s", procedureName, "_RE");
			}
			else if( strcmp(sdlMonth, "sdl03") == 0)
			{
				sprintf(procedureName, "%s%s", procedureName, "_S3");
			}
		}	
	}

	return SHK_CALL_HOOK( GetProcedureByName, scriptInstance, procedureName );
}

undefined8 FreeDungeonVoiceAcbHook(int a1)
{
	FreeAcb(0x70);
	DEBUG_LOG("Freeing dungeon_se.acb\n");
	SHK_CALL_HOOK( FreeDungeonVoiceAcb, a1 );
}

void dvd_logo()
{
	if (!enable_dvd_logo)
		return;

	bool isSwitchX = false;
	bool isSwitchY = false;
	float image_x = 223;
	float image_y = 97;
	float bounce_x = 1280 - image_x;
	float bounce_y = 720 - image_y;
	float default_x_delta = 3;
	float default_y_delta = 3;
	static float x_delta =  3;
	static float y_delta =  3;
	static float x = 0;
	static float y = 0;
	static bool down = true;
	static bool right = true;
	static int color = 0xffffffff;

  	int var1;
	sprite* new_sprite = spd_open_and_process("font/dvd.spd");
	//var1 = SPRITE_00116b78();
	//SPRITE_00947894( 0x45, 4, 1, 0, 5 );
  	//var1 = SPRITE_00116b78();
  	//sprite_set_color_bounds(var1, 3, 0);
  	//var1 = SPRITE_00116b78();
  	//sprite_set_draw_method(var1, 0, 3);
  	spd_sprite_create(new_sprite, 1);
	sprite_set_color(new_sprite, color);
  	sprite_set_screen_position( x, y, new_sprite );
  	SPRITE_001c5254(new_sprite, 0);
  	sprite_toggle_visibility(new_sprite);

	if (right)
		x += x_delta;
	else
		x -= x_delta;

	if (down)
		y += y_delta;
	else
		y -= y_delta;

	if (x >= bounce_x || x <= 0)
	{
		if (x >= bounce_x)
			x = bounce_x;
		else
			x = 0;

		right = !right;
		x_delta = default_x_delta * randomFloatBetween(1, 1.5);
		color = random_color();

		isSwitchX = true;
	}
	
	if (y >= bounce_y || y <= 0)
	{
		if (y >= bounce_y)
			y = bounce_y;
		else
			y = 0;

		down = !down;
		y_delta = default_y_delta * randomFloatBetween(1, 1.1);
		color = random_color();

		isSwitchY = true;
	}

	if (isSwitchX && isSwitchY)
		PlayFromSinglewordACB(2, 52400);
}

int IsPlayerAllowedSprintHook( int a1 )
{
	FUNC_LOG("Loading IsPlayerAllowedSprintHook\n");
	
	int result = SHK_CALL_HOOK( IsPlayerAllowedSprint, a1 );

	if (result == 1 || Button_Hold->R2 == 0 || playerParams->ControlStatus.isColliding || !playerParams->ControlStatus.isMoving)
		return result;

	ModelAnim *pcAnimData = &playerParams->PlayerAnimStruct;

	if (!IsInDungeon(*(short *)(a1 + 0x144)))
	{
		if((int)(playerParams->RunSpeed) != 20 || (int)(playerParams->WalkSpeed) != 12)
			return result;
		else
		{
			pcAnimData->field04 = 2;
			pcAnimData->field06 = 1;
			pcAnimData->AnimIndex = 5;
			pcAnimData->InterpTime = 0.1666667;
			pcAnimData->IsAnimLoop = 1;
			pcAnimData->AnimSpeed = 1.3;

			playerParams->ActionStatus = Sprint;

			return 1;
		}
	}
	else
	{
		ulonglong uVar3 = *(short *)((int)FUN_0001ee3c(playerParams->PlayerModelResource) + 10);
		if (uVar3 == 351 || uVar3 == 352 || uVar3 == 40) //disable sprinting before you unlock it, as well as during the buffet keyfree
			return result;

		int modelMajor = ModelGetMajorID(pcAnimData->PlayerModelResource);
		int isMouse = btlUnitHasAilment( GetBtlPlayerUnitFromID(1), 0x400000 );
		
		if((modelMajor == 100 || modelMajor == 1) && !playerParams->MovementStatus.isCrawling && !isMouse)
		{
			if (modelMajor == 1)
			{
				pcAnimData->AnimSpeed = 1.3;
			} 
			
			pcAnimData->field04 = 2;
			pcAnimData->field06 = 1;
			pcAnimData->AnimIndex = 5;
			pcAnimData->InterpTime = 0.1666667;
			pcAnimData->IsAnimLoop = 1;

			playerParams->ActionStatus = Sprint;

			return 1;
		}
		else
			return result;
	}
}

ulonglong SetupPlayerVariablesHook( longlong a1 )
{
	FUNC_LOG("Loading SetupPlayerVariablesHook\n");

	playerParams = (PlayerParams*)(a1 + 0x19b0);
	DEBUG_LOG("FMWK -> 0x%x\n", a1);
	DEBUG_LOG("playerParams -> 0x%x\n", playerParams);

	SHK_CALL_HOOK( SetupPlayerVariables, a1 );
}

void SetPlayerFieldSpeedsHook( PlayerParams* playerParams )
{
	FUNC_LOG("Loading SetPlayerFieldSpeedsHook\n");
	SHK_CALL_HOOK( SetPlayerFieldSpeeds, playerParams );

	playerParams->SprintSpeed = 27.6;

	return;
}

void SetPlayerDungeonSpeedsHook( PlayerParams* playerParams )
{
	playerParams->RunSpeed = 25.2;
  	playerParams->WalkSpeed = 12.6;
  	playerParams->MouseSpeed = 36.75;
  	playerParams->SprintSpeed = 36.75;
  	return;
}

void SetMorganaCarSpeedsHook( PlayerParams* playerParams )
{
	FUNC_LOG("Loading SetMorganaCarSpeedsHook\n");
	SHK_CALL_HOOK(SetMorganaCarSpeeds, playerParams );

	playerParams->SprintSpeed = 80.0;

	return;
}

void PlayerSnapToGroundHook( PlayerParams* player )
{
	if (isAdjustingGround)
	{
		float floorHeight;

		asm ("fmr %1, f0"
		: "=r" (floorHeight)
		: "r" (0)
		: "cc");

		printf("floor -> %f\n", floorHeight);
	}

	SHK_CALL_HOOK(PlayerSnapToGround, player);
}

longlong FUN_00325e38Hook( long a1, float *a2, double a3, double a4 )
{
	if (isAdjustingGround)
	{
		printf("a2 -> %f\n", *(float*)(a2));
	}
	return SHK_CALL_HOOK( FUN_00325e38, a1, a2, a3, a4 );
}

void ShowFieldTaskPromptHook( double a1, undefined8 sprite_id, undefined8 sprite, ulonglong a4, float *a5 )
{
	if (sprite_id == 8 && isHitGrapple)
	{
		sprite_id = 11;
	}

	SHK_CALL_HOOK( ShowFieldTaskPrompt, a1, sprite_id, sprite, a4, a5 );
}

u64 FUN_0030ab40Hook( HitTable *a1, HitTable* a2, undefined8 a3, uint a4, uint *a5, longlong a6 )
{
	u64 result = SHK_CALL_HOOK( FUN_0030ab40, a1, a2, a3, a4, a5, a6);
	
	HitTable* htb_trigger = GetCurrentHtbBlock(a5, a6, a3, a4, 100.0);

	if (htb_trigger)
	{
		isHitGrapple = (htb_trigger->trigger_type == 4 || htb_trigger->trigger_type == 5);
	}
	else
		isHitGrapple = 0;

	return result;
}

bool checkThirdSem()
{
	int totalDays = GetTotalDays();
	 
	if (totalDays >= 275 && GetBitflagState( 164 )) //if 1/1 (or later) and third semester
	{
		if( totalDays > 308 && GetBitflagState( 165 ) ) //if past 2/3 and true ending
		{
			return false;
		}
		return true;
	}
	
	return false;
}

void newDrawDate( undefined a1, date_ui* dateUI )
{
	float fVar1;
  	sprite *sprites;
  	ulonglong uVar2;
  	int spritePositionSetOffset;
  	int b;
  	byte bVar5;
  	undefined8 uVar6;
  	undefined8 uVar7;
  	int g;
  	int r;
  	uint sprite_id;
  	double dVar8;
  	double dVar9;
  	double y;
  	double dVar10;
	double monthNumberScale;
  	double dVar11;
  	double x;
  	double dVar12;
  	uint a;
	uint weekdayColor;
  	int currentMonth;
  	int currentDay;
  	longlong timeOfDay = (longlong)dateUI->timeOfDay;
	int* timeOfDay_sprites;
	timeOfDay_sprites = 0x0cff304;
  	int weekday = GetWeekday((int)dateUI->total_days);
  	int isNextDayHoliday = check_next_day_public_holiday((int)dateUI->total_days);
  	GetDayMonth((int)dateUI->total_days,&currentMonth,&currentDay);

						/* set sprite offset for double digit days */
  	fVar1 = 66.0;
  	if (currentDay < 10) {
  	  fVar1 = 86.0;
  	}
	
  	dVar10 = (double)fVar1;

  	dVar12 = 255.0;
  	dVar11 = 0.0;
  	a = (uint)(longlong)(dateUI->opacity_maybe * 255.0);
  	dVar8 = dVar11;
	
  	if (currentDay < 10) {
  	  dVar11 = -10.0;
  	}
	
  	                  /* display the square background for weather icons */
	draw_weather_square_bg_sprite(dateUI, dVar11, 0xc2); //a | 0xffffff00

  	                  /* Display Month whiteshadow */
  	x = 61.0;
  	y = 45.0;
  	dVar9 = 59.0;
  	dVar11 = (double)(dateUI->field31_0x2c * dateUI->scale_multiplier);
	draw_month_white_backdrop_sprite(dateUI, currentMonth, x, y, dVar10, dVar9, 0xc2, dVar11); //-1

  	                  /* Display Day Number WhiteShadow */
  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
  	draw_date_day_whiteshadow(dateUI,0xc2); //a | 0xffffff00

  	                  /* Display Weekday Dropshadow */
  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
  	spritePositionSetOffset = (int)((longlong)weekday << 3);
  	dVar11 = (double)(dateUI->field143_0xcc * dateUI->scale_multiplier);
	draw_weekday_dropshadow_sprite(dateUI, weekday, spritePositionSetOffset, 0xc2, dVar11); //a | 0xffffff00

  	uVar6 = 0xffffffff;
	draw_weather_icon_sprite(dateUI,uVar6); //Weather Icon
  	draw_date_month_black_shadow(dVar10,dVar9,dateUI,uVar6,uVar7,0xffffffff); //month black drop
  	draw_date_day_black_shadow(dateUI,0xffffffff); //day black drop
  	FUN_00056918(dateUI,0xffffffff);
  	draw_weekday_whiteshadow(dateUI,0xffffffff); //weekday white backdrop

  	//uVar7 = 4;                                                      
  	//uVar2 = SPRITE_00116b78();
  	//sprite_set_draw_method((int)uVar2,0,uVar7);

	draw_date_month_sprite(dateUI, currentMonth, x, y, dVar10, 0xff);
	
  	                  /* Display Day Number Sprite */
  	draw_date_day_sprite(dateUI,0xff);
	
	draw_weekday_sprite(dateUI, weekday, spritePositionSetOffset, 0xff, dVar11, 0x51);

  	//uVar7 = 3;
	//uVar2 = SPRITE_00116b78();
  	//sprite_set_draw_method((int)uVar2,0,uVar7);
	
  	                  /* Display Month Number Sprite */
	//draw_date_month_sprite(dateUI, currentMonth, x, y, dVar10, 0xc2);
	
  	                  /* Display Day Number Sprite */
  	//draw_date_day_sprite(dateUI,0xc2);


  	                  /* Display Weekday Sprite */

  	                  /* Determine usage of red weekday sprite color */
	if ((isNextDayHoliday == 0) && weekday != 0) 
	{
		if (weekday == 6) 
	  	{
	  		weekdayColor = 0x00fff000;
	  	}
	  	else 
	  	{
	  		weekdayColor = 0xffffff00;
	  	}
	}
	else 
	{	
		weekdayColor = 0xff000000;
	}

	uint weekdayBackdrop = 0xc2;

	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
	weekdayColor = weekdayColor | a;
	dVar10 = (double)(dateUI->field143_0xcc * dateUI->scale_multiplier);
	spritePositionSetOffset = (int)((longlong)weekday << 3);
	draw_weekday_sprite(dateUI, weekday, spritePositionSetOffset, weekdayBackdrop, dVar10, 0x51);
	draw_weekday_sprite(dateUI, weekday, spritePositionSetOffset, weekdayColor, dVar10, 0x11f);

	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
	if (dateUI->timeOfDay == '\x06') {
	  timeOfDay = 5;
	}

	spritePositionSetOffset = (int)(timeOfDay << 3);
	sprite_id = *(uint *)((int)timeOfDay_sprites + (int)(timeOfDay << 2));
	dVar11 = (double)*(float *)(0x0cfeb40 + spritePositionSetOffset);
	dVar10 = (double)*(float *)(0x0cfeb3c + spritePositionSetOffset);
	bVar5 = FUN_00048ec4((longlong)dateUI->total_days);

	if ((bVar5 != 0) && ((int)timeOfDay == 3)) {
  	  dVar10 = (double)*(float *)0x0cfeb74;
  	  sprite_id = 0x5a; //90
  	  dVar11 = (double)*(float *)0x0cfeb78;
	}

	                  /* Display Time of Day Sprite */
	float x_adj;
	float y_adj;
	get_tod_sprite_adjust(sprite_id, &x_adj, &y_adj);

	draw_time_of_day_sprite(dateUI, sprite_id, dVar10, dVar11, dVar8, 0xc2);
	draw_time_of_day_sprite(dateUI, sprite_id + 37, dVar10 - x_adj, dVar11 - y_adj, dVar8, 0xffffffff);

	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
	//draw_weather_sprite(dateUI,a | 0xffffff00);
  	return;
}

void Draw_DateHook(undefined8 a1, date_ui* dateUI)
{
	dvd_logo();
	//SHK_CALL_HOOK( Draw_Date, a1, dateUI );

	if (checkThirdSem() || GetBitflagState(8487))
	{
		newDrawDate(a1, dateUI);
		return;
	}

	float fVar1;
  	sprite *sprites;
  	ulonglong uVar2;
  	int spritePositionSetOffset;
  	int b;
  	byte bVar5;
  	undefined8 uVar6;
  	undefined8 uVar7;
  	int g;
  	int r;
  	uint sprite_id;
  	double dVar8;
  	double dVar9;
  	double y;
  	double dVar10;
	double monthNumberScale;
  	double dVar11;
  	double x;
  	double dVar12;
  	uint a;
	uint weekdayColor;
  	int currentMonth;
  	int currentDay;
  	longlong timeOfDay = (longlong)dateUI->timeOfDay;
	int* timeOfDay_sprites;
	timeOfDay_sprites = 0x0cff304;
  	int weekday = GetWeekday((int)dateUI->total_days);
  	int isNextDayHoliday = check_next_day_public_holiday((int)dateUI->total_days);
  	GetDayMonth((int)dateUI->total_days,&currentMonth,&currentDay);

						/* set sprite offset for double digit days */
  	fVar1 = 66.0;
  	if (currentDay < 10) {
  	  fVar1 = 86.0;
  	}

  	dVar10 = (double)fVar1;
						/* Some sort of sprite mode setup */
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,1,0);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,3,0);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,9,1);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,4,0);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,0x20,0xf);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,5,1);
  	uVar2 = SPRITE_00116b78();
  	itfCalcMsgMngFunc5(uVar2,0);
  	uVar2 = SPRITE_00116b78();
  	SPRITE_0094774c(uVar2,1);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_draw_method((int)uVar2,0,0);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,0x20,0x8);

  	uVar2 = SPRITE_00116b78();
  	SPRITE_00947894((int)uVar2,0,1,1,0);

	date_set_transparency_color(dateUI, 0xffffff00);

  	uVar2 = SPRITE_00116b78();
  	sprite_set_draw_method((int)uVar2,0,3);
  	uVar2 = SPRITE_00116b78();
  	SPRITE_00947894((int)uVar2,4,5,1,1);
  	dVar12 = 255.0;
  	dVar11 = 0.0;
  	a = (uint)(longlong)(dateUI->opacity_maybe * 255.0);
  	dVar8 = dVar11;
	
  	if (currentDay < 10) {
  	  dVar11 = -10.0;
  	}
	
  	                  /* display the square background for weather icons */
	draw_weather_square_bg_sprite(dateUI, dVar11, a | 0xffffff00);

  	                  /* Display Month whiteshadow */
  	x = 61.0;
  	y = 45.0;
  	dVar9 = 59.0;
  	dVar11 = (double)(dateUI->field31_0x2c * dateUI->scale_multiplier);
	draw_month_white_backdrop_sprite(dateUI, currentMonth, x, y, dVar10, dVar9, -1, dVar11);

  	                  /* Display Day Number WhiteShadow */
  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
  	draw_date_day_whiteshadow(dateUI,a | 0xffffff00);

  	                  /* Display Weekday Dropshadow */
  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
  	spritePositionSetOffset = (int)((longlong)weekday << 3);
  	dVar11 = (double)(dateUI->field143_0xcc * dateUI->scale_multiplier);
	draw_weekday_dropshadow_sprite(dateUI, weekday, spritePositionSetOffset, a | 0xffffff00, dVar11);

  	                  /* Make White backdrop under black drop translucent */

						/* Set erase draw type */
	uVar2 = SPRITE_00116b78();
  	uVar7 = 4;
  	sprite_set_draw_method((int)uVar2,0,uVar7);
  	uVar6 = 0xffffffff;

	draw_weather_icon_sprite(dateUI,uVar6); //Weather Icon
  	draw_date_month_black_shadow(dVar10,dVar9,dateUI,uVar6,uVar7,0xff); //month black drop
  	draw_date_day_black_shadow(dateUI,0xff); //day black drop
  	FUN_00056918(dateUI,0xff);
  	draw_weekday_whiteshadow(dateUI,0xff); //weekday white backdrop
  	
  	uVar2 = SPRITE_00116b78();
  	sprite_set_draw_method((int)uVar2,0,3);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,0x20,0xf);
  	uVar2 = SPRITE_00116b78();
  	SPRITE_00947894((int)uVar2,8,9,0,1);
  	date_set_transparency_color(dateUI, 0xffffff00); //affects black backdrop
  	uVar2 = SPRITE_00116b78();
  	sprite_set_draw_method((int)uVar2,0,0);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,0x20,0x8);
  	uVar2 = SPRITE_00116b78();
  	SPRITE_00947894((int)uVar2,0,1,1,0);
  	date_set_transparency_color(dateUI, 0xffffff00);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_draw_method((int)uVar2,0,3);
  	uVar2 = SPRITE_00116b78();
  	uVar6 = 5;
  	SPRITE_00947894((int)uVar2,4,uVar6,1,1);

					/* draw the actual black drops */
  	dVar11 = 194.0;
  	uVar2 = (longlong)(dateUI->opacity_maybe * dVar11) & 0xffffffffU | 0xffffff00; //0xffffffc2

  	draw_weather_icon_sprite(dateUI,(int)uVar2);

  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar11);
  	draw_date_month_black_shadow(dVar10,dVar9,dateUI,uVar2,uVar6,a);

  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar11);
  	draw_date_day_black_shadow(dateUI,a);

  	FUN_00056918(dateUI,(longlong)((double)dateUI->opacity_maybe * dVar11) & 0xffffffff);

  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar11);
  	draw_weekday_whiteshadow(dateUI,a);
	
  	uVar2 = SPRITE_00116b78();
  	sprite_set_draw_method((int)uVar2,0,3);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_color_bounds((int)uVar2,0x20,0xf);
  	uVar2 = SPRITE_00116b78();
  	SPRITE_00947894((int)uVar2,8,9,0,1);
  	date_set_transparency_color(dateUI, 0x0);
  	uVar2 = SPRITE_00116b78();
  	sprite_set_draw_method((int)uVar2,0,0);
  	uVar2 = SPRITE_00116b78();
  	SPRITE_00947894((int)uVar2,4,5,4,5);

	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12) | 0xffffff00;

  	                  /* Display Month Number Sprite */
	draw_date_month_sprite(dateUI, currentMonth, x, y, dVar10, a);
	
  	                  /* Display Day Number Sprite */
  	draw_date_day_sprite(dateUI,a);


  	                  /* Display Weekday Sprite */

  	                  /* Determine usage of red weekday sprite color */
  	if ((isNextDayHoliday == 0) && weekday != 0) 
	{
  		if (weekday == 6) 
	  	{
	  		weekdayColor = 0x00fff000;
  	  	}
  	  	else 
	  	{
	  		weekdayColor = 0xffffff00;
  	  	}
  	}
  	else 
	{	
		weekdayColor = 0xff000000;
  	}
	
  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
	weekdayColor = weekdayColor | a;
  	dVar10 = (double)(dateUI->field143_0xcc * dateUI->scale_multiplier);
  	spritePositionSetOffset = (int)((longlong)weekday << 3);
	draw_weekday_sprite(dateUI, weekday, spritePositionSetOffset, weekdayColor, dVar10, 0x51);

  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
  	if (dateUI->timeOfDay == '\x06') {
  	  timeOfDay = 5;
  	}

  	spritePositionSetOffset = (int)(timeOfDay << 3);
  	sprite_id = *(uint *)((int)timeOfDay_sprites + (int)(timeOfDay << 2));
  	dVar11 = (double)*(float *)(0x0cfeb40 + spritePositionSetOffset);
  	dVar10 = (double)*(float *)(0x0cfeb3c + spritePositionSetOffset);
  	bVar5 = FUN_00048ec4((longlong)dateUI->total_days);

  	if ((bVar5 != 0) && ((int)timeOfDay == 3)) {
  	  dVar10 = (double)*(float *)0x0cfeb74;
  	  sprite_id = 0x5a; //90
  	  dVar11 = (double)*(float *)0x0cfeb78;
  	}
	                  /* Display Time of Day Sprite */
	float x_adj;
	float y_adj;
	get_tod_sprite_adjust(sprite_id, &x_adj, &y_adj);
	
	draw_time_of_day_sprite(dateUI, sprite_id, dVar10, dVar11, dVar8, 0xffffffff);

  	a = (uint)(longlong)((double)dateUI->opacity_maybe * dVar12);
  	draw_weather_sprite(dateUI,a | 0xffffff00);
  	return;
}

void SecreCInit( void )
{
  // Hooks must be 'bound' to a handler like this in the start function.
  // If you don't do this, the game will crash.
  
  SHK_BIND_HOOK( FUN_004eaca4, SelPortraitFromModelID);
  SHK_BIND_HOOK( FUN_005528f8, WipeParallelHook );
  SHK_BIND_HOOK( FUN_00244250, RankupCardHook );
  SHK_BIND_HOOK( FUN_0023c070, ConfRankupHook );
  SHK_BIND_HOOK( FUN_0049eb90, CharaTexHook );
  SHK_BIND_HOOK( FUN_0049ee38, CommuCardHook );
  SHK_BIND_HOOK( FUN_003e8ff8, FUN_003e8ff8Hook );
  SHK_BIND_HOOK( FUN_005a4584, CallShopBannerHook );
  SHK_BIND_HOOK( FUN_004e392c, BuildGroupChatIconListHook );
  SHK_BIND_HOOK( FUN_00548c8c, GetConfidantListEntryHook );
  SHK_BIND_HOOK( FUN_00397f4c, LmapIdtoPointerList );
  SHK_BIND_HOOK( FUN_0059bb98, ShopBannerColorHook );
  SHK_BIND_HOOK( FUN_005a7098, FUN_005a7098Hook );
  SHK_BIND_HOOK( FUN_00597740, FUN_00597740Hook );
  SHK_BIND_HOOK( FUN_00260340, SET_ITEM_NUM_Hook );
  SHK_BIND_HOOK( FUN_000503d0, FUN_000503d0Hook );
  SHK_BIND_HOOK( FUN_005a6b78, FUN_005a6b78Hook );
  SHK_BIND_HOOK( FUN_005a5130, FUN_005a5130Hook );
  SHK_BIND_HOOK( FUN_0031ad2c, FUN_0031ad2cHook );
  SHK_BIND_HOOK( FUN_003366f0, FUN_003366f0Hook );
  SHK_BIND_HOOK( FUN_00936488, FUN_00936488Hook );
  SHK_BIND_HOOK( FUN_002d87cc, FUN_002d87ccHook );
  SHK_BIND_HOOK( FUN_00310cc0, FUN_00310cc0Hook );
  SHK_BIND_HOOK( FUN_00281d4c, FadeoutHook );
  SHK_BIND_HOOK( CueSelectTrack, CueSelectTrackHook );
  SHK_BIND_HOOK( GetProcedureByName, GetProcedureByNameHook );
  SHK_BIND_HOOK( FreeDungeonVoiceAcb, FreeDungeonVoiceAcbHook );
  SHK_BIND_HOOK( SetupPlayerVariables, SetupPlayerVariablesHook );
  SHK_BIND_HOOK( SetPlayerFieldSpeeds, SetPlayerFieldSpeedsHook );
  SHK_BIND_HOOK( SetPlayerDungeonSpeeds, SetPlayerDungeonSpeedsHook );
  SHK_BIND_HOOK( SetMorganaCarSpeeds, SetMorganaCarSpeedsHook );
  SHK_BIND_HOOK( IsPlayerAllowedSprint, IsPlayerAllowedSprintHook );
  SHK_BIND_HOOK( FUN_00325e38, FUN_00325e38Hook );
  SHK_BIND_HOOK( PlayerSnapToGround, PlayerSnapToGroundHook );
  SHK_BIND_HOOK( ShowFieldTaskPrompt, ShowFieldTaskPromptHook );
  SHK_BIND_HOOK( FUN_0030ab40, FUN_0030ab40Hook );
  SHK_BIND_HOOK( Draw_Date, Draw_DateHook );
}

void SecreCShutdown( void )
{
  // Executed when the PRX module is unloaded.    
}
#endif