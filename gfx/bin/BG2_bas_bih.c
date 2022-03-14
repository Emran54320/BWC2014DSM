#include <PA_BgStruct.h>

extern const char BG2_bas_bih_Tiles[];
extern const char BG2_bas_bih_Map[];
extern const char BG2_bas_bih_Pal[];

const PA_BgStruct BG2_bas_bih = {
	PA_BgNormal,
	256, 192,

	BG2_bas_bih_Tiles,
	BG2_bas_bih_Map,
	{BG2_bas_bih_Pal},

	8832,
	{1536}
};
