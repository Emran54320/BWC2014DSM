#include <PA_BgStruct.h>

extern const char BG2_bas_aus_Tiles[];
extern const char BG2_bas_aus_Map[];
extern const char BG2_bas_aus_Pal[];

const PA_BgStruct BG2_bas_aus = {
	PA_BgNormal,
	256, 192,

	BG2_bas_aus_Tiles,
	BG2_bas_aus_Map,
	{BG2_bas_aus_Pal},

	9216,
	{1536}
};
