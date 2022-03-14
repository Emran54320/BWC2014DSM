#include <PA_BgStruct.h>

extern const char BG2_bas_baixada_Tiles[];
extern const char BG2_bas_baixada_Map[];
extern const char BG2_bas_baixada_Pal[];

const PA_BgStruct BG2_bas_baixada = {
	PA_BgNormal,
	256, 192,

	BG2_bas_baixada_Tiles,
	BG2_bas_baixada_Map,
	{BG2_bas_baixada_Pal},

	5696,
	{1536}
};
