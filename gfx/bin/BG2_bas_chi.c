#include <PA_BgStruct.h>

extern const char BG2_bas_chi_Tiles[];
extern const char BG2_bas_chi_Map[];
extern const char BG2_bas_chi_Pal[];

const PA_BgStruct BG2_bas_chi = {
	PA_BgNormal,
	256, 192,

	BG2_bas_chi_Tiles,
	BG2_bas_chi_Map,
	{BG2_bas_chi_Pal},

	9280,
	{1536}
};
