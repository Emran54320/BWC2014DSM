#include <PA_BgStruct.h>

extern const char BG2_bas_jpn_Tiles[];
extern const char BG2_bas_jpn_Map[];
extern const char BG2_bas_jpn_Pal[];

const PA_BgStruct BG2_bas_jpn = {
	PA_BgNormal,
	256, 192,

	BG2_bas_jpn_Tiles,
	BG2_bas_jpn_Map,
	{BG2_bas_jpn_Pal},

	9024,
	{1536}
};
