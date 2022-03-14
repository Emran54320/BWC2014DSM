#include <PA_BgStruct.h>

extern const char BG2_bas_ger_Tiles[];
extern const char BG2_bas_ger_Map[];
extern const char BG2_bas_ger_Pal[];

const PA_BgStruct BG2_bas_ger = {
	PA_BgNormal,
	256, 192,

	BG2_bas_ger_Tiles,
	BG2_bas_ger_Map,
	{BG2_bas_ger_Pal},

	8896,
	{1536}
};
