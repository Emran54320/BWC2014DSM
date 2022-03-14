#include <PA_BgStruct.h>

extern const char BG2_bas_irn_Tiles[];
extern const char BG2_bas_irn_Map[];
extern const char BG2_bas_irn_Pal[];

const PA_BgStruct BG2_bas_irn = {
	PA_BgNormal,
	256, 192,

	BG2_bas_irn_Tiles,
	BG2_bas_irn_Map,
	{BG2_bas_irn_Pal},

	8704,
	{1536}
};
