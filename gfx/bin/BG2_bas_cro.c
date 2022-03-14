#include <PA_BgStruct.h>

extern const char BG2_bas_cro_Tiles[];
extern const char BG2_bas_cro_Map[];
extern const char BG2_bas_cro_Pal[];

const PA_BgStruct BG2_bas_cro = {
	PA_BgNormal,
	256, 192,

	BG2_bas_cro_Tiles,
	BG2_bas_cro_Map,
	{BG2_bas_cro_Pal},

	8960,
	{1536}
};
