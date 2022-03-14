#include <PA_BgStruct.h>

extern const char BG2_bas_saopaulo_Tiles[];
extern const char BG2_bas_saopaulo_Map[];
extern const char BG2_bas_saopaulo_Pal[];

const PA_BgStruct BG2_bas_saopaulo = {
	PA_BgNormal,
	256, 192,

	BG2_bas_saopaulo_Tiles,
	BG2_bas_saopaulo_Map,
	{BG2_bas_saopaulo_Pal},

	5056,
	{1536}
};
