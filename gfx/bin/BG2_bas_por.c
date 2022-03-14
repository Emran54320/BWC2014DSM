#include <PA_BgStruct.h>

extern const char BG2_bas_por_Tiles[];
extern const char BG2_bas_por_Map[];
extern const char BG2_bas_por_Pal[];

const PA_BgStruct BG2_bas_por = {
	PA_BgNormal,
	256, 192,

	BG2_bas_por_Tiles,
	BG2_bas_por_Map,
	{BG2_bas_por_Pal},

	8768,
	{1536}
};
