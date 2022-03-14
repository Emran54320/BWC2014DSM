#include <PA_BgStruct.h>

extern const char BG2_bas_gha_Tiles[];
extern const char BG2_bas_gha_Map[];
extern const char BG2_bas_gha_Pal[];

const PA_BgStruct BG2_bas_gha = {
	PA_BgNormal,
	256, 192,

	BG2_bas_gha_Tiles,
	BG2_bas_gha_Map,
	{BG2_bas_gha_Pal},

	8960,
	{1536}
};
