#include <PA_BgStruct.h>

extern const char BG2_bas_mex_Tiles[];
extern const char BG2_bas_mex_Map[];
extern const char BG2_bas_mex_Pal[];

const PA_BgStruct BG2_bas_mex = {
	PA_BgNormal,
	256, 192,

	BG2_bas_mex_Tiles,
	BG2_bas_mex_Map,
	{BG2_bas_mex_Pal},

	9600,
	{1536}
};
