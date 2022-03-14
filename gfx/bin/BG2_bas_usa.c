#include <PA_BgStruct.h>

extern const char BG2_bas_usa_Tiles[];
extern const char BG2_bas_usa_Map[];
extern const char BG2_bas_usa_Pal[];

const PA_BgStruct BG2_bas_usa = {
	PA_BgNormal,
	256, 192,

	BG2_bas_usa_Tiles,
	BG2_bas_usa_Map,
	{BG2_bas_usa_Pal},

	9536,
	{1536}
};
