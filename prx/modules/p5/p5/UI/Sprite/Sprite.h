#ifdef GAME_P5
#ifndef SPRITE_H
#define SPRITE_H

// PS3 system includes
#include "lib/common.h"
#include "lib/shk.h"

#define byte u8
#define sbyte s8
#define short s16
#define ushort u16
#define uint u32
#define ulonglong u64
#define longlong s64

typedef struct sprite sprite, *Psprite;

struct sprite {
    struct sprite * this_adr;
    int field1_0x4;
    int a_bitfield;
    uint spd_id;
    int * currentSelectedSprite;
    int field5_0x14;
    int field6_0x18;
    uint * field7_0x1c;
    int * field8_0x20;
    int field9_0x24;
    int field10_0x28;
    float field11_0x2c;
    int * field12_0x30;
    float field13_0x34;
    float field14_0x38;
    float field15_0x3c;
    int * field16_0x40;
    int field17_0x44;
    int field18_0x48;
    uint field19_0x4c;
    int * field20_0x50;
    int field21_0x54;
    int field22_0x58;
    uint field23_0x5c;
    int * field24_0x60;
    int field25_0x64;
    int field26_0x68;
    uint field27_0x6c;
    int * field28_0x70;
    int field29_0x74;
    int field30_0x78;
    undefined field31_0x7c;
    undefined field32_0x7d;
    undefined field33_0x7e;
    undefined field34_0x7f;
    undefined field35_0x80;
    undefined field36_0x81;
    undefined field37_0x82;
    undefined field38_0x83;
    undefined field39_0x84;
    undefined field40_0x85;
    undefined field41_0x86;
    undefined field42_0x87;
    undefined field43_0x88;
    undefined field44_0x89;
    undefined field45_0x8a;
    undefined field46_0x8b;
    undefined field47_0x8c;
    undefined field48_0x8d;
    undefined field49_0x8e;
    undefined field50_0x8f;
    int * field51_0x90;
    int field52_0x94;
    undefined field53_0x98;
    undefined field54_0x99;
    undefined field55_0x9a;
    undefined field56_0x9b;
    undefined field57_0x9c;
    undefined field58_0x9d;
    undefined field59_0x9e;
    undefined field60_0x9f;
    undefined field61_0xa0;
    undefined field62_0xa1;
    undefined field63_0xa2;
    undefined field64_0xa3;
    undefined field65_0xa4;
    undefined field66_0xa5;
    undefined field67_0xa6;
    undefined field68_0xa7;
    undefined field69_0xa8;
    undefined field70_0xa9;
    undefined field71_0xaa;
    undefined field72_0xab;
    undefined field73_0xac;
    undefined field74_0xad;
    undefined field75_0xae;
    undefined field76_0xaf;
    undefined field77_0xb0;
    undefined field78_0xb1;
    undefined field79_0xb2;
    undefined field80_0xb3;
    undefined field81_0xb4;
    undefined field82_0xb5;
    undefined field83_0xb6;
    undefined field84_0xb7;
    undefined field85_0xb8;
    undefined field86_0xb9;
    undefined field87_0xba;
    undefined field88_0xbb;
    undefined field89_0xbc;
    undefined field90_0xbd;
    undefined field91_0xbe;
    undefined field92_0xbf;
    undefined field93_0xc0;
    undefined field94_0xc1;
    undefined field95_0xc2;
    undefined field96_0xc3;
    undefined field97_0xc4;
    undefined field98_0xc5;
    undefined field99_0xc6;
    undefined field100_0xc7;
    undefined field101_0xc8;
    undefined field102_0xc9;
    undefined field103_0xca;
    undefined field104_0xcb;
    undefined field105_0xcc;
    undefined field106_0xcd;
    undefined field107_0xce;
    undefined field108_0xcf;
    undefined field109_0xd0;
    undefined field110_0xd1;
    undefined field111_0xd2;
    undefined field112_0xd3;
    undefined field113_0xd4;
    undefined field114_0xd5;
    undefined field115_0xd6;
    undefined field116_0xd7;
    undefined field117_0xd8;
    undefined field118_0xd9;
    undefined field119_0xda;
    undefined field120_0xdb;
    undefined field121_0xdc;
    undefined field122_0xdd;
    undefined field123_0xde;
    undefined field124_0xdf;
    int * field125_0xe0;
    float field126_0xe4;
    float field127_0xe8;
    float field128_0xec;
    undefined field129_0xf0;
    undefined field130_0xf1;
    undefined field131_0xf2;
    undefined field132_0xf3;
    undefined field133_0xf4;
    undefined field134_0xf5;
    undefined field135_0xf6;
    undefined field136_0xf7;
    undefined field137_0xf8;
    undefined field138_0xf9;
    undefined field139_0xfa;
    undefined field140_0xfb;
    undefined field141_0xfc;
    undefined field142_0xfd;
    undefined field143_0xfe;
    undefined field144_0xff;
    undefined field145_0x100;
    undefined field146_0x101;
    undefined field147_0x102;
    undefined field148_0x103;
    undefined field149_0x104;
    undefined field150_0x105;
    undefined field151_0x106;
    undefined field152_0x107;
    undefined field153_0x108;
    undefined field154_0x109;
    undefined field155_0x10a;
    undefined field156_0x10b;
    undefined field157_0x10c;
    undefined field158_0x10d;
    undefined field159_0x10e;
    undefined field160_0x10f;
    int * field161_0x110;
    float field162_0x114;
    float field163_0x118;
    float field164_0x11c;
    undefined field165_0x120;
    undefined field166_0x121;
    undefined field167_0x122;
    undefined field168_0x123;
    undefined field169_0x124;
    undefined field170_0x125;
    undefined field171_0x126;
    undefined field172_0x127;
    undefined field173_0x128;
    undefined field174_0x129;
    undefined field175_0x12a;
    undefined field176_0x12b;
    undefined field177_0x12c;
    undefined field178_0x12d;
    undefined field179_0x12e;
    undefined field180_0x12f;
    undefined field181_0x130;
    undefined field182_0x131;
    undefined field183_0x132;
    undefined field184_0x133;
    undefined field185_0x134;
    undefined field186_0x135;
    undefined field187_0x136;
    undefined field188_0x137;
    undefined field189_0x138;
    undefined field190_0x139;
    undefined field191_0x13a;
    undefined field192_0x13b;
    undefined field193_0x13c;
    undefined field194_0x13d;
    undefined field195_0x13e;
    undefined field196_0x13f;
    undefined field197_0x140;
    undefined field198_0x141;
    undefined field199_0x142;
    undefined field200_0x143;
    undefined field201_0x144;
    undefined field202_0x145;
    undefined field203_0x146;
    undefined field204_0x147;
    undefined field205_0x148;
    undefined field206_0x149;
    undefined field207_0x14a;
    undefined field208_0x14b;
    undefined field209_0x14c;
    undefined field210_0x14d;
    undefined field211_0x14e;
    undefined field212_0x14f;
    undefined field213_0x150;
    undefined field214_0x151;
    undefined field215_0x152;
    undefined field216_0x153;
    undefined field217_0x154;
    undefined field218_0x155;
    undefined field219_0x156;
    undefined field220_0x157;
    undefined field221_0x158;
    undefined field222_0x159;
    undefined field223_0x15a;
    undefined field224_0x15b;
    undefined field225_0x15c;
    undefined field226_0x15d;
    undefined field227_0x15e;
    undefined field228_0x15f;
    undefined field229_0x160;
    undefined field230_0x161;
    undefined field231_0x162;
    undefined field232_0x163;
    undefined field233_0x164;
    undefined field234_0x165;
    undefined field235_0x166;
    undefined field236_0x167;
    undefined field237_0x168;
    undefined field238_0x169;
    undefined field239_0x16a;
    undefined field240_0x16b;
    undefined field241_0x16c;
    undefined field242_0x16d;
    undefined field243_0x16e;
    undefined field244_0x16f;
    undefined field245_0x170;
    undefined field246_0x171;
    undefined field247_0x172;
    undefined field248_0x173;
    undefined field249_0x174;
    undefined field250_0x175;
    undefined field251_0x176;
    undefined field252_0x177;
    undefined field253_0x178;
    undefined field254_0x179;
    undefined field255_0x17a;
    undefined field256_0x17b;
    undefined field257_0x17c;
    undefined field258_0x17d;
    undefined field259_0x17e;
    undefined field260_0x17f;
    undefined field261_0x180;
    undefined field262_0x181;
    undefined field263_0x182;
    undefined field264_0x183;
    undefined field265_0x184;
    undefined field266_0x185;
    undefined field267_0x186;
    undefined field268_0x187;
    undefined field269_0x188;
    undefined field270_0x189;
    undefined field271_0x18a;
    undefined field272_0x18b;
    undefined field273_0x18c;
    undefined field274_0x18d;
    undefined field275_0x18e;
    undefined field276_0x18f;
    undefined field277_0x190;
    undefined field278_0x191;
    undefined field279_0x192;
    undefined field280_0x193;
    undefined field281_0x194;
    undefined field282_0x195;
    undefined field283_0x196;
    undefined field284_0x197;
    undefined field285_0x198;
    undefined field286_0x199;
    undefined field287_0x19a;
    undefined field288_0x19b;
    undefined field289_0x19c;
    undefined field290_0x19d;
    undefined field291_0x19e;
    undefined field292_0x19f;
    undefined a_color_thing; /* Created by retype action */
    undefined field294_0x1a1;
    undefined field295_0x1a2;
    undefined field296_0x1a3;
    undefined field297_0x1a4;
    undefined field298_0x1a5;
    undefined field299_0x1a6;
    undefined field300_0x1a7;
    undefined field301_0x1a8;
    undefined field302_0x1a9;
    undefined field303_0x1aa;
    undefined field304_0x1ab;
    undefined field305_0x1ac;
    undefined field306_0x1ad;
    undefined field307_0x1ae;
    undefined field308_0x1af;
    undefined field309_0x1b0;
    undefined field310_0x1b1;
    undefined field311_0x1b2;
    undefined field312_0x1b3;
    undefined field313_0x1b4;
    undefined field314_0x1b5;
    undefined field315_0x1b6;
    undefined field316_0x1b7;
    undefined field317_0x1b8;
    undefined field318_0x1b9;
    undefined field319_0x1ba;
    undefined field320_0x1bb;
    undefined field321_0x1bc;
    undefined field322_0x1bd;
    undefined field323_0x1be;
    undefined field324_0x1bf;
    undefined field325_0x1c0;
    undefined field326_0x1c1;
    undefined field327_0x1c2;
    undefined field328_0x1c3;
    undefined field329_0x1c4;
    undefined field330_0x1c5;
    undefined field331_0x1c6;
    undefined field332_0x1c7;
    undefined field333_0x1c8;
    undefined field334_0x1c9;
    undefined field335_0x1ca;
    undefined field336_0x1cb;
    undefined field337_0x1cc;
    undefined field338_0x1cd;
    undefined field339_0x1ce;
    undefined field340_0x1cf;
    undefined field341_0x1d0;
    undefined field342_0x1d1;
    undefined field343_0x1d2;
    undefined field344_0x1d3;
    undefined field345_0x1d4;
    undefined field346_0x1d5;
    undefined field347_0x1d6;
    undefined field348_0x1d7;
    undefined field349_0x1d8;
    undefined field350_0x1d9;
    undefined field351_0x1da;
    undefined field352_0x1db;
    undefined field353_0x1dc;
    undefined field354_0x1dd;
    undefined field355_0x1de;
    undefined field356_0x1df;
    undefined field357_0x1e0;
    undefined field358_0x1e1;
    undefined field359_0x1e2;
    undefined field360_0x1e3;
    undefined field361_0x1e4;
    undefined field362_0x1e5;
    undefined field363_0x1e6;
    undefined field364_0x1e7;
    undefined field365_0x1e8;
    undefined field366_0x1e9;
    undefined field367_0x1ea;
    undefined field368_0x1eb;
    undefined field369_0x1ec;
    undefined field370_0x1ed;
    undefined field371_0x1ee;
    undefined field372_0x1ef;
    undefined field373_0x1f0;
    undefined field374_0x1f1;
    undefined field375_0x1f2;
    undefined field376_0x1f3;
    undefined field377_0x1f4;
    undefined field378_0x1f5;
    undefined field379_0x1f6;
    undefined field380_0x1f7;
    undefined field381_0x1f8;
    undefined field382_0x1f9;
    undefined field383_0x1fa;
    undefined field384_0x1fb;
    undefined field385_0x1fc;
    undefined field386_0x1fd;
    undefined field387_0x1fe;
    undefined field388_0x1ff;
    undefined field389_0x200;
    undefined field390_0x201;
    undefined field391_0x202;
    undefined field392_0x203;
    undefined field393_0x204;
    undefined field394_0x205;
    undefined field395_0x206;
    undefined field396_0x207;
    undefined field397_0x208;
    undefined field398_0x209;
    undefined field399_0x20a;
    undefined field400_0x20b;
    undefined field401_0x20c;
    undefined field402_0x20d;
    undefined field403_0x20e;
    undefined field404_0x20f;
    undefined field405_0x210;
    undefined field406_0x211;
    undefined field407_0x212;
    undefined field408_0x213;
    undefined field409_0x214;
    undefined field410_0x215;
    undefined field411_0x216;
    undefined field412_0x217;
    undefined field413_0x218;
    undefined field414_0x219;
    undefined field415_0x21a;
    undefined field416_0x21b;
    undefined field417_0x21c;
    undefined field418_0x21d;
    undefined field419_0x21e;
    undefined field420_0x21f;
    undefined field421_0x220;
    undefined field422_0x221;
    undefined field423_0x222;
    undefined field424_0x223;
    undefined field425_0x224;
    undefined field426_0x225;
    undefined field427_0x226;
    undefined field428_0x227;
    undefined field429_0x228;
    undefined field430_0x229;
    undefined field431_0x22a;
    undefined field432_0x22b;
    undefined field433_0x22c;
    undefined field434_0x22d;
    undefined field435_0x22e;
    undefined field436_0x22f;
    undefined field437_0x230;
    undefined field438_0x231;
    undefined field439_0x232;
    undefined field440_0x233;
    undefined field441_0x234;
    undefined field442_0x235;
    undefined field443_0x236;
    undefined field444_0x237;
    undefined field445_0x238;
    undefined field446_0x239;
    undefined field447_0x23a;
    undefined field448_0x23b;
    undefined field449_0x23c;
    undefined field450_0x23d;
    undefined field451_0x23e;
    undefined field452_0x23f;
    undefined field453_0x240;
    undefined field454_0x241;
    undefined field455_0x242;
    undefined field456_0x243;
    undefined field457_0x244;
    undefined field458_0x245;
    undefined field459_0x246;
    undefined field460_0x247;
    undefined field461_0x248;
    undefined field462_0x249;
    undefined field463_0x24a;
    undefined field464_0x24b;
    undefined field465_0x24c;
    undefined field466_0x24d;
    undefined field467_0x24e;
    undefined field468_0x24f;
    undefined field469_0x250;
    undefined field470_0x251;
    undefined field471_0x252;
    undefined field472_0x253;
    undefined field473_0x254;
    undefined field474_0x255;
    undefined field475_0x256;
    undefined field476_0x257;
    undefined field477_0x258;
    undefined field478_0x259;
    undefined field479_0x25a;
    undefined field480_0x25b;
    undefined field481_0x25c;
    undefined field482_0x25d;
    undefined field483_0x25e;
    undefined field484_0x25f;
    undefined field485_0x260;
    undefined field486_0x261;
    undefined field487_0x262;
    undefined field488_0x263;
    undefined field489_0x264;
    undefined field490_0x265;
    undefined field491_0x266;
    undefined field492_0x267;
    undefined field493_0x268;
    undefined field494_0x269;
    undefined field495_0x26a;
    undefined field496_0x26b;
    undefined field497_0x26c;
    undefined field498_0x26d;
    undefined field499_0x26e;
    undefined field500_0x26f;
    int color501_0x270;
    int color502_0x274;
    int color503_0x278;
    int color504_0x27c;
    undefined field505_0x280;
    undefined field506_0x281;
    undefined field507_0x282;
    undefined field508_0x283;
    undefined field509_0x284;
    undefined field510_0x285;
    undefined field511_0x286;
    undefined field512_0x287;
    undefined field513_0x288;
    undefined field514_0x289;
    undefined field515_0x28a;
    undefined field516_0x28b;
    undefined field517_0x28c;
    undefined field518_0x28d;
    undefined field519_0x28e;
    undefined field520_0x28f;
    undefined field521_0x290;
    undefined field522_0x291;
    undefined field523_0x292;
    undefined field524_0x293;
    undefined field525_0x294;
    undefined field526_0x295;
    undefined field527_0x296;
    undefined field528_0x297;
    undefined field529_0x298;
    undefined field530_0x299;
    undefined field531_0x29a;
    undefined field532_0x29b;
    undefined field533_0x29c;
    undefined field534_0x29d;
    undefined field535_0x29e;
    undefined field536_0x29f;
    undefined field537_0x2a0;
    undefined field538_0x2a1;
    undefined field539_0x2a2;
    undefined field540_0x2a3;
    undefined field541_0x2a4;
    undefined field542_0x2a5;
    undefined field543_0x2a6;
    undefined field544_0x2a7;
    undefined field545_0x2a8;
    undefined field546_0x2a9;
    undefined field547_0x2aa;
    undefined field548_0x2ab;
    undefined field549_0x2ac;
    undefined field550_0x2ad;
    undefined field551_0x2ae;
    undefined field552_0x2af;
    undefined field553_0x2b0;
    undefined field554_0x2b1;
    undefined field555_0x2b2;
    undefined field556_0x2b3;
    undefined field557_0x2b4;
    undefined field558_0x2b5;
    undefined field559_0x2b6;
    undefined field560_0x2b7;
    undefined field561_0x2b8;
    undefined field562_0x2b9;
    undefined field563_0x2ba;
    undefined field564_0x2bb;
    undefined field565_0x2bc;
    undefined field566_0x2bd;
    undefined field567_0x2be;
    undefined field568_0x2bf;
    undefined field569_0x2c0;
    undefined field570_0x2c1;
    undefined field571_0x2c2;
    undefined field572_0x2c3;
    undefined field573_0x2c4;
    undefined field574_0x2c5;
    undefined field575_0x2c6;
    undefined field576_0x2c7;
    undefined field577_0x2c8;
    undefined field578_0x2c9;
    undefined field579_0x2ca;
    undefined field580_0x2cb;
    undefined field581_0x2cc;
    undefined field582_0x2cd;
    undefined field583_0x2ce;
    undefined field584_0x2cf;
    undefined field585_0x2d0;
    undefined field586_0x2d1;
    undefined field587_0x2d2;
    undefined field588_0x2d3;
    undefined field589_0x2d4;
    undefined field590_0x2d5;
    undefined field591_0x2d6;
    undefined field592_0x2d7;
    undefined field593_0x2d8;
    undefined field594_0x2d9;
    undefined field595_0x2da;
    undefined field596_0x2db;
    undefined field597_0x2dc;
    undefined field598_0x2dd;
    undefined field599_0x2de;
    undefined field600_0x2df;
    undefined field601_0x2e0;
    undefined field602_0x2e1;
    undefined field603_0x2e2;
    undefined field604_0x2e3;
    undefined field605_0x2e4;
    undefined field606_0x2e5;
    undefined field607_0x2e6;
    undefined field608_0x2e7;
    undefined field609_0x2e8;
    undefined field610_0x2e9;
    undefined field611_0x2ea;
    undefined field612_0x2eb;
    undefined field613_0x2ec;
    undefined field614_0x2ed;
    undefined field615_0x2ee;
    undefined field616_0x2ef;
    undefined field617_0x2f0;
    undefined field618_0x2f1;
    undefined field619_0x2f2;
    undefined field620_0x2f3;
    undefined field621_0x2f4;
    undefined field622_0x2f5;
    undefined field623_0x2f6;
    undefined field624_0x2f7;
    undefined field625_0x2f8;
    undefined field626_0x2f9;
    undefined field627_0x2fa;
    undefined field628_0x2fb;
    undefined field629_0x2fc;
    undefined field630_0x2fd;
    undefined field631_0x2fe;
    undefined field632_0x2ff;
    undefined field633_0x300;
    undefined field634_0x301;
    undefined field635_0x302;
    undefined field636_0x303;
    undefined field637_0x304;
    undefined field638_0x305;
    undefined field639_0x306;
    undefined field640_0x307;
    undefined field641_0x308;
    undefined field642_0x309;
    undefined field643_0x30a;
    undefined field644_0x30b;
    undefined field645_0x30c;
    undefined field646_0x30d;
    undefined field647_0x30e;
    undefined field648_0x30f;
    undefined field649_0x310;
    undefined field650_0x311;
    undefined field651_0x312;
    undefined field652_0x313;
    undefined field653_0x314;
    undefined field654_0x315;
    undefined field655_0x316;
    undefined field656_0x317;
    undefined field657_0x318;
    undefined field658_0x319;
    undefined field659_0x31a;
    undefined field660_0x31b;
    undefined field661_0x31c;
    undefined field662_0x31d;
    undefined field663_0x31e;
    undefined field664_0x31f;
    undefined field665_0x320;
    undefined field666_0x321;
    undefined field667_0x322;
    undefined field668_0x323;
    undefined field669_0x324;
    undefined field670_0x325;
    undefined field671_0x326;
    undefined field672_0x327;
    undefined field673_0x328;
    undefined field674_0x329;
    undefined field675_0x32a;
    undefined field676_0x32b;
    undefined field677_0x32c;
    undefined field678_0x32d;
    undefined field679_0x32e;
    undefined field680_0x32f;
    undefined field681_0x330;
    undefined field682_0x331;
    undefined field683_0x332;
    undefined field684_0x333;
    undefined field685_0x334;
    undefined field686_0x335;
    undefined field687_0x336;
    undefined field688_0x337;
    undefined field689_0x338;
    undefined field690_0x339;
    undefined field691_0x33a;
    undefined field692_0x33b;
    undefined field693_0x33c;
    undefined field694_0x33d;
    undefined field695_0x33e;
    undefined field696_0x33f;
    int color697_0x340;
    int color698_0x344;
    int color699_0x348;
    int color700_0x34c;
    undefined field701_0x350;
    undefined field702_0x351;
    undefined field703_0x352;
    undefined field704_0x353;
    undefined field705_0x354;
    undefined field706_0x355;
    undefined field707_0x356;
    undefined field708_0x357;
    undefined field709_0x358;
    undefined field710_0x359;
    undefined field711_0x35a;
    undefined field712_0x35b;
    undefined field713_0x35c;
    undefined field714_0x35d;
    undefined field715_0x35e;
    undefined field716_0x35f;
    undefined field717_0x360;
    undefined field718_0x361;
    undefined field719_0x362;
    undefined field720_0x363;
    undefined field721_0x364;
    undefined field722_0x365;
    undefined field723_0x366;
    undefined field724_0x367;
    undefined field725_0x368;
    undefined field726_0x369;
    undefined field727_0x36a;
    undefined field728_0x36b;
    undefined field729_0x36c;
    undefined field730_0x36d;
    undefined field731_0x36e;
    undefined field732_0x36f;
    undefined field733_0x370;
    undefined field734_0x371;
    undefined field735_0x372;
    undefined field736_0x373;
    undefined field737_0x374;
    undefined field738_0x375;
    undefined field739_0x376;
    undefined field740_0x377;
    undefined field741_0x378;
    undefined field742_0x379;
    undefined field743_0x37a;
    undefined field744_0x37b;
    undefined field745_0x37c;
    undefined field746_0x37d;
    undefined field747_0x37e;
    undefined field748_0x37f;
    undefined field749_0x380;
    undefined field750_0x381;
    undefined field751_0x382;
    undefined field752_0x383;
    undefined field753_0x384;
    undefined field754_0x385;
    undefined field755_0x386;
    undefined field756_0x387;
    undefined field757_0x388;
    undefined field758_0x389;
    undefined field759_0x38a;
    undefined field760_0x38b;
    undefined field761_0x38c;
    undefined field762_0x38d;
    undefined field763_0x38e;
    undefined field764_0x38f;
    undefined field765_0x390;
    undefined field766_0x391;
    undefined field767_0x392;
    undefined field768_0x393;
    undefined field769_0x394;
    undefined field770_0x395;
    undefined field771_0x396;
    undefined field772_0x397;
    undefined field773_0x398;
    undefined field774_0x399;
    undefined field775_0x39a;
    undefined field776_0x39b;
    undefined field777_0x39c;
    undefined field778_0x39d;
    undefined field779_0x39e;
    undefined field780_0x39f;
    undefined field781_0x3a0;
    undefined field782_0x3a1;
    undefined field783_0x3a2;
    undefined field784_0x3a3;
    undefined field785_0x3a4;
    undefined field786_0x3a5;
    undefined field787_0x3a6;
    undefined field788_0x3a7;
    undefined field789_0x3a8;
    undefined field790_0x3a9;
    undefined field791_0x3aa;
    undefined field792_0x3ab;
    undefined field793_0x3ac;
    undefined field794_0x3ad;
    undefined field795_0x3ae;
    undefined field796_0x3af;
    undefined field797_0x3b0;
    undefined field798_0x3b1;
    undefined field799_0x3b2;
    undefined field800_0x3b3;
    undefined field801_0x3b4;
    undefined field802_0x3b5;
    undefined field803_0x3b6;
    undefined field804_0x3b7;
    undefined field805_0x3b8;
    undefined field806_0x3b9;
    undefined field807_0x3ba;
    undefined field808_0x3bb;
    undefined field809_0x3bc;
    undefined field810_0x3bd;
    undefined field811_0x3be;
    undefined field812_0x3bf;
    undefined field813_0x3c0;
    undefined field814_0x3c1;
    undefined field815_0x3c2;
    undefined field816_0x3c3;
    undefined field817_0x3c4;
    undefined field818_0x3c5;
    undefined field819_0x3c6;
    undefined field820_0x3c7;
    undefined field821_0x3c8;
    undefined field822_0x3c9;
    undefined field823_0x3ca;
    undefined field824_0x3cb;
    undefined field825_0x3cc;
    undefined field826_0x3cd;
    undefined field827_0x3ce;
    undefined field828_0x3cf;
    undefined field829_0x3d0;
    undefined field830_0x3d1;
    undefined field831_0x3d2;
    undefined field832_0x3d3;
    undefined field833_0x3d4;
    undefined field834_0x3d5;
    undefined field835_0x3d6;
    undefined field836_0x3d7;
    undefined field837_0x3d8;
    undefined field838_0x3d9;
    undefined field839_0x3da;
    undefined field840_0x3db;
    undefined field841_0x3dc;
    undefined field842_0x3dd;
    undefined field843_0x3de;
    undefined field844_0x3df;
    undefined field845_0x3e0;
    undefined field846_0x3e1;
    undefined field847_0x3e2;
    undefined field848_0x3e3;
    undefined field849_0x3e4;
    undefined field850_0x3e5;
    undefined field851_0x3e6;
    undefined field852_0x3e7;
    undefined field853_0x3e8;
    undefined field854_0x3e9;
    undefined field855_0x3ea;
    undefined field856_0x3eb;
    undefined field857_0x3ec;
    undefined field858_0x3ed;
    undefined field859_0x3ee;
    undefined field860_0x3ef;
    undefined field861_0x3f0;
    undefined field862_0x3f1;
    undefined field863_0x3f2;
    undefined field864_0x3f3;
    undefined field865_0x3f4;
    undefined field866_0x3f5;
    undefined field867_0x3f6;
    undefined field868_0x3f7;
    undefined field869_0x3f8;
    undefined field870_0x3f9;
    undefined field871_0x3fa;
    undefined field872_0x3fb;
    undefined field873_0x3fc;
    undefined field874_0x3fd;
    undefined field875_0x3fe;
    undefined field876_0x3ff;
    undefined field877_0x400;
    undefined field878_0x401;
    undefined field879_0x402;
    undefined field880_0x403;
    undefined field881_0x404;
    undefined field882_0x405;
    undefined field883_0x406;
    undefined field884_0x407;
    undefined field885_0x408;
    undefined field886_0x409;
    undefined field887_0x40a;
    undefined field888_0x40b;
    undefined field889_0x40c;
    undefined field890_0x40d;
    undefined field891_0x40e;
    undefined field892_0x40f;
    int color893_0x410;
    int color894_0x414;
    int color895_0x418;
    int color896_0x41c;
    undefined field897_0x420;
    undefined field898_0x421;
    undefined field899_0x422;
    undefined field900_0x423;
    undefined field901_0x424;
    undefined field902_0x425;
    undefined field903_0x426;
    undefined field904_0x427;
    undefined field905_0x428;
    undefined field906_0x429;
    undefined field907_0x42a;
    undefined field908_0x42b;
    undefined field909_0x42c;
    undefined field910_0x42d;
    undefined field911_0x42e;
    undefined field912_0x42f;
    undefined field913_0x430;
    undefined field914_0x431;
    undefined field915_0x432;
    undefined field916_0x433;
    undefined field917_0x434;
    undefined field918_0x435;
    undefined field919_0x436;
    undefined field920_0x437;
    undefined field921_0x438;
    undefined field922_0x439;
    undefined field923_0x43a;
    undefined field924_0x43b;
    undefined field925_0x43c;
    undefined field926_0x43d;
    undefined field927_0x43e;
    undefined field928_0x43f;
    undefined field929_0x440;
    undefined field930_0x441;
    undefined field931_0x442;
    undefined field932_0x443;
    undefined field933_0x444;
    undefined field934_0x445;
    undefined field935_0x446;
    undefined field936_0x447;
    undefined field937_0x448;
    undefined field938_0x449;
    undefined field939_0x44a;
    undefined field940_0x44b;
    undefined field941_0x44c;
    undefined field942_0x44d;
    undefined field943_0x44e;
    undefined field944_0x44f;
    undefined field945_0x450;
    undefined field946_0x451;
    undefined field947_0x452;
    undefined field948_0x453;
    undefined field949_0x454;
    undefined field950_0x455;
    undefined field951_0x456;
    undefined field952_0x457;
    undefined field953_0x458;
    undefined field954_0x459;
    undefined field955_0x45a;
    undefined field956_0x45b;
    undefined field957_0x45c;
    undefined field958_0x45d;
    undefined field959_0x45e;
    undefined field960_0x45f;
    undefined field961_0x460;
    undefined field962_0x461;
    undefined field963_0x462;
    undefined field964_0x463;
    undefined field965_0x464;
    undefined field966_0x465;
    undefined field967_0x466;
    undefined field968_0x467;
    undefined field969_0x468;
    undefined field970_0x469;
    undefined field971_0x46a;
    undefined field972_0x46b;
    undefined field973_0x46c;
    undefined field974_0x46d;
    undefined field975_0x46e;
    undefined field976_0x46f;
    undefined field977_0x470;
    undefined field978_0x471;
    undefined field979_0x472;
    undefined field980_0x473;
    undefined field981_0x474;
    undefined field982_0x475;
    undefined field983_0x476;
    undefined field984_0x477;
    undefined field985_0x478;
    undefined field986_0x479;
    undefined field987_0x47a;
    undefined field988_0x47b;
    undefined field989_0x47c;
    undefined field990_0x47d;
    undefined field991_0x47e;
    undefined field992_0x47f;
    undefined field993_0x480;
    undefined field994_0x481;
    undefined field995_0x482;
    undefined field996_0x483;
    undefined field997_0x484;
    undefined field998_0x485;
    undefined field999_0x486;
    undefined field1000_0x487;
    undefined field1001_0x488;
    undefined field1002_0x489;
    undefined field1003_0x48a;
    undefined field1004_0x48b;
    undefined field1005_0x48c;
    undefined field1006_0x48d;
    undefined field1007_0x48e;
    undefined field1008_0x48f;
    undefined field1009_0x490;
    undefined field1010_0x491;
    undefined field1011_0x492;
    undefined field1012_0x493;
    undefined field1013_0x494;
    undefined field1014_0x495;
    undefined field1015_0x496;
    undefined field1016_0x497;
    undefined field1017_0x498;
    undefined field1018_0x499;
    undefined field1019_0x49a;
    undefined field1020_0x49b;
    undefined field1021_0x49c;
    undefined field1022_0x49d;
    undefined field1023_0x49e;
    undefined field1024_0x49f;
    undefined field1025_0x4a0;
    undefined field1026_0x4a1;
    undefined field1027_0x4a2;
    undefined field1028_0x4a3;
    undefined field1029_0x4a4;
    undefined field1030_0x4a5;
    undefined field1031_0x4a6;
    undefined field1032_0x4a7;
    undefined field1033_0x4a8;
    undefined field1034_0x4a9;
    undefined field1035_0x4aa;
    undefined field1036_0x4ab;
    undefined field1037_0x4ac;
    undefined field1038_0x4ad;
    undefined field1039_0x4ae;
    undefined field1040_0x4af;
    undefined field1041_0x4b0;
    undefined field1042_0x4b1;
    undefined field1043_0x4b2;
    undefined field1044_0x4b3;
    undefined field1045_0x4b4;
    undefined field1046_0x4b5;
    undefined field1047_0x4b6;
    undefined field1048_0x4b7;
    undefined field1049_0x4b8;
    undefined field1050_0x4b9;
    undefined field1051_0x4ba;
    undefined field1052_0x4bb;
    undefined field1053_0x4bc;
    undefined field1054_0x4bd;
    undefined field1055_0x4be;
    undefined field1056_0x4bf;
    undefined field1057_0x4c0;
    undefined field1058_0x4c1;
    undefined field1059_0x4c2;
    undefined field1060_0x4c3;
    undefined field1061_0x4c4;
    undefined field1062_0x4c5;
    undefined field1063_0x4c6;
    undefined field1064_0x4c7;
    undefined field1065_0x4c8;
    undefined field1066_0x4c9;
    undefined field1067_0x4ca;
    undefined field1068_0x4cb;
    undefined field1069_0x4cc;
    undefined field1070_0x4cd;
    undefined field1071_0x4ce;
    undefined field1072_0x4cf;
    undefined field1073_0x4d0;
    undefined field1074_0x4d1;
    undefined field1075_0x4d2;
    undefined field1076_0x4d3;
    undefined field1077_0x4d4;
    undefined field1078_0x4d5;
    undefined field1079_0x4d6;
    undefined field1080_0x4d7;
    undefined field1081_0x4d8;
    undefined field1082_0x4d9;
    undefined field1083_0x4da;
    undefined field1084_0x4db;
    undefined field1085_0x4dc;
    undefined field1086_0x4dd;
    undefined field1087_0x4de;
    undefined field1088_0x4df;
    int color1089_0x4e0;
    int color1090_0x4e4;
    int color1091_0x4e8;
    int color1092_0x4ec;
};
#endif
#endif