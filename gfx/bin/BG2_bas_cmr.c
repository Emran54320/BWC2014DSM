#include <PA_BgStruct.h>

extern const char BG2_bas_cmr_Tiles[];
extern const char BG2_bas_cmr_Map[];
extern const char BG2_bas_cmr_Pal[];

const PA_BgStruct BG2_bas_cmr = {
	PA_BgNormal,
	256, 192,

	BG2_bas_cmr_Tiles,
	BG2_bas_cmr_Map,
	{BG2_bas_cmr_Pal},

	9472,
	{1536}
};
