#include <PA_BgStruct.h>

extern const char BG2_bas_uru_Tiles[];
extern const char BG2_bas_uru_Map[];
extern const char BG2_bas_uru_Pal[];

const PA_BgStruct BG2_bas_uru = {
	PA_BgNormal,
	256, 192,

	BG2_bas_uru_Tiles,
	BG2_bas_uru_Map,
	{BG2_bas_uru_Pal},

	8896,
	{1536}
};
