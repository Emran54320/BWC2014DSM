#include <PA_BgStruct.h>

extern const char BG2_bas_rus_Tiles[];
extern const char BG2_bas_rus_Map[];
extern const char BG2_bas_rus_Pal[];

const PA_BgStruct BG2_bas_rus = {
	PA_BgNormal,
	256, 192,

	BG2_bas_rus_Tiles,
	BG2_bas_rus_Map,
	{BG2_bas_rus_Pal},

	8832,
	{1536}
};
