#include <PA_BgStruct.h>

extern const char BG2_bas_alg_Tiles[];
extern const char BG2_bas_alg_Map[];
extern const char BG2_bas_alg_Pal[];

const PA_BgStruct BG2_bas_alg = {
	PA_BgNormal,
	256, 192,

	BG2_bas_alg_Tiles,
	BG2_bas_alg_Map,
	{BG2_bas_alg_Pal},

	8832,
	{1536}
};
