#include <PA_BgStruct.h>

extern const char BG2_bas_beirario_Tiles[];
extern const char BG2_bas_beirario_Map[];
extern const char BG2_bas_beirario_Pal[];

const PA_BgStruct BG2_bas_beirario = {
	PA_BgNormal,
	256, 192,

	BG2_bas_beirario_Tiles,
	BG2_bas_beirario_Map,
	{BG2_bas_beirario_Pal},

	5248,
	{1536}
};
