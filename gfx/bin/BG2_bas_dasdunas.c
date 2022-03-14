#include <PA_BgStruct.h>

extern const char BG2_bas_dasdunas_Tiles[];
extern const char BG2_bas_dasdunas_Map[];
extern const char BG2_bas_dasdunas_Pal[];

const PA_BgStruct BG2_bas_dasdunas = {
	PA_BgNormal,
	256, 192,

	BG2_bas_dasdunas_Tiles,
	BG2_bas_dasdunas_Map,
	{BG2_bas_dasdunas_Pal},

	4864,
	{1536}
};
