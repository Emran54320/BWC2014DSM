#include <PA_BgStruct.h>

extern const char BG2_bas_ecu_Tiles[];
extern const char BG2_bas_ecu_Map[];
extern const char BG2_bas_ecu_Pal[];

const PA_BgStruct BG2_bas_ecu = {
	PA_BgNormal,
	256, 192,

	BG2_bas_ecu_Tiles,
	BG2_bas_ecu_Map,
	{BG2_bas_ecu_Pal},

	9088,
	{1536}
};
