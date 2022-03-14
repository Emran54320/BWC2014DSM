#include <PA_BgStruct.h>

extern const char BG2_bas_amazonia_Tiles[];
extern const char BG2_bas_amazonia_Map[];
extern const char BG2_bas_amazonia_Pal[];

const PA_BgStruct BG2_bas_amazonia = {
	PA_BgNormal,
	256, 192,

	BG2_bas_amazonia_Tiles,
	BG2_bas_amazonia_Map,
	{BG2_bas_amazonia_Pal},

	5696,
	{1536}
};
