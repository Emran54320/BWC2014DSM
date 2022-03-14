#include <PA_BgStruct.h>

extern const char BG2_bas_crc_Tiles[];
extern const char BG2_bas_crc_Map[];
extern const char BG2_bas_crc_Pal[];

const PA_BgStruct BG2_bas_crc = {
	PA_BgNormal,
	256, 192,

	BG2_bas_crc_Tiles,
	BG2_bas_crc_Map,
	{BG2_bas_crc_Pal},

	9216,
	{1536}
};
