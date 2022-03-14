#include <PA_BgStruct.h>

extern const char BG2_bas_pernambuco_Tiles[];
extern const char BG2_bas_pernambuco_Map[];
extern const char BG2_bas_pernambuco_Pal[];

const PA_BgStruct BG2_bas_pernambuco = {
	PA_BgNormal,
	256, 192,

	BG2_bas_pernambuco_Tiles,
	BG2_bas_pernambuco_Map,
	{BG2_bas_pernambuco_Pal},

	4864,
	{1536}
};
