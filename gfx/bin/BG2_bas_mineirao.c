#include <PA_BgStruct.h>

extern const char BG2_bas_mineirao_Tiles[];
extern const char BG2_bas_mineirao_Map[];
extern const char BG2_bas_mineirao_Pal[];

const PA_BgStruct BG2_bas_mineirao = {
	PA_BgNormal,
	256, 192,

	BG2_bas_mineirao_Tiles,
	BG2_bas_mineirao_Map,
	{BG2_bas_mineirao_Pal},

	5952,
	{1536}
};
