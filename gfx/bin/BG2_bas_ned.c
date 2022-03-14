#include <PA_BgStruct.h>

extern const char BG2_bas_ned_Tiles[];
extern const char BG2_bas_ned_Map[];
extern const char BG2_bas_ned_Pal[];

const PA_BgStruct BG2_bas_ned = {
	PA_BgNormal,
	256, 192,

	BG2_bas_ned_Tiles,
	BG2_bas_ned_Map,
	{BG2_bas_ned_Pal},

	9216,
	{1536}
};
