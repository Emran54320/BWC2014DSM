#include <PA_BgStruct.h>

extern const char BG2_bas_selection_Tiles[];
extern const char BG2_bas_selection_Map[];
extern const char BG2_bas_selection_Pal[];

const PA_BgStruct BG2_bas_selection = {
	PA_BgNormal,
	256, 256,

	BG2_bas_selection_Tiles,
	BG2_bas_selection_Map,
	{BG2_bas_selection_Pal},

	256,
	{2048}
};
