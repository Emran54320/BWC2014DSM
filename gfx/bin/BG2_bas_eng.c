#include <PA_BgStruct.h>

extern const char BG2_bas_eng_Tiles[];
extern const char BG2_bas_eng_Map[];
extern const char BG2_bas_eng_Pal[];

const PA_BgStruct BG2_bas_eng = {
	PA_BgNormal,
	256, 192,

	BG2_bas_eng_Tiles,
	BG2_bas_eng_Map,
	{BG2_bas_eng_Pal},

	8896,
	{1536}
};
