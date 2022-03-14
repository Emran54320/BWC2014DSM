#include <PA_BgStruct.h>

extern const char BG2_bas_castelao_Tiles[];
extern const char BG2_bas_castelao_Map[];
extern const char BG2_bas_castelao_Pal[];

const PA_BgStruct BG2_bas_castelao = {
	PA_BgNormal,
	256, 192,

	BG2_bas_castelao_Tiles,
	BG2_bas_castelao_Map,
	{BG2_bas_castelao_Pal},

	5632,
	{1536}
};
