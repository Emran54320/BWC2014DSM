#include <PA_BgStruct.h>

extern const char BG2_bas_sui_Tiles[];
extern const char BG2_bas_sui_Map[];
extern const char BG2_bas_sui_Pal[];

const PA_BgStruct BG2_bas_sui = {
	PA_BgNormal,
	256, 192,

	BG2_bas_sui_Tiles,
	BG2_bas_sui_Map,
	{BG2_bas_sui_Pal},

	8448,
	{1536}
};
