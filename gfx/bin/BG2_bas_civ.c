#include <PA_BgStruct.h>

extern const char BG2_bas_civ_Tiles[];
extern const char BG2_bas_civ_Map[];
extern const char BG2_bas_civ_Pal[];

const PA_BgStruct BG2_bas_civ = {
	PA_BgNormal,
	256, 192,

	BG2_bas_civ_Tiles,
	BG2_bas_civ_Map,
	{BG2_bas_civ_Pal},

	8768,
	{1536}
};
