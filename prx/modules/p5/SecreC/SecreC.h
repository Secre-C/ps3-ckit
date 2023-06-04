#ifdef GAME_P5
#ifndef SECREC_H
#define SECREC_H

void SecreCInit( void );
void SecreCShutdown( void );


// PS3 system includes
#include "lib/common.h"
#include "lib/shk.h"

#include "modules/p5/p5.h"

typedef struct  
{
    undefined4 * Wipe_Pac;
}ParallelWipe;

typedef struct
{
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0C;
    undefined4 cardId;
}cmmFormatStruct;

typedef struct
{
    u32 field00;
    u32 field04;
    u8 field08;
    u8 PortraitID;
} SelPrompt;

typedef struct
{
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    cmmFormatStruct * Field52;
}CmmStruct;

typedef struct
{
    u64 field00;
    u32 field08;
    u16 field0c;
    u8 field0e;
    char ItemPosition;
    u64 field10;
    u16 PurchaseQuantity;
    u16 field1a;
    u32 field1c;
    u32 BannerColor;
    u32 field24;
    u64 field28;
    u64 field30;
    u64 field38;
    u64 field40;
    u64 field48;
    u64 field50;
    u64 field58;
    u64 field60;
    u64 field68;
    u64 field70;
    u64 field78;
    u64 field80;
    u64 field88;
    u64 field90;
    u64 field98;
    u64 fielda0;
    u64 fielda8;
    u64 fieldb0;
    u64 fieldb8;
    u16 AvailableItems;
    u16 ShopID;
    u32 fieldc4;
    u64 fieldc8;
    u64 fieldd0;
    u64 fieldd8;
    u64 fielde0;
    u64 fielde8;
    u64 fieldf0;
    u64 fieldf8;
    u64 field100;
    u64 field108;
    u64 field110;
    u64 field118;
    u64 field120;
    u64 field128;
    u64 field130;
    u64 field138;
    u64 field140;
    u64 field148;
    u64 field150;
    u64 field158;
    u64 field160;
    u64 field168;
    u64 field170;
    u64 field178;
    u64 field180;
    u64 field188;
    u64 field190;
    u64 field198;
    u64 field1a0;
    u64 field1a8;
    u64 field1b0;
    u64 field1b8;
    u64 field1c0;
    u64 field1c8;
    u64 field1d0;
    u64 field1d8;
    u64 field1e0;
    u64 field1e8;
    u64 field1f0;
    u64 field1f8;
    u64 field200;
    u64 field208;
    u64 field210;
    u64 field218;
    u64 field220;
    u64 field228;
    u64 field230;
    u64 field238;
    u64 field240;
    u64 field248;
    u64 field250;
    u64 field258;
    u64 field260;
    u64 field268;
    u64 field270;
    u64 field278;
    u64 field280;
    u64 field288;
    u64 field290;
    u64 field298;
    u64 field2a0;
    u64 field2a8;
    u64 field2b0;
    u64 field2b8;
    u64 field2c0;
    u64 field2c8;
    u64 field2d0;
    u64 field2d8;
    u64 field2e0;
    u64 field2e8;
    u64 field2f0;
    u64 field2f8;
    u64 field300;
    u64 field308;
    u64 field310;
    u64 field318;
    u64 field320;
    u64 field328;
    u64 field330;
    u64 field338;
    u64 field340;
    u64 field348;
    u64 field350;
    u64 field358;
    u64 field360;
    u64 field368;
    u64 field370;
    u64 field378;
    u64 field380;
    u64 field388;
    u64 field390;
    u64 field398;
    u64 field3a0;
    u64 field3a8;
    u64 field3b0;
    u64 field3b8;
    u64 field3c0;
    u64 field3c8;
    u64 field3d0;
    u64 field3d8;
    u64 field3e0;
    u64 field3e8;
    u64 field3f0;
    u64 field3f8;
    u64 field400;
    u64 field408;
    u64 field410;
    u64 field418;
    u64 field420;
    u64 field428;
    u64 field430;
    u64 field438;
    u64 field440;
    u64 field448;
    u64 field450;
    u64 field458;
    u64 field460;
    u64 field468;
    u64 field470;
    u64 field478;
    u64 field480;
    u64 field488;
    u64 field490;
    u64 field498;
    u64 field4a0;
    u64 field4a8;
    u64 field4b0;
    u64 field4b8;
    u64 field4c0;
    u64 field4c8;
    u64 field4d0;
    u64 field4d8;
    u64 field4e0;
    u64 field4e8;
    u64 field4f0;
    u64 field4f8;
    u64 field500;
    u64 field508;
    u64 field510;
    u64 field518;
    u64 field520;
    u64 field528;
    u64 field530;
    u64 field538;
    u64 field540;
    u64 field548;
    u64 field550;
    u64 field558;
    u64 field560;
    u64 field568;
    u64 field570;
    u64 field578;
    u64 field580;
    u64 field588;
    u64 field590;
    u64 field598;
    u64 field5a0;
    u64 field5a8;
    u64 field5b0;
    u64 field5b8;
    u64 field5c0;
    u64 field5c8;
    u64 field5d0;
    u64 field5d8;
    u64 field5e0;
    u64 field5e8;
    u64 field5f0;
    u64 field5f8;
    u64 field600;
    u64 field608;
    u64 field610;
    u64 field618;
    u64 field620;
    u64 field628;
    u64 field630;
    u64 field638;
    u64 field640;
    u64 field648;
    u64 field650;
    u64 field658;
    u64 field660;
    u64 field668;
    u64 field670;
    u64 field678;
    u64 field680;
    u64 field688;
    u64 field690;
    u64 field698;
    u64 field6a0;
    u64 field6a8;
    u64 field6b0;
    u64 field6b8;
    u64 field6c0;
    u64 field6c8;
    u64 field6d0;
    u64 field6d8;
    u64 field6e0;
    u64 field6e8;
    u64 field6f0;
    u64 field6f8;
    u64 field700;
    u64 field708;
    u64 field710;
    u64 field718;
    u64 field720;
    u64 field728;
    u64 field730;
    u64 field738;
    u64 field740;
    u64 field748;
    u64 field750;
    u64 field758;
    u64 field760;
    u64 field768;
    u64 field770;
    u64 field778;
    u64 field780;
    u64 field788;
    u64 field790;
    u64 field798;
    u64 field7a0;
    u64 field7a8;
    u64 field7b0;
    u64 field7b8;
    u64 field7c0;
    u64 field7c8;
    u64 field7d0;
    u64 field7d8;
    u64 field7e0;
    u64 field7e8;
    u64 field7f0;
    u16 field7f8;
    u16 field7fa;
    u32 field7fc;
    u64 field800;
    u64 field808;
    u64 field810;
    u64 field818;
    u64 field820;
    u64 field828;
    u64 field830;
    u64 field838;
    u64 field840;
    u64 field848;
    u64 field850;
    u64 field858;
    u64 field860;
    u64 field868;
    u64 field870;
    u64 field878;
    u64 field880;
    u64 field888;
    u64 field890;
    u64 field898;
    u64 field8a0;
    u64 field8a8;
    u64 field8b0;
    u64 field8b8;
    u64 field8c0;
    u64 field8c8;
    u64 field8d0;
    u64 field8d8;
    u64 field8e0;
    u64 field8e8;
    u64 field8f0;
    u64 field8f8;
    u64 field900;
    u64 field908;
    u64 field910;
    u64 field918;
    u64 field920;
    u64 field928;
    u64 field930;
    u64 field938;
    u64 field940;
    u64 field948;
    u64 field950;
    u64 field958;
    u64 field960;
    u64 field968;
    u64 field970;
    u64 field978;
    u64 field980;
    u64 field988;
    u64 field990;
    u64 field998;
    u64 field9a0;
    u64 field9a8;
    u64 field9b0;
    u64 field9b8;
    u64 field9c0;
    u64 field9c8;
    u64 field9d0;
    u64 field9d8;
    u64 field9e0;
    u64 field9e8;
    u64 field9f0;
    u64 field9f8;
    u64 fielda00;
    u64 fielda08;
    u64 fielda10;
    u64 fielda18;
    u64 fielda20;
    u64 fielda28;
    u64 fielda30;
    u64 fielda38;
    u64 fielda40;
    u64 fielda48;
    u64 fielda50;
    u64 fielda58;
    u64 fielda60;
    u64 fielda68;
    u64 fielda70;
    u64 fielda78;
    u64 fielda80;
    u64 fielda88;
    u64 fielda90;
    u64 fielda98;
    u64 fieldaa0;
    u64 fieldaa8;
    u64 fieldab0;
    u64 fieldab8;
    u64 fieldac0;
    u64 fieldac8;
    u64 fieldad0;
    u64 fieldad8;
    u64 fieldae0;
    u64 fieldae8;
    u64 fieldaf0;
    u64 fieldaf8;
    u64 fieldb00;
    u64 fieldb08;
    u64 fieldb10;
    u64 fieldb18;
    u64 fieldb20;
    u64 fieldb28;
    u64 fieldb30;
    u64 fieldb38;
    u64 fieldb40;
    u64 fieldb48;
    u64 fieldb50;
    u64 fieldb58;
    u64 fieldb60;
    u64 fieldb68;
    u64 fieldb70;
    u64 fieldb78;
    u64 fieldb80;
    u64 fieldb88;
    u64 fieldb90;
    u64 fieldb98;
    u64 fieldba0;
    u64 fieldba8;
    u64 fieldbb0;
    u64 fieldbb8;
    u64 fieldbc0;
    u64 fieldbc8;
    u64 fieldbd0;
    u64 fieldbd8;
    u64 fieldbe0;
    u64 fieldbe8;
    u64 fieldbf0;
    u64 fieldbf8;
    u64 fieldc00;
    u64 fieldc08;
    u64 fieldc10;
    u64 fieldc18;
    u64 fieldc20;
    u64 fieldc28;
    u64 fieldc30;
    u64 fieldc38;
    u64 fieldc40;
    u64 fieldc48;
    u64 fieldc50;
    u64 fieldc58;
    u64 fieldc60;
    u64 fieldc68;
    u64 fieldc70;
    u64 fieldc78;
    u64 fieldc80;
    u64 fieldc88;
    u64 fieldc90;
    u64 fieldc98;
    u64 fieldca0;
    u64 fieldca8;
    u64 fieldcb0;
    u64 fieldcb8;
    u64 fieldcc0;
    u64 fieldcc8;
    u64 fieldcd0;
    u64 fieldcd8;
    u64 fieldce0;
    u64 fieldce8;
    u64 fieldcf0;
    u64 fieldcf8;
    u64 fieldd00;
    u64 fieldd08;
    u64 fieldd10;
    u64 fieldd18;
    u64 fieldd20;
    u64 fieldd28;
    u64 fieldd30;
    u64 fieldd38;
    u64 fieldd40;
    u64 fieldd48;
    u64 fieldd50;
    u64 fieldd58;
    u64 fieldd60;
    u64 fieldd68;
    u64 fieldd70;
    u64 fieldd78;
    u64 fieldd80;
    u64 fieldd88;
    u64 fieldd90;
    u64 fieldd98;
    u64 fieldda0;
    u64 fieldda8;
    u64 fielddb0;
    u64 fielddb8;
    u64 fielddc0;
    u64 fielddc8;
    u64 fielddd0;
    u64 fielddd8;
    u64 fieldde0;
    u64 fieldde8;
    u64 fielddf0;
    u64 fielddf8;
    u64 fielde00;
    u64 fielde08;
    u64 fielde10;
    u64 fielde18;
    u64 fielde20;
    u64 fielde28;
    u64 fielde30;
    u64 fielde38;
    u64 fielde40;
    u64 fielde48;
    u64 fielde50;
    u64 fielde58;
    u64 fielde60;
    u64 fielde68;
    u64 fielde70;
    u64 fielde78;
    u64 fielde80;
    u64 fielde88;
    u64 fielde90;
    u64 fielde98;
    u64 fieldea0;
    u64 fieldea8;
    u64 fieldeb0;
    u64 fieldeb8;
    u64 fieldec0;
    u64 fieldec8;
    u64 fielded0;
    u64 fielded8;
    u64 fieldee0;
    u64 fieldee8;
    u64 fieldef0;
    u64 fieldef8;
    u64 fieldf00;
    u64 fieldf08;
    u64 fieldf10;
    u64 fieldf18;
    u64 fieldf20;
    u64 fieldf28;
    u64 fieldf30;
    u64 fieldf38;
    u64 fieldf40;
    u64 fieldf48;
    u64 fieldf50;
    u64 fieldf58;
    u64 fieldf60;
    u64 fieldf68;
    u64 fieldf70;
    u64 fieldf78;
    u64 fieldf80;
    u64 fieldf88;
    u64 fieldf90;
    u64 fieldf98;
    u64 fieldfa0;
    u64 fieldfa8;
    u64 fieldfb0;
    u64 fieldfb8;
    u64 fieldfc0;
    u64 fieldfc8;
    u64 fieldfd0;
    u64 fieldfd8;
    u64 fieldfe0;
    u64 fieldfe8;
    u64 fieldff0;
    u64 fieldff8;
    u64 field1000;
    u64 field1008;
    u64 field1010;
    u64 field1018;
    u64 field1020;
    u64 field1028;
    u64 field1030;
    u64 field1038;
    u64 field1040;
    u64 field1048;
    u64 field1050;
    u64 field1058;
    u64 field1060;
    u64 field1068;
    u64 field1070;
    u64 field1078;
    u64 field1080;
    u64 field1088;
    u64 field1090;
    u64 field1098;
    u64 field10a0;
    u64 field10a8;
    u64 field10b0;
    u64 field10b8;
    u64 field10c0;
    u64 field10c8;
    u64 field10d0;
    u64 field10d8;
    u64 field10e0;
    u64 field10e8;
    u64 field10f0;
    u64 field10f8;
    u64 field1100;
    u64 field1108;
    u64 field1110;
    u64 field1118;
    u64 field1120;
    u64 field1128;
    u64 field1130;
    u64 field1138;
    u64 field1140;
    u64 field1148;
    u64 field1150;
    u64 field1158;
    u64 field1160;
    u64 field1168;
    u64 field1170;
    u64 field1178;
    u64 field1180;
    u64 field1188;
    u64 field1190;
    u64 field1198;
    u64 field11a0;
    u64 field11a8;
    u64 field11b0;
    u64 field11b8;
    u64 field11c0;
    u64 field11c8;
    u64 field11d0;
    u64 field11d8;
    u64 field11e0;
    u64 field11e8;
    u64 field11f0;
    u64 field11f8;
    u64 field1200;
    int field1208;
    int CurrentMoney;
    int SomethingTransactionPrice;
    int field1214;
    int SpendableMoney;
    int field121c;
    u32 PurchasePrice;
} ShopStruct;

#endif
#endif