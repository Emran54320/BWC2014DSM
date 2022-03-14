#include <PA_BgStruct.h>

extern const char BG2_bas_maracana_Tiles[];
extern const char BG2_bas_maracana_Map[];
extern const char BG2_bas_maracana_Pal[];

const PA_BgStruct BG2_bas_maracana = {
	PA_BgNormal,
	256, 192,

	BG2_bas_maracana_Tiles,
	BG2_bas_maracana_Map,
	{BG2_bas_maracana_Pal},

	6080,
	{1536}
};
