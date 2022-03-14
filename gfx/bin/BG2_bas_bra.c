#include <PA_BgStruct.h>

extern const char BG2_bas_bra_Tiles[];
extern const char BG2_bas_bra_Map[];
extern const char BG2_bas_bra_Pal[];

const PA_BgStruct BG2_bas_bra = {
	PA_BgNormal,
	256, 192,

	BG2_bas_bra_Tiles,
	BG2_bas_bra_Map,
	{BG2_bas_bra_Pal},

	9664,
	{1536}
};
