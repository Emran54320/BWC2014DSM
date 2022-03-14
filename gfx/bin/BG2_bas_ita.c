#include <PA_BgStruct.h>

extern const char BG2_bas_ita_Tiles[];
extern const char BG2_bas_ita_Map[];
extern const char BG2_bas_ita_Pal[];

const PA_BgStruct BG2_bas_ita = {
	PA_BgNormal,
	256, 192,

	BG2_bas_ita_Tiles,
	BG2_bas_ita_Map,
	{BG2_bas_ita_Pal},

	8640,
	{1536}
};
