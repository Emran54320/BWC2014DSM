#include <PA_BgStruct.h>

extern const char BG2_bas_nga_Tiles[];
extern const char BG2_bas_nga_Map[];
extern const char BG2_bas_nga_Pal[];

const PA_BgStruct BG2_bas_nga = {
	PA_BgNormal,
	256, 192,

	BG2_bas_nga_Tiles,
	BG2_bas_nga_Map,
	{BG2_bas_nga_Pal},

	9088,
	{1536}
};
