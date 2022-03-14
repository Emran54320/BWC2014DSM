#include <PA_BgStruct.h>

extern const char BG2_bas_hon_Tiles[];
extern const char BG2_bas_hon_Map[];
extern const char BG2_bas_hon_Pal[];

const PA_BgStruct BG2_bas_hon = {
	PA_BgNormal,
	256, 192,

	BG2_bas_hon_Tiles,
	BG2_bas_hon_Map,
	{BG2_bas_hon_Pal},

	9472,
	{1536}
};
