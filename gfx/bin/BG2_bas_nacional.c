#include <PA_BgStruct.h>

extern const char BG2_bas_nacional_Tiles[];
extern const char BG2_bas_nacional_Map[];
extern const char BG2_bas_nacional_Pal[];

const PA_BgStruct BG2_bas_nacional = {
	PA_BgNormal,
	256, 192,

	BG2_bas_nacional_Tiles,
	BG2_bas_nacional_Map,
	{BG2_bas_nacional_Pal},

	5248,
	{1536}
};
