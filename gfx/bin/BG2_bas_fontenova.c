#include <PA_BgStruct.h>

extern const char BG2_bas_fontenova_Tiles[];
extern const char BG2_bas_fontenova_Map[];
extern const char BG2_bas_fontenova_Pal[];

const PA_BgStruct BG2_bas_fontenova = {
	PA_BgNormal,
	256, 192,

	BG2_bas_fontenova_Tiles,
	BG2_bas_fontenova_Map,
	{BG2_bas_fontenova_Pal},

	5632,
	{1536}
};
