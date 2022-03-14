#include <PA_BgStruct.h>

extern const char BG2_bas_gre_Tiles[];
extern const char BG2_bas_gre_Map[];
extern const char BG2_bas_gre_Pal[];

const PA_BgStruct BG2_bas_gre = {
	PA_BgNormal,
	256, 192,

	BG2_bas_gre_Tiles,
	BG2_bas_gre_Map,
	{BG2_bas_gre_Pal},

	8640,
	{1536}
};
