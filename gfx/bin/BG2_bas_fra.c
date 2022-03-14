#include <PA_BgStruct.h>

extern const char BG2_bas_fra_Tiles[];
extern const char BG2_bas_fra_Map[];
extern const char BG2_bas_fra_Pal[];

const PA_BgStruct BG2_bas_fra = {
	PA_BgNormal,
	256, 192,

	BG2_bas_fra_Tiles,
	BG2_bas_fra_Map,
	{BG2_bas_fra_Pal},

	8640,
	{1536}
};
