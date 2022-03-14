#include <PA_BgStruct.h>

extern const char BG2_bas_pantanal_Tiles[];
extern const char BG2_bas_pantanal_Map[];
extern const char BG2_bas_pantanal_Pal[];

const PA_BgStruct BG2_bas_pantanal = {
	PA_BgNormal,
	256, 192,

	BG2_bas_pantanal_Tiles,
	BG2_bas_pantanal_Map,
	{BG2_bas_pantanal_Pal},

	4864,
	{1536}
};
