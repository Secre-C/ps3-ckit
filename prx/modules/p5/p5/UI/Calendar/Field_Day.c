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

#include "Field_Day.h"
#include "modules/p5/p5.h"

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

void date_set_transparency_color( date_ui* a1, int color )
{
    SHK_FUNCTION_CALL_2( 0x56878, void, date_ui*, a1, int, color );
}

void draw_date_day_whiteshadow( date_ui* a1, int a2 )
{
    SHK_FUNCTION_CALL_2( 0x56cf8, void, date_ui*, a1, int, a2 );
}

void draw_weather_icon_sprite( date_ui* dateUI, int color )
{
    //SHK_FUNCTION_CALL_2( 0x56a08, void, date_ui*, dateUI, int, color );
	
	u8 weather_index;
  	double scale;
  	double x;
  	int month;
  	int day;
	
	date_weather_icons weatherIconSprites = *(date_weather_icons*)0xcff2d4;
	
	if (GetTotalDays() >= 275 && GetTotalDays() <= 276 && GetBitflagState(164) && deco_date())
	{
		for (int i = 0; i < 3; i++)
		{
			weatherIconSprites.sunny_sprites[i] = 251 + i;
			weatherIconSprites.cloudy_sprites[i] = 254 + i;
		}
	}

  	x = 0.0;
  	weather_index = Get_Weather_Index((longlong)dateUI->total_days,(int)dateUI->timeOfDay);
  	GetDayMonth((int)dateUI->total_days,&month,&day);
  	if (day < 10) {
  	  x = -10.0;
  	}

  	spd_sprite_create(dateUI->p5_field_day_spd, weatherIconSprites.sunny_sprites[dateUI->weatherIconFrame + (char)weather_index * 3]);
  	sprite_adjust_pos(dateUI->p5_field_day_spd,50.0,35.0);
  	sprite_set_screen_position((double)(((float)(x + 256.0) + dateUI->field72_0x64) * dateUI->scale_multiplier),
  	           (double)((dateUI->field73_0x68 + 43.0) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	sprite_set_bound(dateUI->p5_field_day_spd,(double)dateUI->field74_0x6c);
  	scale = (double)(dateUI->field87_0x7c * dateUI->scale_multiplier);
  	sprite_set_scale(scale,scale,dateUI->p5_field_day_spd);
  	sprite_set_color(dateUI->p5_field_day_spd,color);
  	SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	sprite_toggle_visibility(dateUI->p5_field_day_spd);
  	return;
}

void draw_date_month_black_shadow( double a1, double a2, date_ui* a3, undefined8 a4, undefined8 a5, int a6 )
{
    SHK_FUNCTION_CALL_6( 0x56b98, void, date_ui*, a3, undefined8, a4, undefined8, a5, int, a6, double, a1, double, a2 );
}

void FUN_00056918( date_ui* a1, undefined8 a2 )
{
    SHK_FUNCTION_CALL_2( 0x56918, void, date_ui*, a1, undefined8, a2 );
}

void draw_weekday_whiteshadow( date_ui* a1, int a2 )
{
    SHK_FUNCTION_CALL_2( 0x57678, void, date_ui*, a1, int, a2 );
}

void draw_date_day_black_shadow( date_ui* a1, int a2 )
{
    SHK_FUNCTION_CALL_2( 0x57030, void, date_ui*, a1, int, a2 );
}

void draw_date_month_sprite( date_ui* dateUI, int currentMonth, double x, double y, double x2, int color)
{
    double monthNumberScale;
	int sprite_id = currentMonth + 0x18;
	int totalDays = GetTotalDays();

	if (totalDays == 213)
	{
		//sprite_id = 230; //heeho
	}
	else if (totalDays >= 275 && totalDays <= 276 && GetBitflagState(164) && deco_date())
	{
		sprite_id = 244;
		x -= 15.0;
	}

  	spd_sprite_create(dateUI->p5_field_day_spd,sprite_id);
  	sprite_adjust_pos(dateUI->p5_field_day_spd,x,y);
  	sprite_set_screen_position((double)(((float)(x2 + 20.0) + dateUI->field16_0x14) * dateUI->scale_multiplier),
  	           (double)((dateUI->field17_0x18 + 79.0) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	sprite_set_bound(dateUI->p5_field_day_spd,(double)dateUI->field18_0x1c);
  	monthNumberScale = (double)(dateUI->field31_0x2c * dateUI->scale_multiplier);
  	sprite_set_scale(monthNumberScale,monthNumberScale,dateUI->p5_field_day_spd);
  	sprite_set_color(dateUI->p5_field_day_spd, color);
  	SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	sprite_toggle_visibility(dateUI->p5_field_day_spd);
}

void draw_weather_square_bg_sprite(date_ui* dateUI, double x, uint color)
{
    double scale;

  	spd_sprite_create(dateUI->p5_field_day_spd,0x60);
  	sprite_adjust_pos(dateUI->p5_field_day_spd,50.0,35.0);
  	sprite_set_screen_position((double)(((float)(x + 242.0) + dateUI->field72_0x64) * dateUI->scale_multiplier),
  	           (double)((dateUI->field73_0x68 + 29.0) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	sprite_set_bound(dateUI->p5_field_day_spd,(double)dateUI->field74_0x6c);
  	sprite_set_color(dateUI->p5_field_day_spd,color);
  	scale = (double)(dateUI->field31_0x2c * dateUI->scale_multiplier);
  	sprite_set_scale(scale,scale,dateUI->p5_field_day_spd);
  	SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	sprite_toggle_visibility(dateUI->p5_field_day_spd);
}

void draw_month_white_backdrop_sprite(date_ui* dateUI, int currentMonth, double x, double y, double x2, double y2, int color, double scale)
{
    spd_sprite_create(dateUI->p5_field_day_spd,currentMonth);
  	sprite_adjust_pos(dateUI->p5_field_day_spd, x, y);
  	sprite_set_screen_position((double)((float)(x2 + (double)dateUI->field16_0x14) * dateUI->scale_multiplier),
  	           (double)((dateUI->field17_0x18 + y2) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	sprite_set_bound(dateUI->p5_field_day_spd,(double)dateUI->field18_0x1c);
  	sprite_set_scale(scale,scale,dateUI->p5_field_day_spd);
	sprite_set_color(dateUI->p5_field_day_spd,color);
  	SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	sprite_toggle_visibility(dateUI->p5_field_day_spd);
}

void draw_weekday_dropshadow_sprite(date_ui* dateUI, int weekday, int spritePositionSetOffset, int color, double scale)
{
    spd_sprite_create(dateUI->p5_field_day_spd,weekday + 0x43);
  	sprite_adjust_pos(dateUI->p5_field_day_spd,(double)*(float *)((int)0x0cfea40 + spritePositionSetOffset),
  	           (double)*(float *)((int)0x0cfea44 + spritePositionSetOffset));
  	sprite_set_screen_position ((double)((*(float *)(0x0cfeae8 + spritePositionSetOffset) + dateUI->field128_0xb4) * dateUI->scale_multiplier),
  	           (double)((*(float *)(0x0cfeaec + spritePositionSetOffset) + dateUI->field129_0xb8) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	sprite_set_bound(dateUI->p5_field_day_spd, (double)(*(float *)(0x0cfeb20 + (int)((longlong)weekday << 2)) + dateUI->field130_0xbc));
  	sprite_set_scale(scale,scale,dateUI->p5_field_day_spd);
  	sprite_set_color(dateUI->p5_field_day_spd,color);
  	SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	sprite_toggle_visibility(dateUI->p5_field_day_spd);
}

void draw_weekday_sprite(date_ui* dateUI, int weekday, int spritePositionSetOffset, uint color, double scale, int sprite_id)
{
	//backdrop
    spd_sprite_create(dateUI->p5_field_day_spd,weekday + sprite_id);
  	sprite_adjust_pos(dateUI->p5_field_day_spd,(double)*(float *)((int)0x0cfea40 + spritePositionSetOffset),
  	           (double)*(float *)((int)0x0cfea44 + spritePositionSetOffset));
  	sprite_set_screen_position((double)((*(float *)(0x0cfeae8 + spritePositionSetOffset) + 10.0 + dateUI->field128_0xb4) *
  	                   dateUI->scale_multiplier),(double)((*(float *)(0x0cfeaec + spritePositionSetOffset) + 10.0 + dateUI->field129_0xb8) *
  	                   dateUI->scale_multiplier),dateUI->p5_field_day_spd);
  	sprite_set_bound(dateUI->p5_field_day_spd, (double)(*(float *)(0x0cfeb20 + (int)((longlong)weekday << 2)) + dateUI->field130_0xbc));
  	sprite_set_scale(scale,scale,dateUI->p5_field_day_spd);
  	sprite_set_color(dateUI->p5_field_day_spd,color);
  	SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	sprite_toggle_visibility(dateUI->p5_field_day_spd);
}

void draw_time_of_day_sprite(date_ui* dateUI, int sprite_id, double x, double y, double y_adj, int color)
{
    double scale;
    double x_adj;

    spd_sprite_create(dateUI->p5_field_day_spd,sprite_id);
  	x_adj = SRPITE_001c4958(dateUI->p5_field_day_spd);
  	sprite_adjust_pos(dateUI->p5_field_day_spd,x_adj,y_adj);
  	sprite_set_screen_position((double)((float)(x + (double)dateUI->field156_0xdc) * dateUI->scale_multiplier),
  	           (double)((float)(y + (double)dateUI->field157_0xe0) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	sprite_set_bound(dateUI->p5_field_day_spd,(double)(dateUI->field158_0xe4 + -22.4));
  	scale = (double)(dateUI->field171_0xf4 * dateUI->scale_multiplier);
  	sprite_set_scale(scale,scale,dateUI->p5_field_day_spd);
  	sprite_set_color(dateUI->p5_field_day_spd,color);
  	SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	sprite_toggle_visibility(dateUI->p5_field_day_spd);
}

void get_tod_sprite_adjust(int sprite_id, float* x_adj, float* y_adj)
{
	if (sprite_id == 92) //afternoon
	{
		*x_adj = 2.0;
		*y_adj = -8.0;
	}
	else if (sprite_id == 93) //after school
	{
		*x_adj = 4.0;
		*y_adj = -7.0;
	}
	else if (sprite_id == 94) //evening
	{
		*x_adj = 3.0;
		*y_adj = -9.0;
	}
	else
	{
		*x_adj = 2.0;
		*y_adj = -7.0;
	}
}

void draw_date_day_sprite(date_ui *dateUI,int color)
{
    //SHK_FUNCTION_CALL_2( 0x57368, void, date_ui*, dateUI, int, color );
	//return;

  	double scale;
  	double x;
  	double y;
  	int month;
  	int day;
  	int day_sprite_index;
	
  	GetDayMonth((int)dateUI->total_days,&month,&day);
	int sprite = 0x39;
	int totalDays = GetTotalDays();

	if (totalDays == 213) //heeho
	{
		sprite = 219;
	}
	else if (totalDays >= 275 && totalDays <= 276 && GetBitflagState(164) && deco_date())
	{
		sprite = 241; //new years
	}

  	y = 52.0;
  	x = 49.0;
  	if (day < 10) 
  	{
  	  spd_sprite_create(dateUI->p5_field_day_spd,day + sprite);
  	  sprite_adjust_pos(dateUI->p5_field_day_spd,x,y);
  	  sprite_set_screen_position((double)((dateUI->field44_0x3c + 161.0) * dateUI->scale_multiplier),
  	             (double)((dateUI->field45_0x40 + 67.0) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	  sprite_set_bound(dateUI->p5_field_day_spd,(double)(dateUI->field46_0x44 + 6.6));
  	  x = (double)(dateUI->field59_0x54 * dateUI->scale_multiplier);
  	  sprite_set_scale(x,x,dateUI->p5_field_day_spd);
  	  sprite_set_color(dateUI->p5_field_day_spd,color);
  	  SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	  sprite_toggle_visibility(dateUI->p5_field_day_spd);
  	}
  	else 
  	{
  	  day_sprite_index = day / 10 + (day >> 0x1f);
  	  spd_sprite_create(dateUI->p5_field_day_spd, day + (day_sprite_index - (day_sprite_index >> 0x1f)) * -10 + sprite);
  	  sprite_adjust_pos(dateUI->p5_field_day_spd,x,y);
  	  sprite_set_screen_position((double)((dateUI->field44_0x3c + 186.0) * dateUI->scale_multiplier),
  	             (double)((dateUI->field45_0x40 + 64.0) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	  sprite_set_bound(dateUI->p5_field_day_spd,(double)(dateUI->field46_0x44 + 2.4));
  	  scale = (double)(dateUI->field59_0x54 * 0.92 * dateUI->scale_multiplier);
  	  sprite_set_scale(scale,scale,dateUI->p5_field_day_spd);
  	  sprite_set_color(dateUI->p5_field_day_spd,color);
  	  SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	  sprite_toggle_visibility(dateUI->p5_field_day_spd);
  	  day_sprite_index = day / 10 + (day >> 0x1f);
  	  spd_sprite_create(dateUI->p5_field_day_spd,(day_sprite_index - (day_sprite_index >> 0x1f)) + sprite);
  	  sprite_adjust_pos(dateUI->p5_field_day_spd,x,y);
  	  sprite_set_screen_position((double)((dateUI->field44_0x3c + 134.0) * dateUI->scale_multiplier),
  	             (double)((dateUI->field45_0x40 + 76.0) * dateUI->scale_multiplier), dateUI->p5_field_day_spd);
  	  sprite_set_bound(dateUI->p5_field_day_spd,(double)(dateUI->field46_0x44 + -3.8));
  	  x = (double)(dateUI->field59_0x54 * dateUI->scale_multiplier);
  	  sprite_set_scale(x,x,dateUI->p5_field_day_spd);
  	  sprite_set_color(dateUI->p5_field_day_spd,color);
  	  SPRITE_001c5254(dateUI->p5_field_day_spd,'\0');
  	  sprite_toggle_visibility(dateUI->p5_field_day_spd);
  	}
  	return;
}

bool deco_date()
{
	return sequenceIDGlobal == 6 && !GetBitflagState(8724);
}

u8 FUN_00048ec4( longlong a1 )
{
    SHK_FUNCTION_CALL_1( 0x48ec4, u8, longlong, a1 );
}

void draw_weather_sprite( date_ui* a1, int a2 )
{
    SHK_FUNCTION_CALL_2( 0x577f0, void, date_ui*, a1, int, a2 );
}

#endif
