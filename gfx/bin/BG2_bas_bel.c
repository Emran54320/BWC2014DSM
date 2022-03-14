#include <PA_BgStruct.h>

extern const char BG2_bas_bel_Tiles[];
extern const char BG2_bas_bel_Map[];
extern const char BG2_bas_bel_Pal[];

const PA_BgStruct BG2_bas_bel = {
	PA_BgNormal,
	256, 192,

	BG2_bas_bel_Tiles,
	BG2_bas_bel_Map,
	{BG2_bas_bel_Pal},

	8704,
	{1536}
};
